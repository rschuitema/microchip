
#include "system.h"
#include "delay.h"
#include "gpio.h"

int16_t main (void)
{
    int16_t ret = RET_OK;
    
        /* initialize */
    ret = SYSTEM_Init();
    
    
    GPIO_PinMode(17, GPIO_PIN_OUTPUT);
    GPIO_PinMode(38, GPIO_PIN_OUTPUT);
    GPIO_PinMode(58, GPIO_PIN_OUTPUT);
    GPIO_PinMode(59, GPIO_PIN_OUTPUT);
    GPIO_PinMode(60, GPIO_PIN_OUTPUT);
    GPIO_PinMode(61, GPIO_PIN_OUTPUT);
    GPIO_PinMode(91, GPIO_PIN_OUTPUT);
    GPIO_PinMode(p92, GPIO_PIN_OUTPUT);
    
    GPIO_PortMode(port_a, 0x00);
    
    while (1)
    {
        GPIO_PinSet(17, PIN_LOW);
        GPIO_PinSet(38, PIN_LOW);
        GPIO_PinSet(92, PIN_LOW);
        DEL_WaitMs(DEL_1S);
        
        GPIO_PinSet(17, PIN_HIGH);
        GPIO_PinSet(38, PIN_HIGH);
        GPIO_PinSet(p92, PIN_HIGH);
        GPIO_PinSet(p58, PIN_LOW);
        GPIO_PinSet(59, PIN_LOW);
        GPIO_PinSet(60, PIN_LOW);
        GPIO_PinSet(p61, PIN_LOW);
        GPIO_PinSet(p91, PIN_LOW);
        DEL_WaitMs(DEL_1S);
        
        GPIO_PortSet(port_a, 0x0000);
        DEL_WaitMs(DEL_1S);

        GPIO_PortSet(port_a, 0x00FF);
        DEL_WaitMs(DEL_1S);

    }

    return ret;
}