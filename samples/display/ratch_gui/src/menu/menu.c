#include <zephyr.h>
#include <gui/gui.h>
#include <menu/menu.h>
#include <external.h>

static lv_obj_t *menu_base_obj;

void menu_btn_handler(lv_obj_t *app_obj, lv_event_t event)
{
	const uint32_t *key = lv_event_get_data();
	if (event == LV_EVENT_KEY) {
		lv_obj_t *menu_list_obj = lv_obj_get_child(app_obj, NULL);
		lv_obj_t *menu_list_btn = lv_list_get_btn_selected(menu_list_obj);
		lv_obj_t *menu_list_new_btn = menu_list_btn;
		lv_obj_t *menu_list_focus_btn = menu_list_btn;

		switch (*key) {
			case LV_KEY_UP:
				menu_list_new_btn = lv_list_get_prev_btn(menu_list_obj, menu_list_btn);
				menu_list_focus_btn = lv_list_get_prev_btn(menu_list_obj, menu_list_new_btn);
				if (menu_list_focus_btn != NULL) {
					menu_list_focus_btn = lv_list_get_prev_btn(menu_list_obj, menu_list_focus_btn);
				}
				break;
			case LV_KEY_DOWN:
				menu_list_new_btn = lv_list_get_next_btn(menu_list_obj, menu_list_btn);
				menu_list_focus_btn = lv_list_get_next_btn(menu_list_obj, menu_list_new_btn);
				if (menu_list_focus_btn != NULL) {
					menu_list_focus_btn = lv_list_get_next_btn(menu_list_obj, menu_list_focus_btn);
				}
				break;
			case LV_KEY_LEFT:
				printk("Left\n");
				break;
			case LV_KEY_RIGHT:
				printk("sel: %s uid: %d\n", lv_list_get_btn_text(menu_list_btn), *((uint8_t *)lv_obj_get_user_data(menu_list_btn)));
				//LV_OBJ_ANIM(obj, x, linear, -CONFIG_LVGL_HOR_RES_MAX, 30);
				return;
		}

		if (menu_list_new_btn != NULL) {
			lv_list_focus_btn(menu_list_obj, menu_list_new_btn);
			if (menu_list_focus_btn != NULL) {
				lv_page_focus(menu_list_obj, menu_list_focus_btn, LV_ANIM_ON);
			}
		}
	}
}

static void display_menu(void)
{

	/* Menu button style */
	static lv_style_t menu_btn_style;
	lv_style_init(&menu_btn_style);
	
	/* Default style of button */
	lv_style_set_margin_bottom(&menu_btn_style, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_bottom(&menu_btn_style, LV_STATE_DEFAULT, 8);
	lv_style_set_pad_left(&menu_btn_style, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&menu_btn_style, LV_STATE_DEFAULT, 6);
	lv_style_set_pad_right(&menu_btn_style, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_opa(&menu_btn_style, LV_STATE_DEFAULT, LV_OPA_COVER);
	lv_style_set_bg_color(&menu_btn_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
	lv_style_set_text_color(&menu_btn_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	lv_style_set_text_font(&menu_btn_style, LV_STATE_DEFAULT, &roboto_condensed_bold_18);
	
	/* Focused style of button */
	lv_style_set_bg_color(&menu_btn_style, LV_STATE_FOCUSED, LV_COLOR_BLACK);
	lv_style_set_text_color(&menu_btn_style, LV_STATE_FOCUSED, LV_COLOR_WHITE);

	/* Transition of button */
	lv_style_set_transition_time(&menu_btn_style, LV_STATE_DEFAULT, 0);
	lv_style_set_transition_time(&menu_btn_style, LV_STATE_FOCUSED, 0);

	/* Small delay to make transition synced with scroll animation */
	lv_style_set_transition_delay(&menu_btn_style, LV_STATE_DEFAULT, 150);
	lv_style_set_transition_delay(&menu_btn_style, LV_STATE_FOCUSED, 150);
	lv_style_set_transition_prop_1(&menu_btn_style, LV_STATE_DEFAULT, LV_STYLE_BG_COLOR);
	lv_style_set_transition_prop_2(&menu_btn_style, LV_STATE_DEFAULT, LV_STYLE_TEXT_COLOR);

	/* Create a list */
	menu_base_obj = pagestack_get_base_obj();
	lv_obj_t *menu_list_obj = lv_list_create(menu_base_obj, NULL);
	lv_obj_set_event_cb(menu_base_obj, menu_btn_handler);
	lv_obj_set_size(menu_list_obj, CONFIG_LVGL_HOR_RES_MAX, CONFIG_LVGL_VER_RES_MAX);
	lv_obj_align(menu_list_obj, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_list_set_anim_time(menu_list_obj, 300);

	sys_slist_t *app_list = get_app_list(); 
	sys_snode_t *app;
	uint8_t first = 1;
	/* Add buttons to the list */
	lv_obj_t *menu_list_btn;
	SYS_SLIST_FOR_EACH_NODE(app_list, app){
		menu_list_btn = lv_list_add_btn(menu_list_obj, NULL, get_app_name((struct app_db_entry *)app));
		lv_obj_set_user_data(menu_list_btn, get_app_uid((struct app_db_entry *)app));
		lv_obj_add_style(menu_list_btn, LV_OBJ_PART_MAIN, &menu_btn_style);
		if(first == 1){
			lv_list_focus_btn(menu_list_obj, menu_list_btn);
			first = 0;
		}
	}
}


void menu_setup(){
	display_menu();
}
