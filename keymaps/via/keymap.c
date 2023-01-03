/*
Copyright 2022 heiesch

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_number {
    _QWERTY = 0,
    _RAISE,
    _LOWER,
    _ADJUST,
};

#define KC_L_ENT LT(2,KC_ENT)  // lower
#define KC_R_SBC LT(1,KC_SPC)  // raise
#define KC_G_JA MT(MOD_LCTL,KC_DEL)     // cmd or win
#define KC_G_EN MT(MOD_LCTL,KC_DEL)     // cmd or win
#define KC_C_BS MT(MOD_LSFT,KC_BSPC)             // ctrl
#define KC_A_ESC MT(MOD_LGUI,KC_ESC)       // esc

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    //,--------+--------+---------+--------+---------+--------.   ,--------+---------+--------+---------+--------+--------.
       KC_ESC , KC_Q   , KC_W    , KC_F   , KC_P    , KC_B   ,     KC_J   , KC_L    , KC_U   , KC_Y    , KC_SCLN, KC_MINS,
    //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
       KC_TAB , KC_A   , KC_R    , KC_S   , KC_T    , KC_G   ,     KC_M   , KC_N    , KC_E   , KC_I    , KC_O   , KC_QUOT,
    //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
       KC_LSFT, KC_Z   , KC_X    , KC_C   , KC_D    , KC_V   ,     KC_K   , KC_H    , KC_COMM, KC_DOT  , KC_SLSH, KC_RSFT,
    //`--------+--------+---------+--------+---------+--------/   \--------+---------+--------+---------+--------+--------'
                         KC_A_ESC, KC_G_EN, KC_L_ENT, KC_C_BS,     KC_C_BS, KC_R_SBC, KC_G_JA, KC_A_ESC
    //                 `----------+--------+---------+--------'   `--------+---------+--------+---------'
    ),

    [_RAISE] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, KC_BSLS, KC_CIRC, KC_EXLM, KC_AMPR, KC_PIPE,     KC_AT  , KC_EQL , KC_PLUS, KC_ASTR, KC_PERC, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, _______,     KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT, KC_INS , _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_HASH, KC_GRV , _______, _______, KC_TILD,     KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_PSCR, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                         KC_LALT, _______, TG(3)  , _______,     _______, _______, _______, QK_BOOT
    //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
    ),

    [_LOWER] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                         QK_BOOT, _______, _______, _______,     _______, TG(3)  , _______, _______
    //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
    ),
    [_ADJUST] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
        KC_F22 , KC_F11 , KC_F12 , KC_F13 , KC_F14 , KC_F15 ,     KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 ,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        KC_SLEP, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE, KC_MSTP,     KC_MRWD, KC_MPRV, KC_MNXT, KC_MFFD, _______, MACRO00,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        KC_F23 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F24 ,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                         _______, _______, _______ , _______,     _______, _______, _______, _______
    //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
    ),
};
