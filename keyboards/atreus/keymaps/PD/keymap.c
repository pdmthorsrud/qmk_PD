// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus.h"
#include "keymap_norwegian.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _CODE 1
#define _EXTRALETTERS 2
#define _FUNCTIONS 3
#define _QUICKACCESS 4
#define _GAMINGTG 5
#define _MACQW 6
#define _MACCODE 7
#define _MACEXTRALETTERS 8
#define _MACFUNCTIONS 9
#define _MACQUICKACCESS 10
#define _MACGAMINGTG 11



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = { /* Qwerty */
  {KC_Q,          KC_W,    KC_E,    KC_R,                   KC_T,     KC_TRNS,              KC_Y,     KC_U,       KC_I,     KC_O,     KC_P    },
  {KC_A,          KC_S,    KC_D,    LT(_QUICKACCESS, KC_F), KC_G,     KC_TRNS,              KC_H,     KC_J,       KC_K,     KC_L,     KC_SCLN },
  {KC_Z,          KC_X,    KC_C,    KC_V,                   KC_B,     KC_LALT,              KC_N,     KC_M,       KC_COMM,  KC_DOT,   NO_SLSH },
  {MO(_FUNCTIONS),KC_LGUI, KC_TAB,  MT(MOD_LSFT, KC_TAB),   KC_SPC,   MT(MOD_LCTL, KC_ENT), KC_BSPC,  MO(_CODE),  NO_MINS,  NO_QUES,  OSL(_EXTRALETTERS)}
},
/*
 *  !       @     up     {    }        ||     pgup    7     8     9    *
 *  #     left   down  right  |        ||     pgdn    4     5     6    +
 *  [       ]      (     )    &        ||       `     1     2     3    \
 * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
 */
[_CODE] = { /* [> RAISE <] */
  {KC_EXLM, KC_AT,   KC_UP,   NO_LCBR, NO_RCBR, KC_TRNS,                          KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR},
  {NO_AA,   KC_LEFT, KC_DOWN, KC_RGHT, NO_PIPE, KC_TRNS,                          KC_PGDN, KC_4,    KC_5,   KC_6, KC_TAB},
  {NO_LBRC, NO_RBRC, NO_LPRN, NO_RPRN, NO_AMPR, KC_TRNS,                          KC_GRV,  KC_1,    KC_2,   KC_3, KC_TRNS},
  {KC_CAPS, KC_INS,  KC_LGUI, KC_LSFT, KC_BSPC, MT(MOD_LCTL | MOD_LSFT, KC_ENT),  KC_SPC,  KC_TRNS, KC_DOT, KC_0, NO_EQL}
},
/*
 *  !       @     up     {    }        ||     pgup    7     8     9    *
 *  #     left   down  right  |        ||     pgdn    4     5     6    +
 *  [       ]      (     )    &        ||       `     1     2     3    \
 * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
 */
[_EXTRALETTERS] = { /* [> LOWER <] */
  {KC_TRNS, KC_TRNS, NO_AE,   KC_TRNS, KC_TRNS, KC_TRNS, NO_AT,   KC_TRNS, LSFT(KC_I),  NO_OSLH, KC_TRNS},
  {NO_AA,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M(0),        KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_TRNS, KC_TRNS, KC_TRNS, M(1),        KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_QW), KC_TRNS,     KC_TRNS, KC_TRNS}
},
/*
 *  !       @     up     {    }        ||     pgup    7     8     9    *
 *  #     left   down  right  |        ||     pgdn    4     5     6    +
 *  [       ]      (     )    &        ||       `     1     2     3    \
 * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
 */
[_QUICKACCESS] = { /* [> QUICKACCESS <] */
  {KC_MS_WH_UP,     LALT(LSFT(KC_TAB)), LALT(KC_TAB),           KC_LCBR,    KC_RCBR,    KC_TRNS, KC_PGUP,   KC_7,     KC_8,                 NO_OSLH,          KC_TRNS},
  {KC_MS_WH_DOWN,   LCTL(LSFT(KC_TAB)), LCTL(KC_TAB),           KC_TRNS,    KC_DLR,     KC_TRNS, NO_APOS,   NO_AE,    NO_OSLH,              NO_AA,            KC_WAKE},
  {KC_ESC,          KC_VOLD,            KC_VOLU,                KC_VOLU,    KC_AMPR,    KC_LALT, NO_CIRC,   NO_GRTR,  LSFT(NO_GRTR),        KC_3,             KC_SLEP},
  {KC_TRNS,         KC_INS,             KC_LGUI,                KC_TRNS,    KC_BSPC,    KC_TRNS, KC_SPC,    KC_TRNS,  KC_DOT,               KC_MYCM,          KC_PWR}
},
/*
 *  !       @     up     {    }        ||     pgup    7     8     9    *
 *  #     left   down  right  |        ||     pgdn    4     5     6    +
 *  [       ]      (     )    &        ||       `     1     2     3    \
 * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
 */
