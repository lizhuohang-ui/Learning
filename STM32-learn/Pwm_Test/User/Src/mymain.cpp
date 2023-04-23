//
// Created by 86199 on 2023/3/20.
//
#include "mymain.h"

int my_main(void){
    printf("LED");
    printf("hello world");
    LED led1(GPIOC, GPIO_PIN_2);
    LED led2(GPIOC, GPIO_PIN_3);
    while(1){
        led1.Toggle();
        led2.Toggle();
        HAL_Delay(1000);
        led1.Toggle();
        led2.Toggle();
        HAL_Delay(1000);
    }
}