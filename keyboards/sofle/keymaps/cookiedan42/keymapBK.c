#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _FN,
    _CODE,
    _NUM,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_FN,
    KC_CODE,
    KC_NUM,

    KC_PRVWD,
    KC_NXTWD,
};

/*
 * TEMPLATE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 * [_LAYOUT] = LAYOUT(
 *   6,    6
 *   6,    6
 *   6,    6
 *   6,e,e,6
 *   5,    5
 * )
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   ?  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | GUI  | LAlt | Fn   | / Space /       \Enter \  |CODE | NUM  |      |      |
 *            |      |      |      |      |/       /         \      \ |     |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( 
    KC_ESC,   KC_1, KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,          KC_7,   KC_8,    KC_9,   KC_0,    KC_BSPC,      
    KC_TAB,   KC_Q, KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,          KC_U,   KC_I,    KC_O,   KC_P,    KC_DEL,     
    XXXXXXX, KC_A, KC_S,     KC_D,    KC_F,    KC_G,                              KC_H,          KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,     
    KC_LSFT, KC_Z, KC_X,     KC_C,    KC_V,    KC_B,   XXXXXXX,          XXXXXXX, KC_N,          KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,    
                   KC_LCTRL, KC_LGUI, KC_LALT, KC_FN,  KC_SPC,           KC_BSPC, LT(0,KC_CODE), KC_NUM, XXXXXXX, XXXXXXX 
),

/* FN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  | F6                        |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |                    | PGUP |NXT_WD | Up  |PRV_WD|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| PGDWN| Left | Down | Right| MENU |      |
 * |------+------+------+------+------+------|        |   |       |------+------+------+------+------+------|
 * |LShift| Undo |  Cut | Copy | Paste|      | -------|   |-------|      |      |      |      |      |      | 
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | GUI  | LALT | Fn   | / Space /       \Enter \  |CODE | NUM  |      |      |
 *            |      |      |      |      |/       /         \      \ |     |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */

[_FN] = LAYOUT( \
  KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,    KC_F6,                           KC_F7,     KC_F8,    KC_F9,   KC_F10,   KC_F11,  KC_F12,     
  _______,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                         KC_PGUP,   KC_PRVWD, KC_UP,   KC_NXTWD, XXXXXXX, XXXXXXX,       
  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                         KC_PGDOWN, KC_LEFT,  KC_DOWN, KC_RGHT,  KC_APP,  XXXXXXX,      
   _______, KC_UNDO, KC_CUT,   KC_COPY, KC_PASTE, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,      
                     _______,  _______, _______, _______,  _______,       _______,  _______, _______,  _______, _______
),

/* CODE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | F1   |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11   | F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |   _  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  =   |  -   |  +   |   {  |   }  |-------.    ,-------|   [  |   ]  |   ;  |   :  |   \  |   |  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|      |      |      |   <  |   >  |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | GUI  | LAlt | Fn   | / Space /       \Enter \  |CODE | NUM  |      |      |
 *            |      |      |      |      |/       /         \      \ |     |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_CODE] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6,                            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  XXXXXXX, KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC,                          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  XXXXXXX, KC_EQL,  KC_PMNS,  KC_PPLS, KC_LCBR, KC_RCBR,                          KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_PIPE,
  _______, XXXXXXX, XXXXXXX,  XXXXXXX, KC_LABK, KC_RABK, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______,  _______,        _______,  _______, _______,  _______, _______

),
/* NUM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |  1   |  2   |  3   | +  = | BKSP |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  4   |  5   |  6   |   -  | Tab  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  7   |  8   |  9   |   *  | Enter|-------.    ,-------|     |       |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|  (   |  0   |  )   |   /  |  .   |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | GUI  | LAlt | Fn   | / Space /       \Enter \  |CODE | NUM  |      |      |
 *            |      |      |      |      |/       /         \      \ |     |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_NUM] = LAYOUT( \
  KC_ESC,  KC_P1,   KC_P2,   KC_P3,   KC_EQL,  KC_BSPC,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  \
  _______, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_TAB,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   \
  XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_ENT,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   \
  _______, KC_LPRN, KC_P0,   KC_RPRN, KC_PSLS, KC_PDOT, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   \
                    _______, _______, _______, _______, _______,        _______,  _______, _______,  _______, _______
  ),
};




// new user defined keys behaviour

bool key_FN (uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        layer_on(_FN);
    } else {
        layer_off(_FN);
    }
    return false;
}

bool key_CODE (uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        layer_on(_CODE);
    } else {
        layer_off(_CODE);
    }
    return false;
}


bool key_NUM (uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        layer_on(_NUM);
    } else {
        layer_off(_NUM);
    }
    return false;
}

bool key_PRVWD (uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        register_mods(mod_config(MOD_LCTL));
        register_code(KC_LEFT);
    } else {
        unregister_mods(mod_config(MOD_LCTL));
        unregister_code(KC_LEFT);
    }
    return false;
}

bool key_NXTWD (uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        register_mods(mod_config(MOD_LCTL));
        register_code(KC_RIGHT);
    } else {
        unregister_mods(mod_config(MOD_LCTL));
        unregister_code(KC_RIGHT);
    }
    return false;
}

bool key_COPY (uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        register_mods(mod_config(MOD_LCTL));
        register_code(KC_C);
    } else {
        unregister_mods(mod_config(MOD_LCTL));
        unregister_code(KC_C);
    }
    return false;
}

bool key_PASTE (uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        register_mods(mod_config(MOD_LCTL));
        register_code(KC_V);
    } else {
        unregister_mods(mod_config(MOD_LCTL));
        unregister_code(KC_V);
    }
    return false;
}

bool key_CUT (uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        register_mods(mod_config(MOD_LCTL));
        register_code(KC_X);
    } else {
        unregister_mods(mod_config(MOD_LCTL));
        unregister_code(KC_X);
    }
    return false;
}
bool key_UNDO (uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        register_mods(mod_config(MOD_LCTL));
        register_code(KC_Z);
    } else {
        unregister_mods(mod_config(MOD_LCTL));
        unregister_code(KC_Z);
        }
    return false;
}



// calling the user defined keys

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // return true if unmodified

switch (keycode) {
case LT(0,KC_CODE):
    if (record->tap.count && record->event.pressed) {
        tap_code16(KC_ENT);         // Return true for normal processing of tap keycode
        return false;
    } else {
        return key_CODE(keycode, record);
    }

case KC_FN:
            return key_FN(keycode,record);
case KC_CODE:
            return key_CODE(keycode,record);
case KC_NUM:
            return key_NUM(keycode, record);
case KC_PRVWD:
            return key_PRVWD(keycode, record);
case KC_NXTWD:
            return key_NXTWD(keycode, record);
case KC_COPY:
            return key_COPY(keycode, record);
case KC_PASTE:
            return key_PASTE(keycode, record);
case KC_CUT:
            return key_CUT(keycode, record);
case KC_UNDO:
            return key_UNDO(keycode, record);
    }
    // if not caught
    return true;
}












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
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
