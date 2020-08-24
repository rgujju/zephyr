/*
 * Copyright (c) 2020 Rohit Gujarathi
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT   jdisplay_lpm0xx

#define LOG_LEVEL CONFIG_DISPLAY_LOG_LEVEL
#include <logging/log.h>
LOG_MODULE_REGISTER(lpm0xx);

#include <string.h>
#include <device.h>
#include <drivers/display.h>
#include <init.h>
#include <drivers/gpio.h>
#include <drivers/spi.h>
#include <sys/byteorder.h>

/* Supports LPM013M126
 */

/* Note:
 * -> high/1 means white, low/0 means black
 * -> Display expects LSB first
 * -> If devicetree contains DISP pin then it will be set to high
 *      during initialization.
 * -> Jdisplay memory displays require toggling the VCOM signal periodically
 *      to prevent a DC bias ocurring in the panel. The DC bias can damage
 *      the LCD and reduce the life. This signal must be supplied
 *      from either serial input (sw) or an external signal on the
 *      EXTCOMIN pin. The driver can do this internally
 *      (CONFIG_LPM0XX_VCOM_DRIVER=y) else user can handle it in
 *      application code (CONFIG_LPM0XX_VCOM_DRIVER=n).
 *      Source:
 * https://www.j-display.com/product/pdf/ApplicationNote_reflective-type_color_display_e.pdf
 * -> If CONFIG_LPM0XX_VCOM_DRIVER=y then driver can partially or completely
 *      handle VCOM toggling. User can control method of toggling
 *      by defining extcomin-gpios in devicetree.
 * -> VCOM is toggled through serial input by software if extcomin-gpios
 *      is not defined in devicetree.
 *      EXTMODE pin is connected to VSS
 *      Important: User has to make sure .write is called periodically
 *      for toggling VCOM. If there is no data to update then buf can
 *      be set to NULL then only VCOM will be toggled.
 * -> To control VCOM using external signal EXTCOMIN, define
 *      extcomin-gpios in the devicetree.
 *      EXTMODE pin is connected to VDD
 *      Important: Driver will start a thread which will
 *      toggle the EXTCOMIN pin every 500ms. There is no
 *      dependency on user.
 * -> AG9 and AG8 are always considered 0. As max line number at the
 *      moment is 240 for LPM027M128 display
 * -> Frame buf format for each row,
 *      Adding 2 to frame_buf for the line number and dummy byte
 * +-------------------+---------------------+----------------+
 * | line num (8 bits) | data (WIDTH*4 bits) | dummy (8 bits) |
 * +-------------------+---------------------+----------------+
 * |                           ↑                              |
 * |                   LPM0XX_PANEL_HEIGHT                    |
 * |                           ↓                              |
 * +----------------------------------------------------------+
 * Each byte is of the form
 * | R | G | B | Not used | R | G | B | Not used |
 */

#define LPM0XX_SCS_PIN             DT_INST_GPIO_PIN(0, scs_gpios)
#define LPM0XX_SCS_CNTRL           DT_INST_GPIO_LABEL(0, scs_gpios)

#if defined(CONFIG_LPM0XX_VCOM_DRIVER)
	#if DT_INST_NODE_HAS_PROP(0, extcomin_gpios)
		#define LPM0XX_VCOM_EXTERNAL   1
	#endif
#endif

#define LPM0XX_PANEL_WIDTH         DT_INST_PROP(0, width)
#define LPM0XX_PANEL_HEIGHT        DT_INST_PROP(0, height)

/* Adding 2 for the line number and dummy byte
 * The display is operated in 4 bit mode. Each byte contains 2 pixels.
 */
#define LPM0XX_BYTES_PER_LINE      (((LPM0XX_PANEL_WIDTH*4)/8)+2)

/* +-----+------+----+----+----+
 * | Mode       | M3 | M4 | M5 |
 * +-----+------+----+----+----+
 * | 3-Bit mode | L  | L  | X  |
 * | 1-Bit mode | L  | H  | X  |
 * | 4-Bit mode | H  | X  | X  |
 * +-----+------+----+----+----+
 */

