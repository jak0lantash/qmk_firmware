#include "one_hand_keypad.h"

//#define xxxxxxx KC_NO
//#define _______ KC_TRANS

#define LAYER_SW_MACROS 0
#define LAYER_SETUP 5 
#define LAYER_HW_MACROS 1
#define LAYER_TESTER 6
#define LAYER_TESTER_BACK 7
#define LAYER_AUDIO 2
#define LAYER_AUDIO2 3
#define LAYER_AUDIO3 4

#define _______ KC_TRNS
#define xxxxxxx KC_NO
#define TOL_SWMACROS TO(LAYER_SW_MACROS)
#define TOL_HWMACROS TO(LAYER_HW_MACROS)
#define MOL_SETUP MO(LAYER_SETUP)
#define TGL_TESTER TG(LAYER_TESTER)
#define MOL_TST_BK MO(LAYER_TESTER_BACK)
#define TOL_AUDIO TO(LAYER_AUDIO)
#define TOL_AUDIO2 TO(LAYER_AUDIO2)

enum custom_keycodes {
	M_CDSR = SAFE_RANGE,
	M_SCOPY,
	M_OUTLOOK,
	M_MREMOTENG,
	M_NOTEPAD,
	M_CHROME,
	M_PHRASEXPR,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[LAYER_SW_MACROS] = KEYMAP(
		//_______,	________,	________,	________,	________,	________,	_______,
		MOL_SETUP, 			LGUI(KC_L),	KC_NO, 		KC_NO, 		LGUI(KC_P6), 	LCTL(LALT(KC_P0)), 
		LCTL(KC_F4), 	M(0), 		M(1), 		LCTL(KC_C), 	LCTL(KC_V), 	KC_N, 		LSFT(KC_N), 
		LCTL(KC_F1), 		LCTL(KC_F2), 	LCTL(KC_F3), 	LCTL(KC_F6), 	LCTL(KC_F7), 	LCTL(KC_F8), 
			LGUI(KC_P1),		KC_SPC, 	KC_SPC, 	KC_SPC, 	KC_SPC, 	KC_SPC, 
		KC_SPC, 	KC_SPC, 	KC_SPC, 						KC_NO),

	[LAYER_SETUP] = KEYMAP(
		_______,			TGL_TESTER,	TOL_SWMACROS,	TOL_HWMACROS,	TOL_AUDIO,	TOL_AUDIO2,
		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	TOL_AUDIO3,
		RGB_M_SW,		RGB_HUI,	RGB_SAI,	RGB_VAI,	xxxxxxx,	xxxxxxx,
			RGB_M_P,		RGB_HUD,	RGB_SAD,	RGB_VAD,	xxxxxxx,	xxxxxxx,
		RGB_TOG,	RGB_MOD,	RGB_RMOD,						RESET),

	[LAYER_HW_MACROS] = KEYMAP(
		_______,			M_LOCK,		_______,	_______,	M_WMP,		M_REPLACE,
		M_TCPDUMP,	_______,	_______,	_______,	_______,	_______,	_______,
		M_VCENTER,		M_STE,		M_VMWARE,	M_HJVMWARE,	M_HJ,		M_JHGMAIL,
			M_OUTLOOK,		M_MREMOTENG,	M_NOTEPAD,	M_CHROME,	M_PHRASEXPR,	_______,
		M_CDSR,		_______,	M_WAITCST,						M_SCOPY),

	[LAYER_TESTER] = KEYMAP(
		MOL_TST_BK,			xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
			xxxxxxx,		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,						xxxxxxx),

	[LAYER_TESTER_BACK] = KEYMAP(
		_______,			_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,		_______,	_______,	_______,	_______,	_______,
			_______,		_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,						TGL_TESTER),
	
	[LAYER_AUDIO] = KEYMAP(
		_______,			AU_TOG,		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		LP_NUMB, ODE_TO_JOY, ROCK_A_BYE_BAB, CLOSE_ENCOUNTERS_5_NOT, DOE_A_DEER, IN_LIKE_FLINT,	IMPERIAL_MARC,
		CLUEBOARD_SOUN, BASKET_CASE, STARTUP_SOUN, GOODBYE_SOUND, PLANCK_SOUN, PREONIC_SOUN,
		QWERTY_SOUND, COLEMAK_SOUND, DVORAK_SOUND, PLOVER_SOUND, PLOVER_GOODBYE_SOUND, MUSIC_ON_SOUND,
		AUDIO_ON_SOUND, AUDIO_OFF_SOUND, MUSIC_OFF_SOUND, VOICE_CHANGE_SOUND),

