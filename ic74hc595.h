/**
 * @file ic74hc595.h
 * @author Jaime Albuquerque (jaime.albq@gmail.com)
 * @brief Output shifter register library
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#if !defined(_IC74HC595_H_)
#define _IC74HC595_H_

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "driver/gpio.h"

#define IC74HC595_SEND_MODE_MSB_FIRST 0
#define IC74HC595_SEND_MODE_LSB_FIRST 1

typedef struct {
        gpio_num_t clock_pin;
        gpio_num_t signal_pin;
        gpio_num_t latch_pin;

        int send_mode;
} ic74hc595_t;

int8_t ic74hc595_init(ic74hc595_t *ic74hc595);

int8_t ic74hc595_send(ic74hc595_t *ic74hc595, uint8_t *data, size_t len);

int8_t ic74hc595_send8bits(ic74hc595_t *ic74hc595, uint8_t data);

int8_t ic74hc595_latch(ic74hc595_t *ic74hc595);

#endif // _IC74HC595_H_