#define LPM0XX_BIT_M3              0x10
#define LPM0XX_BIT_M4              0x08
#define LPM0XX_BIT_M5              0x04

#define LPM0XX_BIT_WRITECMD        (0x80 | LPM0XX_BIT_M3) /* 4 bit data mode */
#define LPM0XX_BIT_VCOM            0x40
#define LPM0XX_BIT_CLEAR           0x20

/* 3 bufs One for write_cmd/clear_cmd,
 * one for data and one for dummy byte at the end
 */
static struct spi_buf tx_buf[3];
static struct spi_buf_set buf_set = {.buffers = (struct spi_buf *)&tx_buf,
		   .count = 3
};

struct lpm0xx_data {
	struct device *scs;
#if DT_INST_NODE_HAS_PROP(0, disp_gpios)
	struct device *disp;
#endif
#if DT_INST_NODE_HAS_PROP(0, extcomin_gpios)
	struct device *extcomin;
#endif
	struct device *spi_dev;
	struct spi_config spi_config;
};
static uint8_t extcomin_bit;

#if defined(CONFIG_LPM0XX_VCOM_DRIVER)

#if defined(LPM0XX_VCOM_EXTERNAL)
#define LPM0XX_EXTCOMIN_BIT 0x00
/**
 * @brief Toggle VCOM to avoid DC bias
 *
 * @details This API will toggle either the EXTCOMIN pin
 *          or the M1 bit in serial comm to toggle VCOM
 *
 * @param driver Pointer to the display driver
 */
static void lpm0xx_vcom_toggle(void *a, void *b, void *c)
{
	struct lpm0xx_data *driver = (struct lpm0xx_data *)a;

	while (1) {
		gpio_pin_toggle(driver->extcomin, DT_INST_GPIO_PIN(0, extcomin_gpios));
		k_msleep(5);
		gpio_pin_toggle(driver->extcomin, DT_INST_GPIO_PIN(0, extcomin_gpios));
		k_msleep(500);
	}
}

/* Driver will handle VCOM toggling */
K_THREAD_STACK_DEFINE(vcom_toggle_stack, 256);
struct k_thread vcom_toggle_thread;

#else /* LPM0XX_VCOM_EXTERNAL */
#define LPM0XX_EXTCOMIN_BIT extcomin_bit
#endif /* LPM0XX_VCOM_EXTERNAL */
#endif /* CONFIG_LPM0XX_VCOM_DRIVER */

/**
 * @brief Display memory contents of the display
 *
 * @details Display memory contents, ie actual image data
 *          During initialization DISP pin will be set high
 *
 * @param dev Pointer to the display device
 */
static int lpm0xx_blanking_off(const struct device *dev)
{
#if DT_INST_NODE_HAS_PROP(0, disp_gpios)
	struct lpm0xx_data *driver = dev->data;

	return gpio_pin_set(driver->disp, DT_INST_GPIO_PIN(0, disp_gpios), 1);
#else
	LOG_ERR("Unsupported");
	return -ENOTSUP;
#endif
}

/**
 * @brief Display becomes completely white
 *
 * @details Displays complete white while but the
 *          memory contents are retained
 *
 * @param dev Pointer to the display device
 */
static int lpm0xx_blanking_on(const struct device *dev)
{
#if DT_INST_NODE_HAS_PROP(0, disp_gpios)
	struct lpm0xx_data *driver = dev->data;

	return gpio_pin_set(driver->disp, DT_INST_GPIO_PIN(0, disp_gpios), 0);
#else
	LOG_ERR("Unsupported");
	return -ENOTSUP;
#endif
}

/**
 * @brief Clear the internal memory of the display
 *
 * @details Clear the display memory and the frame_buf
 *          setting it to all white
 *
 * @param dev Pointer to the display device
 */
