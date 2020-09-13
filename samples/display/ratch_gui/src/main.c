/*
 * Copyright (c) 2020 Rohit Gujarathi <gujju.rohit@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <gui/gui.h>
#include <menu/menu.h>

#include <logging/log.h>
LOG_MODULE_REGISTER(app, 4);


//////////////////
// External items
/////////////////
#define APP_NAME_SIZE 20
struct app_db_entry {
	sys_snode_t node;
	char app_name[APP_NAME_SIZE];
	uint8_t uid;
	//tinf_t *tinf_base;
};

/** List of apps of struct app_db_entry */
static sys_slist_t app_list;

char *get_app_name(struct app_db_entry *app){
	return app->app_name;
}

uint8_t *get_app_uid(struct app_db_entry *app){
	return &app->uid;
}

sys_slist_t *get_app_list(){
	return &app_list;
}

char *apps[] = {"Settings",
				"Music",
				"Notifications",
				"Weather",
				"Reminders",
				"Battery",
				"Navigation",
				"About",

};

void init_external(){
	sys_slist_init(&app_list);
	
	for(uint8_t i = 0; i < sizeof(apps)/sizeof(char *); i++){
		struct app_db_entry *app = k_malloc(sizeof(struct app_db_entry));
		memcpy(app->app_name, apps[i], APP_NAME_SIZE);
		app->uid = i;
		sys_slist_append(&app_list, &app->node);
	}
}


void list_apps(void)
{
	sys_snode_t *node;
	ARG_UNUSED(node);
	struct app_db_entry *app;

	SYS_SLIST_FOR_EACH_CONTAINER(&app_list, app, node) {
		printk("app: %s\n", log_strdup(app->app_name));
		//LOG_INF("app");
	}
}

////////////////


void main(void)
{
	init_external();

	if(gui_init() < 0){
		return;
	}
	pagestack_push(&menu_setup, NULL, NULL);

	gui_loop();
}
