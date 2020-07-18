/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100

// Encoders
#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F4 }

// Replace the lily58 font with my custom one
#undef OLED_FONT_H
#define OLED_FONT_H "qmk_hid_custom_font.c"

#define HID_SECONDARY_SCREEN_ENABLE
#define SERIAL_SCREEN_BUFFER_LENGTH (/*SSD1306_MatrixCols*/ 21 * /*SSD1306_MatrixRows*/ 4 + /*Extra IsEnabledBit*/ 1)
