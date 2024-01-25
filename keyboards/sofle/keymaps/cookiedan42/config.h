#pragma once
#define MASTER_RIGHT
// master needs to be connected to computer to read data



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