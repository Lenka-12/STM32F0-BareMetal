/*
 * main.c
 *
 *  Created on: Sep 24, 2023
 *      Author: Malefetsane Lenka
 */

#include <stdint.h>
#include "gpio_driver.h"
#include "timebase.h"


int main(void){
	GPIO_Handle_t led0;
	GPIO_ClockConfig(GPIOB, ENABLE);
	led0.GPIOx = GPIOB;

	led0.GPIOx_Cofig.GPIO_OPType = PushPull;
	led0.GPIOx_Cofig.GPIO_PinAltFnMode = AF0;

	led0.GPIOx_Cofig.GPIO_PinMode = GPIO_MODE_OUT;
	led0.GPIOx_Cofig.GPIO_PinNumber = GPIO_PIN_0;

	led0.GPIOx_Cofig.GPIO_PinSpeed = LowSpeed;
	led0.GPIOx_Cofig.GPIO_PullUpPullDown_Ctrl = NoPullUpOrPullDown;

	GPIO_Init(&led0);
	timebase_init();

	while(1){
		GPIO_TogglePin(GPIOB, GPIO_PIN_0);
		delay(1000);
	}


}
