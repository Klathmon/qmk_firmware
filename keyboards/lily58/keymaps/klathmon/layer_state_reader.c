
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state) {
    case 0:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Main");
      break;
    case 1:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Movement & F-keys");
      break;
    case 2:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Numpad");
      break;
    default:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: %ld", layer_state);
  }

  return layer_state_str;
}
