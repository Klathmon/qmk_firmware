/* Copyright 2023 Gregory Benner
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

#define GREEN_LED LED1
#define RED_LED LED2

#undef USB_MAX_POWER_CONSUMPTION
#define USB_MAX_POWER_CONSUMPTION 350

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100

#define OS_DETECTION_DEBOUNCE 500

// Greg's custom defines
// time between keypresses in KVM related macros (as it misses quicker keypresses)
#define GSB_KVM_DELAY 100
