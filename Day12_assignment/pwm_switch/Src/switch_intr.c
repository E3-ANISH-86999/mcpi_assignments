/*
Author: Nilesh Ghule <nilesh@sunbeaminfo.com>
Course: PG-DESD @ Sunbeam Infotech
Date: Sep 21, 2024
*/

#include "switch_intr.h"


void SwitchInit(void) {
	RCC->AHB1ENR |= BV(SWITCH_GPIO_CLKEN);

    GPIOA->MODER &= ~(BV(SWITCH_PIN*2+1) | BV(SWITCH_PIN*2));

    GPIOA->PUPDR &= ~(BV(SWITCH_PIN*2+1) | BV(SWITCH_PIN*2));

    EXTI->FTSR |= BV(SWITCH_EXTI);

    EXTI->IMR |= BV(SWITCH_EXTI);

    SYSCFG->EXTICR[0] &= ~(BV(3)|BV(2)|BV(1)|BV(0));

    NVIC_EnableIRQ(EXTI0_IRQn); // EXTI0_IRQn
}

volatile uint32_t SwitchExtiFlag = 0;

void EXTI0_IRQHandler(void) {
	EXTI->PR |= BV(SWITCH_EXTI);
	SwitchExtiFlag = 1;

}