static int lpm0xx_clear(const struct device *dev)
{
	struct lpm0xx_data *driver = dev->data;
	int err;
	uint8_t clear_cmd[2] = {LPM0XX_BIT_CLEAR | LPM0XX_EXTCOMIN_BIT, 0};

	tx_buf[0].len = sizeof(uint16_t);
	tx_buf[0].buf = &clear_cmd;
	buf_set.count = 1;

	gpio_pin_set(driver->scs, LPM0XX_SCS_PIN, 1);
	err = spi_write(driver->spi_dev, &driver->spi_config, &buf_set);
	gpio_pin_set(driver->scs, LPM0XX_SCS_PIN, 0);

	return err;
}

/**
 * @brief Send required lines to the LCD
 *
 * @details Update the display by sending num_lines
 *          starting from start_line.
 *
 * @param dev Pointer to the display device
 * @param start_line Starting line number, starts with 1
 *                   corresponds to Y co-ordinate + 1
 * @param num_lines Number of lines ie height to update
 * @param buf  Buffer containing data to write
 */
#if defined(__GNUC__)
	__attribute__((optimize("O3")))
#endif
static int lpm0xx_update_display(const struct device *dev,
								 uint16_t start_line,
								 uint16_t num_lines,
								 uint8_t *buf)
{
	struct lpm0xx_data *driver = dev->data;
	int err;
	uint8_t write_cmd;

	LOG_DBG("Lines %d to %d", start_line, start_line+num_lines-1);

	/* Send write command along with extcomin_bit */
	write_cmd = LPM0XX_BIT_WRITECMD | LPM0XX_EXTCOMIN_BIT;
	extcomin_bit = LPM0XX_EXTCOMIN_BIT ? 0x00 : LPM0XX_BIT_VCOM;
	tx_buf[0].buf = &write_cmd;
	tx_buf[0].len = sizeof(uint8_t);

	/* -1 because frame_buf is referenced from 0 */
	tx_buf[1].buf = &buf[LPM0XX_BYTES_PER_LINE*(start_line-1)];
	/* Send each line to the screen including
	 * the line number and dummy bits
	 */
	tx_buf[1].len = sizeof(uint8_t)*LPM0XX_BYTES_PER_LINE*(num_lines);

	/* Send another trailing 8 bits for the last line
	 * These can be any bits, it does not matter
	 * just reusing the write_cmd buffer
	 */
	tx_buf[2].buf = &write_cmd;
	tx_buf[2].len = sizeof(uint8_t);

	buf_set.count = 3;
	gpio_pin_set(driver->scs, LPM0XX_SCS_PIN, 1);
	err = spi_write(driver->spi_dev, &driver->spi_config, &buf_set);
	gpio_pin_set(driver->scs, LPM0XX_SCS_PIN, 0);

	return err;
}

/**
 * @brief Write to the display at given co-ordinates
 *
 * @details Write buffer to the display.
 *          Buffer width should be a multiple of 8
 *
 *          If CONFIG_LPM0XX_VCOM_DRIVER=y and VCOM toggle is serial(sw)
 *          and buffer is set to NULL, or height/width is 0 then
 *          only VCOM will be toggled
 *
 * @param dev  Pointer to the display device
 * @param x    X co-ordinate
 * @param y    Y co-ordinate
 * @param desc display_buffer_descriptor struct
 * @param buf  Buffer containing data to write
 */
static int lpm0xx_write(const struct device *dev, const uint16_t x,
						const uint16_t y,
						const struct display_buffer_descriptor *desc,
						const void *buf)
{
	LOG_DBG("X: %d, Y: %d, W: %d, H: %d", x, y, desc->width, desc->height);

	if (buf == NULL) {
#if defined(CONFIG_LPM0XX_VCOM_DRIVER) && defined(LPM0XX_VCOM_EXTERNAL)
		LOG_ERR("Display buffer is not available");
		return -EINVAL;
#endif
	}

	if (desc->width != LPM0XX_PANEL_WIDTH) {
		LOG_ERR("Width not equal to %d", LPM0XX_PANEL_WIDTH);
		return -EINVAL;
	}

	if (desc->pitch != desc->width) {
		LOG_ERR("Unsupported mode");
		return -ENOTSUP;
	}

	if ((y + desc->height) > LPM0XX_PANEL_HEIGHT) {
		LOG_ERR("Buffer out of bounds (height)");
		return -EINVAL;
	}

	if ((x + desc->width) > LPM0XX_PANEL_WIDTH) {
		LOG_ERR("Buffer out of bounds (width)");
		return -EINVAL;
	}

	/* Adding 1 since line numbering on the display start with 1 */
	return lpm0xx_update_display(dev, y+1, desc->height, (uint8_t *)buf);
}

