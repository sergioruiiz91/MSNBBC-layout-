// MSN Layout — QWERTY Spanish Corne for Vim + Hyprland
// https://github.com/yourusername/msn-layout
//
// Inspired by the MSN trident (Messi, Suárez, Neymar) — 3 thumbs per side
//
// Layers:
//   L0 - Base (QWERTY Spanish)
//   L1 - Numbers & Symbols
//   L2 - Navigation
//   L3 - Mouse
//   L4 - Hyprland
//   L5 - F-Keys

#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
    _BASE,
    _NUM,
    _NAV,
    _MOUSE,
    _HYPR,
    _FKEYS,
};

// Thumb keys with layer taps
#define SFT_MO  LT(_MOUSE, KC_LSFT)   // Shift tap, Mouse layer hold
#define GUI_HYP LT(_HYPR,  KC_LGUI)   // GUI tap,   HYPR layer hold
#define ENT_NAV LT(_NAV,   KC_ENT)    // Enter tap, NAV layer hold
#define NUM_NO  LT(_NUM,   KC_NO)      // No tap,    NUM layer hold (pinky)
#define FN_NO   LT(_FKEYS, KC_NO)      // No tap,    FKEYS layer hold (pinky)

// Combos
enum combos {
    COMBO_FKEYS,    // Tab + Enter → MO(_FKEYS)
    COMBO_PLAY,     // VolUp + VolDown → Play/Pause
    COMBO_TG_FKEYS, // Alt + GUI + RAlt + RGUI → TG(_FKEYS)
};

const uint16_t PROGMEM combo_fkeys[]    = {LT(_MOUSE, KC_TAB), ENT_NAV, COMBO_END};
const uint16_t PROGMEM combo_play[]     = {KC_VOLU, KC_VOLD, COMBO_END};
const uint16_t PROGMEM combo_tg_fkeys[] = {KC_LALT, KC_LGUI, KC_RALT, KC_RGUI, COMBO_END};

