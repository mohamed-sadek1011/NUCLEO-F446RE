/*
 * rd.h
 *
 *  Created on: Jul 8, 2023
 *      Author: moata
 */

#ifndef RD_RD_H_
#define RD_RD_H_

#include <stdint.h>

#define RCC_BASE	0x40023800

#define GPIOA_BASE  0x40020000
#define GPIOB_BASE	0x40020400
#define GPIOC_BASE	0x40020800
#define GPIOD_BASE	0x40020C00
#define GPIOE_BASE	0x40021000
#define GPIOF_BASE	0x40021400
#define GPIOG_BASE	0x40021800
#define GPIOH_BASE	0x40021C00

#define TIM11_BASE	0x40014800
#define TIM10_BASE	0x40014400
#define TIM9_BASE	0x40014000
#define TIM8_BASE	0x40010400
#define TIM1_BASE	0x40010000
#define TIM14_BASE	0x40002000
#define TIM13_BASE	0x40001C00
#define TIM12_BASE	0x40001800
#define TIM7_BASE	0x40001400
#define TIM6_BASE	0x40001000
#define TIM5_BASE	0x40000C00
#define TIM4_BASE	0x40000800
#define TIM3_BASE	0x40000400
#define TIM2_BASE	0x40000000


// RCC_CR
#define HSION			0
#define HSIRDY			1
#define HSITRIM0		3
#define HSITRIM1		4
#define HSITRIM2		5
#define HSITRIM3		6
#define HSITRIM4		7
#define HSICAL0			8
#define HSICAL1			9
#define HSICAL2			10
#define HSICAL3			11
#define HSICAL4			12
#define HSICAL5			13
#define HSICAL6			14
#define HSICAL7			15
#define HSEON			16
#define	HSERDY			17
#define HSEBYP			18
#define CSSON			19
#define PLLON			24
#define PLLRDY			25
#define PLLI2SON		26
#define PLLI2SRDY		27
#define PLLSAION		28
#define PLLSAIRDY		29

// RCC_PLLCFGR
#define PLLM0		0
#define PLLM1		1
#define PLLM2		2
#define PLLM3		3
#define PLLM4		4
#define PLLM5		5
#define PLLN0		6
#define PLLN1		7
#define PLLN2		8
#define PLLN3		9
#define PLLN4		10
#define PLLN5		11
#define PLLN6		12
#define PLLN7		13
#define PLLN8		14
#define PLLP0		16
#define	PLLP1		17
#define PLLSRC		22
#define PLLQ0		24
#define PLLQ1		25
#define PLLQ2		26
#define PLLQ3		27
#define PLLR0		28
#define PLLR1		29
#define PLLR2		30

// RCC_CFGR
#define SW0         	0
#define SW1         	1
#define SWS0         	2
#define SWS1         	3
#define HPRE0         	4
#define HPRE1         	5
#define HPRE2         	6
#define HPRE3         	7
#define PPRE10         	10
#define PPRE11         	11
#define PPRE12         	12
#define PPRE20         	13
#define PPRE21         	14
#define PPRE22         	15
#define RTCPRE0     	16
#define RTCPRE1     	17
#define RTCPRE2     	18
#define RTCPRE3     	19
#define RTCPRE4     	20
#define MCO10         	21
#define MCO11         	22
#define MCO1_PRE10     	24
#define MCO1_PRE11     	25
#define MCO1_PRE12     	26
#define MCO2_PRE10     	27
#define MCO2_PRE11     	28
#define MCO2_PRE12     	29
#define MCO20         	30
#define MCO21         	31




typedef struct
{
	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_PLLCFGR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_AHB1RSTR;
	volatile uint32_t RCC_AHB2RSTR;
	volatile uint32_t RCC_AHB3RSTR;
	volatile uint32_t Reserved0[1];
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_APB2RSTR;
	volatile uint32_t Reserved1[2];
	volatile uint32_t RCC_AHB1ENR;
	volatile uint32_t RCC_AHB2ENR;
	volatile uint32_t RCC_AHB3ENR;
	volatile uint32_t Reserved2[1];
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_APB2ENR;
	volatile uint32_t Reserved3[2];
	volatile uint32_t RCC_AHB1LPENR;
	volatile uint32_t RCC_AHB2LPENR;
	volatile uint32_t RCC_AHB3LPENR;
	volatile uint32_t Reserved4[1];
	volatile uint32_t RCC_APB1LPENR;
	volatile uint32_t RCC_APB2LPENR;
	volatile uint32_t Reserved5[2];
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
	volatile uint32_t Reserved6[2];
	volatile uint32_t RCC_SSCGR;
	volatile uint32_t RCC_PLLI2SCFGR;
	volatile uint32_t RCC_PLLSAICFGR;
	volatile uint32_t RCC_DCKCFGR;
	volatile uint32_t RCC_CKGATENR;
	volatile uint32_t RCC_CKGATENR2;

}rcc_t;

#define RCC ((volatile rcc_t*)(RCC_BASE))


// GPIOx_MODER

#define MODER00      0
#define MODER01      1
#define MODER10      2
#define MODER11      3
#define MODER20      4
#define MODER21      5
#define MODER30      6
#define MODER31      7
#define MODER40      8
#define MODER41      9
#define MODER50      10
#define MODER51      11
#define MODER60      12
#define MODER61      13
#define MODER70      14
#define MODER71      15
#define MODER80      16
#define MODER81	     17
#define MODER90      18
#define MODER91    	 19
#define MODER100     20
#define MODER101     21
#define MODER110     22
#define MODER111     23
#define MODER120     24
#define MODER121     25
#define MODER130     26
#define MODER131     27
#define MODER140     28
#define MODER141     29
#define MODER150     30
#define MODER151     31

// GPIOx_OTYPER

#define OT0      0
#define OT1      1
#define OT2      2
#define OT3      3
#define OT4      4
#define OT5      5
#define OT6      6
#define OT7      7
#define OT8      8
#define OT9      9
#define OT10     10
#define OT11     11
#define OT12     12
#define OT13     13
#define OT14     14
#define OT15     15

// GPIOx_OSPEEDR
#define OSPEEDR00   0
#define OSPEEDR01   1
#define OSPEEDR10   2
#define OSPEEDR11   3
#define OSPEEDR20   4
#define OSPEEDR21   5
#define OSPEEDR30   6
#define OSPEEDR31   7
#define OSPEEDR40   8
#define OSPEEDR41   9
#define OSPEEDR50   10
#define OSPEEDR51   11
#define OSPEEDR60   12
#define OSPEEDR61   13
#define OSPEEDR70   14
#define OSPEEDR71   15
#define OSPEEDR80   16
#define OSPEEDR81   17
#define OSPEEDR90   18
#define OSPEEDR91   19
#define OSPEEDR100  20
#define OSPEEDR101  21
#define OSPEEDR110  22
#define OSPEEDR111  23
#define OSPEEDR120  24
#define OSPEEDR121  25
#define OSPEEDR130  26
#define OSPEEDR131  27
#define OSPEEDR140  28
#define OSPEEDR141  29
#define OSPEEDR150  30
#define OSPEEDR151  31

// GPIOx_PUPDR

#define PUPDR00   0
#define PUPDR01   1
#define PUPDR10   2
#define PUPDR11   3
#define PUPDR20   4
#define PUPDR21   5
#define PUPDR30   6
#define PUPDR31   7
#define PUPDR40   8
#define PUPDR41   9
#define PUPDR50   10
#define PUPDR51   11
#define PUPDR60   12
#define PUPDR61   13
#define PUPDR70   14
#define PUPDR71   15
#define PUPDR80   16
#define PUPDR81   17
#define PUPDR90   18
#define PUPDR91   19
#define PUPDR100  20
#define PUPDR101  21
#define PUPDR110  22
#define PUPDR111  23
#define PUPDR120  24
#define PUPDR121  25
#define PUPDR130  26
#define PUPDR131  27
#define PUPDR140  28
#define PUPDR141  29
#define PUPDR150  30
#define PUPDR151  31


//GPIOx_IDR

#define IDR0    0
#define IDR1    1
#define IDR2    2
#define IDR3    3
#define IDR4    4
#define IDR5    5
#define IDR6    6
#define IDR7    7
#define IDR8    8
#define IDR9    9
#define IDR10   10
#define IDR11   11
#define IDR12   12
#define IDR13   13
#define IDR14   14
#define IDR15   15

//GPIOx_ODR

#define ODR0    0
#define ODR1    1
#define ODR2    2
#define ODR3    3
#define ODR4    4
#define ODR5    5
#define ODR6    6
#define ODR7    7
#define ODR8    8
#define ODR9    9
#define ODR10   10
#define ODR11   11
#define ODR12   12
#define ODR13   13
#define ODR14   14
#define ODR15   15

//GPIOx_BSRR

#define BS0    0
#define BS1    1
#define BS2    2
#define BS3    3
#define BS4    4
#define BS5    5
#define BS6    6
#define BS7    7
#define BS8    8
#define BS9    9
#define BS10   10
#define BS11   11
#define BS12   12
#define BS13   13
#define BS14   14
#define BS15   15
#define B00    16
#define BR1    17
#define BR2    18
#define BR3    19
#define BR4    20
#define BR5    21
#define BR6    22
#define BR7    23
#define BR8    24
#define BR9    25
#define BR10   26
#define BR11   27
#define BR12   28
#define BR13   29
#define BR14   30
#define BR15   31

// GPIOx_AFRL

