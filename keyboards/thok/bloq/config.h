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


#define MATRIX_ROWS 4
#define MATRIX_COLS 3

#define MATRIX_ROW_PINS { D3, D4, D5, F4 }
#define MATRIX_COL_PINS { F1, F0, D6 }
#define UNUSED_PINS

#define ENCODERS_PAD_A { B4 }
#define ENCODERS_PAD_B { B5 }

#define DIODE_DIRECTION COL2ROW

#define QMK_KEYS_PER_SCAN 4

#define DEBOUNCE 5

#ifdef NKRO_ENABLE
#define FORCE_NKRO
#endif


// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN

#define OLED_TIMEOUT 10000
#define OLED_FONT_H "keyboards/thok/bloq/glcdfont.c"
