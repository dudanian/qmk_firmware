#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0
#define SYMBOL 1
#define NUMPAD 2 
#define TMUX 3
#define ARROW 4

/* my keyboard layout
 *
 * There are a few important considerations for me:
 *
 * dvorak support (base layer)
 * symbol keys (middle layer)
 * arrow keys (topmost layer)
 * macros
 *   ctrl B (tmux)
 *   ctrl alt t (terminal)
 *   alt tab (maybe?)
 *
 * media keys
 *
 * don't EVER have keys greater than 7 chars
 * create defines for complicated keys 'KD_'
 */
enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  // custom tmux codes
  KT_UP,
  KT_DOWN,
  KT_LEFT,
  KT_RGHT,
  KT_PREV,
  KT_NEXT,

};

// base layers should have KC_NO
#undef  _______
#define _______ KC_NO

// the original codes are confusting
#define HOLD       MO
#define TOGGLE     TG
#define TAP_TOGGLE TT

// TODO replace all base layer non-keys with something
// KD_ or KL_ or KM_
// TAP_TOGGLE is fun, but a little weird
// maybe I'll play around with it more later
//
#define KL_ARR  HOLD(ARROW)
#define KL_SYM  HOLD(SYMBOL)
#define KL_NUM  TOGGLE(NUMPAD)
#define KL_TMUX HOLD(TMUX)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * For the most part this is a standard dvorak layout.
 * The most interesting things are in the control keys
 * and the thumb clusters
 *
 * things I like
 * + and = are dedicated keys
 * | and \ are dedicated keys
 * 
 * alt + tab and alt + grv mirror each other on other halves
 * (well, almost. tab is still one row lower)
 *
 * layA - hold for arrows
 * lay0/4 - press for lock arrows
 * layS - hold for symbol layer
 * lay2/3 - press for symbol key latch?
 * layN -   currently numpad, could probably lock it
 *          would very much like to cancel out of that
 * layT
 *
 * it would be pretty cool if ESC cancelled current locked layer
 * not sure if that is possible
 *
 *
 *
 */
[BASE] = LAYOUT_ergodox(
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_PLUS,
        KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_EQL,
        _______, KC_LGUI, KC_LALT, KL_NUM,  KL_SYM,
                                                         // left thumb
                                                         // media keys
                                                         // and enter
                                                     KC_VOLD, KC_VOLU,
                                                              KC_MPLY,
                                            KC_ENT,  KL_ARR,  KL_TMUX,
                                                      // maybe I can do some tmux hing?
                                                      // ctrl b?
                                                      // ooooh or a tmux layer!!!
                                                      // where everything is a tmux shortcut
        // right hand
        // I kind of want to try out the shifted top row..
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, KC_GRV,
        // have forward and backslash on same row, on other ends
        KC_BSLS, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
                 KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
        // pipe matters less, but follow the same pattern as +=
        KC_PIPE, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
                          KL_SYM,  KL_ARR,  KC_LALT, _______, _______,
                                             // maybe I can make these alt ~?
        // right thumb
        _______, _______,
        _______,
        KL_TMUX, KC_BSPC, KC_SPC
    ),


// non-base layers should have KC_TRNS
#undef  _______
#define _______ KC_TRNS
/* Keymap 1: Symbol Layer
 *
 * This is a pretty straight forward layout. It adds the [] and {} keys
 * that I'm missing on the base layer and mirrors them on both halves.
 *
 * It also pulls down the shift symbols from the number row to under
 * the home row. For no particular reason. Note that the () are actually
 * offset to match up with the brackets.
 */
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
        _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______,
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
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_7,    KC_8,    KC_9,    _______, _______,
                 _______, KC_4,    KC_5,    KC_6,    _______, _______,
        _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
                          KC_0,    KC_0,    KC_DOT,  _______, _______,
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
                                            _______, _______, _______,

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


[TMUX] = LAYOUT_ergodox(
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
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KT_PREV, KT_UP,   KT_NEXT, _______, _______,
                 _______, KT_LEFT, KT_DOWN, KT_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
        // right thumb
        _______, _______,
        _______,
        _______, _______, _______
),
};

// I don't think I need this?
#if 0
const uint16_t PROGMEM fn_actions[] = {
    // wtf is this for??
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMBOL)                // FN1 - Momentary Layer 1 (Symbols)
};
#endif

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
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
    case KT_UP:
      if (record->event.pressed) {
        SEND_STRING (SS_LCTRL("b") SS_TAP(X_UP));
      }
      return false;
      break;
    case KT_DOWN:
      if (record->event.pressed) {
        SEND_STRING (SS_LCTRL("b") SS_TAP(X_DOWN));
      }
      return false;
      break;
    case KT_LEFT:
      if (record->event.pressed) {
        SEND_STRING (SS_LCTRL("b") SS_TAP(X_LEFT));
      }
      return false;
      break;
    case KT_RGHT:
      if (record->event.pressed) {
        SEND_STRING (SS_LCTRL("b") SS_TAP(X_RIGHT));
      }
      return false;
      break;
    case KT_PREV:
      if (record->event.pressed) {
        SEND_STRING (SS_LCTRL("b") "p");
      }
      return false;
      break;
    case KT_NEXT:
      if (record->event.pressed) {
        SEND_STRING (SS_LCTRL("b") "n");
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
