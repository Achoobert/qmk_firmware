// spell-checker: disable
/* Achoobert Layout
 * Based on tominabox1
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
  _COLMKD,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAV,
  _READ,
  _PLOVER,
//   _MAGIC
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
// #define SPACE MO(_MAGIC)
#define NAV MO(_NAV)
#define READ MO(_READ)


// Special keys
// when a key is pressed, it alternates between these two sets of definitions
#define OS_SWITCHER 1 // or 0 for CTRL keys
#define TOGGL() (OS_SWITCHER == 0 ? (OS_SWITCHER = 1) : (OS_SWITCHER = 0))
// T->F  x=F
// F->T  x=F

#ifdef OS_SWITCHER
#define MODIFIER LGUI
#else
#define MODIFIER LCTL
#endif

#define COPY     MODIFIER(KC_C)
#define CUT      MODIFIER(KC_X)
#define PASTE    MODIFIER(KC_V)
#define FIND     MODIFIER(KC_F)
#define DBL      MODIFIER(KC_D)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ColmacDH
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   A  |   R  |   S  |   T  |   G  |M/read|   N  |   E  |   I  |O/ Nav|  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * esc/Shft|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Entr/shft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  |  COPY|Lower |    Space    |Raise | PASTE|      | Hypr |  Meh |
 * `-----------------------------------------------------------------------------------'
 */
