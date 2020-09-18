#include QMK_KEYBOARD_H

// Keyboard Layers
#define _QW 0
#define _FN 1

#define _ACT1_ (SAFE_RANGE + 1)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
   KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     XXXXXXX,  XXXXXXX,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,  \
   KC_DEL,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_PSCR,  KC_INS,   KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC, \
   KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_HOME,  KC_END,   KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_BSLS, \
   KC_ESC,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_PGUP,  KC_PGDN,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_UP,    MO(_FN), \
   KC_LCTL,  KC_LGUI,  XXXXXXX,  KC_LALT,  KC_LSFT,  KC_BSPC,  KC_TAB,   KC_SPC,   KC_ENT,   KC_RSFT,  KC_RALT,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT  \
 ),

 [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
   XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    XXXXXXX,  XXXXXXX,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  \
   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
   RGB_TOG,  RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW, RGB_M_SN, XXXXXXX,  RGB_M_X,  RGB_M_G,  RGB_M_T,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _ACT1_,  \
   XXXXXXX,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______, \
   XXXXXXX,  RGB_RMOD, RGB_HUD,  RGB_SAD,  RGB_VAD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RESET    \
 ),

};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
    case _ACT1_:
      // clang-format off
      SEND_STRING_DELAY(SS_LGUI("r") SS_DELAY(750) "setxkbmap -layout us,ru -option grp:caps_toggle\n" SS_LCTL("d"), 5);
      // clang-format on
      break;
    }
  }
  return true;
}
