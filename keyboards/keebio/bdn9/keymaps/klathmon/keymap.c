/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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
#include QMK_KEYBOARD_H

#define TAP_CODE_DELAY 10

#define SEND_EMOJI_CODE(CODE) register_code(KC_RALT); tap_code(KC_U); SEND_STRING(CODE); tap_code(KC_ENTER); unregister_code(KC_RALT); sent_buffer++

enum my_keycodes {
  ENABLE_SELECTOR = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        ENABLE_SELECTOR, LGUI(KC_L), KC_MUTE,
        KC_MPRV, KC_MPLY, KC_MNXT,
        LCTL(KC_Z), LCTL(LSFT(KC_X)), LCTL(KC_Y)
    )
};

bool selector_enabled = false;
uint8_t selected_item = 0;
uint8_t sent_buffer = 0;

void send_selected_item (void) {
  switch (selected_item) {
    case 1:
      SEND_EMOJI_CODE("1F44D"); // thumbs up
      break;
    case 2:
      SEND_EMOJI_CODE("1F389"); // celebrate
      break;
    case 3:
      SEND_EMOJI_CODE("1F4AF"); // 100
      break;
    case 4:
      SEND_EMOJI_CODE("1F44C"); // ok hand
      break;
    case 5:
      SEND_EMOJI_CODE("1F446"); // point up
      break;
    case 6:
      SEND_EMOJI_CODE("1F449"); // point right
      SEND_EMOJI_CODE("1F449"); // point right
      break;
    case 7:
      SEND_EMOJI_CODE("1F595"); // middle finger
      break;
    case 8:
      SEND_EMOJI_CODE("1F4A9"); // poop
      break;
    case 9:
      // shrug emoticon thingy
      register_code(KC_LSHIFT);
      register_code(KC_RALT);
      tap_code(KC_MINS);
      tap_code(KC_MINS);
      unregister_code(KC_RALT);
      unregister_code(KC_LSHIFT);
      SEND_STRING("\\_(");
      SEND_EMOJI_CODE("30C4"); // ツ
      SEND_STRING(")_/");
      register_code(KC_LSHIFT);
      register_code(KC_RALT);
      tap_code(KC_MINS);
      tap_code(KC_MINS);
      unregister_code(KC_RALT);
      unregister_code(KC_LSHIFT);
      sent_buffer += 8;
      break;
  }
}

void clear_sent_buffer (void) {
  while (sent_buffer > 0) {
    sent_buffer--;
    tap_code(KC_BSPACE);
  }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ENABLE_SELECTOR:
      if (record->event.pressed) {
        selected_item = 0;
        selector_enabled = true;
        SEND_STRING("><");
        sent_buffer = 1;
      } else {
        selector_enabled = false;

        clear_sent_buffer();
        tap_code(KC_BSPACE);
        send_selected_item();
      }
      return false;
    default:
      return true; // Process all other keycodes normally
  }
}

void encoder_update_user(uint8_t index, bool clockwise) {
  switch (index) {
    case 1:
      if (!clockwise) {
          tap_code(KC_VOLU);
      } else {
          tap_code(KC_VOLD);
      }
      break;
    case 0:
      if (selector_enabled) {
        if (!clockwise && selected_item < 10) {
          selected_item++;
        } else if (clockwise && selected_item > 0){
          selected_item--;
        }

        clear_sent_buffer();

        send_selected_item();

        SEND_STRING("<");
        sent_buffer += 1;
      }
      break;
  }
}
