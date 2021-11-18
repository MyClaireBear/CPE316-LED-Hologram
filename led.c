/*
 * led.c
 *
 *  Created on: Nov 18, 2021
 *      Author: Claire
 */

#include "stm32g031xx.h"

void LED_init(void) {
	// Init PA0 - PA4 for LED output
	// Start clock for GPIOA
	RCC->IOPENR   |=  (RCC_IOPENR_GPIOAEN);

	// set to output mode
	GPIOA->MODER   &= ~(GPIO_MODER_MODE0 |
						GPIO_MODER_MODE1 |
						GPIO_MODER_MODE2 |
						GPIO_MODER_MODE3 |
						GPIO_MODER_MODE4);

	// set to push pull
	GPIOA->OTYPER  &= ~(GPIO_OTYPER_OT0 |
						GPIO_OTYPER_OT1 |
						GPIO_OTYPER_OT2 |
						GPIO_OTYPER_OT3 |
						GPIO_OTYPER_OT4);

	// pull-down
	GPIOA->PUPDR   &= ~(GPIO_PUPDR_PUPD0 |
						GPIO_PUPDR_PUPD1 |
						GPIO_PUPDR_PUPD2 |
						GPIO_PUPDR_PUPD3 |
						GPIO_PUPDR_PUPD4);

	// very high speed
	GPIOA->OSPEEDR |=  ((3 << GPIO_OSPEEDR_OSPEED0_Pos) |
						(3 << GPIO_OSPEEDR_OSPEED1_Pos) |
						(3 << GPIO_OSPEEDR_OSPEED2_Pos) |
						(3 << GPIO_OSPEEDR_OSPEED3_Pos) |
						(3 << GPIO_OSPEEDR_OSPEED4_Pos));
}


