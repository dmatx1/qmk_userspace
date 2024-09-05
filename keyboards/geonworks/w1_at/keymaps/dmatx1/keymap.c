/* Copyright 2021 Yiancar-Designs
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

#include "dmatx1.h"

enum custom_keycodes {
    KC_P00 = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_all(
    KC_F1,   KC_F2,      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,    KC_ESC,  KC_NUM,  KC_PSLS, KC_PAST,
    KC_F3,   KC_F4,      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_NUHS,            KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
    KC_F5,   KC_F6,      MO(2),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,             KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    KC_F7,   KC_F8,      KC_LSFT, MT_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),              KC_P1,   KC_P2,   KC_P3,   KC_PPLS,
    KC_F9,   KC_F10,     KC_LCTL,          KC_LALT,                            KC_SPC,                                      KC_RALT,          KC_RCTL,            KC_P0,   KC_P0,   KC_PDOT, KC_PENT),

[1] = LAYOUT_all(
    _______, _______,    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______,   _______, _______, _______, _______,
    _______, _______,    _______, _______, KC_UP,   _______, _______, _______, _______, _______, KC_PSCR, KC_CPUP, KC_INS,  KC_HOME, KC_PGUP, KC_PGDN,            _______, _______, _______, _______,
    _______, _______,    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, KC_CALC, KC_CPDN, KC_DEL,  KC_END,           KC_INS,             _______, _______, _______, _______,
    _______, _______,    _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, KC_APP,  KC_RMON, KC_SDEL, KC_PAUS, _______, _______,            _______, _______, _______, _______,
    _______, _______,    _______,          _______,                            KC_ESC,                                      _______,          _______,            _______, _______, _______, _______),

[2] = LAYOUT_all(
    _______, _______,    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,   _______, _______, _______, _______,
    _______, _______,    MO(3),   KC_ALFT, KC_WH_U, KC_ARGH, KC_MUTE, KC_VOLD, KC_VOLU, KC_CAPS, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______,
    _______, _______,    _______, KC_WH_L, KC_WH_D, KC_WH_R, KC_MPLY, KC_MPRV, KC_MNXT, KC_MSTP, _______, _______, _______, _______,          _______,            _______, _______, _______, _______,
    _______, _______,    _______, LT_NUBS, KC_CPUP, KC_CPDN, KC_WBAK, KC_WFWD, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______,
    _______, _______,    _______,          _______,                            KC_ESC,                                      _______,          _______,            _______, _______, _______, _______),

[3] = LAYOUT_all(
    _______, _______,    SL_GRV,  SL_1,    SL_2,    SL_3,    SL_4,    SL_5,    SL_6,    SL_7,    SL_8,    SL_9,    SL_0,    SL_MINS, SL_EQL,  _______, _______,   _______, _______, _______, _______,
    _______, _______,    _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, _______, _______, _______, _______, SL_LBRC, SL_RBRC, SL_NUHS,            _______, _______, _______, _______,
    _______, _______,    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, SL_SCLN, SL_QUOT,          _______,            _______, _______, _______, _______,
    _______, _______,    _______, SL_NUBS, _______, KC_KPEX, KC_KPCP, KP_PACL, KP_PAST, _______, _______, SL_COMM, SL_DOT,  SL_SLSH, _______, _______,            _______, _______, _______, _______,
    _______, _______,    _______,          _______,                            _______,                                     _______,          _______,            _______, _______, _______, _______),

[4] = LAYOUT_all(
    _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______,
    _______, _______,    _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______, _______, _______, _______, _______, _______, EE_CLR , QK_BOOT,            _______, _______, _______, _______,
    _______, _______,    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,          _______,            _______, _______, _______, _______,
    _______, _______,    _______, _______, KC_PGUP, KC_PGDN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______,
    _______, _______,    _______,          _______,                            _______,                                     _______,          _______,            _______, _______, _______, _______)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!dmatx1_process_record(keycode, record) ||
        !dmatx1_process_numpad_record(keycode, record))
        return false;

    if (record->event.pressed) {
        switch(keycode) {
            case KC_P00:
                tap_code(KC_P0);
                tap_code(KC_P0);
                return false;
        }
    }
    return true;
}