	[LAYER_AUDIO2] = KEYMAP(
		_______,			_______,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		CHROMATIC_SOUND, MAJOR_SOUND, MINOR_SOUND, GUITAR_SOUND, VIOLIN_SOUND, CAPS_LOCK_ON_SOUND, CAPS_LOCK_OFF_SOUND,
		SCROLL_LOCK_ON_SOUND, SCROLL_LOCK_OFF_SOUND, NUM_LOCK_ON_SOUND, NUM_LOCK_OFF_SOUND, AG_NORM_SOUND, AG_SWAP_SOUND,
		UNICODE_WINDOWS, UNICODE_LINUX, COIN_SOUND, ONE_UP_SOUND, SONIC_RING, ZELDA_PUZZLE,
		ZELDA_TREASURE, TERMINAL_SOUND, OVERWATCH_THEME, MARIO_THEME),

	[LAYER_AUDIO3] = KEYMAP(
		_______,			_______,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		MARIO_GAMEOVER, MARIO_MUSHROOM, E1M1_DOOM, DISNEY_SONG, NUMBER_ONE, CABBAGE_SONG, OLD_SPICEi,
		VICTORY_FANFARE_SHORT, ALL_STAR, xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
			xxxxxxx,		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,						xxxxxxx),


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

int last_keystroke = 0;
bool layer_not_default = false;

void matrix_init_user(void) {
	//rgblight_init();
	rgblight_enable();
	rgblight_sethsv (COLOR_ORANGE_HSV);
}

void matrix_scan_user(void) {
	if (layer_not_default && timer_elapsed(last_keystroke) > 60000) {
		layer_not_default = false;
		rgblight_setrgb (COLOR_BLUE_RGB);
		layer_move(0);
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!record->event.pressed)
		last_keystroke = timer_read();
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
			SEND_STRING("administrator@vsphere.local" SS_TAP(X_TAB) "VMware1!" SS_TAP(X_ENTER));
			//SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F1) SS_UP(X_LCTRL));
			return false;
			break;
		case M_STE:
			SEND_STRING("IAmOnThePhoneWithTechSupport" SS_TAP(X_ENTER));
			//SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F2) SS_UP(X_LCTRL));
			return false;
			break;
		case M_VMWARE:
			SEND_STRING("VMware1!");
			//SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F3) SS_UP(X_LCTRL));
			return false;
			break;
		case M_CDSR:
			SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_D) SS_UP(X_LALT) SS_UP(X_LCTRL));
			return false;
			break;
		case M_HJVMWARE:
			SEND_STRING("hjacquet@vmware.com");
			//SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F6) SS_UP(X_LCTRL));
			return false;
			break;
		case M_HJ:
			SEND_STRING("Hyacinthe Jacquet");
			//SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F7) SS_UP(X_LCTRL));
			return false;
			break;
		case M_JHGMAIL:
			SEND_STRING("jacquethyacinthe@gmail.com");
			//SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F8) SS_UP(X_LCTRL));
			return false;
			break;
		case M_WAITCST:
			SEND_STRING("Wait for cst feedback" SS_TAP(X_TAB) "Wait for cst");
			//SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F5) SS_UP(X_LCTRL));
			return false;
			break;
		case M_TCPDUMP:
			SEND_STRING("-o - | tcpdump-uw -enr - ");
			//SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F4) SS_UP(X_LCTRL));
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

uint32_t layer_state_set_user(uint32_t state) {
	switch (biton32(state)) {
		case LAYER_SW_MACROS:
			rgblight_sethsv (COLOR_ORANGE_HSV);
			layer_not_default = false;
			break;
		case LAYER_SETUP:
			rgblight_setrgb (COLOR_RED_RGB);
			layer_not_default = false;
			break;
		case LAYER_HW_MACROS:
			rgblight_setrgb (COLOR_GREEN_RGB);
			layer_not_default = true;
			break;
		case LAYER_TESTER:
		case LAYER_TESTER_BACK:
			rgblight_setrgb (COLOR_TURQUOISE_RGB);
			layer_not_default = true;
			break;
		case LAYER_AUDIO:
			rgblight_setrgb (COLOR_YELLOW_RGB);
			layer_not_default = true;
			break;
		case LAYER_AUDIO2:
			rgblight_setrgb (COLOR_BLUE_RGB);
			layer_not_default = true;
			break;
		case LAYER_AUDIO3:
			rgblight_setrgb (COLOR_PINK_RGB);
			layer_not_default = true;
			break;
	}
	return state;
}
