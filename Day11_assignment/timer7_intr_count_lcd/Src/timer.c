/*
 * timer.c
 *
 *  Created on: Sep 30, 2024
 *      Author: sunbeam
 */

#include "timer.h"

volatile int count = 0;

void Timer_Init(uint32_t ms){
	RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;

	TIM7->PSC = (PR-1);
	//* Calculate number of clocks to count (CNT).
	uint32_t cnt = (TCLK / 1000) * ms / PR;
	//* Set CNT in ARR.
	TIM7->ARR = cnt -1;
	//* Reset Timer Counter to 0.
	TIM7->CNT = 0;

	//Enable Interrupt
	TIM7->DIER	|= TIM_DIER_UIE;

	NVIC_EnableIRQ(TIM7_IRQn);
	//* Start Timer in CR1.
	TIM7->CR1 |= TIM_CR1_CEN;
	//* Wait for UIF flag (in SR).
	while(!(TIM7->SR & TIM_SR_UIF));
	//* Clear UIF in SR
	TIM7->SR &= ~TIM_SR_UIF;

}


void TIM7_IRQHandler(void){
	if(TIM7->SR & TIM_SR_UIF){
		TIM7->SR &= ~TIM_SR_UIF;
		count++;
	}
}
