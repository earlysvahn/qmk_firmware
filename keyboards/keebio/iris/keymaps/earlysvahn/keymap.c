#include QMK_KEYBOARD_H

#define _COLEMAK 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _MACROS 4

// Beautify
#define LT_LCTL LT(_LOWER,KC_LCTL)
#define LT_RALT LT(_RAISE,KC_RALT)

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MACROS,
  VIM_SAVE,
  COPY,
  PASTE,
  TMUX_LEFT,
  TMUX_DOWN,
  TMUX_UP,
  TMUX_RIGHT,
  TMUX_S,
  TMUX_V,
};

enum {
    LALT_RAYC,
};

void raycast_on_double_tap(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        SEND_STRING(SS_LGUI(SS_TAP(X_SPC)));
        reset_tap_dance(state);
    } else {
        SEND_STRING(SS_TAP(X_LALT));
    }
}


tap_dance_action_t tap_dance_actions[] = {
    [LALT_RAYC] = ACTION_TAP_DANCE_FN(raycast_on_double_tap),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_COLN,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_D,    TD(LALT_RAYC),    MO(_MACROS), KC_K,KC_H,    KC_DOT,  KC_COMM,KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LT_LCTL, KC_LGUI, KC_SPC,                    KC_ENT,  KC_BSPC, LT_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PMNS, KC_PPLS, KC_BSLS, KC_SLSH, KC_DOT,                             KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PEQL, KC_QUOT, KC_SCLN, KC_COLN, KC_COMM,                            KC_PIPE, KC_LPRN, KC_RPRN, KC_QUES, KC_PLUS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______,VIM_SAVE, KC_COPY, KC_PSTE, KC_PAST, _______,         _______,  KC_TILD, KC_LCBR, KC_RCBR, KC_UNDS, KC_AT,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_DEL, KC_SPC,                     KC_RSFT, KC_BSPC, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,                            _______, KC_PGUP, KC_E,    KC_W,    KC_HOME, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,                            _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,MO(_ADJUST),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F9,   KC_F10,  KC_F11, KC_F12,   _______, _______,          _______, _______, KC_PGDN, KC_B,    _______, KC_END,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MPRV, KC_MSTP,  KC_MPLY, KC_MNXT, _______,                            _______, BL_ON,   BL_OFF, BL_STEP, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_VOLD, KC_VOLU, _______, _______,          _______, _______, _______, _______, _______, _______, DF(_COLEMAK),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MACROS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, BL_OFF,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, BL_OFF,  BL_ON,   BL_STEP, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,TMUX_LEFT,TMUX_DOWN,TMUX_UP,TMUX_RIGHT,_______,                          _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______,  TMUX_S, TMUX_V,  _______,  _______,         _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_LALT, VIM_SAVE,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                // Turn off backlight
                backlight_set(0);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
        case MACROS:
            if (record->event.pressed) {
                layer_on(_MACROS);
            } else {
                layer_off(_MACROS);
            }
            return false;
            break;
        case VIM_SAVE:
            if (record->event.pressed) {
                SEND_STRING(":w\n");
            }
            break;
        case TMUX_UP:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") SS_DELAY(50) SS_TAP(X_UP));
            }
            break;
        case TMUX_LEFT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") SS_DELAY(50) SS_TAP(X_LEFT));
            }
            break;
        case TMUX_RIGHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") SS_DELAY(50) SS_TAP(X_RIGHT));
            }
            break;
        case TMUX_S:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") "s");
            }
            break;
        case TMUX_V:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") "v");
            }
            break;
    }
    return true;
}
