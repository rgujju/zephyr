
#include <gui/gui_priv.h>

#include <logging/log.h>
LOG_MODULE_DECLARE(gui, 4);

extern lv_obj_t *page_base_obj;

#define KEY_DOWN_NODE		DT_ALIAS(sw0)
#define KEY_UP_NODE			DT_ALIAS(sw1)
#define KEY_LEFT_NODE		DT_ALIAS(sw2)
#define KEY_RIGHT_NODE		DT_ALIAS(sw3)

#if DT_NODE_HAS_STATUS(KEY_UP_NODE, okay)
#define KEY_UP_GPIO_LABEL		DT_GPIO_LABEL(KEY_UP_NODE, gpios)
#define KEY_UP_GPIO_PIN			DT_GPIO_PIN(KEY_UP_NODE, gpios)
#define KEY_UP_GPIO_FLAGS		(GPIO_INPUT | DT_GPIO_FLAGS(KEY_UP_NODE, gpios))
#else
//#error "Unsupported board: sw1 devicetree alias is not defined"
#define KEY_UP_GPIO_LABEL		"GPIO_0"
#define KEY_UP_GPIO_PIN			11
#define KEY_UP_GPIO_FLAGS		(GPIO_INPUT)
#endif

#if DT_NODE_HAS_STATUS(KEY_DOWN_NODE, okay)
#define KEY_DOWN_GPIO_LABEL		DT_GPIO_LABEL(KEY_DOWN_NODE, gpios)
#define KEY_DOWN_GPIO_PIN		DT_GPIO_PIN(KEY_DOWN_NODE, gpios)
#define KEY_DOWN_GPIO_FLAGS		(GPIO_INPUT | DT_GPIO_FLAGS(KEY_DOWN_NODE, gpios))
#else
//#error "Unsupported board: sw0 devicetree alias is not defined"
#define KEY_DOWN_GPIO_LABEL		"GPIO_0"
#define KEY_DOWN_GPIO_PIN		12
#define KEY_DOWN_GPIO_FLAGS		(GPIO_INPUT)
#endif

#if DT_NODE_HAS_STATUS(KEY_LEFT_NODE, okay)
#define KEY_LEFT_GPIO_LABEL		DT_GPIO_LABEL(KEY_LEFT_NODE, gpios)
#define KEY_LEFT_GPIO_PIN		DT_GPIO_PIN(KEY_LEFT_NODE, gpios)
#define KEY_LEFT_GPIO_FLAGS		(GPIO_INPUT | DT_GPIO_FLAGS(KEY_LEFT_NODE, gpios))
#else
//#error "Unsupported board: sw0 devicetree alias is not defined"
#define KEY_LEFT_GPIO_LABEL		"GPIO_0"
#define KEY_LEFT_GPIO_PIN		12
#define KEY_LEFT_GPIO_FLAGS		(GPIO_INPUT)
#endif

#if DT_NODE_HAS_STATUS(KEY_RIGHT_NODE, okay)
#define KEY_RIGHT_GPIO_LABEL	DT_GPIO_LABEL(KEY_RIGHT_NODE, gpios)
#define KEY_RIGHT_GPIO_PIN		DT_GPIO_PIN(KEY_RIGHT_NODE, gpios)
#define KEY_RIGHT_GPIO_FLAGS	(GPIO_INPUT | DT_GPIO_FLAGS(KEY_RIGHT_NODE, gpios))
#else
//#error "Unsupported board: sw0 devicetree alias is not defined"
#define KEY_RIGHT_GPIO_LABEL	"GPIO_0"
#define KEY_RIGHT_GPIO_PIN		12
#define KEY_RIGHT_GPIO_FLAGS	(GPIO_INPUT)
#endif


static const struct device *button[4]; /* TODO: 4 variables shoudnt be requried if debouncing and interrupt works correctly */
static struct gpio_callback button_cb_data[4];

struct input_event {
	lv_event_t event;
	uint32_t data;
};

K_MSGQ_DEFINE(btn_msgq, sizeof(struct input_event), 5, 4);

void btn_handler(void *a, void *b, void *c)
{
	struct input_event input_ev;

	while (1) {
		k_msgq_get(&btn_msgq, &input_ev, K_FOREVER);
		lv_event_send(page_base_obj, input_ev.event, &input_ev.data);
	}
}

K_THREAD_DEFINE(btn_handler_tid, 1024,
				btn_handler, NULL, NULL, NULL,
				3, 0, 0);