static int lpm0xx_read(const struct device *dev, const uint16_t x,
					   const uint16_t y,
					   const struct display_buffer_descriptor *desc,
					   void *buf)
{
	LOG_WRN("not supported");
	return -ENOTSUP;
}

static void *lpm0xx_get_framebuffer(const struct device *dev)
{
	LOG_WRN("not supported");
	return NULL;
}

static int lpm0xx_set_brightness(const struct device *dev,
								 const uint8_t brightness)
{
	LOG_WRN("not supported");
	return -ENOTSUP;
}

static int lpm0xx_set_contrast(const struct device *dev, uint8_t contrast)
{
	LOG_WRN("not supported");
	return -ENOTSUP;
}

/**
 * @brief Get display capabilities
 *
 * @details Get display capabilities
 *
 * @param dev  Pointer to the display device
 * @param caps Pointer to display_capabilities struct
 *             this struct will be populated with the
 *             capabilities
 */
static void lpm0xx_get_capabilities(const struct device *dev,
									struct display_capabilities *caps)
{
	memset(caps, 0, sizeof(struct display_capabilities));
	caps->x_resolution = LPM0XX_PANEL_WIDTH;
	caps->y_resolution = LPM0XX_PANEL_HEIGHT;
	caps->supported_pixel_formats = PIXEL_FORMAT_RGB_111;
	caps->current_pixel_format = PIXEL_FORMAT_RGB_111;
	caps->screen_info = SCREEN_INFO_MONO_MSB_FIRST
						| SCREEN_INFO_ALIGNMENT_RESTRICTED
						| SCREEN_INFO_EXTERNAL_BUFFER;
	/* Minimum update is of a line */
	caps->x_alignment = LPM0XX_PANEL_WIDTH-1;
	caps->y_alignment = 0;
}

static int lpm0xx_set_orientation(const struct device *dev,
								  const enum display_orientation orientation)
{
	LOG_ERR("Unsupported");
	return -ENOTSUP;
}

/**
 * @brief Set pixel format
 *
 * @details Set displays pixel format.
 *          This display is black on white
 *
 * @param dev Pointer to the display device
 * @param pf  Pixel format to set display to
 *            Only PIXEL_FORMAT_MONO01 is
 *            supported
 */
static int lpm0xx_set_pixel_format(const struct device *dev,
								   const enum display_pixel_format pf)
{
	if (pf == PIXEL_FORMAT_RGB_111) {
		return 0;
	}

	LOG_ERR("not supported");
	return -ENOTSUP;
}

/**
 * @brief Initialize the display
 *
 * @details Initialize the display
 *          Configure the SPI interface options
 *          Configure GPIO pins for SCS
 *          Configure DISP and EXTCOMIN pins if defined
 *          Set DISP pin to OUTPUT_HIGH if defined
 *          Clear the display and framebuffer
 *          Write all white pixels to the display
 *          else it shows random data
 *
 * @param dev Pointer to the display device
 */
