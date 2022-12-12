#ifdef ENABLE_RGB_MATRIX_GLORIOUS_PASTEL_BREATHING
RGB_MATRIX_EFFECT(GLORIOUS_PASTEL_BREATHING)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "custom/david_libs.h"

bool GLORIOUS_PASTEL_BREATHING(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV config_hsv = rgb_matrix_config.hsv;
    
    HSV blue_base = config_hsv;
    blue_base.h = GLORIOUS_PASTEL_BLUE_HUE;
    blue_base.s = GLORIOUS_PASTEL_BLUE_SAT;

    HSV green_base = config_hsv;
    green_base.h = GLORIOUS_PASTEL_GREEN_HUE;
    green_base.s = GLORIOUS_PASTEL_GREEN_SAT;

    HSV pink_base = config_hsv;
    pink_base.h = GLORIOUS_PASTEL_PINK_HUE;
    pink_base.s = GLORIOUS_PASTEL_PINK_SAT;

    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    uint8_t hsv_v = scale8(abs8(sin8(time) - 128) * 2, config_hsv.v);

    blue_base.v = hsv_v;
    green_base.v = hsv_v;
    pink_base.v = hsv_v;

    RGB blue_final = rgb_matrix_hsv_to_rgb(blue_base);
    RGB green_final = rgb_matrix_hsv_to_rgb(green_base);
    RGB pink_final = rgb_matrix_hsv_to_rgb(pink_base);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        // Blue LEDs
        if(GLORIOUS_PASTEL_is_blue(i)) {
            rgb_matrix_set_color(i, blue_final.r, blue_final.g, blue_final.b);
        }
        // Green LEDS
        else if(GLORIOUS_PASTEL_is_green(i)) {
            rgb_matrix_set_color(i, green_final.r, green_final.g, green_final.b);
        }
        // Pink LEDs
        else if(GLORIOUS_PASTEL_is_pink(i)) {
            rgb_matrix_set_color(i, pink_final.r, pink_final.g, pink_final.b);
        }
        else {
            rgb_matrix_set_color(i, 255, 255, 255);
        }
        
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif //ENABLE_RGB_MATRIX_GLORIOUS_PASTEL_BREATHING
