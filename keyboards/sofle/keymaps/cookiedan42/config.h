#pragma once
#define EE_HANDS
// handedness defined by EEPROM persistent memory


#define AUTO_SHIFT_MODIFIERS
#define AUTO_SHIFT_TIMEOUT 110
/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/



// Cherry MX Lock switch
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define NO_MUSIC_MODE

// add overhead, but enables both displays to show data
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE