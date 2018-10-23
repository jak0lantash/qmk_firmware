#include "one_hand_keypad.h"

//#define xxxxxxx KC_NO
//#define _______ KC_TRANS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		//_______,	________,	________,	________,	________,	________,	_______,
		KC_SPC, 			LGUI(KC_L),	RESET, 		KC_NO, 		LGUI(KC_P6), 	LCTL(LALT(KC_P0)), 
		LCTL(KC_F4), 	M(0), 		M(1), 		LCTL(KC_C), 	LCTL(KC_V), 	KC_N, 		LSFT(KC_NO), 
		LCTL(KC_F1), 		LCTL(KC_F2), 	LCTL(KC_F3), 	LCTL(KC_F6), 	LCTL(KC_F7), 	LCTL(KC_F8), 
			LGUI(KC_P1),		KC_SPC, 	KC_SPC, 	KC_SPC, 	KC_SPC, 	KC_SPC, 
		KC_SPC, 	KC_SPC, 	KC_SPC, 						KC_NO)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	switch (id) {
		case 0:
			if (record->event.pressed) {
				return MACRO( D(LALT), T(P1), T(P2), T(P4), U(LALT), END );
			}
			break;
		case 1:
			if (record->event.pressed) {
				return MACRO( D(LALT), D(P9), D(P5), U(P9), U(P5), U(LALT), END );
			}
			break;
	}
	return MACRO_NONE;
}
