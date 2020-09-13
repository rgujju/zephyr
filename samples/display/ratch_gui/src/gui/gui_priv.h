#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>
#include <gui/gui.h>

lv_anim_t *lv_obj_add_anim(lv_obj_t *obj, lv_anim_exec_xcb_t exec_cb,
	int32_t start, int32_t end, uint16_t time, lv_anim_ready_cb_t ready_cb,
	lv_anim_path_cb_t path_cb);

void button_pressed(const struct device *dev, struct gpio_callback *cb,
					uint32_t pins);
int config_btns();

#define LV_OBJ_ANIM(obj, attr, path, target, time)\
	do{\
		lv_obj_add_anim(\
						(obj),\
						(lv_anim_exec_xcb_t)lv_obj_set_##attr,\
						lv_obj_get_##attr(obj),\
						(target),\
						(time),\
						NULL,\
						lv_anim_path_##path\
					   );\
	}while(0)


