/*
Copyright 2020 (c) Sergej Kravcenko

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#ifdef OLED_DRIVER_ENABLE
#include <stdio.h>
#endif

#ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum layers {
    _COLEMAK = 0,
    _QWERTY,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _ADJUST
};


enum custom_keycodes {
    RGBRST = SAFE_RANGE
};


#define SPC_LWR LT(_LOWER, KC_SPC)
#define SPC_RSE LT(_RAISE, KC_SPC)
#define TAB_LAL LALT_T(KC_TAB)
#define ENT_FUN LT(_FUNCTION, KC_ENT)
#define ENT_SFT LSFT_T(KC_ENT)
#define ENT_LAL LALT_T(KC_ENT)

#define CL_CUT LCTL(KC_X)
#define CL_COPY LCTL(KC_C)
#define CL_PSTE LCTL(KC_V)
#define CL_UNDO LCTL(KC_Z)

#define ADJUST LT(_ADJUST, KC_NO)
#define RGB_TGL KC_TRNS     
#define DF_QWRT DF(_QWERTY)
#define DF_COLE DF(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT(\
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_ESC, \
    KC_LSFT, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,         KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_RSFT, \
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL, \
                               KC_BSPC, SPC_LWR, ENT_LAL,      ENT_SFT, SPC_RSE, KC_DEL \
),

[_QWERTY] = LAYOUT(\
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ESC, \
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT, \
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL, \
                               KC_BSPC, SPC_LWR, ENT_LAL,      ENT_SFT, SPC_RSE, KC_DEL \
),

[_LOWER] = LAYOUT(\
    _______, KC_LGUI, KC_PGUP, KC_UP,   KC_PGDN, KC_DEL,       KC_ASTR, KC_7,    KC_8,    KC_9,    KC_MINS, _______, \
    _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,       KC_SLSH, KC_4,    KC_5,    KC_6,    KC_PLUS, _______, \
    _______, CL_UNDO, CL_CUT,  CL_COPY, CL_PSTE, KC_CAPS,      KC_EQL,  KC_1,    KC_2,    KC_3,    KC_DOT,  _______, \
                               _______, _______, _______,      _______, _______, KC_0\
),

[_RAISE] = LAYOUT(\
    _______, KC_TILD, KC_EQL,  KC_EXLM, KC_DQUO, KC_QUOT,      KC_ASTR, KC_LBRC, KC_AMPR, KC_RBRC, _______, _______, \
    _______, KC_GRV,  KC_LABK, KC_PERC, KC_RABK, KC_PLUS,      KC_QUES, KC_LPRN, KC_DLR,  KC_RPRN, KC_BSLS, _______, \
    _______, _______, KC_CIRC, KC_AT,   KC_UNDS, KC_MINS,      KC_PIPE, KC_LCBR, KC_HASH, KC_RCBR, _______, _______, \
                               _______, _______, _______,      _______, _______, _______\
),

[_FUNCTION] = LAYOUT(\
    _______, _______, KC_MSTP, KC_VOLU, KC_MPLY, _______,      KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, \
    _______, KC_MPRV, KC_MRWD, KC_MUTE, KC_MFFD, KC_MNXT,      KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, \
    _______, ADJUST,  _______, KC_VOLD, _______, _______,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, \
                               _______, _______, _______,      _______, _______, _______\
),

[_ADJUST] = LAYOUT(\
    _______, _______, _______, _______, _______, RESET,        _______, RGB_HUI, RGB_MOD, RGB_HUD, _______, _______, \
    _______, _______, _______, _______, _______, DF_QWRT,      _______, RGB_VAI, RGB_TOG, RGB_VAD, _______, _______, \
    _______, _______, _______, _______, _______, DF_COLE,      _______, RGB_SPI, RGB_TGL, RGB_SPD, _______, _______, \
                               _______, _______, _______,      _______, _______, _______\
),

};

const rgblight_segment_t PROGMEM rgb_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {42, 12, HSV_RED}
);

const rgblight_segment_t PROGMEM rgb_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {42, 12, HSV_GREEN}
);

const rgblight_segment_t PROGMEM rgb_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {42, 12, HSV_BLUE}
);

const rgblight_segment_t PROGMEM rgb_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {42, 12, HSV_GOLD}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_layer1_layer,
    rgb_layer2_layer,
    rgb_layer3_layer,
    rgb_capslock_layer
);

void keyboard_post_init_user(void) {
    rgblight_set_effect_range(0, 42);

     // Enable the LED layers
    rgblight_layers = my_rgb_layers;

    rgblight_set_layer_state(0, layer_state_cmp(default_layer_state, _COLEMAK));
    rgblight_set_layer_state(1, layer_state_cmp(default_layer_state, _QWERTY));
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(3, led_state.caps_lock);
    return true;
}   

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(default_layer_state, _COLEMAK));
    rgblight_set_layer_state(1, layer_state_cmp(default_layer_state, _QWERTY));

    return update_tri_layer_state(state, _LOWER, _RAISE, _FUNCTION);
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    }
    return rotation;
}

static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0xF8, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x78, 0x78, 
        0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 
        0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFC, 0x1E, 0x06, 
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0xFF, 
        0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xFE, 0x00, 
        0x00, 0x00, 0x00, 0xF8, 0xFC, 0x1E, 0x06, 0x06, 0x06, 0x06, 
        0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 
        0x00, 0xC0, 0xF0, 0xF8, 0x3E, 0x1E, 0x06, 0x02, 0x00, 0x0E, 
        0x7E, 0xFC, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFE, 
        0x7E, 0x0E, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xE0, 0x80, 0x80, 0x80, 
        0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 
        0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 
        0x00, 0x7F, 0xFF, 0xE0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
        0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x03, 0x07, 
        0x1F, 0x3C, 0xF8, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x03, 
        0x1F, 0xFF, 0xF8, 0xC0, 0xF8, 0xFF, 0x1F, 0x03, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xF0, 0xF3, 0xF3, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
        0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 
        0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0x01, 0x01, 0x00, 0x30, 0x30, 0x30, 0x30, 0x38, 
        0x1E, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static char rgblight_mode_line[24] = "";
static void render_status(void) {
    // Host Keyboard Layout Status
    oled_write_P(PSTR("Layout: "), false);
    if (layer_state_cmp(default_layer_state, _QWERTY)) {
        oled_write_P(PSTR("Qwerty\n"), false);
    } else if (layer_state_cmp(default_layer_state, _COLEMAK)) {
        oled_write_P(PSTR("Colemak\n"), false);
    } else {
        oled_write_P(PSTR("Unknown\n"), false);
    }

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("Function\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Default\n"), false);
    }

#ifdef RGBLIGHT_ENABLE
    snprintf(rgblight_mode_line, sizeof(rgblight_mode_line) - 1, 
        "Lights mode: %d", rgblight_config.mode);
    oled_write_ln(rgblight_mode_line, false);
#endif

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_logo();
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          //rgblight_config.mode = 0;
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
  }
  return true;
}
