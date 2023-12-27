/*
 * main.c
 *
 *  Created on: Sep 24, 2023
 *      Author: Malefetsane Lenka
 */

#include <stdint.h>
#include "gpio_driver.h"
#include "timebase.h"
#include "lcd_driver.h"


int main(void){
	GPIO_Handle_t led0;
	timebase_init();
	lcd_init();
	led0.GPIOx = GPIOB;

	led0.GPIOx_Cofig.GPIO_OPType = PushPull;
	led0.GPIOx_Cofig.GPIO_PinAltFnMode = AF0;

	led0.GPIOx_Cofig.GPIO_PinMode = GPIO_MODE_OUT;
	led0.GPIOx_Cofig.GPIO_PinNumber = GPIO_PIN_0;

	led0.GPIOx_Cofig.GPIO_PinSpeed = LowSpeed;
	led0.GPIOx_Cofig.GPIO_PullUpPullDown_Ctrl = NoPullUpOrPullDown;

	GPIO_Init(&led0);


	lcd_print_string("Hello World!!");
	lcd_set_cursor(2, 1);
	lcd_print_string("Welcome");

	while(1){
		GPIO_TogglePin(GPIOB, GPIO_PIN_0);
		delay(1000);
	}


}