/*
void btn_handler_sim(void *a, void *b, void *c)
{
	struct input_event input_ev;
	input_ev.data = LV_KEY_DOWN;
	input_ev.event = LV_EVENT_KEY;
	
	int8_t count = 0;
	int8_t dir = 1;
	while (1) {
		count+=dir;
		if (count == 7 || count < 0) {
			input_ev.data = input_ev.data == LV_KEY_DOWN ? LV_KEY_UP : LV_KEY_DOWN;
			dir = -dir;
		}
		k_msgq_put(&btn_msgq, &input_ev, K_NO_WAIT);
		k_sleep(K_MSEC(1000));
	}

}
K_THREAD_DEFINE(btn_handler_sim_tid, 512,
				btn_handler_sim, NULL, NULL, NULL,
				3, 0, 0);
*/

void btn_pressed(const struct device *dev, struct gpio_callback *cb,
				 uint32_t pins)
{
	struct input_event input_ev;

	input_ev.event = LV_EVENT_KEY;

	/* TODO: Do proper GPIO debouncing
	 * This loop is added for delay
	 * */
	for (uint32_t i = 0; i<90000; i++) {
		gpio_pin_get(button[0], KEY_UP_GPIO_PIN);
	}

	if (pins & BIT(KEY_UP_GPIO_PIN)) {
		/* TODO: Remove gpio_pin_get once debouncing works */
		if (gpio_pin_get(button[0], KEY_UP_GPIO_PIN)) {
			input_ev.data = LV_KEY_UP;
		}
	} else if (pins & BIT(KEY_DOWN_GPIO_PIN)) {
		if (gpio_pin_get(button[1], KEY_DOWN_GPIO_PIN)) {
			input_ev.data = LV_KEY_DOWN;
		}
	} else if (pins & BIT(KEY_LEFT_GPIO_PIN)) {
		if (gpio_pin_get(button[2], KEY_LEFT_GPIO_PIN)) {
			input_ev.data = LV_KEY_LEFT;
		}
	} else if (pins & BIT(KEY_RIGHT_GPIO_PIN)) {
		if (gpio_pin_get(button[3], KEY_RIGHT_GPIO_PIN)) {
			input_ev.data = LV_KEY_RIGHT;
		}
	}

	k_msgq_put(&btn_msgq, &input_ev, K_NO_WAIT);
}

int btn_config(const struct device *btn, struct gpio_callback *cb_data, const char *label, gpio_pin_t pin, gpio_flags_t flags)
{
	int ret;

	if (btn == NULL) {
		LOG_ERR("Error: didn't find %s device\n", label);
		return -EIO;
	}

	ret = gpio_pin_configure(btn, pin, flags | GPIO_INT_DEBOUNCE);
	ret |= gpio_pin_interrupt_configure(btn,
										pin,
										GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		LOG_ERR("Error %d: failed to configure %s pin %d",
				ret, label, pin);
		return ret;
	}

	gpio_init_callback(cb_data, btn_pressed, BIT(pin));
	gpio_add_callback(btn, cb_data);
	LOG_DBG("Set up button at %s pin %d", label, pin);

	return 0;
}

int input_init()
{
	int ret;

	button[0] = device_get_binding(KEY_UP_GPIO_LABEL);
	ret = btn_config(button[0], &button_cb_data[0], KEY_UP_GPIO_LABEL, KEY_UP_GPIO_PIN, KEY_UP_GPIO_FLAGS);

	button[1] = device_get_binding(KEY_DOWN_GPIO_LABEL);
	ret |= btn_config(button[1], &button_cb_data[1], KEY_DOWN_GPIO_LABEL, KEY_DOWN_GPIO_PIN, KEY_DOWN_GPIO_FLAGS);

	button[2] = device_get_binding(KEY_LEFT_GPIO_LABEL);
	ret |= btn_config(button[2], &button_cb_data[2], KEY_LEFT_GPIO_LABEL, KEY_LEFT_GPIO_PIN, KEY_LEFT_GPIO_FLAGS);

	button[3] = device_get_binding(KEY_RIGHT_GPIO_LABEL);
	ret |= btn_config(button[3], &button_cb_data[3], KEY_RIGHT_GPIO_LABEL, KEY_RIGHT_GPIO_PIN, KEY_RIGHT_GPIO_FLAGS);

	return ret;
}


