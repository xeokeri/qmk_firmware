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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┐
     * │ o │ o │ o │ o │ o │
     * ├───┼───┼───┼───┼───┤
     * │ + │ + │ + │ + │ + │
     * ├───┼───┼───┼───┼───┤
     * │ + │ + │ + │ + │ + │
     * ├───┼───┼───┼───┼───┤
     * │ + │ + │ + │ + │ + │
     * ├───┼───┼───┼───┼───┤
     * │ + │ + │ + │ + │ + │
     * ├───┼───┼───┼───┼───┤
     * │ + │ + │ + │ + │ + │
     * └───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_5x5(
        _______, _______, KC_MPLY, _______, KC_MUTE,
        _______, _______, _______, _______, MO(1),
        KC_7,    KC_8,    KC_9,    _______, KC_PGUP,
        KC_4,    KC_5,    KC_6,    _______, KC_PGDN,
        KC_1,    KC_2,    KC_3,    _______, KC_HOME,
        KC_0,    KC_0,    KC_DOT,  _______, KC_END
    ),
    [1] = LAYOUT_5x5(
        _______, _______, _______, _______, _______,
        RGB_TOG, _______, _______, _______, _______,
        _______, RGB_HUI, RGB_SAI, RGB_VAI, _______,
        _______, RGB_HUD, RGB_SAD, RGB_VAD, _______,
        _______, _______, RGB_MOD, _______, _______,
        _______, RGB_SPD, RGB_RMOD,RGB_SPI, RESET
    ),
};

void keyboard_post_init_user() {
    // // Read the user config from EEPROM
    // user_config.raw = eeconfig_read_user();

    //   // Set default layer, if enabled
    // if (user_config.rgb_layer_change) {
    //     rgblight_enable_noeeprom();
    //     rgblight_sethsv_noeeprom(HSV_CYAN);
    //     rgblight_mode_noeeprom(1);
    // }

    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;

    print("keyboard_post_init_user");

    // TODO: Add in support to save the settings for RGB to the EEPROM, on startup if they don't yet exist.
    // TODO: Add in support to save the settings for RGB to the EEPROM, on value change.
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // switch (keycode) {
    //     case KC_MCTL:
    //         if (record->event.pressed) {
    //             host_consumer_send(0x29F);
    //         } else {
    //             host_consumer_send(0);
    //         }

    //         return false; /* Skip all further processing of this key */

    //     case KC_LPAD:
    //         if (record->event.pressed) {
    //             host_consumer_send(0x2A0);
    //         } else {
    //             host_consumer_send(0);
    //         }

    //         return false; /* Skip all further processing of this key */

    //     default:
    //         return true; /* Process all other keycodes normally */
    // }

    return true;


}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {
        ENCODER_CCW_CW(KC_BRIU, KC_BRID),
        ENCODER_CCW_CW(KC_BRMD, KC_BRMU),
        ENCODER_CCW_CW(KC_MRWD, KC_MFFD),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
    },
    [1] = {
        ENCODER_CCW_CW(KC_BRIU, KC_BRID),
        ENCODER_CCW_CW(KC_BRMD, KC_BRMU),
        ENCODER_CCW_CW(KC_MRWD, KC_MFFD),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
    },
};

#else

bool encoder_update_user(uint8_t index, bool clockwise) {

    printf("encoder_update_user: %d, clockwise: %s\n", index, clockwise == true ? "true" : "false");

    switch (index) {
    case 0:
        if (clockwise) {
            tap_code(KC_BRIU);
        } else {
            tap_code(KC_BRID);
        }

        break;
    case 1:
        if (clockwise) {
            tap_code(KC_BRMU);
        } else {
            tap_code(KC_BRMD);
        }

        break;
    case 2:
        if (clockwise) {
            tap_code(KC_MFFD);
        } else {
            tap_code(KC_MRWD);
        }

        break;
    case 3:
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }

        break;
    case 4:
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
        break;
    default:
        break;
    }

    return false;
}
#endif
