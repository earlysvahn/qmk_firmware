#include QMK_KEYBOARD_H

#define _COLEMAK 0
#define _LOWER 1
#define _RAISE 2
#define _UTILS 3
#define _EXTRA 4

// Beautify
#define LT_LOWER LT(_LOWER,KC_LCTL)
#define LT_RAISE LT(_RAISE,KC_RALT)
#define LT_ESC LT(_UTILS,KC_ESC)
#define KC_COPY LCTL(KC_C)
#define KC_PSTE LCTL(KC_V)
#define MOD_LSFT OSM(MOD_LSFT)
#define MOD_RSFT OSM(MOD_RSFT)
#define MOD_EXTRA OSL(_EXTRA)
#define APP_TEAM KC_F16
#define APP_SPT KC_F17
#define APP_TERM KC_F18
#define APP_ARC KC_F19
#define APP_SLCK KC_F20

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  LOWER,
  RAISE,
  SPECIAL,
  VIM_SAVE,
  VIM_UNDO,
  COPY,
  PASTE,
  TMUX_LEFT,
  TMUX_DOWN,
  TMUX_UP,
  TMUX_RIGHT,
  TMUX_S,
  TMUX_V,
  TMUX_D,
  SWE_A,
  SWE_AA,
  SWE_O,
  KC_REP
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
     LT_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     QK_REP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     LT_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_COLN,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     MOD_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_D,    TD(LALT_RAYC),    MOD_EXTRA, KC_K,  KC_H,    KC_DOT,  KC_COMM,  KC_SLSH, MOD_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LT_LOWER, KC_SPC,                   KC_ENT,  KC_BSPC, LT_RAISE
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PMNS, KC_PPLS, KC_BSLS, KC_SLSH,  KC_DOT,                            KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_PEQL, KC_SCLN, KC_COLN, KC_QUOT,                            KC_PIPE, KC_LPRN, KC_RPRN, KC_QUES, KC_PLUS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_HASH, VIM_UNDO, KC_COPY, KC_PSTE,KC_PAST,  _______,         _______, KC_TILD, KC_LCBR, KC_RCBR, KC_UNDS, KC_AT,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_DEL, KC_SPC,                     KC_RSFT, VIM_UNDO, VIM_SAVE
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,                            _______, KC_PGUP, KC_E,    KC_W,    KC_HOME, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,                            _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,          _______, _______, KC_PGDN, KC_B,    _______, KC_END,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_LALT, QK_REP,                    _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_UTILS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, BL_ON,   BL_OFF,  BL_STEP, _______, _______,                            _______, TMUX_D,  _______, _______, _______,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MPRV, KC_MSTP,  KC_MPLY, KC_MNXT, _______,                           _______, TMUX_LEFT,TMUX_DOWN,TMUX_UP,TMUX_RIGHT, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_VOLD, KC_VOLU, _______, _______,          _______, _______, TMUX_S, TMUX_V, _______, _______,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   VIM_SAVE,KC_LALT, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_EXTRA] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F13,  KC_F14,  KC_F15,  APP_TEAM, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, APP_SPT, APP_TERM,APP_ARC, APP_SLCK, _______,                            _______, SWE_A,   SWE_AA,  SWE_O,   _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F21,  KC_F22,  KC_F23,  KC_F24, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
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
                update_tri_layer(_LOWER, _RAISE, _UTILS);
                // Turn off backlight
                backlight_set(0);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _UTILS);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _UTILS);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _UTILS);
            }
            return false;
            break;
        case SPECIAL:
            if (record->event.pressed) {
                layer_on(_UTILS);
            } else {
                layer_off(_UTILS);
            }
            return false;
            break;
        case SWE_A:
          if (record->event.pressed) {
                SEND_STRING(SS_LALT("a"));
            }
            return false;
            break;
        case SWE_AA:
          if (record->event.pressed) {
                SEND_STRING(SS_LALT("u") "a");
            }
            return false;
            break;
        case SWE_O:
          if (record->event.pressed) {
                SEND_STRING(SS_LALT("u") "o");
            }
            return false;
            break;
        case VIM_SAVE:
            if (record->event.pressed) {
                SEND_STRING(":w\n");
            }
            return false;
            break;
        case VIM_UNDO:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("r"));
            }
            return false;
            break;
        case TMUX_UP:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") SS_DELAY(50) SS_TAP(X_UP));
            }
            return false;
            break;
        case TMUX_LEFT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") SS_DELAY(50) SS_TAP(X_LEFT));
            }
            return false;
            break;
        case TMUX_RIGHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") SS_DELAY(50) SS_TAP(X_RIGHT));
            }
            return false;
            break;
        case TMUX_S:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") "s");
            }
            return false;
            break;
        case TMUX_V:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") "v");
            }
            return false;
            break;
        case TMUX_D:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") "d");
            }
            return false;
            break;
    }
    return true;
}
