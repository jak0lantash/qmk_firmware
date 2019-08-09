#include "left_redox.h"

//#define xxxxxxx KC_NO
//#define _______ KC_TRANS

#define LAYER_GAME 0
#define LAYER_MACROS 1
#define LAYER_SETUP 5
#define LAYER_TESTER 3
#define LAYER_TESTER_BACK 4

#define _______ KC_TRNS
#define xxxxxxx KC_NO
#define TOL_GAME TO(LAYER_GAME)
#define LTL_MACROS LT(LAYER_MACROS, KC_PGDN)
#define LTL_SETUP LT(LAYER_SETUP, KC_ESC)
#define MOL_SETUP MO(LAYER_SETUP)
#define TGL_TESTER TG(LAYER_TESTER)
#define MOL_TST_BK MO(LAYER_TESTER_BACK)

enum custom_keycodes {
	M_MACRO1 = SAFE_RANGE,
	M_MACRO2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[LAYER_GAME] = KEYMAP(
		LTL_SETUP,	KC_1,		KC_2,		KC_3,		KC_4,		KC_5,
		KC_TAB,		KC_T,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_BSPC,
		KC_CAPS,	KC_G,		KC_A,		KC_S,		KC_D,		KC_F,		KC_ENT,
		KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_PAUS,	KC_PGUP,
		KC_LCTL,	KC_LGUI,	KC_LALT,	KC_PSCR,		KC_SPC,			KC_SPC,		LTL_MACROS),

	[LAYER_MACROS] = KEYMAP(
		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	M_MACRO1,	M_MACRO2,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,		xxxxxxx,		xxxxxxx,	_______),

	[LAYER_TESTER] = KEYMAP(
		MOL_TST_BK,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,		xxxxxxx,		xxxxxxx,	xxxxxxx),

	[LAYER_TESTER_BACK] = KEYMAP(
		_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,		_______,		_______,	TGL_TESTER),

	[LAYER_SETUP] = KEYMAP(
		_______,	_______,	_______,	_______,	_______,	_______,
		KC_A,		_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	TGL_TESTER,
		RGB_TOG,	RGB_MOD,	_______,	_______,		_______,		_______,	RESET)
		
};

int last_keystroke = 0;
bool layer_not_default = false;

#define COLOR_ORANGE_HSV 25, 255, 255
#define COLOR_BLUE_RGB 0x00, 0x00, 0xFF
#define COLOR_BLUE_HSV 240, 255, 255
#define COLOR_ORANGE_RGB 0xFF, 0x30, 0x00
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

void matrix_scan_user(void) {
	if (layer_not_default && timer_elapsed(last_keystroke) > 60000) {
		layer_not_default = false;
		//rgblight_setrgb (COLOR_BLUE_RGB);
		layer_move(0);
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!record->event.pressed)
		last_keystroke = timer_read();
	if (record->event.pressed) switch (keycode) {
		case M_MACRO1:
			SEND_STRING("macro1");
			return false; break;
		case M_MACRO2:
			SEND_STRING("macro2");
			return false; break;
	}
    return true;
}

uint32_t layer_state_set_user(uint32_t state) {
	switch (biton32(state)) {
		case LAYER_GAME:
			rgblight_sethsv (COLOR_ORANGE_HSV);
			layer_not_default = false;
			//PLAY_SONG(a_planck_sound);
			break;
		case LAYER_SETUP:
			rgblight_setrgb (COLOR_RED_RGB);
			layer_not_default = false;
			break;
		case LAYER_MACROS:
			rgblight_setrgb (COLOR_GREEN_RGB);
			layer_not_default = true;
			//PLAY_SONG(a_colemak_sound);
			break;
		case LAYER_TESTER:
		case LAYER_TESTER_BACK:
			rgblight_setrgb (COLOR_TURQUOISE_RGB);
			layer_not_default = true;
			//PLAY_SONG(a_plover_sound);
			break;
	}
	return state;
}
