#include QMK_KEYBOARD_H

// #region Layers and Custom Keycodes
enum custom_keycodes {
    K_WIN = SAFE_RANGE, // KVM: switch to windows PC
    K_MAC,              // KVM: switch to macbook
    K_MW_SM,            // KVM: hybrid view | main: windows  secondary: mac
    K_MM_SW,            // KVM: hybrid view | main: mac      secondary: windows
    K_S_KBM,            // KVM: swap keyboard and mouse
};

// clang-format off
enum layers {
    _MAIN_WIN, // Main layer for Windows
    _MVMT_WIN, // Movement layer for Windows
    _MAIN_MAC, // Main layer for MacOS
    _MVMT_MAC, // Movement layer for MacOS
    _NUMR,     // Number row delete layer tap
    _NUMP,     // Numpad layer
    _HYPR_WIN, // Hyper layer for Windows
    _HYPR_MAC  // Hyper layer for MacOS
};
// clang-format on
// #endregion Layers and Custom Keycodes

// #region Keycode alises
// numpad
#define M_NUMP MO(_NUMP)
// number row delete layer tap
#define M_NUMRD LT(_NUMR, KC_DEL)
// alt/esc hybrid
#define M_LALTE LALT_T(KC_ESC)
// switch win/mac mode
#define M_TGLM TG(_MAIN_MAC)
// movement layer
#define M_MVMTW MO(_MVMT_WIN)
#define M_MVMTM MO(_MVMT_MAC)
// hyper/escape hybrid
#define M_HESCW LT(_HYPR_WIN, KC_ESC)
#define M_HESCM LT(_HYPR_MAC, KC_ESC)
// left one word
#define M_LWRDW LCTL(KC_LEFT)
#define M_LWRDM LALT(KC_LEFT)
// right one word
#define M_RWRDW LCTL(KC_RIGHT)
#define M_RWRDM LALT(KC_RIGHT)
// home
#define M_HOMEW KC_HOME
#define M_HOMEM LGUI(KC_LEFT)
// end
#define M_ENDW KC_END
#define M_ENDM LGUI(KC_RIGHT)
// lock
#define M_LOCKW LGUI(KC_L)
#define M_LOCKM LGUI(LCTL(KC_Q))
// sleep
#define M_SLEPW KC_SLEP
#define M_SLEPM LGUI(LALT(KC_POWER))
// screenshot key
#define M_SSHTW LGUI(LSFT(KC_S))
#define M_SSHTM LGUI(LSFT(KC_5))

// #region RGB Lighting
#define M_R_PLA RGB_MODE_PLAIN
#define M_R_BRE RGB_MODE_BREATHE
#define M_R_RAI RGB_MODE_RAINBOW
#define M_R_SWI RGB_MODE_SWIRL
#define M_R_SNA RGB_MODE_SNAKE
#define M_R_KNI RGB_MODE_KNIGHT
// #endregion RGB Lighting
// #endregion Keycode alises

// #region Keymap
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN_WIN] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLS,
        KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE, M_LOCKW, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
                          M_HESCW, M_LALTE, KC_LCTL, KC_SPC,                    KC_DEL,  M_MVMTW, M_NUMP,  M_HESCW
    ),
    [_MVMT_WIN] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, M_HOMEW, KC_TRNS, M_ENDW,  KC_MINS, KC_EQL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, M_LWRDW, KC_UP,   M_RWRDW, KC_LBRC, KC_RBRC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_LCBR, KC_RCBR,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_HOMEW, KC_TRNS, M_ENDW , KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_MAIN_MAC] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE, M_LOCKM, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
                          M_HESCM, M_LALTE, KC_LGUI, KC_SPC,                    KC_DEL,  M_MVMTM, M_NUMP,  M_HESCM
    ),
    [_MVMT_MAC] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, M_HOMEM, KC_TRNS, M_ENDM,  KC_MINS, KC_EQL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, M_LWRDM, KC_UP,   M_RWRDM, KC_LBRC, KC_RBRC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_LCBR, KC_RCBR,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_HOMEM, KC_TRNS, M_ENDM , KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_NUMR] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_NUMP] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_TRNS,
        KC_TRNS, KC_TRNS, RGB_HUD, RGB_VAI, RGB_HUI, KC_TRNS,                   KC_TRNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_TRNS,
        KC_TRNS, KC_TRNS, RGB_SAD, RGB_VAD, RGB_SAI, KC_TRNS,                   KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_TRNS,
        M_R_PLA, M_R_BRE, M_R_RAI, M_R_SWI, M_R_SNA, M_R_KNI, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0,   KC_P0,   KC_PDOT, KC_PENT, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_HYPR_WIN] = LAYOUT(
        KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, K_S_KBM, K_WIN,   K_MAC,
        KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS,                   KC_TRNS, KC_PSCR, KC_BRMD, KC_BRMU, K_MM_SW, K_MW_SM,
        KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,                   KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_WBAK, KC_WFWD,
        M_SSHTW, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_SLEPW, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, M_TGLM,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_HYPR_MAC] = LAYOUT(
        KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, K_S_KBM, K_WIN,   K_MAC,
        KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS,                   KC_TRNS, KC_PSCR, KC_BRMD, KC_BRMU, K_MM_SW, K_MW_SM,
        KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,                   KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_WBAK, KC_WFWD,
        M_SSHTM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_SLEPM, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, M_TGLM,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS
    )
    // [10] = LAYOUT(
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    // )
};
// clang-format on
// #endregion Keymap

