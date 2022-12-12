#pragma once
#include "rgb_matrix.h"

#define GLORIOUS_PASTEL_BLUE_HUE 166
#define GLORIOUS_PASTEL_BLUE_SAT 206
#define GLORIOUS_PASTEL_GREEN_HUE 92
#define GLORIOUS_PASTEL_GREEN_SAT 203
#define GLORIOUS_PASTEL_PINK_HUE 254
#define GLORIOUS_PASTEL_PINK_SAT 200

bool GLORIOUS_PASTEL_is_blue(uint8_t index) {
    return (
        index == 0 || index == 1 ||
        (16 <= index && index <= 18) ||
        (33 <= index && index <= 37) ||
        (50 <= index && index <= 56) ||
        (63 <= index && index <= 69) ||
        (76 <= index && index <= 80)
    );
}


bool GLORIOUS_PASTEL_is_green(uint8_t index) {
    return (
        (2 <= index && index <= 7) ||
        (19 <= index && index <= 25) ||
        (38 <= index && index <= 43) ||
        (57 <= index && index <= 60) ||
        (70 <= index && index <= 73) ||
        (81 <= index && index <= 83)
    );
}


bool GLORIOUS_PASTEL_is_pink(uint8_t index) {
    return (
        (8 <= index && index <= 15) ||
        (26 <= index && index <= 32) ||
        (44 <= index && index <= 49) ||
        (61 <= index && index <= 62) ||
        (74 <= index && index <= 75) ||
        (84 <= index && index <= 86)
    );
}