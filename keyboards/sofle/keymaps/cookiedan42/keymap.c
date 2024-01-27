#include QMK_KEYBOARD_H

#ifdef LUNA_ENABLE
    #include "luna.h"
#endif

// not using magic keycodes to swap
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
uint8_t mod_config(uint8_t mod) {
    return mod;
}

enum layers {
    _QWER,
    _QW_S,
    _FUNC,
    _CODE,
    _COD2,
    _TEST,
    _MOUS,
};

enum custom_keycodes {
    CC_WIND = SAFE_RANGE,
    CC_VOL,
    CC_ZOOM,
};

const uint16_t KC_PRVWD = LCTL(KC_LEFT);
const uint16_t KC_NXTWD = LCTL(KC_RIGHT);
const uint16_t CC_FN_BK = LT(_FUNC,KC_BSPC);
const uint16_t CC_CO_EN = LT(_CODE,KC_ENT);
const uint16_t CC_SPC2 = LT(_QW_S,KC_SPC);
const uint16_t CC_LCTL = LCTL_T(KC_LPAD);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   ?  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | / Space /       \ BKSP \  | ENT  |      |      |      |
 *            |      |  WIN | LALT | LCTRL|/       /         \  Fn  \ | CODE |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */


[_QWER] = LAYOUT_enc_front( XXXXXXX,XXXXXXX,
  KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5  ,          KC_6     , KC_7     , KC_8   , KC_9   , KC_0   , KC_BSPC,      
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T  ,          KC_Y     , KC_U     , KC_I   , KC_O   , KC_P   , KC_DEL ,     
  XXXXXXX, KC_A   , KC_S   , KC_D   , KC_F   , KC_G  ,          KC_H     , KC_J     , KC_K   , KC_L   , KC_SCLN, KC_QUOT,     
  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B  ,          KC_N     , KC_M     , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,    
           XXXXXXX, KC_LGUI, KC_LALT, CC_LCTL, CC_SPC2,         CC_FN_BK , CC_CO_EN , XXXXXXX, XXXXXXX, XXXXXXX 
),
[_QW_S] = LAYOUT_TRNS(),

