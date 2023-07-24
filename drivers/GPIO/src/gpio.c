/*
 * gpio.c
 *
 *  Created on: Jul 9, 2023
 *      Author: moham
 */

#include "gpio.h"

void gpio_pin_mode(volatile gpio_t* GPIOx, gpio_pin_t pin, gpio_mode_t mode)
{
	switch (mode)
	{
	case output_push_pull:
		//MODER 01: General purpose output mode
		set_bit(GPIOx->GPIOx_MODER, (pin*2));
		clr_bit(GPIOx->GPIOx_MODER, ((pin*2)+1));
		//OT 0: Output push-pull
		clr_bit(GPIOx->GPIOx_OTYPER,pin);
		break;

	case output_open_drain:
		//MODER 01: General purpose output mode
		set_bit(GPIOx->GPIOx_MODER, (pin*2));
		clr_bit(GPIOx->GPIOx_MODER, ((pin*2)+1));
		//OT 1: Output open-drain
		set_bit(GPIOx->GPIOx_OTYPER,pin);
		break;

	case af_push_pull:
		//MODER 01: AF output mode
		clr_bit(GPIOx->GPIOx_MODER, (pin*2));
		set_bit(GPIOx->GPIOx_MODER, ((pin*2)+1));
		//OT 0: Output push-pull
		clr_bit(GPIOx->GPIOx_OTYPER,pin);
		break;

	case af_open_drain:
		//MODER 01: AF output mode
		clr_bit(GPIOx->GPIOx_MODER, (pin*2));
		set_bit(GPIOx->GPIOx_MODER, ((pin*2)+1));
		//OT 1: Output open-drain
		set_bit(GPIOx->GPIOx_OTYPER,pin);
		break;

	case input:
		//MODER 00: Input
		clr_bit(GPIOx->GPIOx_MODER, (pin*2));
		clr_bit(GPIOx->GPIOx_MODER, ((pin*2)+1));
		break;

	case analog:
		//MODER 11: Analog mode
		set_bit(GPIOx->GPIOx_MODER, (pin*2));
		set_bit(GPIOx->GPIOx_MODER, ((pin*2)+1));
		break;

	default:
		//MODER 00: Input
		clr_bit(GPIOx->GPIOx_MODER, (pin*2));
		clr_bit(GPIOx->GPIOx_MODER, ((pin*2)+1));
		break;
	}
}

void gpio_pin_pull(volatile gpio_t* GPIOx, gpio_pin_t pin, gpio_pull_t pull)
{
	switch (pull)
	{
	case no_pull:
		//PUPDR 00: No pull-up, pull-down
		clr_bit(GPIOx->GPIOx_PUPDR, (pin*2));
		clr_bit(GPIOx->GPIOx_PUPDR, ((pin*2)+1));
		break;

	case pull_up:
		//PUPDR 01: Pull-up
		set_bit(GPIOx->GPIOx_PUPDR, (pin*2));
		clr_bit(GPIOx->GPIOx_PUPDR, ((pin*2)+1));
		break;

	case pull_down:
		//PUPDR 10: Pull-down
		clr_bit(GPIOx->GPIOx_PUPDR, (pin*2));
		set_bit(GPIOx->GPIOx_PUPDR, ((pin*2)+1));
		break;

	default:
		//PUPDR 00: No pull-up, pull-down
		clr_bit(GPIOx->GPIOx_PUPDR, (pin*2));
		clr_bit(GPIOx->GPIOx_PUPDR, ((pin*2)+1));
		break;
	}
}

void gpio_pin_write(volatile gpio_t* GPIOx, gpio_pin_t pin, gpio_level level)
{
	switch (level)
	{
	case gpio_low:
		//BR 1: Resets the corresponding ODRx bit
		GPIOx->GPIOx_BSRR = (1<<(pin+16));
		break;

	case gpio_high:
		//BS 1: Sets the corresponding ODRx bit
		GPIOx->GPIOx_BSRR = (1<<pin);
		break;

	default:
		//BR 1: Resets the corresponding ODRx bit
		GPIOx->GPIOx_BSRR = (1<<pin);
		break;
	}
}

gpio_level gpio_pin_read(volatile gpio_t* GPIOx, gpio_pin_t pin)
{
	return ( get_bit(GPIOx->GPIOx_IDR,pin));
}

