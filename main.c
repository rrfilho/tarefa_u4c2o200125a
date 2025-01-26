#include <stdio.h>
#include "pico/stdlib.h"
#include "keypad.h"
#include "led_matrix.h"
#include "animation_one.h"
#include "animation_two.h"
#include "animation_three.h"
#include "animation_four.h"
#include "animation_eight.h"


void init() {
    stdio_init_all();
    keypad_init();
    led_matrix_init();
}

int main() {
    init();
    while (true) {
        char key = keypad_read();
        if (key == '\0') continue;
        switch (key) {
            case '1': led_matrix_draw_animation(animation_one); break;
            case '2': led_matrix_draw_animation(animation_two); break;
            case '3': led_matrix_draw_animation(animation_three); break;
            case '4': led_matrix_draw_animation(animation_four); break;
            case '8': led_matrix_draw_animation(animation_eight); break;
            case 'A': led_matrix_draw("000000"); break;
            case 'B': led_matrix_draw("0000FF"); break;
            case 'C': led_matrix_draw("CC0000"); break; // 255*80% = 204 = 0xCC
            case 'D': led_matrix_draw("007F00"); break; // 255*50% =~127 = 0x7F
            case '#': led_matrix_draw("333333"); break; // 255*20% = 51 = 0x33
        }
        sleep_ms(500);
    }
}