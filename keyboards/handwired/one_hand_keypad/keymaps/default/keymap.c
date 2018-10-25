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
#define TOL_AUDIO3 TO(LAYER_AUDIO3)

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
	A_LP_NUMB,
	A_ODE_TO_JOY,
	A_ROCK_A_BYE_BABY,
	A_CLOSE_ENCOUNTERS_5_NOTE,
	A_DOE_A_DEER,
	A_IN_LIKE_FLINT,
	A_IMPERIAL_MARCH,
	A_CLUEBOARD_SOUND,
	A_BASKET_CASE,
	A_STARTUP_SOUND,
	A_GOODBYE_SOUND,
	A_PLANCK_SOUND,
	A_PREONIC_SOUND,
	A_QWERTY_SOUND, 
	A_COLEMAK_SOUND, 
	A_DVORAK_SOUND, 
	A_PLOVER_SOUND, 
	A_PLOVER_GOODBYE_SOUND, 
	A_MUSIC_ON_SOUND, 
	A_AUDIO_ON_SOUND, 
	A_AUDIO_OFF_SOUND, 
	A_MUSIC_OFF_SOUND, 
  	A_VOICE_CHANGE_SOUND,
	A_CHROMATIC_SOUND, 
	A_MAJOR_SOUND, 
	A_MINOR_SOUND, 
	A_GUITAR_SOUND, 
	A_VIOLIN_SOUND, 
	A_CAPS_LOCK_ON_SOUND, 
	A_CAPS_LOCK_OFF_SOUND,
	A_SCROLL_LOCK_ON_SOUND, 
	A_SCROLL_LOCK_OFF_SOUND, 
	A_NUM_LOCK_ON_SOUND, 
	A_NUM_LOCK_OFF_SOUND, 
	A_AG_NORM_SOUND, 
	A_AG_SWAP_SOUND,
	A_UNICODE_WINDOWS, 
	A_UNICODE_LINUX, 
	A_COIN_SOUND, 
	A_ONE_UP_SOUND, 
	A_SONIC_RING, 
	A_ZELDA_PUZZLE,
	A_ZELDA_TREASURE, 
	A_TERMINAL_SOUND, 
	A_OVERWATCH_THEME, 
	A_MARIO_THEME,
	A_MARIO_GAMEOVER,
	A_MARIO_MUSHROOM, 
	A_E1M1_DOOM, 
	A_DISNEY_SONG, 
	A_NUMBER_ONE, 
	A_CABBAGE_SONG, 
	A_OLD_SPICE,
	A_VICTORY_FANFARE_SHORT, 
	A_ALL_STAR 
};

