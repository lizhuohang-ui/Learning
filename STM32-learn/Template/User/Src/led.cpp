#include "led.h"
LED::LED(GPIO_TypeDef* GPIOx, uint16_t Pin){
    /* LED GPIO Ports Clock Enable */
    if(GPIOx == GPIOA){__HAL_RCC_GPIOA_CLK_ENABLE();}
    if(GPIOx == GPIOB){__HAL_RCC_GPIOB_CLK_ENABLE();}
    if(GPIOx == GPIOC){__HAL_RCC_GPIOC_CLK_ENABLE();}
    if(GPIOx == GPIOD){__HAL_RCC_GPIOD_CLK_ENABLE();}
    /* Configure GPIO pins */
    LED_GPIO = GPIOx;
    LED_GPIO_Pin = Pin;
    LED_GPIO_Mode = GPIO_MODE_OUTPUT_PP;
    LED_GPIO_Pull = GPIO_NOPULL;
    LED_GPIO_Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitTypeDef LED_GPIO_InitStruct = {0};
    LED_GPIO_InitStruct.Pin = Pin;
    LED_GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    LED_GPIO_InitStruct.Pull = GPIO_NOPULL;
    LED_GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOx, &LED_GPIO_InitStruct);
}

void LED::Open() {

}