// #region Key Overrides
const key_override_t redo_windows        = ko_make_with_layers(MOD_MASK_CTRL, KC_Y, LCTL(LSFT(KC_Z)), 1 << _MAIN_WIN);
const key_override_t redo_macos          = ko_make_with_layers(MOD_MASK_GUI, KC_Y, LGUI(LSFT(KC_Z)), 1 << _MAIN_MAC);
const key_override_t open_devtools_macos = ko_make_with_layers(MOD_MASK_SG, KC_J, LALT(LGUI(KC_J)), 1 << _MAIN_MAC);

const key_override_t **key_overrides = (const key_override_t *[]){
    &redo_windows, &redo_macos, &open_devtools_macos,
    NULL // Null terminate
};
// #endregion Key Overrides

// #region Custom Functions
bool is_mac_mode(void) {
    return layer_state_is(_MAIN_MAC) || layer_state_is(_MVMT_MAC) || layer_state_is(_HYPR_MAC);
}

void double_tap_rctl(void) {
    tap_code(KC_RCTL);
    wait_ms(GSB_WAITTIME);
    tap_code(KC_RCTL);
    wait_ms(GSB_WAITTIME);
}
void double_tap_ralt(void) {
    tap_code(KC_RALT);
    wait_ms(GSB_WAITTIME);
    tap_code(KC_RALT);
    wait_ms(GSB_WAITTIME);
}

void kvm_mac(void) {
    layer_move(_MAIN_MAC);

    double_tap_rctl();
    tap_code(KC_P1);

    // wait a bit, then slap an escape in there to make sure the macbook is woken up when switching to it
    wait_ms(500);
    tap_code(KC_ESC);
}
void kvm_win(void) {
    layer_move(_MAIN_WIN);

    double_tap_rctl();
    tap_code(KC_P2);
}
void kbm_swap_kbm(void) {
    double_tap_ralt();
    layer_invert(_MAIN_MAC);
}
// #endregion Custom Functions

#ifdef OLED_ENABLE // SSD1306 OLED header stuff
const char *read_logo(void);
// void set_keylog(uint16_t keycode, keyrecord_t *record);
// const char *read_keylog(void);
// const char *read_keylogs(void);

// void set_timelog(void);
// const char *read_timelog(void);
#endif // OLED_ENABLE

// Custom Keycodes Processing
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case K_WIN:
            if (record->event.pressed) {
                kvm_mac();
            }
            return false;
        case K_MAC:
            if (record->event.pressed) {
                kvm_win();
            }
            return false;
        case K_MM_SW:
            if (record->event.pressed) {
                kvm_mac();

                wait_ms(GSB_WAITTIME);

                double_tap_rctl();
                tap_code(KC_LEFT);
            }
            return false;
        case K_MW_SM:
            if (record->event.pressed) {
                kvm_win();

                wait_ms(GSB_WAITTIME);

                double_tap_rctl();
                tap_code(KC_LEFT);
            }
            return false;
        case K_S_KBM:
            if (record->event.pressed) {
                double_tap_ralt();
                layer_invert(_MAIN_WIN);
            }
            return false;
        default:
            if (record->event.pressed) {
#ifdef OLED_ENABLE
                // set_keylog(keycode, record);
                // set_timelog();
#endif
            }
            return true; // Process all other keycodes normally
    }
}

