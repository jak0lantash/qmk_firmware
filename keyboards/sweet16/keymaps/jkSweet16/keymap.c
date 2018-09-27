#include "sweet16.h"

enum custom_keycodes {
  UP_URL = SAFE_RANGE
};

#define LAYER_MACROS 0
#define LAYER_SETUP 1

#define _______ KC_TRNS
#define xxxxxxx KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[LAYER_MACROS] = LAYOUT_ortho_4x4(
		KC_P7,		KC_P8,		KC_P9,		KC_PSLS,
		KC_P4,		KC_P5,		KC_P6,		KC_PAST,
		KC_P1,		KC_P2,		KC_P3,		KC_PMNS,
		KC_P0,		LT(1, KC_LGUI), KC_PENT,	KC_PPLS),

	[LAYER_SETUP] = LAYOUT_ortho_4x4(
		_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,
		RGB_TOG,	RGB_MOD,	RGB_RMOD,	RGB_M_P,
		_______,	_______,	_______,	RESET)
};

#define COLOR_BLUE_RGB 0x00, 0x00, 0xFF
#define COLOR_BLUE_HSV 240, 255, 255
#define COLOR_ORANGE_RGB 0xFF, 0x30, 0x00
#define COLOR_ORANGE_HSV 37, 255, 255
#define COLOR_CYAN_RGB 0x00, 0xF4, 0xFF
#define COLOR_PINK_RGB 0xFF, 0x00, 0xFF
#define COLOR_GREEN_RGB 0x40, 0xFF, 0x00
#define COLOR_RED_RGB 0xFF, 0x00, 0x00
#define COLOR_YELLOW_RGB 0xFF, 0xFF, 0x00

void matrix_init_user(void) {
	//rgblight_init();
	rgblight_enable();
	rgblight_sethsv (COLOR_ORANGE_HSV);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UP_URL:
            if (record->event.pressed) {
                SEND_STRING("http://1upkeyboards.com");
            }
            return false;
            break;
    }
    return true;
}

uint32_t layer_state_set_user(uint32_t state) {
	switch (biton32(state)) {
		case LAYER_MACROS:
			if (false) rgblight_setrgb (COLOR_ORANGE_RGB);
			break;
	}
	return state;
}	