/* FN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | ZOOM |      |      |      |      |                    |      | HOME | Up   | END  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LCTL | SHFT | LALT |      |      |-------.    ,-------|      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|        |   |       |------+------+------+------+------+------|
 * |LShift| TVOL |      | TWIND|      |      | -------|   |-------|      |      |      |      |      |AS_T0G| 
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | / Space /       \ BKSP \  | ENT  |      |      |      |
 *            |      |  WIN | LALT | LCTRL|/       /         \  Fn  \ | CODE |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_FUNC] = LAYOUT_enc_front( XXXXXXX,XXXXXXX,
  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,       KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,     
  XXXXXXX, CC_ZOOM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, KC_HOME, KC_UP  , KC_END , XXXXXXX, XXXXXXX,       
  XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, XXXXXXX, XXXXXXX,       XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,      
  XXXXXXX, CC_VOL , XXXXXXX, CC_ZOOM, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AS_TOGG,      
           _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

/* CODE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ~   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  =   |  -   |  +   |   {  |   }  |-------.    ,-------|   [  |   ]  |   ;  |   :  |   \  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|  |   |  _   |      |   <  |   >  |-------|    |-------|   (  |   )  |   ,  |   .  |   ?  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | / Space /       \ BKSP \  | ENT  |      |      |      |
 *            |      |  WIN | LALT | LCTRL|/       /         \  Fn  \ | CODE |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_CODE] = LAYOUT_enc_front( XXXXXXX,XXXXXXX,
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,         KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
  KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, KC_EQL , KC_PMNS, KC_PPLS, KC_LCBR, KC_RCBR,         KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, XXXXXXX,
  _______, KC_UNDS, KC_PIPE, XXXXXXX, KC_LABK, KC_RABK,         KC_LPRN, KC_RPRN, KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
           _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______

),

/* CODE2
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ~   |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | / Space /       \ BKSP \  | ENT  |      |      |      |
 *            |      |  WIN | LALT | LCTRL|/       /         \  Fn  \ | CODE |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_COD2] = LAYOUT_enc_front( XXXXXXX,XXXXXXX,
  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,         KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,     
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,         KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
  KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______

),

/* MOUSE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      | Click|MS_UP |RClick|      | ACL2 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | MS_L |MS_DN | MS_R |      | ACL1 |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      | ACL0 |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | / Space /       \ BKSP \  | ENT  |      |      |      |
 *            |      |  WIN | LALT | LCTRL|/       /         \  Fn  \ | CODE |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
  [_MOUS] = LAYOUT_enc_front( XXXXXXX, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, KC_ACL2,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_ACL1,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______ 
  ),

};




// new user defined keys behaviour

// calling the user defined keys

enum mini_layers {
    mini_default = 0,
    mini_isVol,
    mini_isWind,
    mini_isZoom,
};
uint8_t miniLayer = mini_default;

bool handle_KC_UP(keyrecord_t *record){
    switch(miniLayer){
        case mini_isWind:
            if(record->event.pressed){
                register_code(KC_LALT);
                register_code(KC_ESC);
            } else{
                unregister_code(KC_ESC);
                unregister_code(KC_LALT);
            }
            return false;
        case mini_isVol:
            if(record->event.pressed){
                register_code(KC_VOLU);
            } else{
                unregister_code(KC_VOLU);
            }
            return false;
        case mini_isZoom:
            if(record->event.pressed){
                register_code(KC_LCTL);
                register_code(KC_PPLS);
            } else{
                unregister_code(KC_PPLS);
                unregister_code(KC_LCTL);
            }
            return false;

    }
    return true;
}
bool handle_KC_DOWN(keyrecord_t *record){
    switch(miniLayer){
        case mini_isWind:
            if(record->event.pressed){
                register_code(KC_LALT);
                register_code(KC_LSFT);
                register_code(KC_ESC);
            } else{
                unregister_code(KC_ESC);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            return false;
        case mini_isVol:
            if(record->event.pressed){
                register_code(KC_VOLD);
            } else{
                unregister_code(KC_VOLD);
            }
            return false;
        case mini_isZoom:
            if(record->event.pressed){
                register_code(KC_LCTL);
                register_code(KC_PMNS);
            } else{
                unregister_code(KC_PMNS);
                unregister_code(KC_LCTL);
            }
    }
    return true;
}
bool handle_KC_LEFT(keyrecord_t *record){
    switch(miniLayer){
        case mini_isVol:
            tap_code(KC_VOLU);
            tap_code(KC_VOLD);
            tap_code(KC_MUTE);
            return false;
        case mini_isWind:
            if(record->event.pressed){
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_TAB);
            } else{
                unregister_code(KC_TAB);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false;
    }
    return true;
}
bool handle_KC_RGHT(keyrecord_t *record){
    switch(miniLayer){
        case mini_isVol:
            tap_code(KC_VOLU);
            tap_code(KC_VOLD);
            return false;
        case mini_isWind:
            if(record->event.pressed){
                register_code(KC_LCTL);
                register_code(KC_TAB);
            } else{
                unregister_code(KC_TAB);
                unregister_code(KC_LCTL);
            }
            return false;
    }
    return true;
}
bool handle_KC_HOME(keyrecord_t *record){
  switch(miniLayer){
    case mini_isWind:
        if(record->event.pressed){
            register_code(KC_LGUI);
            register_code(KC_LCTL);
            register_code(KC_LEFT);
        } else{
            unregister_code(KC_LEFT);
            unregister_code(KC_LCTL);
            unregister_code(KC_LGUI);
        }
        return false;
    }
    return true;
}
bool handle_KC_END(keyrecord_t *record){
    switch(miniLayer){
        case mini_isWind:
            if(record->event.pressed){
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_RGHT);
            } else{
                unregister_code(KC_RGHT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
            }
            return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode){
        case CC_VOL:  miniLayer = mini_isVol  * record->event.pressed; return false;
        case CC_WIND: miniLayer = mini_isWind * record->event.pressed; return false;
        case CC_ZOOM: miniLayer = mini_isZoom * record->event.pressed; return false;
        case LCTL_T(KC_LPAD):
            if (!(record->tap.count && record->event.pressed)) {return true;}
        case KC_LPAD: 
            if (record->event.pressed){ tap_code16(LALT(KC_SPC)); } return false;

        case KC_UP:   return handle_KC_UP(record);
        case KC_DOWN: return handle_KC_DOWN(record);
        case KC_LEFT: return handle_KC_LEFT(record);
        case KC_RGHT: return handle_KC_RGHT(record);
        case KC_HOME: return handle_KC_HOME(record);
        case KC_END: return handle_KC_END(record);
    }
    return true;
}
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(index<<1 | clockwise){
        case 0: tap_code(KC_VOLD); break;
        case 1: tap_code(KC_VOLU); break;
        // case 2: tap_code(KC_PGUP); break;
        // case 3: tap_code(KC_PGDN); break;       
        case 2: tap_code(KC_WH_U); break;
        case 3: tap_code(KC_WH_D); break;
    }
    return false;
}
#endif


#ifdef OLED_ENABLE

static void print_status_narrow(void) {
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), true);
    switch (get_highest_layer(layer_state)) {
        case _QWER:
        case _QW_S:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _FUNC:
            oled_write_ln_P(PSTR("Func"), false);
            break;
        case _CODE:
            oled_write_ln_P(PSTR("Code1"), false);
            break;        
        case _COD2:
            oled_write_ln_P(PSTR("Code2"), false);
            break;        
        case _MOUS:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }

    // Print active locks
    oled_write_ln_P(PSTR("\n\nLOCK"), true);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock  ? PSTR("numLK") : PSTR("     "), false);
    oled_write_P(led_state.caps_lock ? PSTR("capLK") : PSTR("     "), false);
    
    #ifdef LUNA_ENABLE
    render_luna(0, 13);
    #endif
 }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}
                            
bool oled_task_user(void) {
    print_status_narrow();
    return false;
}

#endif

#ifdef AUTO_SHIFT_TIMEOUT_PER_KEY
    uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
        if (get_mods()){
            return 2 * get_generic_autoshift_timeout();
        } else{
            return get_generic_autoshift_timeout();
        }
    }
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    layer_state_t state1 = state;
   state1 = update_tri_layer_state(state1, _QW_S, _FUNC, _MOUS);
   state1 = update_tri_layer_state(state1, _QW_S, _CODE, _COD2);
   return state1;
}