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

#include "oled.c"

#include "bloq.h"

enum layers {
    THOK_LAYER_0 = 0,
    THOK_LAYER_1,
    THOK_LAYER_2,
    THOK_LAYER_3,
    THOK_LAYER_4,
    THOK_LAYER_R // `Reset` layer
};


// Adobe Shortcuts - Windows
#define COPY    LCTL(KC_C)
#define CUT     LCTL(KC_X)
#define PASTE   LCTL(KC_V)
#define PPASTE  LCTL(LSFT(KC_V))
#define REDO    LCTL(LSFT(KC_Z))
#define UNDO    LCTL(KC_Z)


#if defined(ENCODER_ENABLE)
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [THOK_LAYER_0] = { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) },
    [THOK_LAYER_1] = { ENCODER_CCW_CW(KC_PGDN,  KC_PGUP) },
    [THOK_LAYER_2] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
    [THOK_LAYER_3] = { ENCODER_CCW_CW(RGB_HUD,  RGB_HUI) },
    [THOK_LAYER_4] = { ENCODER_CCW_CW(RGB_VAD,  RGB_VAI) },
    [THOK_LAYER_R] = { ENCODER_CCW_CW(_______,  _______) }
};
#else
bool encoder_update_user(uint8_t index, bool clockwise) {
    uprintf("hello");
    
    switch (get_highest_layer(layer_state | default_layer_state)) {
    case THOK_LAYER_0:
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    case THOK_LAYER_1:
        if (clockwise) {
            tap_code(KC_PGDP);
        } else {
            tap_code(KC_PGUN);
        }
    case THOK_LAYER_2:
        #ifdef RGBLIGHT_ENABLE
        if (clockwise) {
            rgblight_step();
        } else {
            rgblight_step_reverse();
        }
        #endif
    case THOK_LAYER_3:
        #ifdef RGBLIGHT_ENABLE
        if (clockwise) {
            rgblight_increase_hue();
        } else {
            rgblight_decrease_hue();
        }
        #endif
    case THOK_LAYER_4:
        #ifdef RGBLIGHT_ENABLE
        if (clockwise) {
            rgblight_increase_val();
        } else {
            rgblight_decrease_val();
        }
        #endif
    default:
        break;
    }

    return true;
}
#endif
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [THOK_LAYER_0] = LAYOUT(
                          TO(THOK_LAYER_1),
        KC_VOLD,  KC_UP,   KC_VOLU,
        KC_LEFT,  KC_MPLY, KC_RGHT,
        KC_MPRV,  KC_DOWN, KC_MNXT
    ),
    [THOK_LAYER_1] = LAYOUT(
                            TO(THOK_LAYER_2),
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [THOK_LAYER_2] = LAYOUT(
                            TO(THOK_LAYER_3),
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [THOK_LAYER_3] = LAYOUT(
                          TO(THOK_LAYER_4),
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [THOK_LAYER_4] = LAYOUT(
                          TO(THOK_LAYER_0),
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, MO(5),   XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [THOK_LAYER_R] = LAYOUT (
                          QK_BOOT,
      XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX
    )
};

#define LABEL_TIMEOUT 2000
#define STARTUP_TIMEOUT 10000

uint16_t startup_timer;
bool startup = true;

uint16_t key_pressed, key_pos, key_state[10];

uint16_t layer_timer;
bool show_label = false;
void keyboard_post_init_user(void) {
  // Start startup timer
  startup_timer = timer_read();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  set_single_persistent_default_layer(0);
  // Convert key row, column and whether pressed into an array
  key_pressed = record->event.pressed;
  key_pos = record->event.key.col;
  if (record->event.key.row != 0) { key_pos += record->event.key.row * 3 - 2; }

  key_state[key_pos] = key_pressed;

  // Layer change label timer
  if (key_state[0] == 1) {
    layer_timer = timer_read();
    show_label = true;
  }

#ifdef RGB_MATRIX_ENABLED
  // Toggle white or color (Layer 4, Middle Top)
  if (get_highest_layer(layer_state | default_layer_state) == 4 && key_state[2] == 1) {
    if (rgb_matrix_get_sat() == 255) {
      rgb_matrix_sethsv(rgb_matrix_get_hue(), 0, rgb_matrix_get_val());
    } else {
      rgb_matrix_sethsv(rgb_matrix_get_hue(), 255, rgb_matrix_get_val());
    }
  }
#endif

  // Skip startup if keypress
  if (startup) {
    startup = false;

    #ifdef OLED_ENABLE
    oled_clear();
    #endif
  }

  return true;
}

// OLED
#ifdef OLED_ENABLE

// OLED Rotations
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_90;
}

static void render_status(void) {
  // Left Section
  render_oled_bloq_brand();
  render_oled_layers();

  // Mid Section
  if (show_label == true && timer_elapsed(layer_timer) < LABEL_TIMEOUT) {
    render_oled_show_labels();
  } else {
    render_oled_idle();
    show_label = false;
  }

  // Right Section
  render_oled_indicator(key_state);
}

bool oled_task_user(void) {
  // Startup timer ends
  if (startup && timer_elapsed(startup_timer) > STARTUP_TIMEOUT) {
    startup = false;
    oled_clear();
  }

  if (startup) {
    // If the number of seconds on the timer is odd, show pattern
    render_startup((((timer_elapsed(startup_timer) / 1000) % 2) != 1));
  } else {
    render_status();
  }
  
  return false;
}

#endif
