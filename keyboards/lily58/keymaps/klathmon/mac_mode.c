
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

bool mac_mode            = false;
char mac_mode_string[21] = {};

void toggle_mac_mode(void) { mac_mode = !mac_mode; }

bool is_mac_mode(void) { return mac_mode; }

const char *get_mac_mode_display_string(void) {
    if (mac_mode) {
        snprintf(mac_mode_string, sizeof(mac_mode_string), "Mac Mode");
    } else {
        snprintf(mac_mode_string, sizeof(mac_mode_string), "Windows Mode");
    }
    return mac_mode_string;
}
