/*
 * ws2812.c
 *
 *  Created on: Feb 22, 2024
 *      Author: chris
 */

#include "../Inc/ws2812.h"


// Stores all LEDs in memory (3 bytes per LED * ws2812_conf->led_num = 75 bytes)
void ws2812_set_led(ws2812_configuration* ws2812_conf, uint8_t led, uint8_t red, uint8_t green, uint8_t blue) {

    if (led >= ws2812_conf->led_num) {
        return;
    }
    
    ws2812_conf->led_data[led][GREEN] = green;
    ws2812_conf->led_data[led][RED] = red;
    ws2812_conf->led_data[led][BLUE] = blue;
}


void ws2812_delay_ms(uint16_t ms) {
    for (uint16_t i = 0; i < ms; i++) {
        __delay_ms(1);
    }
}

