/*
 * Copyright (c) 2018 PHYTEC Messtechnik GmbH
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <display/cfb.h>
#include <stdio.h>
#include <string.h>

#include <drivers/gpio.h>

#if defined(CONFIG_SSD16XX)
	#define DISPLAY_DRIVER          "SSD16XX"
#endif

#if defined(CONFIG_SSD1306)
	#define DISPLAY_DRIVER          "SSD1306"
#endif

#if defined(CONFIG_LS0XX)
	#define DISPLAY_DRIVER "LS0XX"
#endif

#include <drivers/display.h>
#include <init.h>
#include <drivers/gpio.h>
#include <drivers/spi.h>

struct display_buffer_descriptor desc;

#define HEIGHT  CONFIG_LVGL_VER_RES_MAX
#define WIDTH   CONFIG_LVGL_HOR_RES_MAX

uint8_t img_buf[HEIGHT * WIDTH / 8] = { 0xFF };

void main(void)
{
	const struct device *dev;

	dev = device_get_binding(DISPLAY_DRIVER);

	if (display_set_pixel_format(dev, PIXEL_FORMAT_MONO01) != 0) {
		printk("Failed to set required pixel format\n");
		return;
	}

	printk("initialized %s\n", DISPLAY_DRIVER);
	uint32_t count = 0;
	uint8_t toggle_screen = 0x00;

	desc.height = HEIGHT;
	desc.width = WIDTH;
	desc.pitch = desc.width;
	desc.buf_size = HEIGHT * WIDTH / 8;

	if (display_blanking_off(dev) < 0) {
		printk("NOT Supported\n");
	}

	while (1) {
		memset(img_buf, toggle_screen, HEIGHT * WIDTH / 8);

		if ((count % 30) == 0U) {
			count = 0;
			toggle_screen = toggle_screen ? 0x00 : 0xFF;

			// uint32_t start = k_cycle_get_32();
			display_write(dev, 0, 0, &desc, img_buf);
			// printk("Full Time %d us\n", k_ticks_to_us_ceil32(k_cycle_get_32()-start));
		}

		++count;
		k_msleep(100);
	}
}
