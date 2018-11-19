#include QMK_KEYBOARD_H

#ifndef xxxx
#define xxxx KC_NO
#endif
#ifndef ____
#define ____ KC_TRNS
#endif

#define LAYER_QWERTY 0
#define LAYER_COLEMAK 1
#define LAYER_FN 2
#define LAYER_LAYERS 3
#define LAYER_TESTER 4
#define LAYER_TESTER_BACK 5

#define FN MO(LAYER_FN) 
#define LAYER MO(LAYER_LAYERS)
#define TESTER TG(LAYER_TESTER)
#define TST_BK MO(LAYER_TESTER_BACK)
#define QWERTY TO(LAYER_QWERTY)
#define COLEMAK TO(LAYER_COLEMAK)

#define TGL_TESTER TG(LAYER_TESTER)
#define MOL_TST_BK MO(LAYER_TESTER_BACK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[LAYER_QWERTY] = LAYOUT_JK0(
		KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, LAYER,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_ENT,
		KC_BSPC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS,
		KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_CAPS,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, FN, KC_SPC, KC_RALT, KC_RGUI, KC_APP, KC_RCTL
	),
	[LAYER_COLEMAK] = LAYOUT_JK0(
		KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, LAYER,
		KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_LBRC, KC_RBRC, KC_ENT,
		KC_BSPC, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_NUHS,
		KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_CAPS,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, FN, KC_SPC, KC_RALT, KC_RGUI, KC_APP, KC_RCTL
	),
	[LAYER_FN] = LAYOUT_JK0(
		KC_GRAVE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, RESET,
		____, KC_MUTE, KC_VOLD, KC_VOLU, ____, ____, ____, ____, ____, ____, ____, ____, KC_INSERT, ____,
		____, KC_MPLY, KC_MPRV, KC_MNXT, ____, ____, ____, ____, ____, ____, KC_PSCREEN, KC_SCROLLLOCK, KC_PAUSE,
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, KC_PGUP, KC_HOME, KC_UP, KC_END,
		____, ____, ____, ____, ____, ____, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT
	),
	[LAYER_LAYERS] = LAYOUT_JK0(
		xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, COLEMAK, QWERTY, TESTER, ____,
		xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
		xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
		xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
		xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx
	),
	[LAYER_TESTER] = LAYOUT_JK0(
		xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, TST_BK,
		xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
		xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
		xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
		xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx
	),
	[LAYER_TESTER_BACK] = LAYOUT_JK0(
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		TESTER, ____, ____, ____, ____, ____, ____, ____, ____, ____
	)
};

#define COLOR_BLUE_HSV 240, 255, 255
#define COLOR_BLUE_RGB 0x00, 0x00, 0xFF
#define COLOR_CYAN_RGB 0x00, 0xF4, 0xFF
#define COLOR_GREEN_RGB 0x40, 0xFF, 0x00
#define COLOR_ORANGE_HSV 25, 255, 255
#define COLOR_ORANGE_RGB 0xFF, 0x30, 0x00
#define COLOR_PINK_RGB 0xFF, 0x00, 0xFF
#define COLOR_PURPLE_RGB 0xFF, 0x00, 0x80
#define COLOR_RED_HSV 0, 255, 255
#define COLOR_RED_RGB 0xFF, 0x00, 0x00
#define COLOR_TURQUOISE_RGB 0x00, 0xF4, 0xFF
#define COLOR_YELLOW_RGB 0xFF, 0xFF, 0x00

void matrix_init_user(void) {
	//rgblight_init();
	rgblight_enable();
	rgblight_sethsv (COLOR_ORANGE_HSV);
}

uint32_t layer_state_set_user(uint32_t state) {
	switch (biton32(state)) {
		case LAYER_QWERTY:
			rgblight_sethsv (COLOR_ORANGE_HSV);
			break;
		case LAYER_COLEMAK:
			rgblight_setrgb (COLOR_BLUE_RGB);
			break;
		case LAYER_FN:
			rgblight_setrgb (COLOR_GREEN_RGB);
			break;
		case LAYER_LAYERS:
			rgblight_setrgb (COLOR_YELLOW_RGB);
			break;
		case LAYER_TESTER:
		case LAYER_TESTER_BACK:
			rgblight_setrgb (COLOR_TURQUOISE_RGB);
			break;
	}
	return state;
}
	
