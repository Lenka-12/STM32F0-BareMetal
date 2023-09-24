/*
 * time_base.c
 *
 *  Created on: Sep 22, 2023
 *      Author: malef
 */

#include "stm32f0xx.h"
#include "timebase.h"

#define MILLI_SEC_LOAD   8000
#define MAX_DELAY        0xFFFFFFFF

volatile uint32_t g_curr_tick;
volatile uint32_t g_curr_p;
volatile uint32_t tick_freq = 1;

static void tick_increment(void);

void timebase_init(void){
	/*Reload timer with number of cycles for a milli second*/
	SysTick->LOAD = MILLI_SEC_LOAD-1;
	/*clear systick current value register*/
	SysTick->VAL = 0;
	/*select internal clock source and enable exception*/
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk|SysTick_CTRL_TICKINT_Msk;
	/*enable systick*/
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

	__enable_irq(); /*enable all global interrupts*/

}

static void tick_increment(void){
	g_curr_tick+=tick_freq;
}

void SysTick_Handler(void){
	tick_increment();
}

uint32_t get_tick(){
	__disable_irq();
	g_curr_p = g_curr_tick; /*get current number of ticks*/
	__enable_irq();
	return g_curr_p;
}

/*delay in milli seconds*/
void delay(uint32_t msdelay){
	uint32_t tickstart = get_tick(); /*get current number of ticks*/
	uint32_t wait = msdelay;

	while((get_tick()-tickstart)<wait);
}


