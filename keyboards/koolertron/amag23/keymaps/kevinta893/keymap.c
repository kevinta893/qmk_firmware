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

// Macro/Custom keycodes
enum custom_keycodes {
    SWITCH_TO_NEXT_LAYER,
    RGB_MATRIX_TOGGLE,
};

// Layers for keycodes and keymaps
enum layer_names {
    _PROGRAMMING,
    _GAMING,
};

// Layers in order of next layer order
#define LAYER_COUNT 2
const uint8_t layer_list_user[LAYER_COUNT] = {
    _PROGRAMMING,
    _GAMING
};

// Key Maps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_PROGRAMMING] = LAYOUT(
        KC_ESCAPE,              LCTL(KC_X),         LCTL(KC_C),             LCTL(KC_V),             RGB_MATRIX_TOGGLE,  SWITCH_TO_NEXT_LAYER,
        LGUI(LCTL(KC_F4)),      LGUI(KC_TAB),       LGUI(LCTL(KC_D)),       KC_R,                   KC_R,               KC_R,
        LGUI(LCTL(KC_LEFT)),    KC_AUDIO_VOL_UP,    LGUI(LCTL(KC_RIGHT)),   KC_D,                   KC_R,               KC_R,
        KC_MEDIA_NEXT_TRACK,    KC_AUDIO_VOL_DOWN,  KC_MEDIA_NEXT_TRACK,    KC_MEDIA_PLAY_PAUSE,    KC_NO,              KC_ENTER
    ),
    [_GAMING] = LAYOUT(
        KC_ESCAPE,              LCTL(LSFT(KC_F1)),  LCTL(LSFT(KC_F2)),      LCTL(LSFT(KC_F3)),      RGB_MATRIX_TOGGLE,  SWITCH_TO_NEXT_LAYER,
        KC_R,                   LALT(KC_F10),       KC_R,                   LALT(KC_F9),            LSFT(KC_TAB),       KC_R,
        KC_R,                   KC_AUDIO_VOL_UP,    KC_R,                   KC_D,                   KC_F12,             KC_R,
        KC_MEDIA_PREV_TRACK,    KC_AUDIO_VOL_DOWN,  KC_MEDIA_NEXT_TRACK,    KC_MEDIA_PLAY_PAUSE,    KC_NO,              LALT(KC_F1)
    )
};

// State variables
bool rgb_matrix_enable_state_user = true;
uint8_t current_key_layer_index_user = 0;


/*
 * Moves directly to the specified layer
 */
void go_to_key_layer_user(uint8_t go_to_layer){

    // Setup layer
    switch (go_to_layer) {
        case _PROGRAMMING:
            rgb_matrix_sethsv_noeeprom(0, 255, 150);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            break;
        case _GAMING:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_LEFT_RIGHT);
            break;
    }

    layer_move(go_to_layer);
}

/*
 * Moves directly to the next layer, loops back
 */ 
void go_to_next_key_layer_user(void){
    current_key_layer_index_user = (uint8_t) ((current_key_layer_index_user + 1) % LAYER_COUNT);
    uint8_t next_layer = layer_list_user[current_key_layer_index_user];

    go_to_key_layer_user(next_layer);
}

/*
 * Toggles lighting on/off, no eeprom set
 */ 
void toggle_rgb_matrix_on_off_user(void){
    if (rgb_matrix_enable_state_user){
        rgb_matrix_disable_noeeprom();
        rgb_matrix_enable_state_user = false;
    } else {
        rgb_matrix_enable_noeeprom();
        rgb_matrix_enable_state_user = true;
    }
}

/*
 * Process custom key code events
 */ 
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case RGB_MATRIX_TOGGLE:
            // Turn on or off RGB lighting
            if (!(record->event.pressed)) {
                // Key up
                toggle_rgb_matrix_on_off_user();
            }
            break;
        case SWITCH_TO_NEXT_LAYER:
            // Switch to next layer
            if (!(record->event.pressed)) {
                // Key Up
                go_to_next_key_layer_user();
            }
            break;
    }

    return true;
}

/*
 * Initialization after keyboard finishes startup
 */
void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    go_to_key_layer_user(layer_list_user[0]);
}
