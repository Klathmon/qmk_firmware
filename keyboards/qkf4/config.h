// Copyright 2022 Gregory Benner (@Klathmon)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100

#define OS_DETECTION_DEBOUNCE 500

// Greg's custom defines
// time between keypresses in KVM related macros (as it misses quicker keypresses)
#define GSB_KVM_DELAY 100