[_FUNCTIONS] = { /* [> FUNCTIONS <] */
  {RESET,     KC_AT,      NO_AE,    KC_LCBR,    KC_RCBR,    KC_TRNS, KC_PGUP,   KC_7,     KC_8,     NO_OSLH,          TG(_MACQW)},
  {KC_ESC,    KC_MPRV,    KC_MPLY,  KC_MNXT,    KC_DLR,     KC_TRNS, KC_PGDN,   KC_4,     KC_5,     KC_6,             TG(_GAMINGTG)},
  {KC_DELETE, KC_VOLD,    KC_VOLU,  KC_VOLU,    KC_AMPR,    KC_LALT, KC_GRV,    KC_1,     KC_2,     KC_3,             KC_SLEP},
  {KC_TRNS,   KC_INS,     KC_LGUI,  KC_TRNS,    KC_BSPC,    KC_TRNS, KC_SPC,    KC_TRNS,  KC_DOT,   KC_MYCM,          KC_PWR}
},
/*
 *  !       @     up     {    }        ||     pgup    7     8     9    *
 *  #     left   down  right  |        ||     pgdn    4     5     6    +
 *  [       ]      (     )    &        ||       `     1     2     3    \
 * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
 */
[_GAMINGTG] = { /* GAMING */
  {KC_TAB,          KC_Q,     KC_W,       KC_E,                 KC_R,     KC_TRNS,              KC_Y,     KC_U,       KC_I,     KC_O,     KC_P    },
  {KC_2,            KC_A,     KC_S,       KC_D,                 KC_F,     KC_TRNS,              KC_H,     KC_J,       KC_K,     KC_L,     TO(_QW) },
  {KC_3,            KC_Z,     KC_X,       KC_C,                 KC_V,     KC_LSFT,              KC_N,     KC_M,       KC_COMM,  KC_DOT,   KC_SLSH },
  {KC_4,            KC_ESC,   KC_LALT,    KC_LSFT,              KC_LCTL,  KC_SPC,               KC_BSPC,  MO(_CODE),  NO_MINS,  KC_QUOT,  KC_LGUI  }
},


[_MACQW] = { /* Qwerty */
  {KC_Q,            KC_W,     KC_E,               KC_R,                   KC_T,     KC_TRNS,              KC_Y,     KC_U,       KC_I,     KC_O,     KC_P    },
  {KC_A,            KC_S,     KC_D,               LT(_MACQUICKACCESS, KC_F), KC_G,     KC_TRNS,              KC_H,     KC_J,       KC_K,     KC_L,     KC_SCLN },
  {KC_Z,            KC_X,     KC_C,               KC_V,                   KC_B,     KC_LALT,              KC_N,     KC_M,       KC_COMM,  KC_DOT,   NO_SLSH },
  {MO(_MACFUNCTIONS),  KC_ESC,   KC_TAB,             MT(MOD_LSFT, KC_TAB),   KC_SPC,   MT(MOD_LCTL, KC_ENT), KC_BSPC,  MO(_MACCODE),  NO_MINS,  NO_QUES,  OSL(_EXTRALETTERS)}
},
/*
 *  !       @     up     {    }        ||     pgup    7     8     9    *
 *  #     left   down  right  |        ||     pgdn    4     5     6    +
 *  [       ]      (     )    &        ||       `     1     2     3    \
 * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
 */
[_MACCODE] = { /* [> RAISE <] */
  {KC_EXLM, KC_AT,   KC_UP,   NO_LCBR, NO_RCBR, KC_TRNS,                          KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR},
  {NO_AA,   KC_LEFT, KC_DOWN, KC_RGHT, NO_PIPE, KC_TRNS,                          KC_PGDN, KC_4,    KC_5,   KC_6, KC_TAB},
  {NO_LBRC, NO_RBRC, NO_LPRN, NO_RPRN, NO_AMPR, KC_TRNS,                          KC_GRV,  KC_1,    KC_2,   KC_3, KC_TRNS},
  {KC_CAPS, KC_INS,  KC_LGUI, KC_LSFT, KC_BSPC, MT(MOD_LCTL | MOD_LSFT, KC_ENT),  KC_SPC,  KC_TRNS, KC_DOT, KC_0, NO_EQL}
},
/*
 *  !       @     up     {    }        ||     pgup    7     8     9    *
 *  #     left   down  right  |        ||     pgdn    4     5     6    +
 *  [       ]      (     )    &        ||       `     1     2     3    \
 * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
 */
