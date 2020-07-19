
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

bool mac_mode            = false;
char mac_mode_string[21] = {};

void toggle_mac_mode(void) { mac_mode = !mac_mode; }

bool is_mac_mode(void) { return mac_mode; }
