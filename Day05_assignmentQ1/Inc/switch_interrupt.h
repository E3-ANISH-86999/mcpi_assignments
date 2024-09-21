/*
 * switch_interrupt.h
 *
 *  Created on: Sep 21, 2024
 *      Author: sunbeam
 */

#ifndef SWITCH_INTERRUPT_H_
#define SWITCH_INTERRUPT_H_

#include "stm32f4xx.h"

#define GPIO_SWITCH 	GPIOA
#define SWITCH_PIN 		0
#define SWITCH_CLK_EN	0

#define SWITCH_EXTI		0

void SwitchInit(void);
void EXTI0_IRQHandler(void);

extern volatile uint32_t flag;

#endif /* SWITCH_INTERRUPT_H_ */
