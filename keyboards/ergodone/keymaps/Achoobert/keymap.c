#include QMK_KEYBOARD_H
#include "version.h"

// to build
// from inside wsl2 is better?
// qmk compile -kb ergodone -km Achoobert

// activate the hardware's writable mode with rightmost key of left side
// https://github.com/qmk/qmk_firmware/blob/master/keyboards/ergodone/readme.md
// need old ".\hid_bootloader_cli.exe"
// ./hid_bootloader_cli.exe -mmcu=atmega32u4 ergodone_Achoobert.hex

// TODO gaming layer
// TODO nav layer
// Done! print screen


#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define GAME 3 // qerty gaming layout

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  WIN_TAB_LEFT = SAFE_RANGE,
  WIN_TAB_RIGHT = SAFE_RANGE,
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   F  |   P  |   B  |  L1  |           | Game |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   I  |O / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | `/Symb |Z/Ctrl|X/Ctrl|C/Alt |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |lGAME |  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|LShift|------|       |------|  Tab   |Enter |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   WIN_TAB_LEFT,
        KC_DEL,         KC_Q,         KC_W,   KC_F,   KC_P,   KC_B,   TG(SYMB),
        KC_BSPC,        KC_A,         KC_R,   KC_S,   KC_T,   KC_G,
        LT(SYMB,KC_GRV),        CTL_T(KC_Z),  CTL_T(KC_X),   ALT_T(KC_C),   KC_D,   KC_V,   ALL_T(KC_NO),
        TG(GAME),KC_QUOT,      LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
                                              ALT_T(KC_APP),  KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_LSFT,KC_END,
        // right hand
             WIN_TAB_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(GAME),    KC_J,   KC_L,  KC_U,   KC_Y,   LT(MDIA,KC_SCLN), KC_BSLS,
                          KC_M,   KC_N,  KC_E,   KC_I,   LT(MDIA,KC_O),   GUI_T(KC_QUOT),
             MEH_T(KC_NO),KC_K,   KC_H,  KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                                  KC_UP, KC_DOWN,KC_LBRC,KC_RBRC,          TT(SYMB),
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |   "  |   '  |      |       |      |   (  |  {   |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *//* Keymap 1: experiment Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   *  |   /  |   \  |   &  |  ~   |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   |  |   [  |   {  |   (  |      |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ]  |   }  |   )  |      |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |   "  |   '  |      |       |      |   (  |  {   |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
          EPRM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               KC_QUOT,KC_QUOT,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, KC_LPRN, KC_LCBR
),
/* Keymap 2: Media and mouse keys
 *
 * ,---------------------------------------------------.          ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |          |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|          |------+------+------+------+------+------+--------|
 * |         |   `  |   /  |   \  |   &  |      |      |          |      |      |Prntsc|   ^  |      |      |        |
 * |---------+------+------+------+------+------|      |          |      |------+------+------+------+------+--------|
 * |         |   =  |   [  |   {  |   (  |      |------|          |------|      |   <  |   v  |   >  |      |  Play  |
 * |---------+------+------+------+------+------|      |          |      |------+------+------+------+------+--------|
 * |         | ctrl |   ]  |   }  |   )  |      |      |          |      |      |      | Prev | Next |      |        |
 * `---------+------+------+------+------+-------------'          `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                      |VolUp |VolDn | Mute |      |      |
 *   `-----------------------------------'                                      `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5, _______,
       _______, KC_GRV,  KC_SLSH, KC_BSLS, KC_AMPR, _______, _______,
       _______, KC_EQL, KC_LCBR, KC_LBRC, KC_LPRN, _______,
       _______, KC_LCTL, KC_RCBR, KC_RBRC,  KC_RPRN, _______, _______,
       KC_TRNS, _______, _______, _______, _______,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_PSCR,  KC_UP,   _______, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_LEFT,  KC_DOWN, KC_RIGHT, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS,  KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU,  KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, _______, KC_WBAK
),

/* Keymap 0: Gaming layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Ctrl  |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |togOff|  '"  |  Alt | Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|lShift|------|       |------|  Tab   |Enter |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[GAME] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,          KC_3,          KC_4,     KC_5,   KC_TRNS,
        KC_TAB,         KC_Q,         KC_W,          KC_E,          KC_R,     KC_T,   KC_TRNS,
        KC_BSPC,        KC_A,         KC_S,          KC_D,          KC_F,     KC_G,
        KC_LCTL,        CTL_T(KC_Z),  CTL_T(KC_X),   ALT_T(KC_C),   KC_V,     KC_B,   KC_TRNS,
        KC_TRNS,        KC_QUOT,      KC_LALT,       KC_LEFT,       KC_RGHT,
                                               KC_TRNS,  KC_TRNS,
                                                              KC_TRNS,
                                               KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             KC_TRNS,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_EQL,
             KC_TRNS,     KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,   KC_J,  KC_K,   KC_L,   LT(MDIA, KC_SCLN),GUI_T(KC_QUOT),
             KC_TRNS,     KC_N,   KC_M,  KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_TRNS,
                                  KC_UP, KC_DOWN,KC_LBRC,KC_RBRC,          KC_TRNS,
             KC_TRNS,   CTL_T(KC_ESC),
             KC_TRNS,
             KC_TRNS,   KC_TRNS,        KC_TRNS
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
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP ".colemac with qwrty gaming layer @ " QMK_VERSION);
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
    case WIN_TAB_LEFT:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_LGui);
        tap_code(KC_LEFT);
        unregister_code(KC_LCTL);
        unregister_code(KC_LGui);
      }
      return false;
      break;
    case WIN_TAB_RIGHT:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        tap_code(KC_RIGHT);
        register_code(KC_LGui);
        unregister_code(KC_LCTL);
        unregister_code(KC_LGui);
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
