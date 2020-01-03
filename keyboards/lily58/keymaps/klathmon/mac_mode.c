
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8
#define L_ADJUST_TRI 14

bool mac_mode = false;
char mac_mode_string[21] = {};

void toggle_mac_mode (void) {
  mac_mode = !mac_mode;
}

bool get_mac_mode (void) {
  return mac_mode;
}

const char *read_mac_mode_state(void) {
  if (mac_mode) {
    snprintf(mac_mode_string, sizeof(mac_mode_string), "Mac Mode");
  } else {
    snprintf(mac_mode_string, sizeof(mac_mode_string), "Windows Mode");
  }
  return mac_mode_string;
}
