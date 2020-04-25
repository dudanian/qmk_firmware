#include QMK_KEYBOARD_H
#include "version.h"

// Layers
enum custom_layers {
  DVORAK = 0,
  QWERTY,
  SYMBOL,
  NUMPAD,
  ARROW,
  SPACE,
  LOCK,
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

// Rename layer transition macros
#define BASE       DF
#define HOLD       MO
#define TOGGLE     TG
#define ONE_SHOT   OSL

// Alias for layer transitions
#define KL_DVOR BASE(DVORAK)
#define KL_QWER BASE(QWERTY)
#define KL_SYM  HOLD(SYMBOL)
#define KL_NUM  TOGGLE(NUMPAD)
#define KL_ARR  HOLD(ARROW)
#define KL_SPC  TOGGLE(SPACE)
#define KL_LOCK ONE_SHOT(LOCK)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// base layers should have KC_NO
#undef  _______
#define _______ KC_NO

[DVORAK] = LAYOUT_ergodox(
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_PLUS,
        KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_EQL,
        KC_LCTL, KC_LGUI, KC_LALT, KL_NUM,  KL_SYM,
                                                         // left thumb
                                                     KC_VOLD, KC_VOLU,
                                                              KC_HOME,
                                            KC_ENT,  KL_ARR,  KC_END,

        // right hand
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, KC_GRV,
        KC_BSLS, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
                 KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
        KC_PIPE, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
                          KL_SYM,  KL_ARR,  KC_RALT, _______, KC_RCTL,
        // right thumb
        KL_LOCK, _______,
        _______,
        _______, KC_BSPC, KC_SPC
    ),

[QWERTY] = LAYOUT_ergodox(
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_PLUS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_EQL,
        KC_LCTL, KC_LGUI, KC_LALT, KL_NUM,  KL_SYM,
                                                         // left thumb
                                                     KC_VOLD, KC_VOLU,
                                                              KC_HOME,
                                            KC_ENT,  KL_ARR,  KC_END,

        // right hand
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_GRV,
        KC_BSLS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
		 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_PIPE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KL_SYM,  KL_ARR,  KC_RALT, _______, KC_RCTL,
        // right thumb
        KL_LOCK, _______,
        _______,
        _______, KC_BSPC, KC_SPC
    ),

// non-base layers should have KC_TRNS
#undef  _______
#define _______ KC_TRNS

[SYMBOL] = LAYOUT_ergodox(
        // left hand
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
        _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                                         // left thumb
                                                     _______, _______,
                                                              _______,
                                            _______, _______, _______,

        // right hand
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_CIRC, _______, _______, KC_LBRC, KC_RBRC, _______, _______,
                 KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_CIRC, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
        // right thumb
        _______, _______,
        _______,
        _______, _______, _______
),

[NUMPAD] = LAYOUT_ergodox(
        // left hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                                         // left thumb
                                                     _______, _______,
                                                              _______,
                                            _______, _______, _______,

        // right hand
        _______, _______, _______, KC_PSLS, KC_PAST, KC_PMNS, _______,
        _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
                 _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
        _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
                          KC_P0,   KC_P0,   KC_PDOT, KC_PENT, _______,
        // right thumb
        _______, _______,
        _______,
        _______, _______, _______
),

[ARROW] = LAYOUT_ergodox(
        // left hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                                         // left thumb
                                                     _______, _______,
                                                              _______,
                                            _______, _______,  _______,

        // right hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_PGUP, KC_UP,   KC_PGDN, _______, _______,
                 _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
        // right thumb
        _______, _______,
        _______,
        _______, KC_DEL,  _______
),

[SPACE] = LAYOUT_ergodox(
        // left hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_SPC,
                                                         // left thumb
                                                     _______, _______,
                                                              _______,
                                            _______, _______, _______,

        // right hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
        // right thumb
        _______, _______,
        _______,
        _______, _______,  _______
),

[LOCK] = LAYOUT_ergodox(
        // left hand
        _______, KL_DVOR, KL_QWER, KL_NUM,  KL_SPC,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                                         // left thumb
                                                     _______, _______,
                                                              _______,
                                            _______, _______, _______,

        // right hand
        _______, _______, KC_NLCK, KC_PSCR, KC_SLCK, KC_PAUS, _______,
        _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
        // right thumb
        _______, _______,
        _______,
        _______, _______,  _______
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
