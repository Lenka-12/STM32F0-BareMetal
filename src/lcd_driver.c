/*
 * lcd_driver.c
 *
 *  Created on: Sep 24, 2023
 *      Author: malef
 */

#include "lcd_driver.h"
#include "gpio_driver.h"
#include "timebase.h"

static void lcd_enable();
static void write_nibble(uint8_t value);


void lcd_send_command(uint8_t cmd){
	/*set RS low*/
	GPIO_WritePin(LCD_GPIO_PORT0, LCD_GPIO_RS, GPIO_PIN_RESET);
	write_nibble(cmd>>4);  //send upper nibble
	write_nibble(cmd&0xF); //send lower nibble

	delay(10);  /*wait*/
}


void lcd_print_char(uint8_t data){
	/*set RS high*/
	GPIO_WritePin(LCD_GPIO_PORT0, LCD_GPIO_RS, GPIO_PIN_SET);
	write_nibble(data>>4);  //send upper nibble
	write_nibble(data&0xF); //send lower nibble

}


void lcd_init(void){

	/*1. Configure GPIO pins connected to lcd*/

	/*Enable clock for LCD GPIO pins*/
	GPIO_ClockConfig(LCD_GPIO_PORT0,ENABLE);
	GPIO_ClockConfig(LCD_GPIO_PORT1,ENABLE);
	GPIO_ClockConfig(LCD_GPIO_PORT2,ENABLE);

	GPIO_Handle_t lcd_signal;

	lcd_signal.GPIOx = LCD_GPIO_PORT0;

	lcd_signal.GPIOx_Cofig.GPIO_OPType = PushPull;
	lcd_signal.GPIOx_Cofig.GPIO_PinAltFnMode = AF0;
	lcd_signal.GPIOx_Cofig.GPIO_PinMode = GPIO_MODE_OUT;

	lcd_signal.GPIOx_Cofig.GPIO_PinNumber = LCD_GPIO_RS;
	lcd_signal.GPIOx_Cofig.GPIO_PinSpeed = LowSpeed;
	lcd_signal.GPIOx_Cofig.GPIO_PullUpPullDown_Ctrl= NoPullUpOrPullDown;

	GPIO_Init(&lcd_signal); //RS pin

	lcd_signal.GPIOx_Cofig.GPIO_PinNumber = LCD_GPIO_EN;

	GPIO_Init(&lcd_signal); //Enable PIN

	/*D4 and D5*/
	lcd_signal.GPIOx = LCD_GPIO_PORT1;
	lcd_signal.GPIOx_Cofig.GPIO_PinNumber = LCD_GPIO_D4;

	GPIO_Init(&lcd_signal);

	lcd_signal.GPIOx_Cofig.GPIO_PinNumber = LCD_GPIO_D5;
	GPIO_Init(&lcd_signal);

	/*D6 and D7*/
	lcd_signal.GPIOx = LCD_GPIO_PORT2;
	lcd_signal.GPIOx_Cofig.GPIO_PinNumber = LCD_GPIO_D6;

	GPIO_Init(&lcd_signal);

	lcd_signal.GPIOx_Cofig.GPIO_PinNumber = LCD_GPIO_D7;
	GPIO_Init(&lcd_signal);


	GPIO_WritePin(LCD_GPIO_PORT0, LCD_GPIO_RS, GPIO_PIN_RESET);
	GPIO_WritePin(LCD_GPIO_PORT0, LCD_GPIO_EN, GPIO_PIN_RESET);
	GPIO_WritePin(LCD_GPIO_PORT1, LCD_GPIO_D4, GPIO_PIN_RESET);
	GPIO_WritePin(LCD_GPIO_PORT1, LCD_GPIO_D5, GPIO_PIN_RESET);
	GPIO_WritePin(LCD_GPIO_PORT2, LCD_GPIO_D6, GPIO_PIN_RESET);
	GPIO_WritePin(LCD_GPIO_PORT2, LCD_GPIO_D7, GPIO_PIN_RESET);






	/*2.do LCD initialization*/
	delay(40);
	write_nibble(0x3);
	/*wait*/
	delay(5);
	write_nibble(0x3);
	/*wait*/
	delay(1);
	write_nibble(0x3);
	write_nibble(0x2);

	/*function set command*/

	lcd_send_command(LCD_CMD_4DL_5X8F);

	/*display on and cursor on*/
	lcd_send_command(LCD_CMD_DON_CURON);

	/*display clear*/
	 lcd_display_clear();

	/*Entry mode set*/
	lcd_send_command(LCD_CMD_INCADD);




}


static void lcd_enable(){
	GPIO_WritePin(LCD_GPIO_PORT0, LCD_GPIO_EN, GPIO_PIN_SET);
	delay(1);
	GPIO_WritePin(LCD_GPIO_PORT0, LCD_GPIO_EN, GPIO_PIN_RESET);
}


static void write_nibble(uint8_t value){
	/*LSB goes to DB4, MSB to D7*/
	GPIO_WritePin(LCD_GPIO_PORT1, LCD_GPIO_D4, (value>>0&0x1));
	GPIO_WritePin(LCD_GPIO_PORT1, LCD_GPIO_D5, (value>>1&0x1));
	GPIO_WritePin(LCD_GPIO_PORT2, LCD_GPIO_D6, (value>>2&0x1));
	GPIO_WritePin(LCD_GPIO_PORT2, LCD_GPIO_D7, (value>>3&0x1));
	lcd_enable();

}

void lcd_display_clear(void){
	lcd_send_command(LCD_CMD_DIS_CLEAR);
	delay(3); /*wait*/

}

void lcd_print_string(char* message){
	do{
		lcd_print_char((uint8_t)*message++);
	}while(*message!='\0');
}

void lcd_display_return_home(void){
	lcd_send_command(LCD_CMD_DIS_RETURN_HOME);
	delay(3);
}



void lcd_set_cursor(uint8_t row,uint8_t column){
	column--;

	switch(row)
	{
		case 1:
			/* Set cursor to first row and add index*/
			lcd_send_command(column|=0x80);
			break;
		case 2:
			/*set cursor to 2nd row address and add index*/
			lcd_send_command(column|=0xC0);
			break;
		default:
			break;
	}
}