#define AFRL00	 	0
#define AFRL01	 	1
#define AFRL02 		2
#define AFRL03 		3
#define AFRL10 		4
#define AFRL11 		5
#define AFRL12 		6
#define AFRL13 		7
#define AFRL20 		8
#define AFRL21 		9
#define AFRL22 		10
#define AFRL23 		11
#define AFRL30 		12
#define AFRL31 		13
#define AFRL32 		14
#define AFRL33		15
#define AFRL40	 	16
#define AFRL41	 	17
#define AFRL42	 	18
#define AFRL43 		19
#define AFRL50	 	20
#define AFRL51	 	21
#define AFRL52	 	22
#define AFRL53 		23
#define AFRL60	 	24
#define AFRL61	 	25
#define AFRL62	 	26
#define AFRL63 		27
#define AFRL70	 	28
#define AFRL71	 	29
#define AFRL72	 	30
#define AFRL73 		31


// GPIOx_AFRH


#define AFRH80   0
#define AFRH81   1
#define AFRH82   2
#define AFRH83   3
#define AFRH90   4
#define AFRH91   5
#define AFRH92   6
#define AFRH93   7
#define AFRH100  8
#define AFRH101  9
#define AFRH102  10
#define AFRH103  11
#define AFRH110  12
#define AFRH111  13
#define AFRH112  14
#define AFRH113  15
#define AFRH120  16
#define AFRH121  17
#define AFRH122  18
#define AFRH123  19
#define AFRH130  20
#define AFRH131  21
#define AFRH132  22
#define AFRH133  23
#define AFRH140  24
#define AFRH141  25
#define AFRH142  26
#define AFRH143  27
#define AFRH150  28
#define AFRH151  29
#define AFRH152  30
#define AFRH153  31

typedef struct
{

	volatile uint32_t GPIOx_MODER;
	volatile uint32_t GPIOx_OTYPER;
	volatile uint32_t GPIOx_OSPEEDR;
	volatile uint32_t GPIOx_PUPDR;
	volatile uint32_t GPIOx_IDR;
	volatile uint32_t GPIOx_ODR;
	volatile uint32_t GPIOx_BSRR;
	volatile uint32_t GPIOx_LCKR;
	volatile uint32_t GPIOx_AFRL;
	volatile uint32_t GPIOx_AFRH;
}gpio_t;

#define GPIOA ((volatile gpio_t*)(GPIOA_BASE))
#define GPIOB ((volatile gpio_t*)(GPIOB_BASE))
#define GPIOC ((volatile gpio_t*)(GPIOC_BASE))
#define GPIOD ((volatile gpio_t*)(GPIOD_BASE))
#define GPIOE ((volatile gpio_t*)(GPIOE_BASE))
#define GPIOF ((volatile gpio_t*)(GPIOE_BASE))
#define GPIOG ((volatile gpio_t*)(GPIOE_BASE))
#define GPIOH ((volatile gpio_t*)(GPIOH_BASE))

//TIM Section

//TIMx control register 1 (TIMx_CR1) Bits
#define CEN		0
#define UDIS	1
#define URS		2
#define OPM		3
#define DIR		4
#define CMS0	5
#define CMS1	6
#define ARPE	7
#define CKD0	8
#define CKD1	9

//TIMx DMA/Interrupt enable register (TIMx_DIER) Bits
#define UIE		0
#define CC1IE	1
#define CC2IE	2
#define CC3IE	3
#define CC4IE	4
#define TIE		6
#define UDE		8
#define CC1DE	9
#define CC2DE	10
#define CC3DE	11
#define CC4DE	12
#define TDE		14

//TIMx event generation register (TIMx_EGR)
#define UG		0
#define CC1G	1
#define CC2G	2
#define CC3G	3
#define CC4G	4
#define TG		6


typedef struct
{
	volatile uint32_t TIMx_CR1;
	volatile uint32_t TIMx_CR2;
	volatile uint32_t TIMx_SMCR;
	volatile uint32_t TIMx_DIER;
	volatile uint32_t TIMx_SR;
	volatile uint32_t TIMx_EGR;
	volatile uint32_t TIMx_CCMR1;
	volatile uint32_t TIMx_CCMR2;
	volatile uint32_t TIMx_CCER;
	volatile uint32_t TIMx_CNT;
	volatile uint32_t TIMx_PSC;
	volatile uint32_t TIMx_ARR;
	volatile uint32_t reserved0;
	volatile uint32_t TIMx_CCR1;
	volatile uint32_t TIMx_CCR2;
	volatile uint32_t TIMx_CCR3;
	volatile uint32_t TIMx_CCR4;
	volatile uint32_t reserved1;
	volatile uint32_t TIMx_DCR;
	volatile uint32_t TIMx_DMAR;
	volatile uint32_t TIM2_OR;
	volatile uint32_t TIM5_OR;

}tim_2t5_t;

#define TIM2 ((volatile tim_2t5_t*)(TIM2_BASE))
#define TIM3 ((volatile tim_2t5_t*)(TIM3_BASE))
#define TIM4 ((volatile tim_2t5_t*)(TIM4_BASE))
#define TIM5 ((volatile tim_2t5_t*)(TIM5_BASE))

#endif /* RD_RD_H_ */
