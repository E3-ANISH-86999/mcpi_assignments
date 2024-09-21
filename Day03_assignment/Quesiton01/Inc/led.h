/*
 * led.h
 *
 *  Created on: Sep 20, 2024
 *      Author: sunbeam
 */

#ifndef LED_H_
#define LED_H_

#include "stm32f4xx.h"

#define GPIO_PIN      GPIOD
#define GPIO_GREEN     12
#define GPIO_ORANGE    13
#define GPIO_RED       14
#define GPIO_BLUE      15

#define GPIO_LED_CLKEN 3

void LedInit(uint32_t pin);
void LedOn(uint32_t pin);
void LedOff(uint32_t pin);
//void Led(uint32_t pin);




#endif /* LED_H_ */
