/* Copyright 2023 Gregory Benner
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
    //                                                         |                                                       //
    [_MAIN_WIN] = LAYOUT_ortho_5x12(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_TRNS, KC_TRNS, M_HESC,  M_LALTE, KC_LCTL, KC_SPC,      KC_DEL,  M_MVMTW, M_NUMP,  M_HESC,  KC_TRNS, KC_TRNS
    ),
    //                                                         |                                                       //
    [_MVMT_WIN] = LAYOUT_ortho_5x12(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_HOME, KC_TRNS, KC_END,  KC_MINS, KC_EQL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, M_LWRDW, KC_UP,   M_RWRDW, KC_LBRC, KC_RBRC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_LCBR, KC_RCBR,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_HOME, KC_TRNS, KC_END,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    //                                                         |                                                       //
    [_MAIN_MAC] = LAYOUT_ortho_5x12(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
        KC_TRNS, KC_TRNS, M_HESC,  M_LALTE, KC_LGUI, KC_SPC,      KC_DEL,  M_MVMTM, M_NUMP,  M_HESC, KC_TRNS, KC_TRNS
    ),
    //                                                         |                                                       //
    [_MVMT_MAC] = LAYOUT_ortho_5x12(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, M_HOMEM, KC_TRNS, M_ENDM,  KC_MINS, KC_EQL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, M_LWRDM, KC_UP,   M_RWRDM, KC_LBRC, KC_RBRC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_LCBR, KC_RCBR,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, M_HOMEM, KC_TRNS, M_ENDM , KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    //                                                         |                                                       //
    [_NUMR] = LAYOUT_ortho_5x12(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    //                                                         |                                                       //
    [_NUMP] = LAYOUT_ortho_5x12(
        KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, KC_TRNS, KC_TRNS,     KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_TRNS,
        KC_TRNS, KC_TRNS, RGB_HUD, RGB_VAI, RGB_HUI, KC_TRNS,     KC_TRNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_TRNS,
        KC_TRNS, KC_TRNS, RGB_SAD, RGB_VAD, RGB_SAI, KC_TRNS,     KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_P0,   KC_P0,   KC_PDOT, KC_PENT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    //                                                         |                                                       //
    [_HYPR] = LAYOUT_ortho_5x12(
        KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS,     KC_TRNS, KC_PSCR, KC_BRMD, KC_BRMU, KC_WBAK, KC_WFWD,
        KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,     KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, M_TGLM,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_TGLM
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_ON_STATE(state, _MAIN_MAC)) {
        writePinHigh(LED1);
    } else if (IS_LAYER_ON_STATE(state, _MAIN_WIN)) {
        writePinLow(LED1);
    }

    if (
        IS_LAYER_ON_STATE(state, _MVMT_WIN) ||
        IS_LAYER_ON_STATE(state, _MVMT_MAC) ||
        IS_LAYER_ON_STATE(state, _NUMR) ||
        IS_LAYER_ON_STATE(state, _NUMP) ||
        IS_LAYER_ON_STATE(state, _HYPR)
    ) {
        writePinHigh(LED2);
    } else {
        writePinLow(LED2);
    }

    return state;
}
