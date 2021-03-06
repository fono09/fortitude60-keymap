#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum my_layers {
  _QWERTY,
  _GAMING,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  GAMING,
  LOWER,
  RAISE,
  ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI |  Alt |Lower |Space | Esc  |Enter |Shift |Raise |  Alt |  GUI |
 *               `---------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
                 KC_LGUI, KC_LALT,   LOWER,  KC_SPC, KC_ESC,  KC_ENT, KC_RSFT, RAISE,    KC_RALT, KC_RGUI\
),


/* GAMING
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |  UP  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+-------------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  | LEFT | DOWN | RIGHT|   ;  |  '   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |  /   |Enter |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |  Alt |Lower |Space | Esc  |Enter |Shift |Raise |  Alt |      |
 *               `---------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_UP,   KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                   KC_H,    KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
                   KC_NO, KC_LALT,   LOWER,  KC_SPC, KC_ESC,  KC_ENT, KC_RSFT, RAISE,    KC_RALT, KC_NO\
),

/* Lower
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |  Z/H |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   [  |   ]  |  "   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |   -  |   =  | Ctrl |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
  A(KC_GRV),KC_EXLM,KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, S(KC_QUOT),\
  _______, _______, _______ ,_______, _______, _______,  _______, _______, _______, _______, _______,KC_MINS, KC_EQL, _______, \
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
),


/* Raise
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |      |             |      |      |      | Ins  | Home | PgUp |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      | Del  | End  | PgDn |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |      |      |      |      |             | LEFT | DOWN |  UP  | RIGHT|      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, KC_INS,  KC_HOME, KC_PGUP, \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, KC_DEL,  KC_END,  KC_PGDN, \
  _______, _______, _______, _______, _______, _______,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
                    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______\
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|             | VolDn| MUTE |SELECT| VolUp|      | Bksp |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|             |<PREV | PLAY | STOP | NEXT>|      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |Qwerty|Gaming|      |      |      |      |      |      |      |      |      |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,                   KC_VOLD, KC_MUTE, KC_MSEL, KC_VOLU, _______, KC_BSPC, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,                   KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, _______, _______, \
  QWERTY,  GAMING,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
)


};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case GAMING:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAMING);
      }
      return false;
  }
  return true;
}
