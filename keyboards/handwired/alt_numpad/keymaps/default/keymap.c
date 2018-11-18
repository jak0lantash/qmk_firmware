#include "alt_numpad.h"

// keymap and RGB light per layer from: 
// https://github.com/AGausmann/qmk_firmware/blob/agausmann-v3.x/keyboards/nyquist/keymaps/agausmann/keymap.c

#define LAYER_NUMPAD 0
#define LAYER_NUMBERS 1
#define LAYER_CONSOLE 2
#define LAYER_NAV_CLUSTER 3
#define LAYER_SETUP 6
#define LAYER_ISO 4
#define LAYER_MACROS 5
#define LAYER_TESTER 7
#define LAYER_TESTER_BACK 8

#define _______ KC_TRNS
#define xxxxxxx KC_NO
#define TOL_NUMPAD TO(LAYER_NUMPAD)
#define TOL_NAV_CLUST TO(LAYER_NAV_CLUSTER)
#define TOL_CONSOLE TO(LAYER_CONSOLE)
#define TOL_NUMBERS TO(LAYER_NUMBERS)
#define TGL_ISO TG(LAYER_ISO)
#define MOL_SETUP MO(LAYER_SETUP)
#define LTL_MACROS LT(LAYER_MACROS, KC_PDOT)
#define TOL_MACROS TO(LAYER_MACROS)
#define ALT_PENT ALT_T(KC_PENT)
#define TGL_TESTER TG(LAYER_TESTER)
#define MOL_TST_BK MO(LAYER_TESTER_BACK)

enum custom_keycodes {
	M_CREDSSP = SAFE_RANGE,
	M_EMEA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[LAYER_NUMPAD] = KEYMAP(
		TOL_NAV_CLUST, 	TOL_MACROS,	TOL_NUMBERS,	TGL_ISO, 
		KC_BSPC, 	KC_PSLS, 	KC_PAST, 	KC_PMNS, 
		KC_P7,  	KC_P8, 		KC_P9, 
		KC_P4,  	KC_P5, 		KC_P6, 		KC_PPLS, 
		KC_P1,  	KC_P2, 		KC_P3, 
		KC_P0,  	LTL_MACROS,			ALT_PENT),

	[LAYER_NUMBERS] = KEYMAP(
		_______, 	_______, 	_______, 	TOL_NUMPAD, 
		_______, 	KC_SLSH, 	KC_ASTR, 	KC_MINS, 
		KC_7, 		KC_8, 		KC_9, 
		KC_4, 		KC_5, 		KC_6, 		KC_PLUS, 
		KC_1,		KC_2, 		KC_3, 
		KC_0, 		KC_DOT, 			KC_ENT),

/*	[LAYER_CONSOLE] = KEYMAP(
		_______, 	_______,	_______, 	TOL_NUMPAD, 
		KC_BSPC, 	M(3),		M(0), 		M(4), 
		KC_P7, 		KC_P8, 		KC_P9, 
		KC_P4, 		KC_P5, 		KC_P6, 		M(5), 
		KC_P1, 		KC_P2, 		KC_P3, 
		KC_P0, 		M(2), 				KC_LALT),
*/

	[LAYER_NAV_CLUSTER] = KEYMAP(
		MOL_SETUP,	_______,	_______, 	TOL_NUMPAD, 
		KC_INS, 	KC_HOME, 	KC_PGUP, 	KC_SLSH, 
		KC_DEL, 	KC_END, 	KC_PGDN, 
		KC_PSCR,	KC_UP, 		KC_SLCK,	KC_RGUI, 
		KC_LEFT, 	KC_DOWN, 	KC_RGHT, 
		KC_LCTL, 	KC_LSFT, 			KC_ENT),
	
	[LAYER_ISO] = KEYMAP(
		_______,	_______,	_______,	_______,
		_______,	M(10),		M(11),		_______,
		_______,	_______,	_______,
		_______,	_______,	_______,	_______,
		_______,	_______,	_______,
		_______,	M(12),				M_EMEA),

	[LAYER_MACROS] = KEYMAP(
		_______,	_______,	_______,	TOL_NUMPAD,
		KC_BSPC,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		M_CREDSSP,	xxxxxxx,	xxxxxxx,
		M(4),		M(0),		M(5),		xxxxxxx,
		M(2),		M(3),		xxxxxxx,
		KC_CALC,	_______,			xxxxxxx),

