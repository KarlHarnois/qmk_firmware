#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  | tab  | Bksp |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+-------------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  | ctrl |  "   |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  | shift| shift|   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  esc | Raise| Alt  | GUI  |Lower |    Space    |Raise | GUI  | Alt  |Lower | ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_ESC,  RAISE,   KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, LOWER,   KC_RCTL}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ctrl |      | left | down |  up  |right | left | down |  up  |right |   |  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |shift |      |      |      |      |      |      |ISO ~ |ISO | | Home | End  |shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | esc  |      | alt  | gui  |      |    Bksp     |      | gui  | alt  |      |ctrl  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,       KC_8,       KC_9,     KC_0,    KC_BSPC},
  {KC_LCTL, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_LEFT, KC_DOWN,    KC_UP,      KC_RIGHT, KC_PIPE, KC_BSLASH},
  {KC_LSFT, _______, _______, _______, _______, _______,  _______, S(KC_NUHS), S(KC_NUBS), KC_HOME,  KC_END,  KC_RSFT},
  {KC_ESC,  _______, KC_LALT, KC_LGUI, _______, KC_BSPC,  KC_BSPC, _______,    KC_RGUI,    KC_RALT,  _______, KC_RCTL}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ctrl |      |      |   {  |  }   |      |      |Pg dn |Pg up |   [  |   ]  |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |shift |      |      |      |      |      |      |      |      |   {  |   }  |shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | esc  |      | alt  | gui  |      |   enter     |      | gui  | alt  |      | ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,   KC_ASTR, KC_LPRN, KC_RPRN, KC_MINUS},
  {KC_LCTL, _______, _______, KC_LCBR, KC_RCBR, _______, _______, KC_PGDOWN, KC_PGUP, KC_LBRC, KC_RBRC, KC_EQUAL},
  {KC_LSFT, _______, _______, _______, _______, _______, _______, _______,   _______, KC_LCBR, KC_RCBR, KC_RSFT},
  {KC_ESC,  _______, KC_LALT, KC_LGUI, _______, KC_ENT,  KC_ENT,  _______,   KC_RGUI, KC_RALT, _______, KC_RCTL}
},
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
  }
  return true;
}