void gpio_pin_af(volatile gpio_t* GPIOx, gpio_pin_t pin, gpio_af_t af)
{
	if (pin <8)
	{
		switch (af)
		{
		case gpio_AF0:
			//AF0 0000: Select Alternative Function 0
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+1));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+2));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+3));
			break;

		case gpio_AF1:
			//AF0 0001: Select Alternative Function 1
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+1));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+2));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+3));
			break;
		case gpio_AF2:
			//AF0 0010: Select Alternative Function 2
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+1));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+2));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+3));
			break;
		case gpio_AF3:
			//AF0 0011: Select Alternative Function 3
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+1));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+2));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+3));
			break;
		case gpio_AF4:
			//AF0 0100: Select Alternative Function 4
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+1));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+2));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+3));
			break;
		case gpio_AF5:
			//AF0 0101: Select Alternative Function 5
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+1));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+2));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+3));
			break;
		case gpio_AF6:
			//AF0 0110: Select Alternative Function 6
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+1));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+2));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+3));
			break;
		case gpio_AF7:
			//AF0 0111: Select Alternative Function 7
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+1));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+2));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+3));
			break;
		case gpio_AF8:
			//AF0 1000: Select Alternative Function 8
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+1));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+2));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+3));
			break;
		case gpio_AF9:
			//AF0 1001: Select Alternative Function 9
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+1));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+2));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+3));
			break;
		case gpio_AF10:
			//AF0 1010: Select Alternative Function 10
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+1));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+2));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+3));
			break;
		case gpio_AF11:
			//AF0 1011: Select Alternative Function 11
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+1));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+2));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+3));
			break;
		case gpio_AF12:
			//AF0 1100: Select Alternative Function 12
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+1));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+2));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+3));
			break;
		case gpio_AF13:
			//AF0 1101: Select Alternative Function 13
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)));
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)+1));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+2));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+3));
			break;
		case gpio_AF14:
			//AF0 1110: Select Alternative Function 14
			clr_bit(GPIOx->GPIOx_AFRL,((pin*4)));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+1));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+2));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+3));
			break;
		case gpio_AF15:
			//AF0 1111: Select Alternative Function 15
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+1));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+2));
			set_bit(GPIOx->GPIOx_AFRL,((pin*4)+3));
			break;

		default:
			//BR 1: Resets the corresponding ODRx bit
			GPIOx->GPIOx_BSRR = (1<<pin);
			break;
		}
	}
	else
	{
		switch (af)
		{
		case gpio_AF0:
			//AF0 0000: Select Alternative Function 0
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8))+1));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+2));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+3));
			break;

		case gpio_AF1:
			//AF0 0001: Select Alternative Function 1
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+1));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+2));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+3));
			break;
		case gpio_AF2:
			//AF0 0010: Select Alternative Function 2
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+1));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+2));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+3));
			break;
		case gpio_AF3:
			//AF0 0011: Select Alternative Function 3
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+1));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+2));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+3));
			break;
		case gpio_AF4:
			//AF0 0100: Select Alternative Function 4
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+1));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+2));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+3));
			break;
		case gpio_AF5:
			//AF0 0101: Select Alternative Function 5
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+1));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+2));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+3));
			break;
		case gpio_AF6:
			//AF0 0110: Select Alternative Function 6
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8))+1));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+2));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+3));
			break;
		case gpio_AF7:
			//AF0 0111: Select Alternative Function 7
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8))+1));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+2));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+3));
			break;
		case gpio_AF8:
			//AF0 1000: Select Alternative Function 8
			clr_bit(GPIOx->GPIOx_AFRH,((pin*4)));
			clr_bit(GPIOx->GPIOx_AFRH,((pin*4)+1));
			clr_bit(GPIOx->GPIOx_AFRH,((pin*4)+2));
			set_bit(GPIOx->GPIOx_AFRH,((pin*4)+3));
			break;
		case gpio_AF9:
			//AF0 1001: Select Alternative Function 9
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+1));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+2));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+3));
			break;
		case gpio_AF10:
			//AF0 1010: Select Alternative Function 10
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+1));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+2));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+3));
			break;
		case gpio_AF11:
			//AF0 1011: Select Alternative Function 11
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+1));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+2));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+3));
			break;
		case gpio_AF12:
			//AF0 1100: Select Alternative Function 12
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+1));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+2));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+3));
			break;
		case gpio_AF13:
			//AF0 1101: Select Alternative Function 13
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)));
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+1));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+2));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+3));
			break;
		case gpio_AF14:
			//AF0 1110: Select Alternative Function 14
			clr_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+1));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+2));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+3));
			break;
		case gpio_AF15:
			//AF0 1111: Select Alternative Function 15
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+1));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+2));
			set_bit(GPIOx->GPIOx_AFRH,(((pin-8)*4)+3));
			break;

		default:
			//BR 1: Resets the corresponding ODRx bit

			break;
		}
	}
}
