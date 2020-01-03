
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

#define L_BASE 0
#define L_MOVEMENT 2
#define L_NUMPAD 4

char layer_state_str[24] = {};

const char *read_layer_state(void) {
  switch (layer_state) {
    case L_BASE:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Main");
      break;
    case L_MOVEMENT:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Mvmt & F-keys");
      break;
    case L_NUMPAD:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Numpad");
      break;
    default:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: %ld", layer_state);
  }

  return layer_state_str;
}
