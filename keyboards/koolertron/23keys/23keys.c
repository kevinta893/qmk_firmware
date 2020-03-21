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

#include "23keys.h"

led_config_t g_led_config = {
    {
        //Key Matrix to LED matrix
        { 0,  1,  2,  3 },
        { 4,  5,  6,  7 },
        { 8,  9, 10, 11 },
        { 12, 13, 14, 15 },
        { 16, 17, 18, NO_LED },
        { 19, 20, 21, 22 }
    }, {
        //LED Matrix to Physical Position (positions rounded)
        {   0,   0 }, {  75,   0 }, { 149,   0 }, { 224,   0 },
        {   0,  13 }, {  75,  13 }, { 149,  13 }, { 224,  13 },
        {   0,  26 }, {  75,  26 }, { 149,  26 }, { 224,  26 },
        {   0,  38 }, {  75,  38 }, { 149,  38 }, { 224,  38 },
        {   0,  51 }, {  75,  51 }, { 149,  51 }, 
        {   0,  64 }, {  75,  64 }, { 149,  64 }, { 224,  45 }
    }, {
        //LED Index to lighting type flag
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, 
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT
    }
};

/*
void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up
    rgblight_mode(RGBLIGHT_EFFECT_RAINBOW_SWIRL);
    matrix_init_user();
}

void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)

    matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // put your per-action keyboard code here
    // runs for every action, just before processing by the firmware

    return process_record_user(keycode, record);
}

bool led_update_kb(led_t led_state) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

    return led_update_user(led_state);
}
*/
