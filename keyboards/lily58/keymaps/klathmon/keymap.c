#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define _MAIN_LAYER 0
#define _MOVEMENT_LAYER 1
#define _NUMPAD_LAYER 2
#define _HYPER_LAYER 3

enum custom_keycodes {
  MAC_MODE = SAFE_RANGE, // toggle between MacOS and Windows compat
  LCK_SCRN, // lock screen
  LNCH_APP, // launch the companion app
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN_LAYER] = LAYOUT(
      KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
      KC_LGUI,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,     KC_QUOT,
      KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,   KC_MUTE,  LCK_SCRN,   KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,      KC_ENT,
                                    KC_LALT,  KC_ESC,  KC_LCTL,  KC_SPC,    KC_DEL,  MO(1),    MO(2),    MO(3)
  ),
  [_MOVEMENT_LAYER] = LAYOUT(
      KC_TRNS,    KC_F1,    KC_F2,    KC_F3,    KC_F4,  KC_TRNS,                      KC_TRNS,  KC_HOME,  KC_PGUP,   KC_END,  KC_MINS,   KC_EQL,
      KC_TRNS,    KC_F5,    KC_F6,    KC_F7,    KC_F8,  KC_TRNS,                      KC_TRNS,LCTL(KC_LEFT), KC_UP,LCTL(KC_RIGHT), KC_LBRC, KC_RBRC,
      KC_TRNS,    KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_TRNS,                      KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_LCBR,  KC_RCBR,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS , KC_TRNS,  KC_TRNS,  KC_PGDN,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
  [_NUMPAD_LAYER] = LAYOUT(
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_PAST,  KC_P7,  KC_P8,  KC_P9,  KC_PMNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_PSLS,  KC_P4,  KC_P5,  KC_P6,  KC_PPLS,  KC_NO,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_NO,    KC_P1,  KC_P2,  KC_P3,  KC_PENT,  KC_NO,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_P0,  KC_P0,KC_PDOT,  KC_PENT,  KC_TRNS,
                                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
  [_HYPER_LAYER] = LAYOUT(
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  RGB_M_P,  KC_TRNS,  KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    RESET,  KC_TRNS,  KC_MPRV,  KC_MPLY,  KC_MNXT, LNCH_APP,  MAC_MODE,
                                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
};

int RGB_current_mode;

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);

void set_wpm(void);
const char *read_wpm_string(void);

void toggle_mac_mode(void);
bool get_mac_mode(void);
const char *read_mac_mode_state(void);

bool is_hid_connected(void);
const char *read_hid_status(void);
void increase_screen_num(void);
void decrease_screen_num(void);
void write_slave_info_screen(struct CharacterMatrix *matrix);


void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_mac_mode_state());
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_hid_status());
    matrix_write_ln(matrix, read_wpm_string());
  } else {
    write_slave_info_screen(matrix);
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_wpm();
#endif
  }

  uint8_t mods = get_mods();

  switch (keycode) {
    // fancy keycodes!
    case MAC_MODE:
      if (record->event.pressed) {
        toggle_mac_mode();
      }
      return false;
      break;
    case LCK_SCRN:
      if (record->event.pressed) {
        if (get_mac_mode()) {
          tap_code16(LGUI(LCTL(KC_Q)));
        } else {
          tap_code16(LGUI(KC_L));
        }
      }
      return false;
      break;
    case LNCH_APP:
      if (record->event.pressed) {
        if (get_mac_mode()) {
          // do something eventually...
          SEND_STRING(SS_LGUI(" "));
          _delay_ms(400);
          SEND_STRING("terminal.app"SS_TAP(X_ENT));
          _delay_ms(400);
          SEND_STRING(SS_LGUI("n")); // new window
          _delay_ms(200);
          SEND_STRING("npx @klathmon/qmk-hid-display"SS_TAP(X_ENT));
          _delay_ms(200);
          SEND_STRING(SS_LGUI("m")); // minimize new window
        } else {
          SEND_STRING(SS_LGUI("r"));
          _delay_ms(400);
          SEND_STRING("cmd /C npx @klathmon/qmk-hid-display"SS_TAP(X_ENT));
          _delay_ms(100);
          register_code(KC_LGUI);
          tap_code(KC_DOWN);
          unregister_code(KC_GUI);
        }
      }
      return false;
      break;
    // keycode rewrites
    case KC_LCTL:
      if (get_mac_mode()) {
        if (record->event.pressed) {
          register_code(KC_LGUI);
        } else {
          unregister_code(KC_LGUI);
        }
        return false;
      }
      break;
    case KC_LGUI:
      if (get_mac_mode()) {
        if (record->event.pressed) {
          register_code(KC_LCTL);
        } else {
          unregister_code(KC_LCTL);
        }
        return false;
      }
      break;
    case KC_DOWN:
      if (get_mac_mode() && mods & MOD_MASK_GUI) {
        if (record->event.pressed) {
          register_code16(LCTL(LGUI(KC_DOWN)));
        } else {
          unregister_code16(LCTL(LGUI(KC_DOWN)));
        }
        return false;
      }
      break;
    case KC_UP:
      if (get_mac_mode() && mods & MOD_MASK_GUI) {
        if (record->event.pressed) {
          register_code16(LCTL(LGUI(KC_UP)));
        } else {
          unregister_code16(LCTL(LGUI(KC_UP)));
        }
        return false;
      }
      break;
    case KC_LEFT:
      if (get_mac_mode() && mods & MOD_MASK_GUI) {
        if (record->event.pressed) {
            register_code16(LALT(KC_LEFT));
          } else {
            unregister_code16(LALT(KC_LEFT));
          }
        }
        return false;
      }
      break;
    case KC_RIGHT:
      if (get_mac_mode() && mods & MOD_MASK_GUI) {
        if (record->event.pressed) {
            register_code16(LALT(KC_RIGHT));
          } else {
            unregister_code16(LALT(KC_RIGHT));
          }
        }
        return false;
      }
      break;
    case KC_F12: // open devtools on macos
      if (get_mac_mode()) {
        if (record->event.pressed) {
          register_code16(LALT(LGUI(KC_J)));
        } else {
          unregister_code16(LALT(LGUI(KC_J)));
        }
        return false;
      }
      break;
  }
  return true;
}

// Rotary Encoder
void encoder_update_user(uint8_t index, bool counterclockwise) {
  switch (biton32(layer_state)) {
    case _HYPER_LAYER: {
      if (counterclockwise) {
        decrease_screen_num();
      } else {
        increase_screen_num();
      }
      break;
    }

    default: {
      if (counterclockwise) {
        tap_code(KC_VOLD);
      } else {
        tap_code(KC_VOLU);
      }
      break;
    }
  }
}
