/*
 * Copyright (c) 2020 Rohit Gujarathi <gujju.rohit@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <lvgl.h>
#include "lvgl_display.h"

void lvgl_flush_cb_3bit(struct _disp_drv_t *disp_drv,
			const lv_area_t *area, lv_color_t *color_p)
{
	struct device *display_dev = (struct device *)disp_drv->user_data;
	uint16_t w = area->x2 - area->x1 + 1;
	uint16_t h = area->y2 - area->y1 + 1;
	struct display_buffer_descriptor desc;

	/* INFO: RATCH: Formula hardcoded for LPM0XX */
	desc.buf_size = ((w >> 1) + 2) * h;
	desc.width = w;
	desc.pitch = w;
	desc.height = h;
	display_write(display_dev, area->x1, area->y1, &desc, (void *) color_p);

	lv_disp_flush_ready(disp_drv);
}

#if defined(__GNUC__)
__attribute__((optimize("O3")))
#endif
void lvgl_set_px_cb_3bit(struct _disp_drv_t *disp_drv,
			 uint8_t *buf, lv_coord_t buf_w, lv_coord_t x, lv_coord_t y,
			 lv_color_t color, lv_opa_t opa)
{
	/* INFO: RATCH: x and y should be absolute co-ordinates and vdb should be 100%
	 * For this _lv_blend_fill is modified to provide absolute co-ordinates
	 */
	/* INFO: RATCH: Calculation of address is hardcoded for LPM0XX */
	uint8_t *buf_xy = (uint8_t *)(buf + ((x >> 1) + 1) +  (y * ((buf_w >> 1) + 2)));
	uint8_t color_3bit = 0;

	/* INFO: RATCH: Add thresholding if absolutely required. It adds about
	 * 6ms to draw time.
	 */
	if (LV_COLOR_GET_R(color)) {
		color_3bit |= 0x08;
	}
	if (LV_COLOR_GET_G(color)) {
		color_3bit |= 0x04;
	}
	if (LV_COLOR_GET_B(color)) {
		color_3bit |= 0x02;
	}

	if (x % 2 == 0) {
		*buf_xy &= 0x0F;
		*buf_xy |= (color_3bit << 4);
	} else {
		*buf_xy &= 0xF0;
		*buf_xy |= color_3bit;
	}
}

void lvgl_rounder_cb_3bit(struct _disp_drv_t *disp_drv,
			  lv_area_t *area)
{
	struct device *display_dev = (struct device *)disp_drv->user_data;
	struct display_capabilities cap;

	display_get_capabilities(display_dev, &cap);

	if (cap.screen_info & SCREEN_INFO_X_ALIGNMENT_WIDTH) {
		area->x1 = 0;
		area->x2 = cap.x_resolution - 1;
	}
}
