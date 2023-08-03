#include "led.h"

void led_init(void){
    //1. Init Clock for GPION
    GPIOB_PCLKEN();

    //Clear GPIOB_B
    GPIOB->MODER  &= ~(0xF);
    GPIOB->MODER  |= (0x5);
}

void blink_led(void){
    GPIOB->ODR ^= (0x3);
}
