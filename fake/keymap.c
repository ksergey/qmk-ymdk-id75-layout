#include QMK_KEYBOARD_H

// Keyboard Layers
#define _QW 0
#define _LOWER 1
#define _RAISE 2

#define K_ACT1 (SAFE_RANGE + 1)

#define K_LOWER MO(_LOWER)
#define K_RAISE MO(_RAISE)
#define K_SSPACE LSFT_T(KC_SPC)
#define K_ELOWER LT(_LOWER, KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
   KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_VOLD,  KC_VOLU,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,  \
   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_PGUP,  KC_HOME,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC, \
   KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_PGDN,  KC_END,   KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_BSLS, \
   KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_INS,   XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_PGUP,  KC_PGDN, \
   KC_LCTL,  KC_LGUI,  KC_LALT,  K_LOWER,  XXXXXXX,  K_SSPACE, KC_DEL,   KC_BSPC,  K_ELOWER, XXXXXXX,  K_RAISE,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT  \
 ),

 [_LOWER] = LAYOUT_ortho_5x15( /* FUNCTION */
   XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    XXXXXXX,  XXXXXXX,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  \
   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
   XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX  \
 ),

 [_RAISE] = LAYOUT_ortho_5x15( /* FUNCTION */
   RGB_TOG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_RMOD, RGB_MOD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RESET,   \
   XXXXXXX,  RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW, RGB_M_SN, RGB_M_P,  RGB_M_B,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
   XXXXXXX,  RGB_M_X,  RGB_M_G,  RGB_M_T,  XXXXXXX,  XXXXXXX,  RGB_M_X,  RGB_M_G,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  K_ACT1, \
   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_M_T,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
   XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  RGB_M_SW, RGB_M_SN, XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX  \
 ),

};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
    case K_ACT1:
      // clang-format off
      SEND_STRING_DELAY(SS_LGUI("r") SS_DELAY(1000) "setxkbmap -layout us,ru -option grp:caps_toggle\n" SS_LCTL("d"), 10);
      // clang-format on
      break;
    }
  }
  return true;
}
