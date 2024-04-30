#include QMK_KEYBOARD_H

enum my_keycodes {
  KVM_MACBOOK = SAFE_RANGE,
  KVM_WINDOWS
};

enum layers {
    _MAIN_WIN,
    _MVMT_WIN,
    _MAIN_MAC,
    _MVMT_MAC,
    _NUMR,
    _NUMP,
    _HYPR,
};
#define M_TGLM      TG(_MAIN_MAC)
#define M_HESC      LT(_HYPR, KC_ESC)
#define M_LALTE     LALT_T(KC_ESC)
#define M_NUMRD     LT(_NUMR, KC_DEL)
#define M_MVMTW     MO(_MVMT_WIN)
#define M_MVMTM     MO(_MVMT_MAC)
#define M_NUMP      MO(_NUMP)
#define M_LWRDW     LCTL(KC_LEFT)
#define M_RWRDW     LCTL(KC_RIGHT)
#define M_LWRDM     LALT(KC_LEFT)
#define M_RWRDM     LALT(KC_RIGHT)
#define M_HOMEM     LGUI(KC_LEFT)
#define M_ENDM      LGUI(KC_RIGHT)
#define M_LOCKW     LGUI(KC_L)
#define M_LOCKM     LGUI(LCTL(KC_Q))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN_WIN] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLS,
        KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE, M_LOCKW, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
                          M_HESC,  M_LALTE, KC_LCTL, KC_SPC,                    KC_DEL,  M_MVMTW, M_NUMP,  M_HESC
    ),
    [_MVMT_WIN] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_HOME, KC_TRNS, KC_END,  KC_MINS, KC_EQL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, M_LWRDW, KC_UP,   M_RWRDW, KC_LBRC, KC_RBRC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_LCBR, KC_RCBR,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_TRNS, KC_END , KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_MAIN_MAC] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE, M_LOCKM, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
                          M_HESC,  M_LALTE, KC_LGUI, KC_SPC,                    KC_DEL,  M_MVMTM, M_NUMP,  M_HESC
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
        RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL, RGB_MODE_SNAKE, RGB_MODE_KNIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0,   KC_P0,   KC_PDOT, KC_PENT, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_HYPR] = LAYOUT(
        KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KVM_MACBOOK, KVM_WINDOWS,
        KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS,                   KC_TRNS, KC_PSCR, KC_BRMD, KC_BRMU, KC_WBAK, KC_WFWD,
        KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,                   KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, M_TGLM,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS
    )
    // [10] = LAYOUT(
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    // )
};

const key_override_t redo_windows = ko_make_with_layers(MOD_MASK_CTRL, KC_Y, LCTL(LSFT(KC_Z)), 1<<_MAIN_WIN);
const key_override_t redo_macos = ko_make_with_layers(MOD_MASK_GUI, KC_Y, LGUI(LSFT(KC_Z)), 1<<_MAIN_MAC);
const key_override_t open_devtools_macos = ko_make_with_layers(MOD_MASK_SG, KC_J, LALT(LGUI(KC_J)), 1<<_MAIN_MAC);

const key_override_t **key_overrides = (const key_override_t *[]){
    &redo_windows,
    &redo_macos,
    &open_devtools_macos,
    NULL // Null terminate
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KVM_MACBOOK:
        if (record->event.pressed) {
            tap_code(KC_RCTL);
            wait_ms(200);
            tap_code(KC_RCTL);
            wait_ms(200);
            tap_code(KC_P1);
            layer_move(_MAIN_MAC);
        }
        return false;
    case KVM_WINDOWS:
        if (record->event.pressed) {
            tap_code(KC_RCTL);
            wait_ms(200);
            tap_code(KC_RCTL);
            wait_ms(200);
            tap_code(KC_P2);
            layer_move(_MAIN_WIN);
        }
        return false;
    default:
      return true; // Process all other keycodes normally
  }
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
// const char *read_layer_state(void);
const char *read_logo(void);
// void set_keylog(uint16_t keycode, keyrecord_t *record);
// const char *read_keylog(void);
// const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);


char layer_state_str[24];
const char *read_layer_string(void) {
  switch (biton32(layer_state)) {
    case _MAIN_WIN:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Main Win");
      break;
    case _MVMT_WIN:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Movement Win");
      break;
    case _MAIN_MAC:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Main Mac");
      break;
    case _MVMT_MAC:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Movement Mac");
      break;
    case _NUMR:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Number Row");
      break;
    case _NUMP:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Numpad");
      break;
    case _HYPR:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Meta & F-Keys");
      break;
    default:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: %d", biton32(layer_state));
  }

  return layer_state_str;
}


bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_string(), false);
    oled_write(read_logo(), false);
    // oled_write_ln(read_keylog(), false);
    // oled_write_ln(read_keylogs(), false);
    // oled_write_ln(read_mode_icon(), false);
    // oled_write_ln(read_host_led_state(), false);
    // oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
// #ifdef OLED_ENABLE
//     set_keylog(keycode, record);
// #endif
//     // set_timelog();
//   }
//   return true;
// }

// Rotary Encoder
#ifdef ENCODER_ENABLE
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
    // case _HYPR: {
    //   if (counterclockwise) {
    //     increase_screen_num();
    //   } else {
    //     decrease_screen_num();
    //   }
    //   break;
    // }
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
