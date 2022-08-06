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

#include "ansi.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = { {
    // Key Matrix to LED Index
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    {  0,  1,  2,  3,  4 },
    {  5,  6,  7,  8,  9 },
    { 10, 11, 12, 13, 14 },
    { 15, 16, 17, 18, 19 },
    { 20, 21, 22, 23, 24 }
}, {
    // LED Index to Physical Position
    // NO LEDS on the rotaty encoder rows.
    /*
    { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }
    */
    { 1, 0 }, { 1, 1 }, { 1, 2 }, { 1, 3 }, { 1, 4 },
    { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 2, 4 },
    { 3, 0 }, { 3, 1 }, { 3, 2 }, { 3, 3 }, { 3, 4 },
    { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 }, { 4, 4 },
    { 5, 0 }, { 5, 1 }, { 5, 2 }, { 5, 3 }, { 5, 4 }
}, {
    // LED Index to Flag
    // NOTE: No LED flags for the encoders
    /*
    1, 1, 1, 1, 1,
    */
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
} };

#endif
