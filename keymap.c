#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#if KEYLOGGER_ENABLE
# ifdef AUTOLOG_ENABLE
bool log_enable = true;
# else
bool log_enable = false;
# endif
#endif

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  `  ~  | 1  ! | 2  @ | 3  # | 4  $ | 5  % |      |           |      | 6  ^ | 7  & | 8  * | 9  ( | 0  ) |  -  _  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  | Home |           | PgUp |   Y  |   U  |   I  |   O  |   P  |  \  |  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Esc   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;  : |  '  "  |
 * |--------+------+------+------+------+------| End  |           | PgDn |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  | , <  | . >  | /  ? | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtl | LAlt |      |  L2  |  L1  |                                       |  L1  |  L2  | [  { | ]  } | RCtl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,--------------.       ,--------------.
 *                                       |       |      |       |      |       |
 *                               ,-------|-------|------|       |------+-------+-------.
 *                               |       |       |      |       |      |       |       |
 *                               |  Bspc |  Del  |------|       |------| Enter | Space |
 *                               |       |       | LGui |       | RGui |       |       |
 *                               `----------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
        // left hand
        KC_GRV,  KC_1,    KC_2,    KC_3,     KC_4,     KC_5,    KC_TRNS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,    KC_HOME,
        KC_ESC,  KC_A,    KC_S,    KC_D,     KC_F,     KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,    KC_END,
        KC_LCTL, KC_LALT, KC_TRNS, MO(NUMB), MO(SYMB),
                                                       KC_TRNS, KC_TRNS,
                                                                KC_TRNS,
                                             KC_BSPC,  KC_DEL,  KC_LGUI,
        // right hand
        KC_TRNS, KC_6,    KC_7,     KC_8,     KC_9,    KC_0,    KC_MINS,
        KC_PGUP, KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,    KC_BSLS,
                 KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN, KC_QUOT,
        KC_PGDN, KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
                          MO(SYMB), MO(NUMB), KC_LBRC, KC_RBRC, KC_RCTL,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_RGUI, KC_ENT,  KC_SPC
),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |           |  F8  |  F9  |  F10 |  F11 |  F12 |  F13 |  F14   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   ~    |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |  -  _  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   <  |   >  |   (  |   )  |  ` ~ |------|           |------| Left |  Up  | Down | Right|   +  |  =  +  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   {  |   }  |  [ { |  ] } |   ~  |      |           |      |   <  |   >  |  [ { |  ] } |  \ | |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,--------------.       ,--------------.
 *                                       |       |      |       |      |       |
 *                               ,-------|-------|------|       |------+-------+-------.
 *                               |       |       |      |       |      |       |       |
 *                               |       |       |------|       |------|       |       |
 *                               |       |       |      |       |      |       |       |
 *                               `----------------------'       `----------------------'
 */
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,
       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,
       KC_TRNS, KC_LABK, KC_RABK, KC_LPRN, KC_RPRN, KC_GRV,
       KC_TRNS, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_F14,
       KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
                KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_PLUS, KC_EQL,
       KC_TRNS, KC_LABK, KC_RABK, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Numbers Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |  Ver |      |  / ? |   *  |  - _ |   +  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  [ { |  7 & |  8 * |  9 ( |   (  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|  ] } |  4 $ |  5 % |  6 ^ |   )  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   &  |  1 ! |  2 @ |  3 # | Entr |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0 ) |      |  . > |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,--------------.       ,--------------.
 *                                       |       |      |       |      |       |
 *                               ,-------|-------|------|       |------+-------+-------.
 *                               |       |       |      |       |      |       |       |
 *                               |       |       |------|       |------|       |       |
 *                               |       |       |      |       |      |       |       |
 *                               `----------------------'       `----------------------'
 */
[NUMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       VRSN,    KC_TRNS, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_TRNS,
       KC_TRNS, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_LPRN, KC_TRNS,
                KC_RBRC, KC_4,    KC_5,    KC_6,    KC_RPRN, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_ENT,  KC_TRNS,
                         KC_0,    KC_TRNS, KC_DOT,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

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
#if KEYLOGGER_ENABLE
  if (log_enable) {
    uint8_t layer = biton32(layer_state);

  uprintf(
    "{ \"keylog\": true, \"col\": %d, \"row\": %d, \"pressed\": %d, \"layer\": \"%d\" }\n",
    record->event.key.row,
    record->event.key.col,
    record->event.pressed,
    layer
  );
  }
#endif
  switch (keycode) {
    // dynamically generate these.
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  ergodox_led_all_on();
  for (int i = LED_BRIGHTNESS_HI; i > LED_BRIGHTNESS_LO; i--) {
    ergodox_led_all_set (i);
    wait_ms (5);
  }
  wait_ms(1000);
  for (int i = LED_BRIGHTNESS_LO; i > 0; i--) {
    ergodox_led_all_set (i);
    wait_ms (10);
  }
  ergodox_led_all_off();
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  return state;
};
