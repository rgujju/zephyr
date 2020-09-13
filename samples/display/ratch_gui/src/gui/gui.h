
#include <lvgl.h>

LV_FONT_DECLARE(roboto_condensed_regular_18)
LV_FONT_DECLARE(roboto_condensed_bold_18)

lv_obj_t* pagestack_get_base_obj();
int pagestack_init();
int pagestack_push(void (*setup)(), void (*loop)(), void (*destroy)());

int gui_init();
void gui_loop();
