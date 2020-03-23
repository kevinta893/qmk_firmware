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
    _BASE
};

// Define Macro/Custom keycodes
enum custom_keycodes {
    WIN_NEXT_DESKTOP_RIGHT,
    WIN_NEXT_DESKTOP_LEFT,
    WIN_NEXT_DESKTOP_INDEX,
    WIN_NEXT_DESKTOP_NEW,
    WIN_NEXT_DESKTOP_CLOSE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESCAPE, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_4, RGB_TOG,
        LGUI(LCTL(KC_F4)), LGUI(KC_TAB), LGUI(LCTL(KC_D)), KC_E, KC_R, RGB_MODE_FORWARD,
        LGUI(LCTL(KC_LEFT)), KC_AUDIO_VOL_UP, LGUI(LCTL(KC_RIGHT)), KC_D, RGB_VAD, RGB_MODE_REVERSE,
        KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE, KC_NO, KC_ENTER
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
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
