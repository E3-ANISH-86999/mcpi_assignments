/*
 * switch_interrupt.c
 *
 *  Created on: Sep 21, 2024
 *      Author: sunbeam
 */
#include "switch_interrupt.h"
#include "led.h"

volatile uint32_t flag = 0;

void SwitchInit(void){
	RCC->AHB1ENR |= BV(SWITCH_CLK_EN);

	GPIO_SWITCH->MODER &= ~(BV(SWITCH_PIN*2) | BV(SWITCH_PIN*2+1));

	GPIO_SWITCH->PUPDR &= ~(BV(SWITCH_PIN*2) | BV(SWITCH_PIN*2+1));

	EXTI->FTSR |= BV(SWITCH_EXTI);

	EXTI->IMR |= BV(SWITCH_EXTI);

	SYSCFG->EXTICR[0] &= ~(BV(3) |BV(2) |BV(1) |BV(0));

	NVIC_EnableIRQ(EXTI0_IRQn);

}

void EXTI0_IRQHandler(void){
	EXTI->PR |= BV(SWITCH_EXTI);

	//LedToggle(LED_GREEN_PIN);

	flag=1;


}