// [_COLMKD] = LAYOUT_planck_mit(
//     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_BSPC,
//     KC_DEL,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    LT(READ,KC_M),    KC_N,    KC_E,    KC_I,    LT(NAV,KC_O), KC_QUOT,
//     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
//     RGB_TOG, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
// ),
[_COLMKD] = LAYOUT_planck_mit(
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_BSPC,
    KC_DEL,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    LT(READ,KC_M),    KC_N,    KC_E,    KC_I,    LT(NAV,KC_O), KC_QUOT,
    LT(KC_LSFT, KC_ESC), KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, LT(KC_RSFT, KC_ENT),
    KC_LCTL, KC_LGUI, KC_LALT, COPY, LT(LOWER, KC_TAB),   LT(NAV, KC_SPC),  LT(RAISE, KC_ENT), PASTE, _______, KC_HYPR, KC_MEH
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |  Esc |  Esc |  Esc |  F5  |      |      | F10  |  Esc | Esc  |  Esc | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F11 |  F12 |  F9  |  F8  |  F7  |  F6  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | lShft| COPY | CUT  |PASTE | DBL  | F6   | F7   | F8   | F9   | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Gui  | Alt  |      |      |             |      |      |      |      |      | 
 * `-----------------------------------------------------------------------------------'
 */
// [_LOWER] = LAYOUT_planck_mit(
//     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
//     KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
//     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
//     _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
// ),
[_LOWER] = LAYOUT_planck_mit(
    KC_ESC,  KC_ESC,  KC_ESC,  KC_ESC,  KC_F5,   _______, _______, KC_F10,  KC_ESC,  KC_ESC,  KC_ESC,  KC_F12,
    _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F11,  KC_F12,  KC_F9,   KC_F8,   KC_F7,   KC_F6,   _______,
    KC_LSFT, COPY,    CUT,     PASTE,   DBL,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   +  |   -  |   *  |   /  |   =  |   4  |   5  |   6  |   -  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | COPY | CUT  |PASTE | FIND | DBL  |   1  |   2  |   3  |   +  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
// [_RAISE] = LAYOUT_planck_mit(
//     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
//     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
//     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
//     _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
// ),
[_RAISE] = LAYOUT_planck_mit(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_EQL,  KC_4,    KC_5,    KC_6,    KC_MINS, KC_EQL,  _______,
    _______, COPY,    CUT,     PASTE,   FIND,    DBL,     KC_1,    KC_2,    KC_3,    KC_PLUS, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Nav (hold 'o')
 *                      v------------------------NAV CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      |   `  |  /   |  \   |  &   |      |pntSrn|pntApp|  ^   |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  +/= |  [   |   {  |  (   |      |      |  <-  |  V   |  ->  |   *  | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |   ]  |   }  |   )  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_mit(
    _______, KC_GRV,  KC_SLSH, KC_BSLS, KC_AMPR, _______, _______, KC_PSCR,  KC_UP, _______, _______, KC_DEL ,
    _______, KC_PLUS, KC_LCBR, KC_LCBR, KC_LPRN, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_MPLY,
    _______, KC_LCTL, KC_RCBR, KC_RCBR,  KC_RPRN, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Read (hold 'm')
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      |  `   |  /   |  \   |  &   |      |      | prnt | pgup |      |      |  del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  =   |  [   |   {  |  (   |      |   *  | home |pgdown|  end |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   ]  |   }  |   )  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_READ] = LAYOUT_planck_mit(
    _______, KC_GRV,  KC_SLSH, KC_BSLS, KC_AMPR, _______, _______, KC_PSCR, KC_PGUP,  _______, _______, KC_DEL ,
    _______, KC_PLUS, KC_LCBR, KC_LCBR, KC_LPRN, _______, KC_TRNS, KC_HOME, KC_PGDN, KC_END, _______, _______,
    _______, KC_LCTL, KC_RCBR, KC_RCBR, KC_RPRN, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),
 */

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); //, _NAV, _READ
}

switch (keycode) {
    case KC_TAB:
      if (record->event.pressed && is_mac_with_base_layer_off()) {
        uint8_t mods = get_mods();
        uint8_t mod_state = mods & MOD_MASK_ALT;
        if (get_mods() & mod_state) {
          del_mods(mod_state);
          add_mods(MOD_LCTL);
          mac_alt_tab_on = true;
        }

        mod_state = mods & MOD_MASK_CTRL;
        if (get_mods() & mod_state && !mac_alt_tab_on) {
          del_mods(mod_state);
          add_mods(MOD_LGUI);
          mac_ctrl_on = true;
        }
      }
      break;
    case KC_LSFT:
      if (record->event.pressed && is_mac_with_base_layer_off()) {
        uint8_t mods = get_mods();
        uint8_t mod_state = mods & MOD_MASK_AG;
        if (get_mods() & mod_state) {
          del_mods(mod_state);
          add_mods(MOD_LGUI);
          mac_gui_on = true;
          SEND_STRING(SS_TAP(X_SPACE));
          return false;
        } else {
          return true;
        }
      }
      break;
    case KC_LEFT:
    case KC_RIGHT:
      if (record->event.pressed && is_mac_with_base_layer_off()) {
        /* && !mac_ctrl_on/!mac_alt_tab_on are required since setting the state while holding the key changes
        the modifier from OS's perspective. As a result, just the pressed key cannot be the single source
        of truth to determine which state we're in, and a separate bool is required */
        uint8_t mods = get_mods();
        uint8_t mod_state = mods & MOD_MASK_ALT;
        //Allows Ctrl <-/-> on Mac if Ctrl Tab is already pressed
        if (get_mods() & mod_state && mac_alt_tab_on && !mac_ctrl_on) {
          del_mods(mod_state);
          add_mods(MOD_LCTL);
        }

        mod_state = mods & MOD_MASK_CTRL;
        if (get_mods() & mod_state && !mac_alt_tab_on) {
          del_mods(mod_state);
          add_mods(MOD_LALT);
          mac_ctrl_on = true;
        }
      }
      break;
    case KC_DEL:
      if (record->event.pressed && is_mac_with_base_layer_off()) {
        uint8_t mod_state = get_mods() & MOD_MASK_CTRL;
        if (get_mods() & mod_state) {
          del_mods(mod_state);
          add_mods(MOD_LALT);
          mac_ctrl_on = true;
        }
      }
      break;
    case KC_LALT:
      if (!record->event.pressed && is_mac_with_base_layer_off()) {
        if (mac_alt_tab_on) {
          unregister_mods(MOD_LCTL);
          mac_alt_tab_on = false;
          return false;
        } else if (mac_gui_on) {
          SEND_STRING(SS_UP(X_LGUI));
          mac_gui_on = false;
          return false;
        }
      }
      break;
    case KC_RALT:
      if (!record->event.pressed && mac_alt_tab_on && is_mac_with_base_layer_off()) {
        unregister_mods(MOD_LCTL);
        mac_alt_tab_on = false;
        return false;
      }
      break;
    case KC_LCTL:
    case KC_RCTL:
      if (!record->event.pressed && mac_ctrl_on && is_mac_with_base_layer_off()) {
        SEND_STRING(SS_UP(X_LGUI) SS_UP(X_LALT));
        mac_ctrl_on = false;
        return false;
      }
      break;

    case KC_HOME:
      if (record->event.pressed && is_mac_with_base_layer_off()) {
        SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));
        return false;
      }
      break;
    case KC_END:
      if (record->event.pressed && is_mac_with_base_layer_off()) {
        SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));
        return false;
      }
      break;
    case KC_BSPC:
      if (record->event.pressed) {
        if (char_to_del > 1) {
          layer_off(GIT_C);
          layer_off(GIT_S);
          backspace_n_times(char_to_del);
          char_to_del = 1;
          return false;
        }

        if (is_mac_with_base_layer_off()) {
          uint8_t mod_state = get_mods() & MOD_MASK_CTRL;
          if (get_mods() & mod_state) {
            del_mods(mod_state);
            add_mods(MOD_LALT);
            mac_ctrl_on = true;
          }
        }
      }
      break;

    /* -------------------------------------------------------------------------
     *                            CUSTOM MACROS
     * ------------------------------------------------------------------------ */
    case CTRL_CTV:
      if (record->event.pressed) {
        if ( get_mods() & MOD_MASK_SHIFT ) {
          clear_mods();
          SEND_STRING(SS_LCTL("ctv"));
        } else {
          SEND_STRING(SS_LCTL("ctv") SS_TAP(X_ENTER));
        }
      }
      break;
    case CTRL_LCTV:
      if (record->event.pressed) {
        if ( get_mods() & MOD_MASK_SHIFT ) {
          //Firefox
          clear_mods();
          SEND_STRING(SS_LCTL("lcP"));
          wait_ms(200);
          SEND_STRING(SS_LCTL("v") SS_TAP(X_ENTER));
        } else if ( get_mods() & MOD_MASK_CTRL ) {
          //Chrome
          clear_mods();
          SEND_STRING(SS_LCTL("lcNv") SS_TAP(X_ENTER));
        } else {
          SEND_STRING(SS_LCTL("lctv"));
        }
      }
      break;
    case CTRL_CAV:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("c" SS_TAP(X_TAB)));
        wait_ms(50);
        SEND_STRING(SS_LCTL("av"));
      }
      break;
    case SARCASM:
      if (record->event.pressed) {
        sarcasm_on = !sarcasm_on;
      }
      break;

    /* -------------------------------------------------------------------------
     *                            OS TOGGLING
     * ------------------------------------------------------------------------ */
    case TOG_OS:
      if (record->event.pressed) {
        is_win = ! is_win;
        led_show_current_os();
      }
      break;
    case CTR_ALT:
      if (record->event.pressed) {
        send_string(key_down[is_win]);
      } else {
        send_string(key_up[is_win]);
      }
      break;
    case OS_CTRL:
      if (is_win) {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTL));
        } else {
          SEND_STRING(SS_UP(X_LCTL));
        }
      } else {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LGUI));
        } else {
          SEND_STRING(SS_UP(X_LGUI));
        }
      }
      break;
    case OS_WIN:
      if (is_win) {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LGUI));
        } else {
          SEND_STRING(SS_UP(X_LGUI));
        }
      } else {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTL));
        } else {
          SEND_STRING(SS_UP(X_LCTL));
        }
      }
      break;

    /* -------------------------------------------------------------------------
     *                            STRING MACROS
     * ------------------------------------------------------------------------ */
    // case :
    //   if (record->event.pressed) {
    //     send_string_remembering_length("");
    //   }
    //   break;
    // case :
    //   if (record->event.pressed) {
    //     send_string_remembering_length("", "");
    //   }
    //   break;
    case TILD_BLOCK:
      if (record->event.pressed) {
        SEND_STRING("```" SS_LSFT(SS_TAP(X_ENTER) SS_TAP(X_ENTER)) "```" SS_TAP(X_UP));
        char_to_del = 4;
      }
      break;
    case ADMINS:
      if (record->event.pressed) {
        send_shifted_strings_add("admin", "/aurora/status");
      }
      break;
    case PRESCRIPTION:
      if (record->event.pressed) {
        SEND_STRING("55\t12122019\t");
        char_to_del = 8;
      }
      break;
    case FOURS:
      if (record->event.pressed) {
        SEND_STRING("4444333322221111\t1\t12\t21\t123\n");
        char_to_del = 16;
      }
      break;
      
  