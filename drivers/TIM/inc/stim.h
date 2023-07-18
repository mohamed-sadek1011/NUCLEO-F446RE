/*
 * stim.h
 *
 *  Created on: Jul 18, 2023
 *      Author: moham
 */

#ifndef STIM_H_
#define STIM_H_
#include "rd.h"
#include <stdint.h>
#include "bits.h"

#define tim_null -1

typedef enum
{
	tim_basic, tim_input_capture, tim_output_compare, tim_one_pulse, tim_pwm
}tim_mode_t;

typedef enum
{
	tim_us, tim_ms
}tim_unit_t;

typedef enum
{
	tim_update_interrupt_disable, tim_update_interrupt_enable
}tim_update_int_t;

typedef struct
{
	// general config
	tim_mode_t 			mode;
	uint8_t 			tim_clk_mhz;

	//basic timer related config
	uint16_t 			event_tick;
	tim_unit_t 			unit;
	tim_update_int_t 	update_int;

}tim_config_t;


typedef struct
{
	volatile tim_2t5_t*	n;
	tim_config_t 	config;

}tim_t;

void tim_init(tim_t* tim);

void tim_start (tim_t* tim);

void tim_stop (tim_t* tim);

void tim_wait_update_event (tim_t* tim);

#endif /* STIM_H_ */
