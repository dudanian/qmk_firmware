#include QMK_KEYBOARD_H
#include "version.h"

// enum custom_layers;
#include "layers.h"

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

// Alias for layer transitions
#define KL_QWER TOGGLE(QWERTY)
#define KL_GAME TOGGLE(GAMING)
#define KL_NUM  TOGGLE(NUMPAD)
#define KL_SYM  HOLD(SYMBOL)
#define KL_ARR  HOLD(ARROW)
#define KL_ARRL TOGGLE(ARROW)
#define KL_LOCK HOLD(LOCK)

// Simple macros
#define KM_LCA  LCTL(KC_LALT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// base layers should have KC_NO
#undef  _______
#define _______ KC_NO

[DVORAK] = LAYOUT_ergodox(
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_PLUS,
        KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_EQL,
        KM_LCA,  KC_LGUI, KC_LALT, KL_ARR,  KL_SYM,
                                                         // left thumb
                                                     KC_VOLD, KC_VOLU,
                                                              KC_MPLY,
                                            KC_ENT,  KL_ARR,  KC_MUTE,

        // right hand
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, KC_GRV,
        KC_BSLS, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
                 KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
        KC_PIPE, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
                          KL_SYM,  KL_ARR,  KC_RALT, KL_ARRL, KC_RCTL,
        // right thumb
        KC_PGUP, KC_PGDN,
        KC_LCTL,
        KL_LOCK, KC_BSPC, KC_SPC
    ),

// non-base layers should have KC_TRNS
#undef  _______
#define _______ KC_TRNS

[QWERTY] = LAYOUT_ergodox(
        // left hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,
        _______, _______, _______, _______, _______,
                                                         // left thumb
                                                     _______, _______,
                                                              _______,
                                            _______, _______, _______,

        // right hand
        _______, _______, _______, _______, _______, KC_MINS, _______,
        _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                          _______, _______, _______, _______, _______,
        // right thumb
        _______, _______,
        _______,
        _______, _______,  _______
    ),

[GAMING] = LAYOUT_ergodox(
        // left hand
        _______, _______, _______, _______, _______, _______, KC_6,
        _______, _______, _______, _______, _______, _______, KC_7,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_8,
        KC_LCTL, _______, _______, KC_LALT, KC_SPC,
                                                         // left thumb
                                                     KC_F1,   KC_F2,
                                                              KC_F3,
                                            _______, _______, KC_F4,

        // right hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
        // right thumb
        KC_VOLD, KC_VOLU,
        _______,
        _______, _______,  _______
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
        _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______,
        _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
                 _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
        _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
                          KC_P0,   KC_P0,   KC_PDOT, KC_PENT, _______,
        // right thumb
        _______, _______,
        _______,
        _______, _______, _______
),


[SYMBOL] = LAYOUT_ergodox(
        // left hand
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
        _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                                         // left thumb
                                                     KC_MNXT, KC_MPRV,
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
                 KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______,
        _______, _______, KC_HOME, _______, KC_END,  _______, _______,
                          _______, _______, _______, _______, _______,
        // right thumb
        _______, _______,
        _______,
        _______, KC_DEL,  _______
),

[LOCK] = LAYOUT_ergodox(
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
        _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          KC_PSCR, KC_SLCK, KC_PAUS, _______, _______,
        // right thumb
        KL_QWER, KL_GAME,
        KL_NUM,
        _______, _______, _______
),

};
