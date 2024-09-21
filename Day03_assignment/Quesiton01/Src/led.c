/*
 * led.c
 *
 *  Created on: Sep 20, 2024
 *      Author: sunbeam
 */

#include "led.h"

void LedInit(uint32_t pin){
	RCC->AHB1ENR |= BV(GPIO_LED_CLKEN);

	GPIO_PIN->MODER |= BV(pin*2);
	GPIO_PIN->MODER &= ~BV(pin*2+1);

	GPIO_PIN->OTYPER &= ~BV(pin);

	GPIO_PIN->OSPEEDR &= ~(BV(pin*2+1) | BV(pin*2));

	GPIO_PIN->PUPDR &= ~(BV(pin*2+1) | BV(pin*2));
}

void LedOn(uint32_t pin){
	GPIO_PIN->BSRR = BV(pin);
	DelayMs(200);
}

void LedOff(uint32_t pin){
	GPIO_PIN->BSRR = BV(pin+ 16);
	DelayMs(200);
}










