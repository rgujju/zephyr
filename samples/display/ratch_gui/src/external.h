
#include <zephyr.h>
struct app_db_entry;
sys_slist_t *get_app_list();
char *get_app_name(struct app_db_entry *app);
uint8_t *get_app_uid(struct app_db_entry *app);
