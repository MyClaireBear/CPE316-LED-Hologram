/*
 * led.c
 *
 *  Created on: Nov 18, 2021
 *      Author: Claire
 */

#include "stm32g031xx.h"
#include "main.h"

void LED_init(void) {
	// Init PA0 - PA4 for LED output
	// Start clock for GPIOA
	RCC->IOPENR   |=  (RCC_IOPENR_GPIOBEN);

	// set to output mode
	GPIOB->MODER   &= ~(GPIO_MODER_MODE0 |
						GPIO_MODER_MODE1 |
						GPIO_MODER_MODE2 |
						GPIO_MODER_MODE3 |
						GPIO_MODER_MODE4);

	GPIOB->MODER   |= (GPIO_MODER_MODE0_0 |
							GPIO_MODER_MODE1_0 |
							GPIO_MODER_MODE2_0 |
							GPIO_MODER_MODE3_0 |
							GPIO_MODER_MODE4_0);



	// set to push pull
	GPIOB->OTYPER  &= ~(GPIO_OTYPER_OT0 |
						GPIO_OTYPER_OT1 |
						GPIO_OTYPER_OT2 |
						GPIO_OTYPER_OT3 |
						GPIO_OTYPER_OT4);

	// no pull-up or pull-down
	GPIOB->PUPDR   &= ~(GPIO_PUPDR_PUPD0 |
						GPIO_PUPDR_PUPD1 |
						GPIO_PUPDR_PUPD2 |
						GPIO_PUPDR_PUPD3 |
						GPIO_PUPDR_PUPD4);

	// very low speed
	GPIOB->OSPEEDR &=  ~((GPIO_OSPEEDR_OSPEED0)|
						(GPIO_OSPEEDR_OSPEED1) |
						(GPIO_OSPEEDR_OSPEED2) |
						(GPIO_OSPEEDR_OSPEED3) |
						(GPIO_OSPEEDR_OSPEED4));


}

