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
    SWITCH_TO_NEXT_LAYER = SAFE_RANGE,
    MY_STRING_MACRO_1
};

// Layers for keycodes and keymaps
enum layer_names {
    _PROGRAMMING,
    _BIOS_NAV,
	_BASIC_ENTRY,
    _FIDGET
};

// Layers in order of next layer order
#define LAYER_COUNT 4
const uint8_t layer_list_user[LAYER_COUNT] = {
    _PROGRAMMING,
	_BIOS_NAV,
	_BASIC_ENTRY,
    _FIDGET
};

// Key Maps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_PROGRAMMING] = LAYOUT(
        KC_ESCAPE,              LCTL(KC_X),         LCTL(KC_C),             LCTL(KC_V),             KC_F9,              SWITCH_TO_NEXT_LAYER,
        KC_NO,                  LGUI(KC_TAB),       LGUI(LCTL(KC_D)),       KC_F10,                 KC_UP,              KC_DELETE,
        LGUI(LCTL(KC_LEFT)),    KC_AUDIO_VOL_UP,    LGUI(LCTL(KC_RIGHT)),   KC_LEFT,                KC_DOWN,            KC_RIGHT,
        KC_MEDIA_PREV_TRACK,    KC_AUDIO_VOL_DOWN,  KC_MEDIA_NEXT_TRACK,    KC_MEDIA_PLAY_PAUSE,              KC_ENTER
    ),
	[_BIOS_NAV] = LAYOUT(
        KC_ESCAPE,              KC_DELETE,          KC_F9,             	    KC_F10,                 KC_F11,             SWITCH_TO_NEXT_LAYER,
        KC_1,                   KC_2,               KC_3,                   KC_N,                   KC_UP,              KC_Y,
        KC_4,                   KC_5,               KC_6,                   KC_LEFT,                KC_DOWN,            KC_RIGHT,
        KC_7,                   KC_8,               KC_9,                   KC_NO,                  KC_ENTER
	),
	[_BASIC_ENTRY] = LAYOUT(
        KC_ESCAPE,              KC_BACKSPACE,       KC_AT,             	    KC_HASH,                KC_DOLLAR,          SWITCH_TO_NEXT_LAYER,
        KC_A,                   KC_B,               KC_C,                   KC_1,                   KC_2,               KC_3,
        KC_D,                   KC_E,               KC_F,                   KC_S,                   KC_T,               KC_NO,
        KC_G,                   KC_H,               KC_I,                   KC_LSFT,                KC_ENTER
	),
    [_FIDGET] = LAYOUT(
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      SWITCH_TO_NEXT_LAYER,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO
        KC_NO,      KC_NO,      KC_NO,      KC_NO,                  KC_NO
    )
};

// State variables
uint8_t current_key_layer_index_user = 0;


/*
 * Moves directly to the specified layer
 */
void go_to_key_layer_user(uint8_t go_to_layer){

    // Setup layer
    switch (go_to_layer) {
        case _PROGRAMMING:
            break;
		case _BIOS_NAV:
            break;
		case _BASIC_ENTRY:
            break;
        case _FIDGET:
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
 * Process custom key code events
 */ 
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case SWITCH_TO_NEXT_LAYER:
            // Switch to next layer
            if (!(record->event.pressed)) {
                // Key Up
                go_to_next_key_layer_user();
            }
            break;
        case MY_STRING_MACRO_1:
            if (!(record->event.pressed)) {
                // Key Up
                SEND_STRING("sudo ufw disable");
            }
            break;
    }

    return true;
}

/*
 * Initialization after keyboard finishes startup
 */
void keyboard_post_init_user(void) {
    go_to_key_layer_user(layer_list_user[0]);
}
