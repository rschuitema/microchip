
#include "system.h"
#include "delay.h"

int16_t main (void)
{
    int16_t ret = RET_OK;
    
    TRISA = 0xFF00;     /* port A pin 0..7 as output */

    /* initialize */
    ret = SYSTEM_Init();
    
    
    while (1)
    {
        PORTA = 0x00;
        DEL_WaitMs(DEL_1S);
        
        PORTA = 0xFF;
        DEL_WaitMs(DEL_1S);
    }

    return ret;
}