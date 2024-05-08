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

// only using 8 layers so we can fit it in 8 bits
#define LAYER_STATE_8BIT

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100
#define USB_POLLING_INTERVAL_MS 5

#define MK_3_SPEED
#define MK_W_OFFSET_UNMOD 16
#define MK_W_INTERVAL_UNMOD 40

#define OS_DETECTION_DEBOUNCE 500
// #define ENABLE_COMPILE_KEYCODE

// Encoders
#ifndef ENCODERS_PAD_A
#    define ENCODERS_PAD_A \
        { F5 }
#    define ENCODERS_PAD_B \
        { F4 }
#endif

// RGB Lighting Changes
#define RGBLIGHT_SLEEP
#define RGBLIGHT_DEFAULT_VAL 15

// Dynamic Macros
#define DYNAMIC_MACRO_NO_NESTING
#define DYNAMIC_MACRO_SIZE 128

// OLED
#define OLED_BRIGHTNESS 64 // start out with lowest brightness
#define OLED_TIMEOUT 15000
#define SPLIT_OLED_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_TRANSPORT_MIRROR

// Greg's custom defines
// time between keypresses in KVM related macros (as it misses quicker keypresses)
#define GSB_KVM_DELAY 100
// invert the OLED for one frame every time a key is pressed, helps with burnin
#define GSB_FLASH_INVERT_ON_KEYPRESS

// if defined, the rotary encode will move the left/right screens through the possible options in the KVM
// #define GSB_HYPER_KVM_ROTARY

// if defined, the mac/windows logo will be displayed for each mode. when undef, the lily58 logo will be below the layer info line
// #define GSB_LAYER_LOGO
