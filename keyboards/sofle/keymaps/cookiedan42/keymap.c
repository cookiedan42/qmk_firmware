#include QMK_KEYBOARD_H

// not using magic keycodes to swap
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
uint8_t mod_config(uint8_t mod) {
    return mod;
}



enum sofle_layers {
    _QWERTY,
    _FN,
    _CODE,
    _NUM,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
};
const uint16_t KC_PRVWD = LCTL(KC_LEFT);
const uint16_t KC_NXTWD = LCTL(KC_RIGHT);
const uint16_t KC_RUN = LALT(KC_SPC);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BAR  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   ?  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | / Space /       \Enter \  | ENT |      |      |      |
 *            |      |  WIN | LALT | LCTRL|/       /         \  Fn  \ |CODE | NUM  |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */


[_QWERTY] = LAYOUT_enc_front( XXXXXXX,XXXXXXX,
  KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5  ,          KC_6           , KC_7            , KC_8    , KC_9   , KC_0   , KC_BSPC,      
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T  ,          KC_Y           , KC_U            , KC_I    , KC_O   , KC_P   , KC_DEL ,     
  KC_RUN , KC_A   , KC_S   , KC_D   , KC_F   , KC_G  ,          KC_H           , KC_J            , KC_K    , KC_L   , KC_SCLN, KC_QUOT,     
  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B  ,          KC_N           , KC_M            , KC_COMM , KC_DOT , KC_SLSH, KC_RSFT,    
           XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_SPC,          LT(_FN,KC_BSPC), LT(_CODE,KC_ENT), TG(_NUM), XXXXXXX, XXXXXXX 
),
/* FN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  | F6                        |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | PGUP |      |      |                    |      |      | Up   |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | PRVWD| PGDWN| NXTWD|      |-------.    ,-------|      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|        |   |       |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      | -------|   |-------|      |      |      |      |      |      | 
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  WIN |  BAR |      |      | / MENU  /       \Enter \  | ENT |      |      |      |
 *            |  WIN |      | LALT | LCTRL|/       /         \  Fn  \ |CODE | NUM  |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */

[_FN] = LAYOUT_enc_front( XXXXXXX,XXXXXXX,
  KC_F1  , KC_F2  , KC_F3  ,  KC_F4  , KC_F5  ,  KC_F6  ,       KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,     
  XXXXXXX, XXXXXXX, XXXXXXX,  KC_PGUP, XXXXXXX,  XXXXXXX,       XXXXXXX, XXXXXXX, KC_UP  , XXXXXXX, XXXXXXX, XXXXXXX,       
  XXXXXXX, XXXXXXX, KC_PRVWD, KC_PGDN, KC_NXTWD, XXXXXXX,       XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,      
  _______, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      
           _______, _______,  _______, _______,  KC_APP ,       _______, _______, _______, _______, _______
),

/* CODE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ~   |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |  =   |  -   |  +   |   {  |   }  |-------.    ,-------|   [  |   ]  |   ;  |   :  |   \  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   |  |  _   |      |   <  |   >  |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  WIN |  BAR |      |      | / Space /       \Enter \  | ENT |      |      |      |
 *            |  WIN |      | LALT | LCTRL|/       /         \  Fn  \ |CODE | NUM  |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_CODE] = LAYOUT_enc_front( XXXXXXX,XXXXXXX,
  KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,         KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
  KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  KC_GRV , KC_EQL , KC_PMNS, KC_PPLS, KC_LCBR, KC_RCBR,         KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, XXXXXXX,
  _______, KC_UNDS, KC_PIPE, XXXXXXX, KC_LABK, KC_RABK,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
           _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______

),
/* NUM
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * |  ESC |  1   |  2   |  3   | +  = | BKSP |                    |      |      |      |      |      |AS_TOG|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  4   |  5   |  6   |   -  | Tab  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |NUM_LK|  7   |  8   |  9   |   *  | Enter|-------.    ,-------|     |       |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|  (   |  0   |  )   |   /  |  .   |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  WIN |  BAR |      |      | / Space /       \Enter \  | ENT |      |      |      |
 *            |  WIN |      | LALT | LCTRL|/       /         \  Fn  \ |CODE | NUM  |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_NUM] = LAYOUT_enc_front( XXXXXXX,XXXXXXX,
  KC_ESC , KC_P1  , KC_P2  , KC_P3  , KC_EQL , KC_BSPC,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AS_TOGG,
  KC_TAB , KC_P4  , KC_P5  , KC_P6  , KC_PMNS, KC_TAB ,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AS_UP  ,
  KC_NUM , KC_P7  , KC_P8  , KC_P9  , KC_PAST, KC_ENT ,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AS_DOWN,
  KC_LSFT, KC_LPRN, KC_P0  , KC_RPRN, KC_PSLS, KC_PDOT,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AS_RPT ,
           _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______
  ),
};




// new user defined keys behaviour

// calling the user defined keys

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     return true;
// }

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(index){
        case 0:
            clockwise
                ?tap_code(KC_VOLU)
                :tap_code(KC_VOLD);
            break;
        case 1:
            clockwise
                ?tap_code(KC_PGDN);
                :tap_code(KC_PGUP);
            break;
    }
    return false;
}

#endif


#ifdef OLED_ENABLE

static void print_status_narrow(void) {
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), true);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _FN:
            oled_write_ln_P(PSTR("Func"), false);
            break;
        case _CODE:
            oled_write_ln_P(PSTR("Code"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("NUM"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }

    // Print active locks
    oled_write_ln_P(PSTR("\n\nLOCK"), true);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("numLK") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("capLK") : PSTR("    "), false);

 }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    print_status_narrow();
    return false;
}

#endif
