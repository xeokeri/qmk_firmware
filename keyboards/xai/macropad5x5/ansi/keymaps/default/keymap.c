/* Copyright 2022 Xeon Xai <xeokeri@gmail.com>

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

enum my_keycodes {
    KC_MCON = SAFE_RANGE, // KC_MISSION_CONTROL
    KC_LPAD // KC_LAUNCH_PAD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        _______, _______, KC_MPLY, _______, KC_MUTE,
        _______, _______, _______, _______, MO(1),
        KC_7,    KC_8,    KC_9,    _______, KC_PGUP,
        KC_4,    KC_5,    KC_6,    _______, KC_PGDN,
        KC_1,    KC_2,    KC_3,    _______, KC_HOME,
        KC_0,    KC_0,    KC_DOT,  _______, KC_END
    ),

    [1] = LAYOUT(
        _______, _______, _______, _______, _______,
        RGB_TOG, _______, _______, _______, _______,
        _______, RGB_HUI, RGB_SAI, RGB_VAI, _______,
        _______, RGB_HUD, RGB_SAD, RGB_VAD, _______,
        _______, _______, RGB_MOD, _______, _______,
        _______, RGB_SPD, RGB_RMOD,RGB_SPI, RESET
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MCON:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }

            return false; /* Skip all further processing of this key */

        case KC_LPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }

            return false; /* Skip all further processing of this key */

        default:
            return true; /* Process all other keycodes normally */
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
    case 0:
        if (clockwise) {
            tap_code(KC_BRID);
        } else {
            tap_code(KC_BRIU);
        }
    case 1:
        if (clockwise) {
            tap_code(KC_BRMD);
        } else {
            tap_code(KC_BRMU);
        }
    case 2:
        if (clockwise) {
            tap_code(KC_MRWD);
        } else {
            tap_code(KC_MFFD);
        }
    case 3:
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    case 4:
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    default:
        break;
    }

    return true;
}
