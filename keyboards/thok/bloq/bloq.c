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

#include "bloq.h"
enum layers {
    THOK_LAYER_0 = 0,
    THOK_LAYER_1 = 1,
    THOK_LAYER_2 = 2,
    THOK_LAYER_3 = 3,
    THOK_LAYER_4 = 4,
    THOK_LAYER_RESET = 5
};

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = { {
    // Key Matrix to LED Index
    { NO_LED, NO_LED, NO_LED  },
    { 0,  1,  2 },
    { 3,  4 , 5 },
    { 6,  7,  8 }
}, {
    // LED Index to Physical Position
    { 0,  0 }, { 112,  0 }, { 224,  0 },
    { 0, 32 }, { 112, 32 }, { 224, 32 },
    { 0, 64 }, { 112, 64 }, { 224, 64 }
}, {
    // LED Index to Flag
    4, 4, 4,
    4, 4, 4,
    4, 4, 4
} };

#endif