	[LAYER_SETUP] = KEYMAP(
		_______, 	TGL_TESTER, 	xxxxxxx, 	RESET, 
		xxxxxxx, 	xxxxxxx, 	xxxxxxx, 	xxxxxxx, 
		xxxxxxx, 	xxxxxxx, 	xxxxxxx, 
		RGB_HUI, 	RGB_SAI, 	RGB_VAI, 	xxxxxxx, 
		RGB_HUD, 	RGB_SAD, 	RGB_VAD, 
		RGB_TOG, 	RGB_MOD, 			RGB_MODE_PLAIN),

	[LAYER_TESTER] = KEYMAP(
		MOL_TST_BK,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,			xxxxxxx),

	[LAYER_TESTER_BACK] = KEYMAP(
		_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,
		_______,	_______,	_______,
		_______,	_______,	_______,	_______,
		_______,	_______,	_______,
		_______,	_______,			TGL_TESTER)

	
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	//keyevent_t event = record->event;

	switch (id) {
		case 0:
			if (record->event.pressed) {
				return MACRO( 
					T(E), T(N), W(100), T(ENT), W(100), 
					D(LSFT), T(V), T(M), U(LSFT), T(W), T(A), T(R), T(E), T(1), D(LSFT), T(1), U(LSFT), W(100), T(ENT), W(100),
					T(S), T(T), T(SPC), T(E), W(100), T(ENT), W(100),
					T(Y), W(100), T(ENT), W(100),
					D(LSFT), T(I), T(A), U(LSFT), T(M), D(LSFT), T(O), U(LSFT), T(N), D(LSFT), T(T), U(LSFT), T(H), T(E), D(LSFT), T(P), U(LSFT), T(H), T(O), T(N), T(E), D(LSFT), T(W), U(LSFT), T(I), T(T), T(H), D(LSFT), T(T), U(LSFT), T(E), T(C), T(H), D(LSFT), T(S), U(LSFT), T(U), T(P), T(P), T(O), D(R), D(T), U(R), U(T), W(100), T(ENT),
				END );
			}
			break;
		case 2:
			if (record->event.pressed) {
				return MACRO(
					D(LALT), T(P1), T(P2), T(P4), U(LALT),
				END );
			}
			break;
		case 3:
			if (record->event.pressed) {
				return MACRO(
					T(MINS), T(O), T(SPC), T(MINS), T(SPC), D(LALT), T(P1), T(P2), T(P4), U(LALT),
					T(SPC), T(T), T(C), T(P), T(D), T(U), T(M), T(P), T(MINS), T(U), T(W), T(SPC), T(MINS), T(E), T(N), T(R), T(SPC), T(MINS), T(SPC),
				END );
			}
			break;
		case 4:
			if (record->event.pressed) {
				return MACRO( 
					T(A), T(D), T(M), T(I), T(N), T(I), T(S), T(T), T(R), T(A), T(T), T(O), T(R), D(LALT), T(P6), T(P4), U(LALT), T(V), T(S), T(P), T(H), T(E), T(R), T(E), T(DOT), T(L), T(O), T(C), T(A), T(L), W(100), T(TAB), W(100),
					D(LSFT), T(V), T(M), U(LSFT), T(W), T(A), T(R), T(E), T(1), D(LSFT), T(1), U(LSFT), W(100), T(ENT), W(100),
				END );
			}
			break;
		case 5:
			if (record->event.pressed) {
				return MACRO(
					D(LSFT), T(V), T(M), U(LSFT), T(W), T(A), T(R), T(E), T(1), D(LSFT), T(1), U(LSFT),
				END );
			}
			break;
		case 10:
			if (record->event.pressed) {
				return MACRO(
					D(LALT), T(P8), T(P4), U(LALT),
				END );
			}
			break;
		case 11:
			if (record->event.pressed) {
				return MACRO(
					D(LALT), T(P5), T(P8), U(LALT),
				END );
			}
			break;
		case 12:
			if (record->event.pressed) {
				return MACRO(
					D(LALT), T(P9), T(P0), U(LALT),
				END );
			}
			break;
	}
	return MACRO_NONE;
}

