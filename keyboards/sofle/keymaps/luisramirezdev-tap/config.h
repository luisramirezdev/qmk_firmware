#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define SPLIT_USB_DETECT
#define TAPPING_TERM_PER_KEY

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 250
#endif
