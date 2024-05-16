/*
 * ws2812_spi.c
 *
 *  Created on: Feb 22, 2024
 *      Author: chris
 */


#include "../Inc/ws2812_spi.h"
#include "string.h"
#include "stdlib.h"

uint8_t *spi_send_data;

void ws2812_spi_adjust_brightness(ws2812_configuration* ws2812_conf, uint8_t brightness) {
	uint8_t green, red, blue;
    
    
	for (uint8_t i = 0; i < ws2812_conf->led_num; i++) {
        green = ws2812_conf->led_data[i][GREEN] * brightness / 100;
        red = ws2812_conf->led_data[i][RED] * brightness / 100;
        blue = ws2812_conf->led_data[i][BLUE] * brightness / 100;

        for (uint8_t j = 0; j < 8; j++) {
			uint16_t index = i * 24 + j;
			spi_send_data[index] = (green & (1 << (7 - j))) ? 0b1110 : 0b100;
			spi_send_data[index + 8] = (red & (1 << (7 - j))) ? 0b1110 : 0b100;
			spi_send_data[index + 16] = (blue & (1 << (7 - j))) ? 0b1110 : 0b100;
        }
    }
 
    SPI1_BufferWrite(spi_send_data, ws2812_conf->led_num * 24);

    __delay_us(285);
}

void ws2812_spi_fade(ws2812_configuration* ws2812_conf, uint16_t fade_time_ms) {

  uint16_t fade_delay = 0;
  
  /* Do nothing */
  if (fade_time_ms < ws2812_conf->brightness) {
	return;
  }
  
  fade_delay = (fade_time_ms / ws2812_conf->brightness) / 2;
  
  for (int fade = ws2812_conf->brightness; fade >= 0; fade -= 2) {
    ws2812_spi_adjust_brightness(ws2812_conf, (uint8_t) fade);
    ws2812_delay_ms(fade_delay);
  }
  
  for (int fade = 0; fade < ws2812_conf->brightness; fade += 2) {
    ws2812_spi_adjust_brightness(ws2812_conf, (uint8_t) fade);
    ws2812_delay_ms(fade_delay);
  }

}

void ws2812_spi_data(ws2812_configuration* ws2812_conf, uint8_t green, uint8_t red, uint8_t blue, uint8_t brightness) {

    uint8_t send_data[24];
	
    green = green * brightness / 100;
	red = red * brightness / 100;
	blue = blue * brightness / 100;

	for (uint8_t i = 0; i < 8; i++) {
        uint8_t mask = (uint8_t)(1 << (7 - i));
		send_data[i] = (green & mask) ? 0b1110 : 0b100;
		send_data[i + 8] = (red & mask) ? 0b1110 : 0b100;
		send_data[i + 16] = (blue & mask) ? 0b1110 : 0b100;
	}

    SPI1_BufferWrite(send_data, 24);
}

void ws2812_spi_send_single(ws2812_configuration* ws2812_conf) {

	for (uint8_t i = 0; i < ws2812_conf->led_num; i++) {
		ws2812_spi_data(ws2812_conf, ws2812_conf->led_data[i][GREEN], ws2812_conf->led_data[i][RED], ws2812_conf->led_data[i][BLUE], ws2812_conf->brightness);
	}
    __delay_us(285);
}



void ws2812_spi_send(ws2812_configuration* ws2812_conf) {
	
	uint8_t green, red, blue;
    
	for (uint8_t i = 0; i < ws2812_conf->led_num; i++) {
        green = ws2812_conf->led_data[i][GREEN] * ws2812_conf->brightness / 100;
        red = ws2812_conf->led_data[i][RED] * ws2812_conf->brightness / 100;
        blue = ws2812_conf->led_data[i][BLUE] * ws2812_conf->brightness / 100;

        for (uint8_t j = 0; j < 8; j++) {
			uint16_t index = i * 24 + j;
			spi_send_data[index] = (green & (1 << (7 - j))) ? 0b1110 : 0b100;
			spi_send_data[index + 8] = (red & (1 << (7 - j))) ? 0b1110 : 0b100;
			spi_send_data[index + 16] = (blue & (1 << (7 - j))) ? 0b1110 : 0b100;
        }
    }

 
    SPI1_BufferWrite(spi_send_data, ws2812_conf->led_num * 24);

    __delay_us(285);
}


bool ws2812_spi_init(ws2812_configuration* ws2812_conf) {

	// create a buffer for the data using ws2812_configuration
	ws2812_conf->led_data = malloc(ws2812_conf->led_num * sizeof(*ws2812_conf->led_data));

	if (ws2812_conf->led_data == NULL) {
		return false;
	}
    
    spi_send_data = malloc(ws2812_conf->led_num * 24);
    
    if (spi_send_data == NULL) {
        return false;
    }

   	memset(ws2812_conf->led_data, 0, ws2812_conf->led_num * sizeof(*ws2812_conf->led_data));

	// Set all leds to 0
    ws2812_spi_send(ws2812_conf);

	return true;
}

void ws2812_spi_clear(ws2812_configuration* ws2812_conf) {
    for (uint8_t i = 0; i < ws2812_conf->led_num; i++) {
        ws2812_set_led(ws2812_conf, i, 0, 0, 0);
    }
	ws2812_spi_send(ws2812_conf);
}

void ws2812_spi_deinit(ws2812_configuration* ws2812_conf) {

	free(ws2812_conf->led_data);
    free(spi_send_data);
	ws2812_conf->led_data = NULL;
	ws2812_conf->handle = NULL;
	ws2812_conf->led_num = 0;
	ws2812_conf->brightness = 0;
	ws2812_conf->dma = 0;
}






