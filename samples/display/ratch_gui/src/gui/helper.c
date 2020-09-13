#include <gui/gui_priv.h>

#include <logging/log.h>
LOG_MODULE_DECLARE(gui);

lv_anim_t *lv_obj_add_anim(lv_obj_t *obj, lv_anim_exec_xcb_t exec_cb,
	int32_t start, int32_t end, uint16_t time, lv_anim_ready_cb_t ready_cb,
	lv_anim_path_cb_t path_cb)
{
	static lv_anim_t a;
	lv_anim_path_t path;
	lv_anim_path_init(&path);
	lv_anim_path_set_cb(&path, path_cb);

	lv_anim_init(&a);
	a.var = obj;
	a.start = start;
	a.end = end;
	a.exec_cb = exec_cb;
	a.ready_cb = ready_cb;
	a.path = path;
	a.time = time;
	lv_anim_start(&a);
	return &a;
}