#ifdef OLED_ENABLE // SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
// #region OLED Display functions
char layer_state_str[24];
char os_str[4];
void print_layer_state_string(bool invert, bool write_os) {
    if (is_mac_mode()) {
        snprintf(os_str, sizeof(os_str), "Mac");
    } else {
        snprintf(os_str, sizeof(os_str), "Win");
    }

    switch (biton32(layer_state)) {
        case _MAIN_WIN:
        case _MAIN_MAC:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Main       %s", write_os ? os_str : "   ");
            break;
        case _MVMT_WIN:
        case _MVMT_MAC:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Movement   %s", write_os ? os_str : "   ");
            break;
        case _HYPR_WIN:
        case _HYPR_MAC:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Hyper      %s", write_os ? os_str : "   ");
            break;
        case _NUMR:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Number Row %s", write_os ? os_str : "   ");
            break;
        case _NUMP:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Numpad     %s", write_os ? os_str : "   ");
            break;
        default:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: %d", biton32(layer_state));
    }

    oled_write(layer_state_str, invert);
}

static char logo[][2][3] = {{{0x95, 0x96, 0}, {0xb5, 0xb6, 0}}, {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}}};
char        mode_icon_half[12];
// where to render the logo as constants
#    define LOGO_COLUMN 19
#    define LOGO_ROW 0
void print_mode_icon(bool invert) {
    oled_write("                     ", invert);
    if (is_mac_mode()) {
        oled_set_cursor(LOGO_COLUMN, LOGO_ROW);
        snprintf(mode_icon_half, sizeof(mode_icon_half), "%s", logo[0][0]);
        oled_write(mode_icon_half, invert);

        oled_set_cursor(LOGO_COLUMN, LOGO_ROW + 1);
        snprintf(mode_icon_half, sizeof(mode_icon_half), "%s", logo[0][1]);
        oled_write(mode_icon_half, invert);
    } else {
        oled_set_cursor(LOGO_COLUMN, LOGO_ROW);
        snprintf(mode_icon_half, sizeof(mode_icon_half), "%s", logo[1][0]);
        oled_write(mode_icon_half, invert);

        oled_set_cursor(LOGO_COLUMN, LOGO_ROW + 1);
        snprintf(mode_icon_half, sizeof(mode_icon_half), "%s", logo[1][1]);
        oled_write(mode_icon_half, invert);
    }
}
// #endregion OLED Display functions

// #region OLED Display update functions
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    return rotation;
}
bool oled_task_user(void) {
    static bool invert_text = GSB_DEFAULT_INVERT_OLED;

#    ifdef GSB_SCREENSAVER
    static uint32_t last_toggle_time = 0;

    // Check if the interval has elapsed
    if (timer_elapsed(last_toggle_time) > GSB_SCREENSAVER) {
        invert_text      = !invert_text; // Toggle the invert state
        last_toggle_time = timer_read(); // Reset the timer
    }
#    endif // GSB_SCREENSAVER

    if (is_keyboard_master()) {
#    ifdef GSB_LAYER_LOGO
        print_layer_state_string(invert_text, false);
        print_mode_icon(invert_text);
        oled_write("                       ", invert_text);
        oled_write("                       ", invert_text);
#    else
        print_layer_state_string(invert_text, true);
        oled_write(read_logo(), invert_text);
#    endif

        // oled_write(read_logo(), invert_text);
        // oled_write_ln(read_keylog(), invert_text);
        // oled_write_ln(read_keylogs(), invert_text);
        // oled_write_ln(read_host_led_state(), invert_text);
        // oled_write_ln(read_timelog(), invert_text);
    } else {
        oled_write(read_logo(), invert_text);
    }

    return false;
}
// #endregion OLED Display update functions
#endif // OLED_ENABLE

#ifdef ENCODER_ENABLE // Rotary Encoder Processing
bool encoder_update_user(uint8_t index, bool counterclockwise) {
    switch (biton32(layer_state)) {
        case _MVMT_WIN:
        case _MVMT_MAC: {
            if (counterclockwise) {
                tap_code(KC_WH_D);
            } else {
                tap_code(KC_WH_U);
            }
            break;
        }
        case _NUMP: {
            if (counterclockwise) {
                tap_code16(LCTL(KC_Y));
            } else {
                tap_code16(LCTL(KC_Z));
            }
            break;
        }
#ifdef GSB_HYPER_KVM_ROTARY
        case _HYPR_WIN:
        case _HYPR_MAC: {
          if (counterclockwise) {
            double_tap_rctl();
            tap_code(KC_RGHT);
          } else {
            double_tap_rctl();
            tap_code(KC_LEFT);
          }
          break;
        }
#endif
        default: {
            if (counterclockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        }
    }
    return true;
}
#endif
