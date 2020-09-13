#include <gui/gui_priv.h>

#include <logging/log.h>
LOG_MODULE_DECLARE(gui);

extern lv_group_t *lvgl_kb_group;
lv_obj_t *page_base_obj;
lv_obj_t *app_base_obj;

struct page_t{
	void (*setup)();
	void (*loop)();
	void (*destroy)();
};

#define MAX_PAGES 5
static struct page_t pages[MAX_PAGES];
static uint8_t curr_page = -1;

// TODO: Need to add custom event handler which will handle other events as well,
// 		like accelerometer, bluetooth events, etc
int pagestack_push(void (*setup)(), void (*loop)(), void (*destroy)())
{
	/* starts with 0 */
	if(curr_page != MAX_PAGES-1){
		curr_page++;
		pages[curr_page].setup = setup;
		pages[curr_page].loop = loop;
		pages[curr_page].destroy = destroy;

		if(pages[curr_page].setup != NULL){
			pages[curr_page].setup();
		}
		LOG_INF("Push page %d", curr_page);

		return 0;
	}else{
		return -1;
	}
}

int pagestack_pop(){
	
	if(curr_page != 0){
		if(pages[curr_page].destroy != NULL){
			pages[curr_page].destroy();
		}
		curr_page--;
		pages[curr_page].setup();
		LOG_INF("Pop page %d", curr_page);
		return 0;
	}else{
		return -1;
	}
}


void page_ev_handler(lv_obj_t *obj, lv_event_t event)
{
	const uint32_t *key = lv_event_get_data();

	if (event == LV_EVENT_KEY) {
		app_base_obj = lv_obj_get_child(obj, NULL);
		switch (*key) {
			case LV_KEY_LEFT:
				printk("quit app\n");
				pagestack_pop();
				break;
			case LV_KEY_UP:
			case LV_KEY_DOWN:
			case LV_KEY_RIGHT:
				lv_event_send(app_base_obj, LV_EVENT_KEY, key);
				break;
		}
	}
}

int pagestack_init()
{
	static lv_style_t page_base_style;

	lv_style_init(&page_base_style);
	// TODO: change 176 to reflect actual display
	lv_style_set_transform_width(&page_base_style, LV_STATE_DEFAULT, 176);
	lv_style_set_transform_height(&page_base_style, LV_STATE_DEFAULT, 176);
	lv_style_set_bg_opa(&page_base_style, LV_STATE_DEFAULT, LV_OPA_COVER);
	lv_style_set_bg_color(&page_base_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);

	page_base_obj = lv_obj_create(lv_scr_act(), NULL);
	lv_group_add_obj(lvgl_kb_group, page_base_obj);
	lv_obj_set_event_cb(page_base_obj, page_ev_handler);
	lv_obj_set_size(page_base_obj, 176, 176);
	lv_obj_add_style(page_base_obj, LV_OBJ_PART_MAIN, &page_base_style);
	lv_obj_align(page_base_obj, NULL, LV_ALIGN_CENTER, 0, 0);

	/* Create an app_base_obj so that app cannot
	 * interact directly with the page_base_obj */
	app_base_obj = lv_obj_create(page_base_obj, NULL);
	lv_obj_set_size(app_base_obj, 176, 176);
	lv_obj_add_style(app_base_obj, LV_OBJ_PART_MAIN, &page_base_style);
	lv_obj_align(app_base_obj, NULL, LV_ALIGN_CENTER, 0, 0);

	return 0;
}

lv_obj_t* pagestack_get_base_obj()
{
	return app_base_obj;
}
