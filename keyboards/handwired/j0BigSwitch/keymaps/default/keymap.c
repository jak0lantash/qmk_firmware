#include "big_switch.h"

#define _______ KC_TRNS
#define xxxxxxx KC_NO

enum {
	TD_ONE_BIG_SWITCH = 0
};

#ifdef AUDIO_ENABLE
	float sound1[][2] = SONG(MARIO_MUSHROOM);
	float sound2[][2] = SONG(DVORAK_SOUND);
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(TD(TD_ONE_BIG_SWITCH))

};

#define COLOR_ORANGE_HSV 25, 255, 255

void matrix_init_user(void) {
	//rgblight_init();
	rgblight_enable();
	rgblight_sethsv (COLOR_ORANGE_HSV);
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

void dance_one_big_switch(qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1:
			rgblight_setrgb (COLOR_BLUE_RGB);
			PLAY_SONG(sound1);
			SEND_STRING(
"Hello," SS_TAP(X_ENTER)\
SS_TAP(X_ENTER)\
"Thank you for contacting VMware Tanzu Support." SS_TAP(X_ENTER)\
"My name is Hyacinthe. I acknowledge reception of your query." SS_TAP(X_ENTER)\
SS_TAP(X_ENTER)\
SS_TAP(X_ENTER)\
"Best Regards," SS_TAP(X_ENTER)\
SS_TAP(X_ENTER)\
"--" SS_TAP(X_ENTER)\
"Hyacinthe Jacquet" SS_TAP(X_ENTER)\
"Staff Technical Support Engineer, VMware Tanzu" SS_TAP(X_ENTER)\
"hjacquet" SS_DOWN(X_LALT) SS_TAP(X_KP_6) SS_TAP(X_KP_4) SS_UP(X_LALT) "vmware.com" SS_TAP(X_ENTER)\
"Cork, Ireland" SS_TAP(X_ENTER)\
"Office Hours: Mon-Fri 8:30AM - 5:00PM UTC (Friday 4:00PM)" SS_TAP(X_ENTER)\
"Out of Office Hours Contact +1 877-477-226"
			);
			PLAY_SONG(sound1);
			rgblight_sethsv (COLOR_ORANGE_HSV);
			break;
		case 2:
			rgblight_setrgb (COLOR_GREEN_RGB);
			PLAY_SONG(sound2);
			SEND_STRING(
"This case is now archived." SS_TAP(X_ENTER)\
"Archived cases can be reopened within 7 days. If so, it will remain assigned to me so we can continue working on it together. Please also feel free to contact us again if you have any other query." SS_TAP(X_ENTER)\
"It was a pleasure working with you on this case." SS_TAP(X_ENTER)\
SS_TAP(X_ENTER)\
"You may receive a Customer Satisfaction Survey. If you could find some time to fill it, I would greatly appreciate your feedback as it is very important to us to understand how our customers feel about the service we provide. Please note that I am personally evaluated on all the questions (including the 'Overall'). If you need to provide further feedback or about VMware globally, please use the comment section as our Management actively monitors its content."
			);
			PLAY_SONG(sound2);
			rgblight_sethsv (COLOR_ORANGE_HSV);
			break;
		case 4:
			reset_keyboard();
			break;
		default:
			reset_tap_dance(state);
			break;
	}
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_ONE_BIG_SWITCH] = ACTION_TAP_DANCE_FN(dance_one_big_switch)
};