#ifdef AUDIO_ENABLE
	float a_lp_numb[][2] = SONG(LP_NUMB);
	float a_ode_to_joy[][2] = SONG(ODE_TO_JOY);
	float a_rock_a_bye_bab[][2] = SONG(ROCK_A_BYE_BABY);
	float a_close_encounters_5_not[][2] = SONG(CLOSE_ENCOUNTERS_5_NOTE);
	float a_doe_a_deer[][2] = SONG(DOE_A_DEER);
	float a_in_like_flint[][2] = SONG(IN_LIKE_FLINT);
	float a_imperial_march[][2] = SONG(IMPERIAL_MARCH);
	float a_clueboard_sound[][2] = SONG(CLUEBOARD_SOUND);
	float a_basket_case[][2] = SONG(BASKET_CASE);
	float a_startup_song[][2] = SONG(STARTUP_SOUND);
	float a_goodbye_sound[][2] = SONG(GOODBYE_SOUND);
	float a_planck_sound[][2] = SONG(PLANCK_SOUND);
	float a_qwerty_sound[][2] = SONG(QWERTY_SOUND);
	float a_colemak_sound[][2] = SONG(COLEMAK_SOUND);
	float a_dvorak_sound[][2] = SONG(DVORAK_SOUND);
	float a_plover_sound[][2] = SONG(PLOVER_SOUND);
	float a_plover_goodbye_sound[][2] = SONG(PLOVER_GOODBYE_SOUND);
	float a_music_on_sound[][2] = SONG(MUSIC_ON_SOUND);
	float a_audio_on_sound[][2] = SONG(AUDIO_ON_SOUND);
	float a_audio_off_sound[][2] = SONG(AUDIO_OFF_SOUND);
	float a_music_off_sound[][2] = SONG(MUSIC_OFF_SOUND);
	float a_dhromatic_sound[][2] = SONG(CHROMATIC_SOUND);
	float a_major_sound[][2] = SONG(MAJOR_SOUND);
	float a_minor_sound[][2] = SONG(MINOR_SOUND);
	float a_guitar_sound[][2] = SONG(GUITAR_SOUND);
	float a_violin_sound[][2] = SONG(VIOLIN_SOUND);
	float a_caps_lock_on_sound[][2] = SONG(CAPS_LOCK_ON_SOUND);
	float a_caps_lock_off_sound[][2] = SONG(CAPS_LOCK_OFF_SOUND);
	float a_scroll_lock_on_sound[][2] = SONG(SCROLL_LOCK_ON_SOUND);
	float a_scroll_lock_off_sound[][2] = SONG(SCROLL_LOCK_OFF_SOUND);
	float a_num_lock_on_sound[][2] = SONG(NUM_LOCK_ON_SOUND);
	float a_num_lock_off_sound[][2] = SONG(NUM_LOCK_OFF_SOUND);
	float a_ag_norm_sound[][2] = SONG(AG_NORM_SOUND);
	float a_ag_swap_sound[][2] = SONG(AG_SWAP_SOUND);
	float a_unicode_windows[][2] = SONG(UNICODE_WINDOWS);
	float a_unicode_linux[][2] = SONG(UNICODE_LINUX);
	float a_coin_sound[][2] = SONG(COIN_SOUND);
	float a_one_up_sound[][2] = SONG(ONE_UP_SOUND);
	float a_sonic_ring[][2] = SONG(SONIC_RING);
	float a_zelda_puzzle[][2] = SONG(ZELDA_PUZZLE);
	float a_zelda_treasure[][2] = SONG(ZELDA_TREASURE);
	float a_terminal_sound[][2] = SONG(TERMINAL_SOUND);
	float a_overwatch_theme[][2] = SONG(OVERWATCH_THEME);
	float a_mario_theme[][2] = SONG(MARIO_THEME);
	float a_mario_gameover[][2] = SONG(MARIO_GAMEOVER);
	float a_mario_mushroom[][2] = SONG(MARIO_MUSHROOM);
	float a_e1m1_doom[][2] = SONG(E1M1_DOOM);
	float a_disney_song[][2] = SONG(DISNEY_SONG);
	float a_number_one[][2] = SONG(NUMBER_ONE);
	float a_cabbage_song[][2] = SONG(CABBAGE_SONG);
	float a_old_spicei[][2] = SONG(OLD_SPICE);
	float a_victory_fanfare_short[][2] = SONG(VICTORY_FANFARE_SHORT);
	float a_all_star[][2] = SONG(ALL_STAR);
	float a_voice_change_sound[][2] = SONG(VOICE_CHANGE_SOUND);
