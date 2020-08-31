/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "xd75.h"

// Layer shorthand
#define xxxxxxx KC_NO

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
#define ACCENTS LT(LAYER_ACCENTS, KC_ENT)

#define TGL_TESTER TG(LAYER_TESTER)
#define MOL_TST_BK MO(LAYER_TESTER_BACK)

enum custom_keycodes {
	M_GRAVE = SAFE_RANGE,
	M_GRAVE3,
	M_000,
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
	M_OELIG,
	M_ATILD,
	M_EURO,
	M_SNIP,
	M_DIGITS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1!     | 2"     | 3£     | 4$     | 5%     | =+     | ~#     | -_     | 6^     | 7&     | 8*     | 9(     | 0)     | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [{     | PageUp | ]}     | Y      | U      | I      | O      | P      | BSPACE |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | BSPACE | A      | S      | D      | F      | G      | ?????? | PageDn | ?????? | H      | J      | K      | L      | ;:     | '@     |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | \|     | Z      | X      | C      | V      | HOME   | UP     | END    | B      | N      | M      | ,<     | .>     | /?     |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | FN     | SPACE           | LEFT   | DOWN   | RIGHT  | ENTER           | ALT+GR | CAPS   | LEFT   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [LAYER_QWERTY] = { /* QWERTY */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_EQL,  KC_NUHS, KC_MINS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL   },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_PGUP, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC  },
  { KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    M_SNIP,  KC_PGDN, M_DIGITS,KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT  },
  { KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_HOME, KC_UP,   KC_END,  KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH  },
  { KC_LCTL, KC_LGUI, KC_LALT, FN,      KC_SPC,  xxxxxxx, KC_LEFT, KC_DOWN, KC_RGHT, ACCENTS, xxxxxxx, KC_RALT, KC_CAPS, KC_LEFT, KC_RGHT  },
 },

 [LAYER_COLEMAK] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    _______, _______, _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______  },
  { _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    _______, _______, _______, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    _______  },
  { _______, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, _______, KC_K,    KC_M,    _______, _______, _______  },
  { _______, _______, _______, _______, _______, xxxxxxx, _______, _______, _______, _______, xxxxxxx, _______, _______, _______, _______  },
 },

/* ACCENTS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | ```    | â      | è      | é      | ê      |        |        |        |        | ÿ      | û      | î      | ô      | œ      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | à      | ä      | ë      |        |        |        |        |        | ù      | ü      | ï      | ö      |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | æ      | ã      |        | ç      |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |                 |        |        |        |                 |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [LAYER_ACCENTS] = {
  { M_GRAVE, _______, _______, M_EURO,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { M_GRAVE3,M_ACIRC, M_EGRAV, M_EACCU, M_ECIRC, _______, _______, _______, _______, M_YUML,  M_UCIRC, M_ICIRC, M_OCIRC, M_OELIG, _______  },
  { _______, M_AGRAV, M_AUML,  M_EUML,  _______, _______, _______, _______, _______, M_UGRAV, M_UUML,  M_IUML,  M_OUML,  _______, _______  },
  { _______, M_AELIG, M_ATILD, _______, M_CCEDL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, xxxxxxx, _______, _______, _______, _______, xxxxxxx, _______, _______, _______, _______  },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | F1     | F2     | F3     | F4     | F5     | NUM LK | P/     | P*     | F6     | F7     | F8     | F9     | F10    | F11    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | ```    | MUTE   | VOL DN | VOL UP | RGB HD | RGB HI | P7     | P8     | P9     | -      | COLEMAK| QWERTY | TESTER | INSERT | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | DEL    | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      | RESET  | PRNT SC| SCROLLK| PAUSE  |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | RGB TOG| RGB MOD| RGB RMO| RGB VD | RGB VI | P1     | P2     | P3     | PENT   | MENU   | PG UP  | HOME   | UP     | END    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | FN     | BACKLIGHT STEP  | P0     | 000    | P.     |                 | PG DOWN| LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [LAYER_FN] = { /* FUNCTION */
  { M_GRAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11   },
  { M_GRAVE3,KC_MUTE, KC_VOLD, KC_VOLU, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, COLEMAK, QWERTY,  TESTER,  KC_INS,  KC_F12   },
  { KC_DEL,  KC_MPLY, KC_MPRV, KC_MNXT, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, RESET,   KC_PSCR, KC_SLCK, KC_PAUSE,xxxxxxx  },
  { _______, RGB_TOG, RGB_MOD, RGB_RMOD,RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_APP,  KC_PGUP, KC_HOME, KC_UP,   KC_END   },
  { _______, _______, _______, FN,      BL_STEP, xxxxxxx, KC_P0,   M_000,   KC_PDOT, _______, xxxxxxx, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT  },
 },

 [LAYER_TESTER] = {
  { xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx  },
  { xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx  },
  { xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx  },
  { xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx  },
  { xxxxxxx, xxxxxxx, xxxxxxx, TST_BK,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx  },
 },

 [LAYER_TESTER_BACK] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QWERTY,  _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 }
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
		case M_000:
			SEND_STRING(SS_TAP(X_KP_0) SS_TAP(X_KP_0) SS_TAP(X_KP_0));
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
		case M_ATILD: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_7) SS_UP(X_LALT));
			return false;
			break;
		case M_EURO: 
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_8) SS_UP(X_LALT));
			return false;
			break;
		case M_SNIP:
			SEND_STRING("[...]");
			return false;
			break;
		case M_DIGITS:
			SEND_STRING("[0-9]");
			return false;
			break;
	}
	return true;
}

/*const uint16_t PROGMEM fn_actions[] = {

};*/

/*const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};*/

void led_set_user(uint8_t usb_led) {
	if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
		capslock_led_on();
	} else {
		capslock_led_off();
	}
	
	if (usb_led & (1<<USB_LED_NUM_LOCK)) {
		gp100_led_off();
	} else {
		gp100_led_on();
	}
}
