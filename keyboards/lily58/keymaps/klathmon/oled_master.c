#include <stdio.h>
#include <stdbool.h>
#include "lily58.h"

bool        is_mac_mode(void);
const char *get_wpm_display_string(void);
const char *get_layer_display_string(void);
const char *get_hid_status_display_string(void);
static char logo[][2][3] = {{{0x95, 0x96, 0}, {0xb5, 0xb6, 0}}, {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}}};
char        screen_buffer[84];

const char *read_all_lines(void) {
    snprintf(
        screen_buffer,
        sizeof(screen_buffer),
        "%-20s\n%-20s\n%20s\n%-9s %7s %2s",
        get_layer_display_string(),
        get_hid_status_display_string(),
        (is_mac_mode() ? logo[0][0] : logo[1][0]),
        get_wpm_display_string(),
        (is_mac_mode() ? "MacOS" : "Windows"),
        (is_mac_mode() ? logo[0][1] : logo[1][1])
    );
    return screen_buffer;
}
