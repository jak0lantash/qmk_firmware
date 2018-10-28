#include "one_hand_keypad.h"

//#define xxxxxxx KC_NO
//#define _______ KC_TRANS

#define LAYER_SW_MACROS 0
#define LAYER_SETUP 5 
#define LAYER_HW_MACROS 1
#define LAYER_TESTER 6
#define LAYER_TESTER_BACK 7
#define LAYER_AUDIO 2

#define _______ KC_TRNS
#define xxxxxxx KC_NO
#define TOL_SWMACROS TO(LAYER_SW_MACROS)
#define TOL_HWMACROS TO(LAYER_HW_MACROS)
#define MOL_SETUP MO(LAYER_SETUP)
#define TGL_TESTER TG(LAYER_TESTER)
#define MOL_TST_BK MO(LAYER_TESTER_BACK)
#define TOL_AUDIO TO(LAYER_AUDIO)

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
	M_TCPDUMP,
	M_HELP,
	M_PIPE,
	M_USCORE,
	A_LP_NUMB,
	A_CLOSE_ENCOUNTERS_5_NOTE,
	A_IMPERIAL_MARCH,
	A_STARTUP_SOUND,
	A_GOODBYE_SOUND,
	A_PLANCK_SOUND,
	A_QWERTY_SOUND,
	A_COLEMAK_SOUND,
	A_DVORAK_SOUND,
	A_PLOVER_SOUND,
	A_PLOVER_GOODBYE_SOUND,
	A_UNICODE_WINDOWS,
	A_COIN_SOUND,
	A_MARIO_MUSHROOM,
	A_MARIO_THEME,
	A_MARIO_THEME_FULL
};

