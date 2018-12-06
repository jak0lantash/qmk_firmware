#include "sweet16.h"

#define LAYER_NUMPAD 0
#define LAYER_MACROS 1
#define LAYER_SETUP 2
#define LAYER_BLANK 3
#define LAYER_BLANK_BACK 4

enum custom_keycodes {
	M_CDSR = SAFE_RANGE,
	M_SCOPY,
	M_OUTLOOK,
	M_MREMOTENG,
	M_NOTEPAD,
	M_VCENTER,
	M_STE,
	M_VMWARE,
	M_HJVMWARE,
	M_HJ,
	M_JHGMAIL,
	M_WAITCST,
	M_REPLACE,
	M_LOCK,
	M_WMP,
	M_TCPDUMP
};

#define _______ KC_TRNS
#define xxxxxxx KC_NO

#define LT_SETUP LT(LAYER_SETUP, KC_BSPC)
#define MO_SETUP MO(LAYER_SETUP)
#define TG_TESTER TG(LAYER_BLANK)
#define MO_BACK MO(LAYER_BLANK_BACK)
#define TG_NUMPAD TG(LAYER_NUMPAD)
#define TG_MACROS TG(LAYER_MACROS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[LAYER_NUMPAD] = LAYOUT_ortho_4x4(
		LT_SETUP,	KC_PSLS,	KC_PAST,	KC_PMNS,
		KC_KP_7,	KC_KP_8,	KC_KP_9,	KC_PPLS,
		KC_KP_4,	KC_KP_5,	KC_KP_6,	KC_PENT,
		KC_KP_1,	KC_KP_2,	KC_KP_3,	KC_KP_0),

	[LAYER_MACROS] = LAYOUT_ortho_4x4(
		MO_SETUP,	M_TCPDUMP,	M_WMP,		M_REPLACE,
		M_HJVMWARE,	M_HJ,		M_JHGMAIL,	M_WAITCST,
		M_VCENTER,	M_STE,		M_VMWARE,	M_CDSR,
		M_OUTLOOK,	M_MREMOTENG,	M_NOTEPAD,	M_SCOPY),

	[LAYER_SETUP] = LAYOUT_ortho_4x4(
		_______,	TG_TESTER,	TG_NUMPAD,	TG_MACROS,
		RGB_HUI,	RGB_SAI,	RGB_VAI,	RGB_M_SW,
		RGB_HUD,	RGB_SAD,	RGB_VAD,	RGB_M_P,
		RGB_TOG,	RGB_MOD,	RGB_RMOD,	RESET),

	[LAYER_BLANK] = LAYOUT_ortho_4x4(
		MO_BACK,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx),

	[LAYER_BLANK_BACK] = LAYOUT_ortho_4x4(
		_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,
		_______,	_______,	_______,	TG_TESTER)
};

#define COLOR_BLUE_RGB 0x00, 0x00, 0xFF
#define COLOR_BLUE_HSV 240, 255, 255
#define COLOR_ORANGE_RGB 0xFF, 0x30, 0x00
#define COLOR_ORANGE_HSV 25, 255, 255
#define COLOR_CYAN_RGB 0x00, 0xF4, 0xFF
#define COLOR_PINK_RGB 0xFF, 0x00, 0xFF
#define COLOR_GREEN_RGB 0x40, 0xFF, 0x00
#define COLOR_RED_RGB 0xFF, 0x00, 0x00
#define COLOR_RED_HSV 0, 255, 255
#define COLOR_YELLOW_RGB 0xFF, 0xFF, 0x00

//bool first_boot = true;
//int first_boot_time = 0;

void matrix_init_user(void) {
	//rgblight_init();
	rgblight_enable();
	rgblight_sethsv (COLOR_ORANGE_HSV);
	//rgblight_sethsv (COLOR_RED_HSV);
	//first_boot_time = timer_read();
}

/*void matrix_scan_user(void) {
	if (first_boot && timer_elapsed(first_boot_time) > 1000) {
		first_boot = false;
		rgblight_sethsv (COLOR_ORANGE_HSV);
	}
}*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) switch (keycode) {
		case M_OUTLOOK:
			SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_KP_1) SS_UP(X_LGUI));
			return false;
			break;
		case M_MREMOTENG:
			SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_KP_2) SS_UP(X_LGUI));
			return false;
			break;
		case M_NOTEPAD:
			SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_KP_3) SS_UP(X_LGUI));
			return false;
			break;
		case M_SCOPY:
			SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_C) SS_UP(X_LALT) SS_UP(X_LCTRL));
			return false;
			break;
		case M_VCENTER:
			//SEND_STRING("administrator@vsphere.local" SS_TAP(X_TAB) "VMware1!" SS_TAP(X_ENTER));
			SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F1) SS_UP(X_LCTRL));
			return false;
			break;
		case M_STE:
			//SEND_STRING("IAmOnThePhoneWithTechSupport" SS_TAP(X_ENTER));
			SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F2) SS_UP(X_LCTRL));
			return false;
			break;
		case M_VMWARE:
			//SEND_STRING("VMware1!");
			SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F3) SS_UP(X_LCTRL));
			return false;
			break;
		case M_CDSR:
			SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_D) SS_UP(X_LALT) SS_UP(X_LCTRL));
			return false;
			break;
		case M_HJVMWARE:
			//SEND_STRING("hjacquet@vmware.com");
			SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F6) SS_UP(X_LCTRL));
			return false;
			break;
		case M_HJ:
			//SEND_STRING("Hyacinthe Jacquet");
			SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F7) SS_UP(X_LCTRL));
			return false;
			break;
		case M_JHGMAIL:
			//SEND_STRING("jacquethyacinthe@gmail.com");
			SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F8) SS_UP(X_LCTRL));
			return false;
			break;
		case M_WAITCST:
			//SEND_STRING("Wait for cst feedback" SS_TAP(X_TAB) "Wait for cst");
			SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F5) SS_UP(X_LCTRL));
			return false;
			break;
		case M_TCPDUMP:
			//SEND_STRING("-o - | tcpdump-uw -enr - ");
			SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F4) SS_UP(X_LCTRL));
			return false;
			break;
		case M_WMP:
			SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_KP_6) SS_UP(X_LGUI));
			return false;
			break;
		case M_REPLACE:
			SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_UP(X_LALT) SS_UP(X_LCTRL));
			return false;
			break;
    }
    return true;
}

uint32_t layer_state_set_user(uint32_t state) {
	switch (biton32(state)) {
		case LAYER_NUMPAD:
			rgblight_sethsv (COLOR_ORANGE_HSV);
			break;
		case LAYER_MACROS:
			rgblight_setrgb (COLOR_BLUE_RGB);
			break;
		case LAYER_SETUP:
			rgblight_setrgb (COLOR_RED_RGB);
			break;
		case LAYER_BLANK:
		case LAYER_BLANK_BACK:
			rgblight_setrgb (COLOR_CYAN_RGB);
			break;
	}
	return state;
}
