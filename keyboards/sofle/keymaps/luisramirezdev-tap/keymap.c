 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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
#include "oled.c"

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
};
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO, KC_NO, LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_NO, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, KC_MUTE, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_NO, KC_ESC, MO(4), LT(1,KC_TAB), KC_SPC, KC_ENT, LT(3,KC_BSPC), LT(2,KC_DEL), KC_NO, KC_NO),
	[1] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LGUI(KC_Z), LGUI(KC_V), LGUI(KC_C), LGUI(KC_X), SGUI_T(KC_Z), KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO),
	[2] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PERC, KC_DLR, KC_ASTR, KC_LBRC, KC_RBRC, KC_PLUS, KC_BSLS, KC_PIPE, KC_NO, KC_NO, KC_NO, KC_NO, KC_GRV, KC_EXLM, KC_AMPR, KC_LPRN, KC_RPRN, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TILD, KC_HASH, KC_AT, KC_LCBR, KC_RCBR, KC_NO, KC_NO, KC_LT, KC_GT, KC_QUOT, KC_DQUO, KC_NO, KC_NO, KC_NO, KC_CIRC, KC_COLN, KC_UNDS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO),
	[3] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_0, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO),
	[4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO)
};