#ifdef AUDIO_ENABLE
	#define MARIO_THEME_FULL \
		Q__NOTE(_E5), \
		H__NOTE(_E5), \
		H__NOTE(_E5), \
		Q__NOTE(_C5), \
		H__NOTE(_E5), \
		W__NOTE(_G5), \
		Q__NOTE(_G4), \
		WD_NOTE(_REST), \
		H__NOTE(_REST), \
		\
		HD_NOTE(_C5), \
		HD_NOTE(_G4), \
		HD_NOTE(_E4), \
		H__NOTE(_B4), \
		Q__NOTE(_AS4), \
		H__NOTE(_A4), \
		Q__NOTE(_REST), \
		\
		Q__NOTE(_G4), \
		Q__NOTE(_E5), \
		Q__NOTE(_G5), \
		H__NOTE(_A5), \
		Q__NOTE(_F5), \
		H__NOTE(_G5), \
		Q__NOTE(_C5), \
		Q__NOTE(_D5), \
		HD_NOTE(_B4), \
		Q__NOTE(_REST), \
		\
		HD_NOTE(_C5), \
		HD_NOTE(_G4), \
		HD_NOTE(_E4), \
		H__NOTE(_B4), \
		Q__NOTE(_AS4), \
		H__NOTE(_A4), \
		Q__NOTE(_REST), \
		\
		Q__NOTE(_G4), \
		Q__NOTE(_E5), \
		Q__NOTE(_G5), \
		H__NOTE(_A5), \
		Q__NOTE(_F5), \
		H__NOTE(_G5), \
		Q__NOTE(_C5), \
		Q__NOTE(_D5), \
		HD_NOTE(_B4), \
		WD_NOTE(_REST), \
		\
		Q__NOTE(_E5), \
		H__NOTE(_E5), \
		H__NOTE(_E5), \
		Q__NOTE(_C5), \
		H__NOTE(_E5), \
		W__NOTE(_G5), \
		Q__NOTE(_G4)
	

	float a_lp_numb[][2] = SONG(LP_NUMB);
	float a_close_encounters_5_note[][2] = SONG(CLOSE_ENCOUNTERS_5_NOTE);
	float a_imperial_march[][2] = SONG(IMPERIAL_MARCH);
	float a_startup_sound[][2] = SONG(STARTUP_SOUND);
	float a_goodbye_sound[][2] = SONG(GOODBYE_SOUND);
	float a_planck_sound[][2] = SONG(PLANCK_SOUND);
	float a_qwerty_sound[][2] = SONG(QWERTY_SOUND);
	float a_colemak_sound[][2] = SONG(COLEMAK_SOUND);
	float a_dvorak_sound[][2] = SONG(DVORAK_SOUND);
	float a_plover_sound[][2] = SONG(PLOVER_SOUND);
	float a_plover_goodbye_sound[][2] = SONG(PLOVER_GOODBYE_SOUND);
	float a_unicode_windows[][2] = SONG(UNICODE_WINDOWS);
	float a_coin_sound[][2] = SONG(COIN_SOUND);
	float a_mario_mushroom[][2] = SONG(MARIO_MUSHROOM);
	float a_mario_theme[][2] = SONG(MARIO_THEME);
	float a_mario_theme_full[][2] = SONG(MARIO_THEME_FULL);
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[LAYER_SW_MACROS] = KEYMAP(
		//_______,	________,	________,	________,	________,	________,	_______,
		MOL_SETUP, 			LGUI(KC_L),	KC_NO, 		KC_NO, 		LGUI(KC_P6), 	LCTL(LALT(KC_P0)), 
		LCTL(KC_F4), 	M(0), 		M(1), 		LCTL(KC_C), 	LCTL(KC_V), 	KC_N, 		LSFT(KC_N), 
		LCTL(KC_F1), 		LCTL(KC_F2), 	LCTL(KC_F3), 	LCTL(KC_F6), 	LCTL(KC_F7), 	LCTL(KC_F8), 
			LGUI(KC_P1),		LGUI(KC_P2), 	LGUI(KC_P3), 	LGUI(KC_P4), 	LGUI(KC_P5), 	LGUI(KC_P6), 
		LCTL(LALT(KC_D)), LCTL(KC_F5), 	LCTL(LALT(KC_F12)), 						LCTL(LALT(KC_C))),

	[LAYER_SETUP] = KEYMAP(
		_______,			TGL_TESTER,	TOL_SWMACROS,	TOL_HWMACROS,	TOL_AUDIO,	xxxxxxx,
		AU_TOG,		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		RGB_M_SW,		RGB_HUI,	RGB_SAI,	RGB_VAI,	xxxxxxx,	xxxxxxx,
			RGB_M_P,		RGB_HUD,	RGB_SAD,	RGB_VAD,	xxxxxxx,	xxxxxxx,
		RGB_TOG,	RGB_MOD,	RGB_RMOD,							RESET),

	[LAYER_HW_MACROS] = KEYMAP(
		_______,			M_LOCK,		_______,	_______,	M_WMP,		M_REPLACE,
		M_TCPDUMP,	M_PIPE,		M_USCORE,	KC_COPY,	KC_PASTE,	_______,	_______,
		M_VCENTER,		M_STE,		M_VMWARE,	M_HJVMWARE,	M_HJ,		M_JHGMAIL,
			M_OUTLOOK,		M_MREMOTENG,	M_NOTEPAD,	M_CHROME,	M_PHRASEXPR,	M_WMP,
		M_CDSR,		M_WAITCST,	M_HELP,								M_SCOPY),

	[LAYER_TESTER] = KEYMAP(
		MOL_TST_BK,			xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
			xxxxxxx,		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,							xxxxxxx),

	[LAYER_TESTER_BACK] = KEYMAP(
		_______,			_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,		_______,	_______,	_______,	_______,	_______,
			_______,		_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,							TGL_TESTER),
	
	[LAYER_AUDIO] = KEYMAP(
		_______,			_______,	_______,	_______,	_______,	_______,
		A_LP_NUMB,	A_CLOSE_ENCOUNTERS_5_NOTE,	A_IMPERIAL_MARCH,	A_STARTUP_SOUND,	A_GOODBYE_SOUND,	A_PLANCK_SOUND,	A_QWERTY_SOUND,
		A_COLEMAK_SOUND,	A_DVORAK_SOUND,	A_PLOVER_SOUND,	A_PLOVER_GOODBYE_SOUND,	A_UNICODE_WINDOWS,	A_COIN_SOUND,
		A_MARIO_MUSHROOM,	A_MARIO_THEME,	A_MARIO_THEME_FULL,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,							AU_TOG)

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
				return MACRO( D(LALT), T(P9), T(P5), U(LALT), END );
			}
			break;
	}
	return MACRO_NONE;
}

int last_keystroke = 0;
bool layer_not_default = false;

