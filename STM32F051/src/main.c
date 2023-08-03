#include "stm32f0xx.h"
#include <stdint.h>
#include <stdio.h>
#include "systick.h"
#include "lcd.h"
//Semihosting init func
/*
extern  void initialise_monitor_handles(void);
*/
void PB0_Init(void);
void PA0_Init(void);
int main(void){
   
    //initialise_monitor_handles();

    lcd_init();
    PB0_Init();
    PA0_Init();
    lcd_send_str("Hello World!!");
    lcd_set_cursor(2,1);
     lcd_send_str("Welcll Done!!");
    SysTick_Init(1000,EXC_ENABLE,MILLI_SECOND);
    
    
  


}
void PB0_Init(void){
    GPIO_Handle_t led0;
    led0.GPIOx = GPIOB;
    led0.GPIOx_Config.AFSEL = AF0;
    led0.GPIOx_Config.OutPutType = PUSHPULL;
    led0.GPIOx_Config.PinNumber = GPIO_PIN0;
    led0.GPIOx_Config.PinMode = OutputMode;
    led0.GPIOx_Config.PinSpeed = LOWSPEED;
    led0.GPIOx_Config.PullUpPullDown = NoPullUpOrPullDown;

    GPIO_Init(&led0);
    led0.GPIOx_Config.PinNumber = GPIO_PIN1;
    GPIO_Init(&led0);

}
void PA0_Init(void){
      GPIO_Handle_t led0;
    led0.GPIOx = GPIOA;
    led0.GPIOx_Config.AFSEL = AF0;
    led0.GPIOx_Config.OutPutType = PUSHPULL;
    led0.GPIOx_Config.PinNumber = GPIO_PIN0;
    led0.GPIOx_Config.PinMode = InputMode;
    led0.GPIOx_Config.PinSpeed = LOWSPEED;
    led0.GPIOx_Config.PullUpPullDown = PullUp;

    GPIO_IRQEnable(&led0,EXTI0_1_IRQn,FT_INTERRUPT);

}

void SysTick_Handler(void) {
      GPIO_TogglePin(GPIOB,GPIO_PIN0);
}
void EXTI0_1_IRQHandler(void){
    GPIO_ISRHandler(GPIO_PIN0);
    GPIO_WritePin(GPIOB,GPIO_PIN1,PIN_SET);

}