[_MACEXTRALETTERS] = { /* [> LOWER <] */
  {KC_TRNS, KC_TRNS, NO_AE,   KC_TRNS, KC_TRNS, KC_TRNS, KC_AT,   KC_TRNS, LSFT(KC_I),  NO_OSLH, KC_TRNS},
  {NO_AA,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_MACQW), KC_TRNS,     KC_TRNS, KC_TRNS}
},
/*
 *  !       @     up     {    }        ||     pgup    7     8     9    *
 *  #     left   down  right  |        ||     pgdn    4     5     6    +
 *  [       ]      (     )    &        ||       `     1     2     3    \
 * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
 */
[_MACQUICKACCESS] = { /* [> QUICKACCESS <] */
  {KC_MS_WH_UP,     LALT(LSFT(KC_TAB)), LALT(KC_TAB),           KC_LCBR,    KC_RCBR,    KC_TRNS, KC_PGUP,   KC_7,     KC_8,     NO_OSLH,          KC_TRNS},
  {KC_MS_WH_DOWN,   LCTL(LSFT(KC_TAB)), LCTL(KC_TAB),           KC_TRNS,    KC_DLR,     KC_TRNS, KC_PGDN,   KC_4,     KC_5,     KC_6,             KC_WAKE},
  {KC_ESC,          KC_VOLD,            KC_VOLU,                KC_VOLU,    KC_AMPR,    KC_LALT, KC_GRV,    KC_1,     KC_2,     KC_3,             KC_SLEP},
  {KC_TRNS,         KC_INS,             KC_LGUI,                KC_TRNS,    KC_BSPC,    KC_TRNS, KC_SPC,    KC_TRNS,  KC_DOT,   KC_MYCM,          KC_PWR}
},
/*
 *  !       @     up     {    }        ||     pgup    7     8     9    *
 *  #     left   down  right  |        ||     pgdn    4     5     6    +
 *  [       ]      (     )    &        ||       `     1     2     3    \
 * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
 */
[_MACFUNCTIONS] = { /* [> FUNCTIONS <] */
  {RESET,     KC_AT,      NO_AE,    KC_LCBR,    KC_RCBR,    KC_TRNS, KC_PGUP,   KC_7,     KC_8,     NO_OSLH,          TG(_MACQW)},
  {KC_ESC,    KC_MRWD,    KC_MPLY,  KC_MFFD,    KC_DLR,     KC_TRNS, KC_PGDN,   KC_4,     KC_5,     KC_6,             TG(_GAMINGTG)},
  {KC_DELETE, KC_VOLD,    KC_VOLU,  KC_VOLU,    KC_AMPR,    KC_LALT, KC_GRV,    KC_1,     KC_2,     KC_3,             KC_SLEP},
  {KC_TRNS,   KC_INS,     KC_LGUI,  KC_TRNS,    KC_BSPC,    KC_TRNS, KC_SPC,    KC_TRNS,  KC_DOT,   KC_MYCM,          KC_PWR}
},
/*
 *  !       @     up     {    }        ||     pgup    7     8     9    *
 *  #     left   down  right  |        ||     pgdn    4     5     6    +
 *  [       ]      (     )    &        ||       `     1     2     3    \
 * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
 */
[_MACGAMINGTG] = { /* GAMING */
  {KC_1,            KC_Q,     KC_W,       KC_E,                 KC_T,     KC_TRNS,              KC_Y,     KC_U,       KC_I,     KC_O,     KC_TRNS    },
  {KC_2,            KC_A,     KC_S,       KC_D,                 KC_G,     KC_TRNS,              KC_H,     KC_J,       KC_K,     KC_L,     KC_SCLN },
  {KC_3,            KC_Z,     KC_X,       KC_C,                 KC_V,     KC_LALT,              MOD_LALT, KC_TAB,     KC_COMM,  KC_DOT,   KC_SLSH },
  {KC_4,            KC_ESC,   KC_LGUI,    KC_TRNS,              KC_SPC,   KC_LCTL,              KC_BSPC,  MO(_MACCODE),  NO_MINS,  KC_QUOT,  KC_LGUI  }
}};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
          break;
        case 1:
            SEND_STRING("^^");
            return false;
      }
    return MACRO_NONE;
};



//[_EXTRALETTERS] = { /* [> LOWER <] */
//  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
//  {NO_AA,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
//  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
//  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_QW), KC_TRNS, KC_TRNS, KC_TRNS}
//},
