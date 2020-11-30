#include QMK_KEYBOARD_H

enum layers {
  _BASE,                // base layer
  _RAISE,               // raise layer
  // _MUSIC,               // music mode
  // _MUSIC_4_LIFE,        // music mode until unplugged
  // _MOUSE,               // mousekeys
  // _TERMINAL,            // terminal
  // _ADMIN                // admin duties
};

// enum custom_keycodes {
//   TERM_ABOUT = SAFE_RANGE,
//   TERM_PRINT,
//   TERM_FLUSH,
//   TERM_HELP,
//   CKEYS_ABOUT,
// };

#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE
   * ,---------------------------------------------------------------------------------------------------------------------------.
   * | esc |  q  |  w  |  e  |  r  |  t  |------|  7  |  8  |  9  |  *  |------|  y  |  u  |  i  |  o  |  p  |  bs | pause|------|
   * |-----+-----+-----+-----+-----+-----+------+-----+-----+-----+-----+------+-----+-----+-----+-----+-----+-----+------+------+
   * | tab |  a  |  s  |  d  |  f  |  g  |------|  4  |  5  |  6  |  /  |------|  h  |  j  |  k  |  l  |  ;  |  '  |------|------|
   * |-----+-----+-----+-----+-----+-----+------+-----+-----+-----+-----+------+-----+-----+-----+-----+-----+-----+------+------+
   * |shift|  z  |  x  |  c  |  v  |  b  |------|  1  |  2  |  3  |  +  |------|  n  |  m  |  ,  |  .  |  /  |shift|  up  |------|
   * |-----+-----+-----+-----+-----+-----+------+-----+-----+-----+-----+------+-----+-----+-----+-----+-----+-----+------+------+
   * |-----|ctrl | alt | win | del |enter|------|  0  |  =  |  .  |  -  |------|space|raise|  [  |  ]  | del | left| down | right|
   * `-------------------------------------------------------------------------------------------------------------------------- '
   */
  [_BASE] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_7,    KC_8,    KC_9,    KC_PAST, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_MPLY
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_4,    KC_5,    KC_6,    KC_SLSH, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_1,    KC_2,    KC_3,    KC_PPLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP
    KC_LCTL, KC_LALT, KC_LGUI, KC_DEL,  KC_ENT,  KC_0,    KC_EQL   KC_DOT,  KC_MINS, KC_SPC,  RAISE,   KC_LBRC, KC_RBRC, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT
  ),
    /* RAISE
   * ,---------------------------------------------------------------------------------------------------------------------------.
   * |print|  !  |  @  |  #  |  $  |  %  |------|  f7 |  f8 |  f9 |home |------|  ^  |  &  |  *  |  (  |  )  |  ~  |      |------|
   * |-----+-----+-----+-----+-----+-----+------+-----+-----+-----+-----+------+-----+-----+-----+-----+-----+-----+------+------+
   * |reset|  <  |  [  |  {  |  (  |  :  |------|  f4 |  f5 |  f6 | end |------|  =  |  )  |  }  |  ]  |  >  |  `  |------|------|
   * |-----+-----+-----+-----+-----+-----+------+-----+-----+-----+-----+------+-----+-----+-----+-----+-----+-----+------+------+
   * |caps |     |     |     |     |     |------|  f1 |  f2 |  f3 |insrt|------|     |     |  |  |  /  |ctrl/|caps |pg up |------|
   * |-----+-----+-----+-----+-----+-----+------+-----+-----+-----+-----+------+-----+-----+-----+-----+-----+-----+------+------+
   * |-----|rctrl|r alt|r win|     |     |------| f10 | f11 | f12 |calc |------|     |raise|  (  |  )  |     | prev|pg dn | next |
   * `-------------------------------------------------------------------------------------------------------------------------- '
   */
  [_RAISE] = LAYOUT(
    KC_PSCR, KC_EXLM, KC_AT  , KC_HASH, KC_DLR,  KC_PERC, KC_F7,   KC_F8,   KC_F9,   KC_HOME, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, KC_TRNS
    RESET,   KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_COLN, KC_F4,   KC_F5,   KC_F6,   KC_END,  KC_PEQL, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK, KC_GRV,
    KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_INS,  KC_TRNS, KC_TRNS, KC_PIPE, KC_BSLS, KC_TRNS, KC_CAPS, KC_PGUP
    KC_RCTL, KC_RALT, KC_RGUI, KC_TRNS, KC_TRNS, KC_F10,  KC_F11   KC_F12,  KC_CALC, KC_TRNS, KC_TRNS,   KC_LBRC, KC_RBRC, KC_TRNS, KC_MPRV, KC_PGDN, KC_MNXT
  )
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case TERM_ABOUT:
//       if (record->event.pressed) {
//         // when keycode TERM_ABOUT is pressed
//         SEND_STRING("about"SS_TAP(X_ENTER));
//       } else {
//         // when keycode TERM_ABOUT is released
//       }
//       break;
//     case TERM_PRINT:
//       if (record->event.pressed) {
//         SEND_STRING("print"SS_TAP(X_ENTER));
//       } else { }
//       break;
//     case TERM_FLUSH:
//       if (record->event.pressed) {
//         SEND_STRING("flush"SS_TAP(X_ENTER));
//       } else { }
//       break;
//     case TERM_HELP:
//       if (record->event.pressed) {
//         SEND_STRING("help"SS_TAP(X_ENTER));
//       } else { }
//       break;
//     case CKEYS_ABOUT:
//       if (record->event.pressed) {
//         SEND_STRING("https://cKeys.org"SS_TAP(X_ENTER)"Making people smile one keyboard at a time."SS_TAP(X_ENTER)"cKeys is a volunteer-run 501(c)(3) nonprofit organization."SS_TAP(X_ENTER));
//       } else { }
//       break;
//   }
//   return true;
// };
