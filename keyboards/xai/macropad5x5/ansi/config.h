/*
Copyright 2022 Xeon Xai <xeokeri@gmail.com>

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

#pragma once

#include "config_common.h"

#define VENDOR_ID 0xFFFF
#define PRODUCT_ID 0x7878
#define DEVICE_VER 0x0001
#define MANUFACTURER "Xeon Xai"
#define PRODUCT "MacroPad 5x5"

#define MATRIX_ROWS 6
#define MATRIX_COLS 5

#define MATRIX_ROW_PINS { A6, B2, A1, A3, A2, A4 }
#define MATRIX_COL_PINS { A5, A0, B9, B8, B0 }

#define ENCODERS_PAD_A { B13, B15, B4, B6, B1 }
#define ENCODERS_PAD_B { B12, B14, B3, B5, B7 }

#define DIODE_DIRECTION COL2ROW

#define QMK_KEYS_PER_SCAN 4

#define DEBOUNCE 5

#ifdef NKRO_ENABLE
#define FORCE_NKRO
#endif

#define SPI_DRIVER SPID1

#define DRIVER_LED_TOTAL 25
#define RGB_DI_PIN A7
#ifdef RGB_DI_PIN
   #define RGBLED_NUM 25
#endif

// https://docs.qmk.fm/#/feature_rgb_matrix?id=additional-configh-options
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_TYPING_HEATMAP

// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
