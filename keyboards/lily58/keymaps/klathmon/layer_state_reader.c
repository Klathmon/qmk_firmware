
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

char layer_state_str[21] = {};

const char *get_layer_display_string(void) {
  switch (biton32(layer_state)) {
    case 0:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Main");
      break;
    case 1:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Mvmt & Emoji");
      break;
    case 2:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Numpad");
      break;
    case 3:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Meta & F-Keys");
      break;
    default:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: %d", biton32(layer_state));
  }

  return layer_state_str;
}
