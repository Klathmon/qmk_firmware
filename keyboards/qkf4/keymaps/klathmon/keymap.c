#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

// #region Layers and Custom Keycodes
enum my_keycodes {
    K_WIN = SAFE_RANGE, // KVM: switch to windows PC
    K_MAC,              // KVM: switch to macbook
    K_MW_SM,            // KVM: hybrid view | main: windows  secondary: mac
    K_MM_SW,            // KVM: hybrid view | main: mac      secondary: windows
    K_S_KBM,            // KVM: swap keyboard and mouse
    KQ_FLSH,            // type out qmk flash command for this keyboard
};

// clang-format off
enum my_layers {
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
// Macos forward and back
#define M_BAKM LOPT(KC_LEFT)
#define M_FWDM LOPT(KC_RGHT)
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
#define M_SLEPM LGUI(LALT(KC_PWR))
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
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
        KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
                          M_HESCW,  M_LALTE, KC_LCTL, KC_SPC,           M_NUMRD, M_MVMTW, M_NUMP,  M_HESCW
    ),
    [_MVMT_WIN] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, M_LWRDW, KC_UP,   M_RWRDW, KC_MINS, KC_EQL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_LBRC, KC_RBRC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_HOME, KC_BSLS, KC_END , KC_LCBR, KC_RCBR,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_MAIN_MAC] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
                          M_HESCM,  M_LALTE, KC_LGUI, KC_SPC,           M_NUMRD, M_MVMTM, M_NUMP,  M_HESCM
    ),
    [_MVMT_MAC] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, M_LWRDM, KC_UP,   M_RWRDM, KC_MINS, KC_EQL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_LBRC, KC_RBRC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, M_HOMEM, KC_BSLS, M_ENDM,  KC_LCBR, KC_RCBR,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_NUMR] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_NUMP] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_P4,   KC_P5,   KC_P6,   KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_P0,   KC_TRNS, KC_TRNS
    ),
    [_HYPR_WIN] = LAYOUT(
        KC_CAPS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,            KC_TRNS, KC_PSCR, KC_TRNS, K_S_KBM, K_WIN,   K_MAC,
        KC_TRNS, KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,            M_LOCKW, KC_VOLD, KC_MUTE, KC_VOLU, KC_WBAK, KC_WFWD,
        M_SSHTW, KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,           M_SLEPW, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, M_TGLM,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          QK_BOOT, KQ_FLSH, KC_TRNS, KC_TRNS
    ),
    [_HYPR_MAC] = LAYOUT(
        KC_CAPS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,            KC_TRNS, KC_PSCR, KC_TRNS, K_S_KBM, K_WIN,   K_MAC,
        KC_TRNS, KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,            M_LOCKM, KC_VOLD, KC_MUTE, KC_VOLU, M_BAKM,  M_FWDM,
        M_SSHTM, KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,           M_SLEPM, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, M_TGLM,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          QK_BOOT, KQ_FLSH, KC_TRNS, KC_TRNS
    )
    // [10] = LAYOUT(
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
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
void kvm_mac(void) {
    layer_move(_MAIN_MAC);
    SEND_STRING_DELAY(SS_TAP(X_RCTL) SS_TAP(X_RCTL) SS_TAP(X_P1), GSB_KVM_DELAY);

    // wait a bit, then slap an escape in there to make sure the macbook is woken up when switching to it
    wait_ms(500);
    tap_code(KC_ESC);
}
void kvm_win(void) {
    layer_move(_MAIN_WIN);
    SEND_STRING_DELAY(SS_TAP(X_RCTL) SS_TAP(X_RCTL) SS_TAP(X_P2), GSB_KVM_DELAY);
}
void kbm_swap_kbm(void) {
    layer_invert(_MAIN_MAC);
    SEND_STRING_DELAY(SS_TAP(X_RALT) SS_TAP(X_RALT), GSB_KVM_DELAY);
}
// #endregion Custom Functions

// Custom Keycodes Processing
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KQ_FLSH: {
            if (record->event.pressed) {
                SEND_STRING("qmk flash -j 0 -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_TAP(X_ENTER));
            }
            return false;
        }
        case K_WIN: {
            if (record->event.pressed) {
                kvm_mac();
            }
            return false;
        }
        case K_MAC: {
            if (record->event.pressed) {
                kvm_win();
            }
            return false;
        }
        case K_MM_SW: {
            if (record->event.pressed) {
                kvm_mac();

                wait_ms(GSB_KVM_DELAY);

                SEND_STRING_DELAY(SS_TAP(X_RCTL) SS_TAP(X_RCTL) SS_TAP(X_LEFT), GSB_KVM_DELAY);
            }
            return false;
        }
        case K_MW_SM: {
            if (record->event.pressed) {
                kvm_win();

                wait_ms(GSB_KVM_DELAY);

                SEND_STRING_DELAY(SS_TAP(X_RCTL) SS_TAP(X_RCTL) SS_TAP(X_LEFT), GSB_KVM_DELAY);
            }
            return false;
        }
        case K_S_KBM: {
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_TAP(X_RALT) SS_TAP(X_RALT), GSB_KVM_DELAY);
                layer_invert(_MAIN_WIN);
            }
            return false;
        }
        default: {
            return true; // Process all other keycodes normally
        }
    }
}

// Host OS Detection
bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            layer_move(_MAIN_MAC);
            break;
        case OS_LINUX:
        case OS_WINDOWS:
        case OS_UNSURE:
            layer_move(_MAIN_WIN);
            break;
    }
    return true;
}
