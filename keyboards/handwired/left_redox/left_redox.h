#ifndef KB_H
#define KB_H

#include "quantum.h"

#define KEYMAP( \
	K00, K01, K02, K03, K04, K05,		\
	K10, K11, K12, K13, K14, K15, K16,	\
	K20, K21, K22, K23, K24, K25, K26,	\
	K30, K31, K32, K33, K34, K35, K36, K37,	\
	K40, K41, K42, K43, K44,      K46, K47	\
) { \
	{ K00,	K01,	K02,	K03,	K04,	K05,	KC_NO,	KC_NO },	\
	{ K10,	K11,	K12,	K13,	K14,	K15,	K16,	KC_NO },	\
	{ K20,	K21,	K22,	K23,	K24,	K25,	K26,	KC_NO },	\
	{ K30,	K31,	K32,	K33,	K34,	K25,	K36,	K37 },		\
	{ K40,	K41,	K42,	K43,	K44,	KC_NO,	K46,	K47 }		\
}

#endif
