/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers {
    _MAIN_WIN,
    _MVMT_WIN,
    _MAIN_MAC,
    _MVMT_MAC,
    _NUMR,
    _NUMP,
    _HYPR,
};

enum custom_keycodes {
    COINS = SAFE_RANGE,
    ONEUP,
    OVERW,
    MARIOT,
    MARIOG,
    MARIOM,
    DISNEY
};

#define M_TGLM TG(_MAIN_MAC)
#define M_HESC  LT(_HYPR, KC_ESC)
#define M_LALTE LALT_T(KC_ESC)
#define M_NUMRD LT(_NUMR, KC_DEL)
#define M_MVMTW MO(_MVMT_WIN)
#define M_MVMTM MO(_MVMT_MAC)
#define M_NUMP  MO(_NUMP)
#define M_LWRDW LCTL(KC_LEFT)
#define M_RWRDW LCTL(KC_RIGHT)
#define M_LWRDM LALT(KC_LEFT)
#define M_RWRDM LALT(KC_RIGHT)
#define M_HOMEM LGUI(KC_LEFT)
#define M_ENDM  LGUI(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN_WIN] = LAYOUT_planck_grid(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
        KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
        KC_NO,   KC_NO,   M_HESC,  M_LALTE, KC_LCTL, KC_SPC,  M_NUMRD, M_MVMTW, M_NUMP,  M_HESC, KC_NO,   KC_ENT
    ),
    [_MVMT_WIN] = LAYOUT_planck_grid(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_LWRDW, KC_UP,   M_RWRDW, KC_MINS, KC_EQL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_LBRC, KC_RBRC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_BSLS, KC_END , KC_LCBR, KC_RCBR,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_MAIN_MAC] = LAYOUT_planck_grid(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
        KC_NO,   KC_NO,   M_HESC,  M_LALTE, KC_LGUI, KC_SPC,  M_NUMRD, M_MVMTM, M_NUMP,  M_HESC, KC_NO,   KC_ENT
    ),
    [_MVMT_MAC] = LAYOUT_planck_grid(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_LWRDM, KC_UP,   M_RWRDM, KC_MINS, KC_EQL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_LBRC, KC_RBRC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_HOMEM, KC_BSLS, M_ENDM,  KC_LCBR, KC_RCBR,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_NUMR] = LAYOUT_planck_grid(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_NUMP] = LAYOUT_planck_grid(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P4,   KC_P5,   KC_P6,   KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_HYPR] = LAYOUT_planck_grid(
        KC_CAPS, COINS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS, KC_PSCR, KC_BRMD, KC_BRMU, KC_WBAK, KC_WFWD,
        DISNEY,  MARIOT,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_TRNS, KC_TRNS,
        CK_TOGG, MARIOG,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, M_TGLM,
        MU_TOG,  MU_MOD,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_TGLM
    )
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


#ifdef AUDIO_ENABLE
float coin_song [][2] = SONG(E__NOTE(_A5  ),HD_NOTE(_E6  ),);
float oneup_song [][2] = SONG(Q__NOTE(_E6  ),Q__NOTE(_G6  ),Q__NOTE(_E7  ),Q__NOTE(_C7  ),Q__NOTE(_D7  ),Q__NOTE(_G7  ),);
float mario_song [][2] = SONG(Q__NOTE(_E5),H__NOTE(_E5),H__NOTE(_E5),Q__NOTE(_C5),H__NOTE(_E5),W__NOTE(_G5),Q__NOTE(_G4),);
float mariogo_song [][2] = SONG(HD_NOTE(_C5 ),HD_NOTE(_G4 ),H__NOTE(_E4 ),H__NOTE(_A4 ),H__NOTE(_B4 ),H__NOTE(_A4 ),H__NOTE(_AF4),H__NOTE(_BF4),H__NOTE(_AF4),WD_NOTE(_G4 ),);
float disney_song [][2] = SONG(H__NOTE(_G3 ),H__NOTE(_G4 ),H__NOTE(_F4 ),H__NOTE(_E4 ),H__NOTE(_CS4),H__NOTE(_D4 ),W__NOTE(_A4 ),H__NOTE(_B3 ),H__NOTE(_B4 ),H__NOTE(_A4 ),H__NOTE(_G4 ),H__NOTE(_FS4),H__NOTE(_G4 ),W__NOTE(_C5 ),H__NOTE(_D5 ),H__NOTE(_C5 ),H__NOTE(_B4 ),H__NOTE(_A4 ),H__NOTE(_G4 ),H__NOTE(_F4 ),H__NOTE(_E4 ),H__NOTE(_D4 ),W__NOTE(_A4 ),W__NOTE(_B3 ),W__NOTE(_C4 ),);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef AUDIO_ENABLE
    switch (keycode) {
        case COINS:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(coin_song);
            }
            return false;
        case MARIOT:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(mario_song);
            }
            return false;
        case MARIOG:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(mariogo_song);
            }
            return false;
        case DISNEY:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(disney_song);
            }
            return false;
    }
#endif
    return true;
}

#ifdef AUDIO_ENABLE
bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case M_HESC:
      return false;
    default:
      return true;
  }
}
#endif
