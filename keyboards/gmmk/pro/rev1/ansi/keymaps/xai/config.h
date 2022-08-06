/* Copyright 2021 Xeon Xai <xeokeri@gmail.com>
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

#pragma once

#define NO_USB_STARTUP_CHECK

// https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix#additional-config-h-options-id-additional-configh-options
#ifdef RGB_MATRIX_ENABLE
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    #define RGB_DISABLE_TIMEOUT 120000 // 2 minutes (2 * 60 * 1000ms)

    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR

    #define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#endif
