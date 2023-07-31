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
#include "./planck_keymap_swiss_de.h"

// PLANCK added this, idk what this does

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

// KEY OVERRIDES
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t backslash_key_override = ko_make_basic(MOD_MASK_SHIFT, CH_SLSH, CH_BSLS);

// this globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &backslash_key_override,
    NULL
};

// TAIKO COMBOS
const uint16_t PROGMEM escape_combo[] = {KC_TAB, KC_Q, COMBO_END};
const uint16_t PROGMEM ae_combo[] = {KC_E, KC_A, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {KC_E, KC_O, COMBO_END};
const uint16_t PROGMEM ue_combo[] = {KC_E, KC_U, COMBO_END};

combo_t key_combos[] = {
	COMBO(escape_combo, KC_ESC),
	COMBO(ae_combo, CH_ADIA),
	COMBO(oe_combo, CH_ODIA),
	COMBO(ue_combo, CH_UDIA)
};

// KEYS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_planck_grid( // NORMAL
    //.-----------------------------------------------------------------------------------------------------------.
    //| TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | <-     |
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //| LSFT   | A      | S      | D      | F      | G      | H      | J      | K      | L      | /      | RSFT   |
        KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, CH_SLSH, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //| LCTL   | Y      | X      | C      | V      | B      | N      | M      | ,      | .      | -      | ENTER  |
        KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, CH_COMM, CH_DOT,  CH_MINS,  KC_ENT,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //| LCTL   |        | LALT   | MOD    | LAYER1 | SPACE           | LAYER2 | ENTER  | RALT   |        |        |
        KC_LCTL, XXXXXXX, KC_LALT, KC_LGUI,   MO(1),  KC_SPC,  KC_SPC,   MO(2),  KC_ENT, KC_RALT, XXXXXXX, XXXXXXX
    //'-----------------------------------------------------------------------------------------------------------'
    ),

    [1] = LAYOUT_planck_grid( // NUMBER, ARROW, MODS
    //.-----------------------------------------------------------------------------------------------------------.
    //| §      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | <-     |
        CH_SECT,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //| LSFT   | CAPS   | PrScr  | INS    |        |        | LEFT   | DOWN   | UP     | RIGHT  | '      | RSFT   |
        KC_LSFT, KC_CAPS, KC_PSCR,  KC_INS, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, CH_QUOT, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //| LCTL   |        |        |        |        |        | HOME   | PGDOWN | PGUP   | END    |        |        |
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //| LCTL   |        | LALT   | MOD    | LAYER1 | SPACE           | LAYER3 | RALT   |        |        |        |
        KC_LCTL, XXXXXXX, KC_LALT, KC_LGUI, _______,  KC_SPC,  KC_SPC,   MO(3), KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX
    //'-----------------------------------------------------------------------------------------------------------'
    ),

    [2] = LAYOUT_planck_grid( // SPECIALS
    //.-----------------------------------------------------------------------------------------------------------.
    //| ~      | ¦      | @      | #      | °      | $      | `      | |      | '      | ?      | !      | <-     |
        CH_TILD, CH_BRKP,   CH_AT, CH_HASH,  CH_DEG,  CH_DLR,  CH_GRV, CH_PIPE, CH_QUOT, CH_QUES, CH_EXLM, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //| CAPS   | <      | [      | {      | (      | \      | /      | )      | }      | ]      | >      | DEL    |
        KC_CAPS, CH_LABK, CH_LBRC, CH_LCBR, CH_LPRN, CH_BSLS, CH_SLSH, CH_RPRN, CH_RCBR, CH_RBRC, CH_RABK,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //| LCTL   |        |        | MUTE   | VOL DN | VOL UP | PRV    | PLY    | NXT    |        |        |        |
        KC_LCTL, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //| LCTL   |        | LALT   | MOD    | LAYER3 | SPACE           | LAYER2 | RALT   |        |        |        |
        KC_LCTL, XXXXXXX, KC_LALT, KC_LGUI,   MO(3),  KC_SPC,  KC_SPC, _______, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX
    //'-----------------------------------------------------------------------------------------------------------'
    ),

    [3] = LAYOUT_planck_grid( // F KEYS, QMK RGB
    //.-----------------------------------------------------------------------------------------------------------.
    //| ESC    | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | <-     |
         KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //| LSFT   | F11    | F12    | F13    | F14    | F15    | HUE +  | SAT +  | BRI +  | EFF +  | TG RGB | RESET  |
        KC_LSFT,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_TOG, QK_BOOT,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //| LCTL   |        |        |        |        |        | HUE -  | SAT -  | BRI -  | EFF -  | MO RGB | DEBUG  |
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_MOD, DB_TOGG,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //|        |        | LALT   | MOD    | LAYER3 | SPACE           | LAYER3 | RALT   |        | LAYER4 | LAYER5 |
        XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI, _______,  KC_SPC,  KC_SPC, _______, KC_RALT, XXXXXXX,   TG(4),   TG(5)
    //'-----------------------------------------------------------------------------------------------------------'
    ),

    [4] = LAYOUT_planck_grid( // MOUSE
    //.-----------------------------------------------------------------------------------------------------------.
    //|        |        | MUP    |        |        |        |        |        | MOUSE3 | MWH UP |        |        |
        XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, KC_WH_U, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //|        | MLEFT  | MDOWN  | MRIGHT |        |        |        | MOUSE1 | MOUSE2 | MWH DN |        |        |
        XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, KC_WH_D, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //|        |        |        |        |        |        |        |        |        |        |        |        |
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //|        |        |        |        |        |                 |        |        |        | LAYER4 | LAYER5 |
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   TG(4),   TG(5)
    //'-----------------------------------------------------------------------------------------------------------'
    ),

    [5] = LAYOUT_planck_grid( // GAMING / CSGO
    //.-----------------------------------------------------------------------------------------------------------.
    //| ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | <-     |
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //| TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | DEL    |
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //| LSFT   | A      | S      | D      | F      | G      | H      | J      | K      | L      | /      | RSFT   |
        KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, CH_SLSH, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //| LCTL   | Y      | X      | C      | B      | SPACE           | F13    | ,      | .      | -      | LAYER5 |
        KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_B,  KC_SPC,  KC_SPC,  KC_F13, CH_COMM, CH_DOT,  CH_MINS,   TG(5)
    //'-----------------------------------------------------------------------------------------------------------'
    )
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;