int last_keystroke = 0;
bool layer_not_default = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!record->event.pressed)
		last_keystroke = timer_read();
	if (record->event.pressed) switch (keycode) {
		case M_CREDSSP:
			SEND_STRING("REG ADD HKLM" SS_DOWN(X_LALT) SS_TAP(X_KP_9) SS_TAP(X_KP_2) SS_UP(X_LALT) "Software" SS_DOWN(X_LALT) SS_TAP(X_KP_9) SS_TAP(X_KP_2) SS_UP(X_LALT) "Microsoft" SS_DOWN(X_LALT) SS_TAP(X_KP_9) SS_TAP(X_KP_2) SS_UP(X_LALT) "Windows" SS_DOWN(X_LALT) SS_TAP(X_KP_9) SS_TAP(X_KP_2) SS_UP(X_LALT) "CurrentVersion" SS_DOWN(X_LALT) SS_TAP(X_KP_9) SS_TAP(X_KP_2) SS_UP(X_LALT) "Policies" SS_DOWN(X_LALT) SS_TAP(X_KP_9) SS_TAP(X_KP_2) SS_UP(X_LALT) "System" SS_DOWN(X_LALT) SS_TAP(X_KP_9) SS_TAP(X_KP_2) SS_UP(X_LALT) "CredSSP" SS_DOWN(X_LALT) SS_TAP(X_KP_9) SS_TAP(X_KP_2) SS_UP(X_LALT) "Parameters" SS_DOWN(X_LALT) SS_TAP(X_KP_9) SS_TAP(X_KP_2) SS_UP(X_LALT) " " SS_DOWN(X_LALT) SS_TAP(X_KP_4) SS_TAP(X_KP_7) SS_UP(X_LALT) "v AllowEncryptionOracle " SS_DOWN(X_LALT) SS_TAP(X_KP_4) SS_TAP(X_KP_7) SS_UP(X_LALT) "t REG_DWORD " SS_DOWN(X_LALT) SS_TAP(X_KP_4) SS_TAP(X_KP_7) SS_UP(X_LALT) "d 2");
			return false;
			break;
		case M_EMEA:
			SEND_STRING("EMEA");
			return false;
			break;
	}
	return true;
}


#define COLOR_BLUE_RGB 0x00, 0x00, 0xFF
#define COLOR_BLUE_HSV 240, 255, 255
#define COLOR_ORANGE_RGB 0xFF, 0x30, 0x00
#define COLOR_ORANGE_HSV 25, 255, 255
#define COLOR_TURQUOISE_RGB 0x00, 0xF4, 0xFF
#define COLOR_PINK_RGB 0xFF, 0x00, 0xFF
#define COLOR_GREEN_RGB 0x40, 0xFF, 0x00
#define COLOR_RED_RGB 0xFF, 0x00, 0x00
#define COLOR_YELLOW_RGB 0xFF, 0xFF, 0x00
#define COLOR_PURPLE_RGB 0xFF, 0x00, 0x80

void matrix_init_user(void) {
	//rgblight_init();
	rgblight_enable();
	rgblight_sethsv (COLOR_ORANGE_HSV);
}

/*uint32_t default_layer_state_set_kb(uint32_t state) {
	//rgblight_sethsv (COLOR_ORANGE_HSV);
}*/

void matrix_scan_user(void) {
	if (layer_not_default && timer_elapsed(last_keystroke) > 60000) {
		layer_not_default = false;
		rgblight_setrgb (COLOR_BLUE_RGB);
		layer_move(0);
	}
}

uint32_t layer_state_set_user(uint32_t state) {
	switch (biton32(state)) {
		case LAYER_NUMPAD:
			rgblight_sethsv (COLOR_ORANGE_HSV);
			layer_not_default = false;
			break;
		case LAYER_NUMBERS:
			rgblight_setrgb (COLOR_GREEN_RGB);
			layer_not_default = true;
			break;
/*		case LAYER_CONSOLE:
			rgblight_setrgb (COLOR_PINK_RGB);
			layer_not_default = true;
			break;
*/		case LAYER_NAV_CLUSTER:
			rgblight_setrgb (COLOR_PINK_RGB);
			layer_not_default = true;
			break;
		case LAYER_SETUP:
			rgblight_setrgb (COLOR_RED_RGB);
			layer_not_default = true;
			break;
		case LAYER_ISO:
			rgblight_setrgb (COLOR_YELLOW_RGB);
			layer_not_default = true;
			break;
		case LAYER_MACROS:
			rgblight_setrgb (COLOR_BLUE_RGB);
			layer_not_default = false;
			break;
		case LAYER_TESTER:
		case LAYER_TESTER_BACK:
			rgblight_setrgb (COLOR_TURQUOISE_RGB);
			layer_not_default = false;
			break;
		default: //  for any other layers, or the default layer
			//rgblight_sethsv (COLOR_ORANGE_HSV);
		break;
	}
	return state;
}
