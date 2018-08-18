#include "kb.h"

// keymap and RGB light per layer from: 
// https://github.com/AGausmann/qmk_firmware/blob/agausmann-v3.x/keyboards/nyquist/keymaps/agausmann/keymap.c

#define LAYER_NUMPAD 0
#define LAYER_NUMBERS 1
#define LAYER_CONSOLE 2
#define LAYER_NAV_CLUSTER 3
#define LAYER_SETUP 4

#define _______ KC_TRNS
#define xxxxxxx KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[LAYER_NUMPAD] = KEYMAP(
		TO(3),  	TO(2), 		TO(1), 		KC_LALT, 
		KC_BSPC, 	KC_PSLS, 	KC_PAST, 	KC_PMNS, 
		KC_P7,  	KC_P8, 		KC_P9, 
		KC_P4,  	KC_P5, 		KC_P6, 		KC_PPLS, 
		KC_P1,  	KC_P2, 		KC_P3, 
		KC_P0,  	KC_PDOT, 			ALT_T(KC_PENT)),

	[LAYER_NUMBERS] = KEYMAP(
		_______, 	_______, 	_______, 	TO(0), 
		_______, 	KC_SLSH, 	KC_ASTR, 	KC_MINS, 
		KC_7, 		KC_8, 		KC_9, 
		KC_4, 		KC_5, 		KC_6, 		KC_PLUS, 
		KC_1,		KC_2, 		KC_3, 
		KC_0, 		KC_DOT, 			KC_ENT),

	[LAYER_CONSOLE] = KEYMAP(
		_______, 	_______,	_______, 	TO(0), 
		KC_BSPC, 	M(3),		M(0), 		M(4), 
		KC_P7, 		KC_P8, 		KC_P9, 
		KC_P4, 		KC_P5, 		KC_P6, 		M(5), 
		KC_P1, 		KC_P2, 		KC_P3, 
		KC_P0, 		M(2), 				KC_LALT),

	[LAYER_NAV_CLUSTER] = KEYMAP(
		MO(4), 		_______,	_______, 	TO(0), 
		KC_INS, 	KC_HOME, 	KC_PGUP, 	KC_SLSH, 
		KC_DEL, 	KC_END, 	KC_PGDN, 
		KC_NO, 		KC_UP, 		KC_NO, 		KC_RGUI, 
		KC_LEFT, 	KC_DOWN, 	KC_RGHT, 
		KC_LCTL, 	KC_LSFT, 			KC_ENT),

	
	[LAYER_SETUP] = KEYMAP(
		xxxxxxx, 	_______, 	xxxxxxx, 	RESET, 
		xxxxxxx, 	xxxxxxx, 	xxxxxxx, 	xxxxxxx, 
		xxxxxxx, 	xxxxxxx, 	xxxxxxx, 
		RGB_HUI, 	RGB_SAI, 	RGB_VAI, 	xxxxxxx, 
		RGB_HUD, 	RGB_SAD, 	RGB_VAD, 
		RGB_TOG, 	RGB_MOD, 			RGB_MODE_PLAIN)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	//keyevent_t event = record->event;

	switch (id) {
		case 0:
			if (record->event.pressed) {
				return MACRO( 
						T(E), T(N), T(ENT), 
						D(LSFT), T(V), T(M), U(LSFT), T(W), T(A), T(R), T(E), T(1), D(LSFT), T(1), U(LSFT), T(ENT),
						T(S), T(T), T(SPC), T(E), T(ENT),
						T(Y), T(ENT),
						D(LSFT), T(I), T(A), U(LSFT), T(M), D(LSFT), T(O), U(LSFT), T(N), D(LSFT), T(T), U(LSFT), T(H), T(E), D(LSFT), T(P), U(LSFT), T(H), T(O), T(N), T(E), D(LSFT), T(W), U(LSFT), T(I), T(T), T(H), D(LSFT), T(T), U(LSFT), T(E), T(C), T(H), D(LSFT), T(S), U(LSFT), T(U), T(P), T(P), T(O), D(R), D(T), U(R), U(T), T(ENT),
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
						T(MINS), T(O), T(SPC), D(LALT), T(P1), T(P2), T(P4), U(LALT),
						T(SPC), T(T), T(C), T(P), T(D), T(U), T(M), T(P), T(MINS), T(U), T(W), T(SPC), T(MINS), T(E), T(N), T(R), T(SPC), T(MINS), T(SPC),
					END );
			}
			break;
		case 4:
			if (record->event.pressed) {
				return MACRO( T(A), T(D), T(M), T(I), T(N), T(I), T(S), T(T), T(R), T(A), T(T), T(O), T(R), D(LSFT), T(2), U(LSFT), T(V), T(S), T(P), T(H), T(E), T(R), T(E), T(DOT), T(L), T(O), T(C), T(A), T(L), T(TAB), D(LSFT), T(V), T(M), U(LSFT), T(W), T(A), T(R), T(E), T(1), D(LSFT), T(1), U(LSFT), T(ENT), END );
			}
			break;
		case 5:
			if (record->event.pressed) {
				return MACRO(
						D(LSFT), T(V), T(M), U(LSFT), T(W), T(A), T(R), T(E), T(1), D(LSFT), T(1), U(LSFT),
					END );
			}
			break;
	}
	return MACRO_NONE;
}

#define COLOR_BLUE_RGB 0x00, 0x00, 0xFF
#define COLOR_BLUE_HSV 240, 255, 255
#define COLOR_ORANGE_RGB 0xFF, 0x30, 0x00
#define COLOR_ORANGE_HSV 37, 255, 255
#define COLOR_CYAN_RGB 0x00, 0xF4, 0xFF
#define COLOR_PINK_RGB 0xFF, 0x00, 0xFF
#define COLOR_GREEN_RGB 0x40, 0xFF, 0x00
#define COLOR_RED_RGB 0xFF, 0x00, 0x00

void matrix_init_user(void) {
	//rgblight_init();
	rgblight_enable();
	rgblight_sethsv (COLOR_ORANGE_HSV);
}

/*uint32_t default_layer_state_set_kb(uint32_t state) {
	//rgblight_sethsv (COLOR_ORANGE_HSV);
}*/

uint32_t layer_state_set_user(uint32_t state) {
	switch (biton32(state)) {
		case LAYER_NUMPAD:
			rgblight_setrgb (COLOR_ORANGE_RGB);
		break;
		case LAYER_NUMBERS:
			rgblight_setrgb (COLOR_CYAN_RGB);
		break;
		case LAYER_CONSOLE:
			rgblight_setrgb (COLOR_GREEN_RGB);
		break;
		case LAYER_NAV_CLUSTER:
			rgblight_setrgb (COLOR_PINK_RGB);
		break;
		case LAYER_SETUP:
			rgblight_setrgb (COLOR_RED_RGB);
		break;
		default: //  for any other layers, or the default layer
			//rgblight_sethsv (COLOR_ORANGE_HSV);
		break;
	}
	return state;
}