combo_t key_combos[] = {
    [COMBO_FKEYS]    = COMBO(combo_fkeys,    MO(_FKEYS)),
    [COMBO_PLAY]     = COMBO(combo_play,     KC_MPLY),
    [COMBO_TG_FKEYS] = COMBO(combo_tg_fkeys, TG(_FKEYS)),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // ┌───────┬───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┬───────┐
    // │  Tab  │   Q   │   W   │   E   │   R   │   T   │   │   Y   │   U   │   I   │   O   │   P   │  L2   │
    // ├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
    // │  Alt  │   A   │   S   │   D   │   F   │   G   │   │   H   │   J   │   K   │   L   │   Ñ   │   '   │
    // ├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
    // │ Shift │   Z   │   X   │   C   │   V   │   B   │   │   N   │   M   │   ,   │   .   │   -   │  L5   │
    // └───────┴───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────┴───────┘
    //                         │ Ctrl  │ Space │Sft/L3 │   │GUI/L4 │ Bspc  │Ent/L2 │
    //                         └───────┴───────┴───────┘   └───────┴───────┴───────┘
    [_BASE] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,       KC_Y,    KC_U, KC_I,    KC_O,   KC_P,    NUM_NO,
        KC_LALT, KC_A, KC_S, KC_D, KC_F, KC_G,       KC_H,    KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,       KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH, FN_NO,
                        KC_LCTL, KC_SPC, SFT_MO,      GUI_HYP, KC_BSPC, ENT_NAV
    ),

    // ┌───────┬───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┬───────┐
    // │  Esc  │       │       │       │       │       │   │   \   │   '   │   ]   │   [   │       │       │
    // ├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
    // │   `   │   1   │   2   │   3   │   4   │   5   │   │   6   │   7   │   8   │   9   │   0   │   -   │
    // ├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
    // │       │  <>   │       │       │       │       │   │       │       │       │       │       │   =   │
    // └───────┴───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────┴───────┘
    //                         │ Ctrl  │ Shift │AltGr  │   │  GUI  │ Bspc  │       │
    //                         └───────┴───────┴───────┘   └───────┴───────┴───────┘
    [_NUM] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_NO,          KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_BSLS, KC_QUOT, KC_RBRC, KC_LBRC, KC_NO,  KC_NO,
        KC_GRV,  KC_1,           KC_2,    KC_3,       KC_4,       KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS,
        KC_NO,   KC_NUBS,        KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_EQL,
                                          KC_LCTL,    KC_LSFT,    KC_RALT,    KC_LGUI, KC_BSPC, KC_NO
    ),

    // ┌───────┬───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┬───────┐
    // │       │       │       │       │       │       │   │       │       │       │       │       │       │
    // ├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
    // │  Alt  │ Home  │ PgDn  │ PgUp  │  End  │       │   │ Left  │  Up   │ Down  │ Right │       │       │
    // ├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
    // │ Shift │       │       │       │       │       │   │       │       │       │       │       │       │
    // └───────┴───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────┴───────┘
    //                         │ Ctrl  │ Space │  ▼▼▼  │   │  GUI  │ Bspc  │  ▼▼▼  │
    //                         └───────┴───────┴───────┘   └───────┴───────┴───────┘
    [_NAV] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO,
        KC_LALT, KC_HOME, KC_PGDN,  KC_PGUP, KC_END, KC_NO,      KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT, KC_NO, KC_NO,
        KC_LSFT, KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO,
                                    KC_LCTL, KC_SPC, KC_TRNS,    KC_LGUI, KC_BSPC, KC_TRNS
    ),

    // ┌───────┬───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┬───────┐
    // │       │       │       │       │       │       │   │       │  Ac2  │  Ac1  │  Ac0  │       │       │
    // ├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
    // │       │  ⏮   │  ⏭   │  ⏯   │ Vol-  │ Vol+  │   │  M←   │  M↑   │  M↓   │  M→   │       │       │
    // ├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
    // │       │       │       │       │       │       │   │       │  W↑   │  W↓   │ Mute  │       │       │
    // └───────┴───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────┴───────┘
    //                         │       │       │  ▼▼▼  │   │ Btn3  │ Btn2  │ Btn1  │
    //                         └───────┴───────┴───────┘   └───────┴───────┴───────┘
    [_MOUSE] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_ACL2, KC_ACL1, KC_ACL0, KC_NO,   KC_NO,
        KC_NO, KC_MPRV, KC_MNXT, KC_MPLY, KC_VOLD, KC_VOLU,      KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, KC_NO,   KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_WH_U, KC_WH_D, KC_MUTE, KC_NO,   KC_NO,
                                  KC_NO,  KC_NO,   KC_TRNS,      KC_BTN3, KC_BTN2, KC_BTN1
    ),

    // ┌───────┬───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┬───────┐
    // │       │       │  WS2  │       │       │       │   │       │       │       │       │       │       │
    // ├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
    // │  Alt  │  WS1  │ S+tgl │  WS3  │  WS4  │  WS5  │   │  S+H  │  S+J  │  S+K  │  S+L  │       │       │
    // ├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
    // │       │  S+.  │  WS-  │       │       │  WS+  │   │  S+←  │  S+↑  │  S+↓  │  S+→  │       │       │
    // └───────┴───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────┴───────┘
    //                         │ Ctrl  │ Shift │       │   │  GUI  │  ▼▼▼  │       │
    //                         └───────┴───────┴───────┘   └───────┴───────┴───────┘
    [_HYPR] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,          LGUI(KC_2), KC_NO,          KC_NO,          KC_NO,          KC_NO,             KC_NO,             KC_NO,             KC_NO,              KC_NO, KC_NO,
        KC_LALT, LGUI(KC_1),     LGUI(KC_S), LGUI(KC_3),     LGUI(KC_4),     LGUI(KC_5),     LGUI(KC_H),        LGUI(KC_J),        LGUI(KC_K),        LGUI(KC_L),         KC_NO, KC_NO,
        KC_NO,   LGUI(KC_DOT),   LGUI(KC_6), KC_NO,          KC_NO,          LGUI(KC_5),     LGUI(KC_LEFT),     LGUI(KC_UP),       LGUI(KC_DOWN),     LGUI(KC_RIGHT),     KC_NO, KC_NO,
                                             KC_LCTL,         KC_LSFT,        KC_NO,          KC_LGUI,           KC_TRNS,           KC_NO
    ),

    // ┌───────┬───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┬───────┐
    // │       │       │       │       │       │       │   │       │       │       │       │       │       │
    // ├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
    // │       │  F1   │  F2   │  F3   │  F4   │  F5   │   │  F6   │  F7   │  F8   │  F9   │  F10  │  F11  │
    // ├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
    // │       │  F12  │       │       │       │       │   │       │       │       │       │       │       │
    // └───────┴───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────┴───────┘
    //                         │       │       │       │   │       │       │       │
    //                         └───────┴───────┴───────┘   └───────┴───────┴───────┘
    [_FKEYS] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,
        KC_NO, KC_F1,  KC_F2, KC_F3, KC_F4, KC_F5,      KC_F6, KC_F7, KC_F8, KC_F9,  KC_F10, KC_F11,
        KC_NO, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,
                               KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO
    ),
};
// clang-format on