#endif

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
		_______,			_______,	_______,	_______,	_______,	_______,
		A_LP_NUMB,	A_ODE_TO_JOY,	A_ROCK_A_BYE_BABY,	A_CLOSE_ENCOUNTERS_5_NOTE,	A_DOE_A_DEER,	A_IN_LIKE_FLINT,	A_IMPERIAL_MARCH,
		A_CLUEBOARD_SOUND, 	A_BASKET_CASE, 	A_STARTUP_SOUND, 	A_GOODBYE_SOUND, 	A_PLANCK_SOUND, 	A_PREONIC_SOUND,
		A_QWERTY_SOUND, 	A_COLEMAK_SOUND, 	A_DVORAK_SOUND, 	A_PLOVER_SOUND, 	A_PLOVER_GOODBYE_SOUND, A_MUSIC_ON_SOUND, 
		A_AUDIO_ON_SOUND, 	A_AUDIO_OFF_SOUND, 	A_MUSIC_OFF_SOUND, 	AU_TOG),

	[LAYER_AUDIO2] = KEYMAP(
		_______,			_______,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		A_CHROMATIC_SOUND, 	A_MAJOR_SOUND, 	A_MINOR_SOUND, 	A_GUITAR_SOUND, 	A_VIOLIN_SOUND, 	A_CAPS_LOCK_ON_SOUND, 	A_CAPS_LOCK_OFF_SOUND,
		A_SCROLL_LOCK_ON_SOUND, 	A_SCROLL_LOCK_OFF_SOUND, 	A_NUM_LOCK_ON_SOUND, 	A_NUM_LOCK_OFF_SOUND, 	A_AG_NORM_SOUND, 	A_AG_SWAP_SOUND,
		A_UNICODE_WINDOWS, 	A_UNICODE_LINUX, 	A_COIN_SOUND, 	A_ONE_UP_SOUND, 	A_SONIC_RING, 	A_ZELDA_PUZZLE,
		A_ZELDA_TREASURE, 	A_TERMINAL_SOUND, 	A_OVERWATCH_THEME, 	AU_TOG),

	[LAYER_AUDIO3] = KEYMAP(
		_______,			_______,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		A_MARIO_GAMEOVER, 	A_MARIO_MUSHROOM, 	A_E1M1_DOOM, 	A_DISNEY_SONG, 	A_NUMBER_ONE, 	A_CABBAGE_SONG, 	A_OLD_SPICE,
		A_VICTORY_FANFARE_SHORT, 	A_ALL_STAR, 	A_VOICE_CHANGE_SOUND,	A_MARIO_THEME,	xxxxxxx,	xxxxxxx,
			xxxxxxx,		xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,	xxxxxxx,
		xxxxxxx,	xxxxxxx,	xxxxxxx,						AU_TOG)


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
		case A_LP_NUMB: PLAY_SONG(a_lp_numb); return false; break;
		case A_ODE_TO_JOY: PLAY_SONG(a_ode_to_joy); return false; break;
		case A_ROCK_A_BYE_BABY: PLAY_SONG(a_rock_a_bye_bab); return false; break;
		case A_CLOSE_ENCOUNTERS_5_NOTE: PLAY_SONG(a_close_encounters_5_not); return false; break;
		case A_DOE_A_DEER: PLAY_SONG(a_doe_a_deer); return false; break;
		case A_IN_LIKE_FLINT: PLAY_SONG(a_in_like_flint); return false; break;
		case A_IMPERIAL_MARCH: PLAY_SONG(a_imperial_march); return false; break;
		case A_CLUEBOARD_SOUND: PLAY_SONG(a_clueboard_sound); return false; break;
		case A_BASKET_CASE: PLAY_SONG(a_basket_case); return false; break;
		case A_STARTUP_SOUND: PLAY_SONG(a_startup_song); return false; break;
		case A_GOODBYE_SOUND: PLAY_SONG(a_goodbye_sound); return false; break;
		case A_PLANCK_SOUND: PLAY_SONG(a_planck_sound); return false; break;
		case A_QWERTY_SOUND: PLAY_SONG(a_qwerty_sound); return false; break;
		case A_COLEMAK_SOUND: PLAY_SONG(a_colemak_sound); return false; break;
		case A_DVORAK_SOUND: PLAY_SONG(a_dvorak_sound); return false; break;
		case A_PLOVER_SOUND: PLAY_SONG(a_plover_sound); return false; break;
		case A_PLOVER_GOODBYE_SOUND: PLAY_SONG(a_plover_goodbye_sound); return false; break;
		case A_MUSIC_ON_SOUND: PLAY_SONG(a_music_on_sound); return false; break;
		case A_AUDIO_ON_SOUND: PLAY_SONG(a_audio_on_sound); return false; break;
		case A_AUDIO_OFF_SOUND: PLAY_SONG(a_audio_off_sound); return false; break;
		case A_MUSIC_OFF_SOUND: PLAY_SONG(a_music_off_sound); return false; break;
		case A_CHROMATIC_SOUND: PLAY_SONG(a_dhromatic_sound); return false; break;
		case A_MAJOR_SOUND: PLAY_SONG(a_major_sound); return false; break;
		case A_MINOR_SOUND: PLAY_SONG(a_minor_sound); return false; break;
		case A_GUITAR_SOUND: PLAY_SONG(a_guitar_sound); return false; break;
		case A_VIOLIN_SOUND: PLAY_SONG(a_violin_sound); return false; break;
		case A_CAPS_LOCK_ON_SOUND: PLAY_SONG(a_caps_lock_on_sound); return false; break;
		case A_CAPS_LOCK_OFF_SOUND: PLAY_SONG(a_caps_lock_off_sound); return false; break;
		case A_SCROLL_LOCK_ON_SOUND: PLAY_SONG(a_scroll_lock_on_sound); return false; break;
		case A_SCROLL_LOCK_OFF_SOUND: PLAY_SONG(a_scroll_lock_off_sound); return false; break;
		case A_NUM_LOCK_ON_SOUND: PLAY_SONG(a_num_lock_on_sound); return false; break;
		case A_NUM_LOCK_OFF_SOUND: PLAY_SONG(a_num_lock_off_sound); return false; break;
		case A_AG_NORM_SOUND: PLAY_SONG(a_ag_norm_sound); return false; break;
		case A_AG_SWAP_SOUND: PLAY_SONG(a_ag_swap_sound); return false; break;
		case A_UNICODE_WINDOWS: PLAY_SONG(a_unicode_windows); return false; break;
		case A_UNICODE_LINUX: PLAY_SONG(a_unicode_linux); return false; break;
		case A_COIN_SOUND: PLAY_SONG(a_coin_sound); return false; break;
		case A_ONE_UP_SOUND: PLAY_SONG(a_one_up_sound); return false; break;
		case A_SONIC_RING: PLAY_SONG(a_sonic_ring); return false; break;
		case A_ZELDA_PUZZLE: PLAY_SONG(a_zelda_puzzle); return false; break;
		case A_ZELDA_TREASURE: PLAY_SONG(a_zelda_treasure); return false; break;
		case A_TERMINAL_SOUND: PLAY_SONG(a_terminal_sound); return false; break;
		case A_OVERWATCH_THEME: PLAY_SONG(a_overwatch_theme); return false; break;
		case A_MARIO_THEME: PLAY_SONG(a_mario_theme); return false; break;
		case A_MARIO_GAMEOVER: PLAY_SONG(a_mario_gameover); return false; break;
		case A_MARIO_MUSHROOM: PLAY_SONG(a_mario_mushroom); return false; break;
		case A_E1M1_DOOM: PLAY_SONG(a_e1m1_doom); return false; break;
		case A_DISNEY_SONG: PLAY_SONG(a_disney_song); return false; break;
		case A_NUMBER_ONE: PLAY_SONG(a_number_one); return false; break;
		case A_CABBAGE_SONG: PLAY_SONG(a_cabbage_song); return false; break;
		case A_OLD_SPICE: PLAY_SONG(a_old_spicei); return false; break;
		case A_VICTORY_FANFARE_SHORT: PLAY_SONG(a_victory_fanfare_short); return false; break;
		case A_ALL_STAR: PLAY_SONG(a_all_star); return false; break;
		case A_VOICE_CHANGE_SOUND: PLAY_SONG(a_voice_change_sound); return false; break;
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
