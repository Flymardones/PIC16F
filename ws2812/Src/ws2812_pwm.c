/*
 * ws2812_pwm.c
 *
 *  Created on: Feb 28, 2024
 *      Author: chris
 */

#include "../Inc/ws2812_pwm.h"
#include "string.h"
#include "stdlib.h"


void ws2812_pwm_adjust_brightness(ws2812_configuration* ws2812_conf, uint8_t brightness) {
    uint8_t green, red, blue;
    uint8_t (*led_data)[3] = (uint8_t(*)[3])ws2812_conf->buffer;
    uint8_t *send_data = (uint8_t*) malloc(ws2812_conf->led_num * 24);
    
    if (send_data == NULL) {
        return;
    }

   	for (uint8_t i = 0; i < ws2812_conf->led_num; i++) {
        green = (led_data[i][GREEN] * brightness / 100);
        red = (led_data[i][RED] * brightness / 100);
        blue = (led_data[i][BLUE] * brightness / 100);
        
        for (uint8_t j = 0; j < 8; j++) {
            uint16_t index = i * 24 + j;
            send_data[index] = (green & (1 << (7 - j))) ? 0x14 : 0xA;
            send_data[index + 8] = (red & (1 << (7 - j))) ? 0x14 : 0xA;
            send_data[index + 16] = (blue & (1 << (7 - j))) ? 0x14 : 0xA;
        }
    }

    /* Send data */
    for (uint16_t i = 0; i < (ws2812_conf->led_num * 24); i++) {
        CCP1_LoadDutyValue(send_data[i]);
        T2CON |= 0x80;
    } 
    free(send_data);
    __delay_us(285);
}


void ws2812_pwm_fade(ws2812_configuration* ws2812_conf, uint16_t fade_time_ms) {

  uint16_t fade_delay = 0;
  
  /* Do nothing */
  if (fade_time_ms < ws2812_conf->brightness) {
	return;
  }
  
  fade_delay = (fade_time_ms / ws2812_conf->brightness) / 2;
  
  for (int fade = ws2812_conf->brightness; fade >= 0; fade -= 2) {
    ws2812_pwm_adjust_brightness(ws2812_conf, (uint8_t)fade);
    ws2812_delay_ms(fade_delay);
  }
  
  for (int fade = 0; fade < ws2812_conf->brightness; fade += 2) {
    ws2812_pwm_adjust_brightness(ws2812_conf, (uint8_t)fade);
    ws2812_delay_ms(fade_delay);
  }
}


void ws2812_pwm_data(ws2812_configuration* ws2812_conf, uint8_t green, uint8_t red, uint8_t blue, uint8_t brightness) {

	uint8_t send_data[24];
    
    green = green * brightness / 100;
	red = red * brightness / 100;
	blue = blue * brightness / 100;

    for (uint8_t i = 0; i < 8; i++) {
        send_data[i] = (green & (1 << (7 - i))) ? 0x14 : 0xA;
        send_data[i + 8] = (red & (1 << (7 - i))) ? 0x14 : 0xA;
        send_data[i + 16] = (blue & (1 << (7 - i))) ? 0x14 : 0xA;
    }

    for (uint8_t i = 0; i < 24; i++) {
        CCP1_LoadDutyValue(send_data[i]);
        T2CON |= 0x80;
    }
}

void ws2812_pwm_send_single(ws2812_configuration* ws2812_conf) {
    uint8_t (*led_data)[3] = (uint8_t(*)[3])ws2812_conf->buffer;

    for (uint8_t i = 0; i < ws2812_conf->led_num; i++) {
        ws2812_pwm_data(ws2812_conf, led_data[i][0],led_data[i][1],led_data[i][2], ws2812_conf->brightness);
    }

    __delay_us(285);
}


void ws2812_pwm_send(ws2812_configuration* ws2812_conf) {
    
    uint8_t green, red, blue;
    uint8_t (*led_data)[3] = (uint8_t(*)[3])ws2812_conf->buffer;
    uint8_t *send_data = (uint8_t*) malloc(ws2812_conf->led_num * 24);
    
    if (send_data == NULL) {
        return;
    }

   	for (uint8_t i = 0; i < ws2812_conf->led_num; i++) {
        green = (led_data[i][GREEN] * ws2812_conf->brightness / 100);
        red = (led_data[i][RED] * ws2812_conf->brightness / 100);
        blue = (led_data[i][BLUE] * ws2812_conf->brightness / 100);
        
        for (uint8_t j = 0; j < 8; j++) {
            uint16_t index = i * 24 + j;
            send_data[index] = (green & (1 << (7 - j))) ? 0x14 : 0xA;
            send_data[index + 8] = (red & (1 << (7 - j))) ? 0x14 : 0xA;
            send_data[index + 16] = (blue & (1 << (7 - j))) ? 0x14 : 0xA;
        }
    }

    /* Send data */
    for (uint16_t i = 0; i < (ws2812_conf->led_num * 24); i++) {
        CCP1_LoadDutyValue(send_data[i]);
        T2CON |= 0x80;
    } 
    free(send_data);
    __delay_us(285);
}

void ws2812_pwm_clear(ws2812_configuration* ws2812_conf) {
    for (uint8_t i = 0; i < ws2812_conf->led_num; i++) {
        ws2812_set_led(ws2812_conf, (uint8_t)i, 0, 0, 0);
    }
    ws2812_pwm_send(ws2812_conf);
}


bool ws2812_pwm_init(ws2812_configuration* ws2812_conf) {

    uint8_t (*led_data)[3] = malloc(ws2812_conf->led_num * sizeof(*led_data));

    if (led_data == NULL) {
        return false;
    }
    
    ws2812_conf->buffer = led_data;
    memset(ws2812_conf->buffer, 0, ws2812_conf->led_num * sizeof(*led_data));

    ws2812_pwm_send(ws2812_conf);

    return true;
}

void ws2812_pwm_deinit(ws2812_configuration* ws2812_conf) {

    free(ws2812_conf->buffer);
    ws2812_conf->buffer = NULL;
	ws2812_conf->handle = NULL;
	ws2812_conf->led_num = 0;
	ws2812_conf->brightness = 0;
	ws2812_conf->dma = 0;
}