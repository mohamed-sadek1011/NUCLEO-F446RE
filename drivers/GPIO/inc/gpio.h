/*
 * gpio.h
 *
 *  Created on: Jul 9, 2023
 *      Author: moham
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "rd.h"
#include "bits.h"

typedef enum
{
	gpio_pin0, 	gpio_pin1, 	gpio_pin2, 	gpio_pin3,

	gpio_pin4, 	gpio_pin5, 	gpio_pin6, 	gpio_pin7,

	gpio_pin8, 	gpio_pin9, 	gpio_pin10, gpio_pin11,

	gpio_pin12, gpio_pin13, gpio_pin14, gpio_pin15

}gpio_pin_t;

typedef enum
{
	gpio_AF0, 	gpio_AF1, 	gpio_AF2, 	gpio_AF3,

	gpio_AF4, 	gpio_AF5, 	gpio_AF6, 	gpio_AF7,

	gpio_AF8, 	gpio_AF9, 	gpio_AF10, 	gpio_AF11,

	gpio_AF12, 	gpio_AF13, 	gpio_AF14, 	gpio_AF15

}gpio_af_t;

typedef enum
{
	output_push_pull, output_open_drain, input, af_push_pull, af_open_drain, analog
}gpio_mode_t;

typedef enum
{
	no_pull, pull_up, pull_down
}gpio_pull_t;

typedef enum
{
	gpio_low, gpio_high
}gpio_level;

typedef enum
{
	gpio_low_speed, gpio_medium_speed, gpio_high_speed, gpio_very_high_speed
}gpio_speed;

void gpio_pin_mode(volatile gpio_t* GPIOx, gpio_pin_t pin, gpio_mode_t mode);
void gpio_pin_pull(volatile gpio_t* GPIOx, gpio_pin_t pin, gpio_pull_t pull);
void gpio_pin_write(volatile gpio_t* GPIOx, gpio_pin_t pin, gpio_level level);
gpio_level gpio_pin_read(volatile gpio_t* GPIOx, gpio_pin_t pin);
void gpio_pin_af(volatile gpio_t* GPIOx, gpio_pin_t pin, gpio_af_t af);
void gpio_pin_speed(volatile gpio_t* GPIOx, gpio_pin_t pin, gpio_speed speed);


#endif /* GPIO_H_ */
