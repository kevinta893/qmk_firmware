/* Copyright 2020 Kevin Ta
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

// Defines layers for keycodes and keymaps
enum layer_names {
    _PROGRAMMING,
    _GAMING,
};

// Define Macro/Custom keycodes
enum custom_keycodes {
    SWITCH_TO_NEXT_LAYER,
    RGB_MATRIX_TOGGLE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_PROGRAMMING] = LAYOUT(
        KC_ESCAPE,              LCTL(KC_X),         LCTL(KC_C),             LCTL(KC_V),             RGB_MATRIX_TOGGLE,  SWITCH_TO_NEXT_LAYER,
        LGUI(LCTL(KC_F4)),      LGUI(KC_TAB),       LGUI(LCTL(KC_D)),       KC_R,                   KC_R,               KC_R,
        KC_R,                   KC_AUDIO_VOL_UP,    KC_R,                   KC_D,                   KC_R,               KC_R,
        LGUI(LCTL(KC_LEFT)),    KC_AUDIO_VOL_DOWN,  LGUI(LCTL(KC_RIGHT)),   KC_MEDIA_PLAY_PAUSE,    KC_NO,              KC_ENTER
    ),
    [_GAMING] = LAYOUT(
        KC_ESCAPE,              LCTL(KC_X),         LCTL(KC_C),             LCTL(KC_V),             RGB_MATRIX_TOGGLE,  SWITCH_TO_NEXT_LAYER,
        LGUI(LCTL(KC_F4)),      LGUI(KC_TAB),       LGUI(LCTL(KC_D)),       KC_R,                   KC_R,               KC_R,
        KC_R,                   KC_AUDIO_VOL_UP,    KC_R,                   KC_D,                   KC_R,               KC_R,
        LGUI(LCTL(KC_LEFT)),    KC_AUDIO_VOL_DOWN,  LGUI(LCTL(KC_RIGHT)),   KC_MEDIA_PLAY_PAUSE,    KC_NO,              KC_ENTER
    )
};

bool rgb_matrix_enable_state = true;



bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // Custom keycodes
    switch (keycode) {
        case RGB_MATRIX_TOGGLE:
            if (!record->event.pressed) {
                if (rgb_matrix_enable_state){
                    rgb_matrix_disable_noeeprom();
                    rgb_matrix_enable_state = false;
                } else {
                    rgb_matrix_enable_noeeprom();
                    rgb_matrix_enable_state = true;
                }
            }
            break;
        case SWITCH_TO_NEXT_LAYER:
            break;
    }

    // Layer switching
    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case _PROGRAMMING:
            rgb_matrix_sethsv_noeeprom(0, 255, 150);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            break;
        case _GAMING:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
            break;
    }

    return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

void keyboard_post_init_user(void) {
  rgb_matrix_enable_noeeprom();
  rgb_matrix_sethsv_noeeprom(0, 255, 150);
  rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
  rgb_matrix_enable_state = true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
