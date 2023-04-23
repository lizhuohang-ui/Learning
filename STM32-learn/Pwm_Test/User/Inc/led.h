#ifndef TEMPLATE_LED_H
#define TEMPLATE_LED_H
#ifdef __cplusplus
extern "C"{
#endif
#include "main.h"


#ifdef __cplusplus
class LED {
public:
    LED(GPIO_TypeDef* GPIOx, uint16_t Pin);
    void Open(void);
    void Close(void);
    void Toggle(void);
private:
    GPIO_TypeDef *LED_GPIO;
    uint32_t LED_GPIO_Pin;
    uint32_t LED_GPIO_Mode;
    uint32_t LED_GPIO_Pull;
    uint32_t LED_GPIO_Speed;
};
#endif


#ifdef __cplusplus
}
#endif // __cplusplus
#endif //TEMPLATE_LED_H
