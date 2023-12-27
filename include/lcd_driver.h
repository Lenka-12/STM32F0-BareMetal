/*
 * lcd_driver.h
 *
 *  Created on: Sep 24, 2023
 *      Author: malef
 */

#ifndef INC_LCD_DRIVER_H_
#define INC_LCD_DRIVER_H



#include "stm32f0xx.h"



/*application configurable items*/
#define LCD_GPIO_PORT0            GPIOC
#define LCD_GPIO_PORT1            GPIOB
#define LCD_GPIO_PORT2            GPIOA

#define LCD_GPIO_RS              GPIO_PIN_14
#define LCD_GPIO_EN              GPIO_PIN_15
#define LCD_GPIO_D4              GPIO_PIN_8
#define LCD_GPIO_D5              GPIO_PIN_9
#define LCD_GPIO_D6              GPIO_PIN_12
#define LCD_GPIO_D7              GPIO_PIN_15

/* LCD commands*/

#define LCD_CMD_4DL_5X8F         0x28    /*4 bit data length 5x5 font size*/
#define LCD_CMD_DON_CURON        0x0E    /*display on, cursor on */
#define LCD_CMD_INCADD           0x06    /*increment RAM address*/
#define LCD_CMD_DIS_CLEAR        0x01    /*clear display*/
#define LCD_CMD_DIS_RETURN_HOME  0x02    /*return home*/




/*bsp exposed APIs*/
void lcd_init(void);
void lcd_send_command(uint8_t cmd);
void lcd_print_char(uint8_t data);
void lcd_display_clear(void);
void lcd_print_string(char* message);
void lcd_display_return_home(void);

void lcd_set_cursor(uint8_t row,uint8_t column);


#endif /* INC_LCD_DRIVER_H_ */