#define COLOR_ORANGE_HSV 25, 255, 255

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
		case M_OUTLOOK:
			SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_KP_1) SS_UP(X_LGUI));
			return false; break;
		case M_MREMOTENG:
			SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_KP_2) SS_UP(X_LGUI));
			return false; break;
		case M_NOTEPAD:
			SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_KP_3) SS_UP(X_LGUI));
			return false; break;
		case M_SCOPY:
			SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_C) SS_UP(X_LALT) SS_UP(X_LCTRL));
			return false; break;
		case M_VCENTER:
			SEND_STRING("administrator@vsphere.local" SS_TAP(X_TAB) "VMware1!" SS_TAP(X_ENTER));
			//SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F1) SS_UP(X_LCTRL));
			return false; break;
		case M_STE:
			SEND_STRING("IAmOnThePhoneWithTechSupport" SS_TAP(X_ENTER));
			//SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F2) SS_UP(X_LCTRL));
			return false; break;
		case M_VMWARE:
			SEND_STRING("VMware1!");
			//SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F3) SS_UP(X_LCTRL));
			return false; break;
		case M_CDSR:
			SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_D) SS_UP(X_LALT) SS_UP(X_LCTRL));
			return false; break;
		case M_HJVMWARE:
			SEND_STRING("hjacquet@vmware.com");
			//SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F6) SS_UP(X_LCTRL));
			return false; break;
		case M_HJ:
			SEND_STRING("Hyacinthe Jacquet");
			//SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F7) SS_UP(X_LCTRL));
			return false; break;
		case M_JHGMAIL:
			SEND_STRING("jacquethyacinthe@gmail.com");
			//SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F8) SS_UP(X_LCTRL));
			return false; break;
		case M_WAITCST:
			SEND_STRING("Wait for cst feedback" SS_TAP(X_TAB) "Wait for cst");
			//SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F5) SS_UP(X_LCTRL));
			return false; break;
		case M_TCPDUMP:
			SEND_STRING("-o - | tcpdump-uw -enr - ");
			//SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F4) SS_UP(X_LCTRL));
			return false; break;
		case M_WMP:
			SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_KP_6) SS_UP(X_LGUI));
			return false; break;
		case M_HELP:
			SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_F12) SS_UP(X_LALT) SS_UP(X_LCTRL));
			return false; break;
		case M_REPLACE:
			SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_UP(X_LALT) SS_UP(X_LCTRL));
			return false; break;
		case M_PIPE:
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_UP(X_LALT));
			return false; break;
		case M_USCORE:
			SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_9) SS_TAP(X_KP_5) SS_UP(X_LALT));
			return false; break;
		case A_LP_NUMB: 		PLAY_SONG(a_lp_numb); 			return false; break;
		case A_CLOSE_ENCOUNTERS_5_NOTE: PLAY_SONG(a_close_encounters_5_note);	return false; break;
		case A_IMPERIAL_MARCH: 		PLAY_SONG(a_imperial_march); 		return false; break;
		case A_STARTUP_SOUND: 		PLAY_SONG(a_startup_sound); 		return false; break;
		case A_GOODBYE_SOUND: 		PLAY_SONG(a_goodbye_sound); 		return false; break;
		case A_PLANCK_SOUND: 		PLAY_SONG(a_planck_sound); 		return false; break;
		case A_QWERTY_SOUND: 		PLAY_SONG(a_qwerty_sound); 		return false; break;
		case A_COLEMAK_SOUND: 		PLAY_SONG(a_colemak_sound); 		return false; break;
		case A_DVORAK_SOUND: 		PLAY_SONG(a_dvorak_sound); 		return false; break;
		case A_PLOVER_SOUND: 		PLAY_SONG(a_plover_sound); 		return false; break;
		case A_PLOVER_GOODBYE_SOUND: 	PLAY_SONG(a_plover_goodbye_sound); 	return false; break;
		case A_UNICODE_WINDOWS: 	PLAY_SONG(a_unicode_windows); 		return false; break;
		case A_COIN_SOUND: 		PLAY_SONG(a_coin_sound); 		return false; break;
		case A_MARIO_MUSHROOM: 		PLAY_SONG(a_mario_mushroom); 		return false; break;
		case A_MARIO_THEME: 		PLAY_SONG(a_mario_theme); 		return false; break;
		case A_MARIO_THEME_FULL: 	PLAY_SONG(a_mario_theme_full); 		return false; break;
	}
    return true;
}

#define COLOR_BLUE_RGB 0x00, 0x00, 0xFF
#define COLOR_BLUE_HSV 240, 255, 255
#define COLOR_ORANGE_RGB 0xFF, 0x30, 0x00
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
			PLAY_SONG(a_planck_sound);
			break;
		case LAYER_SETUP:
			rgblight_setrgb (COLOR_RED_RGB);
			layer_not_default = false;
			break;
		case LAYER_HW_MACROS:
			rgblight_setrgb (COLOR_GREEN_RGB);
			layer_not_default = true;
			PLAY_SONG(a_colemak_sound);
			break;
		case LAYER_TESTER:
		case LAYER_TESTER_BACK:
			rgblight_setrgb (COLOR_TURQUOISE_RGB);
			layer_not_default = true;
			PLAY_SONG(a_plover_sound);
			break;
		case LAYER_AUDIO:
			rgblight_setrgb (COLOR_BLUE_RGB);
			layer_not_default = true;
			break;
	}
	return state;
}
