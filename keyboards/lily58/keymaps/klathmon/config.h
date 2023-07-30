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

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100
#define USB_POLLING_INTERVAL_MS 5

#define MK_3_SPEED
#define MK_W_OFFSET_UNMOD 16
#define MK_W_INTERVAL_UNMOD 40

// Encoders
#ifndef ENCODERS_PAD_A
#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F4 }
#endif

// RGB Lighting Changes
#define RGBLIGHT_SLEEP
#define RGBLIGHT_DEFAULT_VAL 15
