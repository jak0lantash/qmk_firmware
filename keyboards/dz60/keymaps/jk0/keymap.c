#include QMK_KEYBOARD_H

#ifndef xxxx
#define xxxx KC_NO
#endif
#ifndef ____
#define ____ KC_TRNS
#endif

#define LAYER_QWERTY 0
#define LAYER_COLEMAK 1
#define LAYER_ACCENTS 2
#define LAYER_FN 3
#define LAYER_LAYERS 4
#define LAYER_TESTER 5
#define LAYER_TESTER_BACK 6

#define FN MO(LAYER_FN) 
#define LAYER LT(LAYER_LAYERS, KC_DEL)
#define TESTER TG(LAYER_TESTER)
#define TST_BK MO(LAYER_TESTER_BACK)
#define QWERTY TO(LAYER_QWERTY)
#define COLEMAK TO(LAYER_COLEMAK)

#define TGL_TESTER TG(LAYER_TESTER)
#define MOL_TST_BK MO(LAYER_TESTER_BACK)

enum custom_keycodes {
	M_GRAVE = SAFE_RANGE,
	M_GRAVE3,
	M_ACIRC,
	M_AGRAV,
	M_AUML,
	M_EGRAV,
	M_EACCU,
	M_EUML,
	M_ECIRC,
	M_AELIG,
	M_CCEDL,
	M_YUML,
	M_UCIRC,
	M_UGRAV,
	M_UUML,
	M_ICIRC,
	M_IUML,
	M_OCIRC,
	M_OUML,
	M_OELIG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[LAYER_QWERTY] = LAYOUT_JK0(
		KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, LAYER,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_ENT,
		KC_BSPC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS,
		KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP), KC_CAPS,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, FN, LT(LAYER_ACCENTS, KC_ENT), KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT
	),
	[LAYER_COLEMAK] = LAYOUT_JK0(
		KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, LAYER,
		KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_LBRC, KC_RBRC, KC_ENT,
		KC_BSPC, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_NUHS,
		KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_CAPS,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, FN, LSFT_T(KC_ENT), KC_RALT, KC_RGUI, KC_APP, KC_RCTL
	),
	[LAYER_ACCENTS] = LAYOUT_JK0(
		M_GRAVE, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		M_GRAVE3, M_ACIRC, M_EGRAV, M_EACCU, M_ECIRC, ____, M_YUML, M_UCIRC, M_ICIRC, M_OCIRC, M_OELIG, ____, ____, ____,
		____, M_AGRAV, M_AUML, M_EUML, ____, ____, M_UGRAV, M_UUML, M_IUML, M_OUML, ____, ____, ____,
		____, ____, ____, M_AELIG, M_CCEDL, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____
	),
	[LAYER_FN] = LAYOUT_JK0(
		M_GRAVE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, xxxx,
		M_GRAVE3, KC_MUTE, KC_VOLD, KC_VOLU, ____, ____, ____, ____, ____, ____, ____, ____, KC_INSERT, ____,
		____, KC_MPLY, KC_MPRV, KC_MNXT, ____, ____, ____, ____, ____, ____, KC_PSCREEN, KC_SCROLLLOCK, KC_PAUSE,
		____, ____, ____, ____, ____, ____, ____, ____, ____, KC_APP, KC_PGUP, KC_HOME, KC_UP, KC_END,
		____, ____, ____, ____, ____, ____, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT
	),
	[LAYER_LAYERS] = LAYOUT_JK0(
		xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, COLEMAK, QWERTY, TESTER, ____,
		xxxx, BL_TOGG, BL_STEP, BL_BRTG, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
		xxxx, RGB_TOG, RGB_MOD, RGB_RMOD, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_G, RGB_M_X, xxxx,
		xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
		RESET, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx
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
			rgblight_setrgb (COLOR_RED_RGB);
			break;
		case LAYER_TESTER:
		case LAYER_TESTER_BACK:
			rgblight_setrgb (COLOR_TURQUOISE_RGB);
			break;
		case LAYER_ACCENTS:
			rgblight_setrgb (COLOR_PINK_RGB);
			break;
	}
	return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) switch (keycode) {
		case M_GRAVE:
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_9) SS_TAP(X_KP_6) SS_UP(X_LALT));
			return false;
			break;
		case M_GRAVE3:
			SEND_STRING(
				SS_DOWN(X_LALT) SS_TAP(X_KP_9) SS_TAP(X_KP_6) SS_UP(X_LALT)
				SS_DOWN(X_LALT) SS_TAP(X_KP_9) SS_TAP(X_KP_6) SS_UP(X_LALT)
				SS_DOWN(X_LALT) SS_TAP(X_KP_9) SS_TAP(X_KP_6) SS_UP(X_LALT)
			);
			return false;
			break;
		case M_AGRAV: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_UP(X_LALT));
			return false;
			break;
		case M_ACIRC: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_6) SS_UP(X_LALT));
			return false;
			break;
		case M_AUML: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_8) SS_UP(X_LALT));
			return false;
			break;
		case M_EGRAV: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_2) SS_UP(X_LALT));
			return false;
			break;
		case M_EACCU: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_3) SS_UP(X_LALT));
			return false;
			break;
		case M_ECIRC: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_4) SS_UP(X_LALT));
			return false;
			break;
		case M_EUML: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_5) SS_UP(X_LALT));
			return false;
			break;
		case M_ICIRC: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_8) SS_UP(X_LALT));
			return false;
			break;
		case M_IUML: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_9) SS_UP(X_LALT));
			return false;
			break;
		case M_OCIRC: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_4) SS_UP(X_LALT));
			return false;
			break;
		case M_OUML: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_6) SS_UP(X_LALT));
			return false;
			break;
		case M_UGRAV: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_9) SS_UP(X_LALT));
			return false;
			break;
		case M_UCIRC: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_1) SS_UP(X_LALT));
			return false;
			break;
		case M_UUML: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_2) SS_UP(X_LALT));
			return false;
			break;
		case M_YUML: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_5) SS_UP(X_LALT));
			return false;
			break;
		case M_CCEDL: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_1) SS_UP(X_LALT));
			return false;
			break;
		case M_AELIG: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_0) SS_UP(X_LALT));
			return false;
			break;
		case M_OELIG: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_6) SS_UP(X_LALT));
			return false;
			break;
	}
	return true;
}
	
