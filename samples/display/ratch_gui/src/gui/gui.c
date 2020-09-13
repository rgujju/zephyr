
#include <device.h>
#include <drivers/gpio.h>
#include <drivers/display.h>
#include <lvgl.h>
#include <string.h>
#include <zephyr.h>
#include <gui/gui_priv.h>

#include <logging/log.h>
LOG_MODULE_REGISTER(gui, 4);

int gui_init()
{
	const struct device *display_dev;
	display_dev = device_get_binding(CONFIG_LVGL_DISPLAY_DEV_NAME);

	if (display_dev == NULL) {
		LOG_ERR("Display not found.");
		return -1;
	}

	pagestack_init();
	input_init();

	lv_task_handler();
	display_blanking_off(display_dev);
	LOG_INF("GUI initialized");
	return 0;
}

void gui_loop()
{
	while (1) {
		lv_task_handler();
		k_sleep(K_MSEC(10));
	}
}


