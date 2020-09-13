/*
 * Copyright (c) 2018 Jan Van Winkel <jan.van_winkel@dxplore.eu>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <device.h>
#include <drivers/display.h>
#include <lvgl.h>
#include <stdio.h>
#include <string.h>
#include <zephyr.h>

#define LOG_LEVEL CONFIG_LOG_DEFAULT_LEVEL
#include <logging/log.h>
LOG_MODULE_REGISTER(app);
static lv_style_t style;
lv_obj_t * obj;

void lv_ex_style_1(void)
{
    
    lv_style_init(&style);
    lv_style_set_radius(&style, LV_STATE_DEFAULT, 5);

    lv_style_set_transform_width(&style, LV_STATE_DEFAULT,128);
    lv_style_set_transform_height(&style, LV_STATE_DEFAULT,128);
    lv_style_set_bg_opa(&style, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    /*Create an object with the new style*/
    obj = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_add_style(obj, LV_OBJ_PART_MAIN, &style);
    lv_obj_align(obj, NULL, LV_ALIGN_CENTER, 0, 0);
}


void main(void)
{
	uint32_t count = 0;
	struct device *display_dev;
	display_dev = device_get_binding(CONFIG_LVGL_DISPLAY_DEV_NAME);

	if (display_dev == NULL) {
		LOG_ERR("device not found.  Aborting test.");
		return;
	}
	
	lv_ex_style_1();
	lv_task_handler();
	display_blanking_off(display_dev);

	uint8_t toggle, toggle_old = 0;
	while (1) {
		if ((count % 100) == 0U) {
			lv_obj_remove_style(obj, LV_OBJ_PART_MAIN, &style); 
			if(toggle == 0){
				toggle = 1;
				lv_style_set_bg_color(&style, LV_STATE_DEFAULT, LV_COLOR_RED);
			}else{
				lv_style_set_bg_color(&style, LV_STATE_DEFAULT, LV_COLOR_YELLOW);
				toggle = 0;
			}
			lv_obj_add_style(obj, LV_OBJ_PART_MAIN, &style);
			printk("toggle %d\n", toggle);
		}
		uint32_t start = k_cycle_get_32(); 
		lv_task_handler();
		uint32_t wr_time = k_ticks_to_ms_ceil32(k_cycle_get_32()-start);
		if(toggle_old != toggle){
			toggle_old = toggle;
			printk("Full Time %d ms\n", k_ticks_to_ms_ceil32(k_cycle_get_32()-start));
		}
		k_sleep(K_MSEC(10));
		++count;
	}
}