static int lpm0xx_init(const struct device *dev)
{
	struct lpm0xx_data *driver = dev->data;

	driver->spi_dev = device_get_binding(DT_INST_BUS_LABEL(0));
	if (driver->spi_dev == NULL) {
		LOG_ERR("Could not get SPI device for LPM0XX");
		return -EIO;
	}

	driver->spi_config.frequency = DT_INST_PROP(0, spi_max_frequency);
	driver->spi_config.operation = SPI_OP_MODE_MASTER | SPI_WORD_SET(8);
	driver->spi_config.slave = 0;
	driver->spi_config.operation |= SPI_TRANSFER_MSB;
	driver->spi_config.cs = NULL;

	driver->scs = device_get_binding(LPM0XX_SCS_CNTRL);
	if (driver->scs == NULL) {
		LOG_ERR("Could not get SCS pin port for LPM0XX");
		return -EIO;
	}

	gpio_pin_configure(driver->scs, LPM0XX_SCS_PIN, GPIO_OUTPUT_INACTIVE);

#if DT_INST_NODE_HAS_PROP(0, disp_gpios)
	driver->disp = device_get_binding(DT_INST_GPIO_LABEL(0, disp_gpios));
	if (driver->disp == NULL) {
		LOG_ERR("Could not get DISP pin port for LPM0XX");
		return -EIO;
	}
	LOG_INF("Configuring DISP pin to OUTPUT_HIGH");
	gpio_pin_configure(driver->disp, DT_INST_GPIO_PIN(0, disp_gpios), GPIO_OUTPUT_HIGH);
#endif

#if defined(CONFIG_LPM0XX_VCOM_DRIVER) && defined(LPM0XX_VCOM_EXTERNAL)
	driver->extcomin = device_get_binding(DT_INST_GPIO_LABEL(0, extcomin_gpios));
	if (driver->extcomin == NULL) {
		LOG_ERR("Could not get EXTCOMIN pin port for LPM0XX");
		return -EIO;
	}
	LOG_INF("Configuring EXTCOMIN pin");
	gpio_pin_configure(driver->extcomin, DT_INST_GPIO_PIN(0, extcomin_gpios),
					   GPIO_OUTPUT_LOW);

	/* Start thread for toggling VCOM */
	k_tid_t vcom_toggle_tid = k_thread_create(&vcom_toggle_thread,
							  vcom_toggle_stack,
							  K_THREAD_STACK_SIZEOF(vcom_toggle_stack),
							  lpm0xx_vcom_toggle,
							  driver, NULL, NULL,
							  3, 0, K_NO_WAIT);
	k_thread_name_set(vcom_toggle_tid, "lpm0xx_vcom");
#endif /* CONFIG_LPM0XX_VCOM_DRIVER && LPM0XX_VCOM_EXTERNAL*/

	return lpm0xx_clear(dev);
}

/**
 * @brief Initialize externally supplied buffer
 *
 * @details Initialize the display
 *
 * @param dev Pointer to the display device
 */
static int lpm0xx_init_buffer(const struct device *dev, void *buf)
{
	/* Initialize frame_buf with line numbers so that
	 * we dont spend time later and the actual transfer
	 * is fast
	 */
	for (uint8_t current_line = 1; current_line <= LPM0XX_PANEL_HEIGHT; current_line++) {
		((uint8_t *)buf)[LPM0XX_BYTES_PER_LINE*(current_line-1)] = current_line;
	}
	return 0;
}

static struct lpm0xx_data lpm0xx_driver;

static struct display_driver_api lpm0xx_driver_api = {
	.blanking_on = lpm0xx_blanking_on,
	.blanking_off = lpm0xx_blanking_off,
	.write = lpm0xx_write,
	.read = lpm0xx_read,
	.get_framebuffer = lpm0xx_get_framebuffer,
	.set_brightness = lpm0xx_set_brightness,
	.set_contrast = lpm0xx_set_contrast,
	.get_capabilities = lpm0xx_get_capabilities,
	.set_pixel_format = lpm0xx_set_pixel_format,
	.set_orientation = lpm0xx_set_orientation,
	.init_buffer = lpm0xx_init_buffer,
};

DEVICE_AND_API_INIT(lpm0xx, DT_INST_LABEL(0), lpm0xx_init,
					&lpm0xx_driver, NULL,
					POST_KERNEL, CONFIG_APPLICATION_INIT_PRIORITY,
					&lpm0xx_driver_api);
