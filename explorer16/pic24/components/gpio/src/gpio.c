/*******************************************************************************
* Description      : implementation of simple delay routines
*******************************************************************************/

/*******************************************************************************
*                          Include files
*******************************************************************************/
#include <stdint.h>
#include "gpio.h"

#define TRIS_N	(int*) 0x0000
#define TRIS_A	(int*) 0x02C0
#define TRIS_B	(int*) 0x02C8
#define TRIS_C	(int*) 0x02D0
#define TRIS_D	(int*) 0x02D8
#define TRIS_E	(int*) 0x02E0
#define TRIS_F	(int*) 0x02E8
#define TRIS_G	(int*) 0x02F0

#define PORT_N	(int*) 0x0000
#define PORT_A	(int*) 0x02C2
#define PORT_B	(int*) 0x02CA
#define PORT_C	(int*) 0x02D2
#define PORT_D	(int*) 0x02DA
#define PORT_E	(int*) 0x02E2
#define PORT_F	(int*) 0x02EA
#define PORT_G	(int*) 0x02F2

#define LAT_N	(int*) 0x0000
#define LAT_A	(int*) 0x02C4
#define LAT_B	(int*) 0x02CC
#define LAT_C	(int*) 0x02D4
#define LAT_D	(int*) 0x02DC
#define LAT_E	(int*) 0x02E4
#define LAT_F	(int*) 0x02EC
#define LAT_G	(int*) 0x02F4

/*******************************************************************************
*                          Static type definitions
*******************************************************************************/
/** Definition of a pin */
typedef struct tagPin
{
    int* lat;
    int* tris;
    int* port;
    int8_t bitpos;
    int8_t pinnr;
    GPIO_PinMode_t mode;
}Pin_t;

/** Definition of a port */
typedef struct tagPort
{
    int* lat;
    int* tris;
    int* port;
}Port_t;

/*******************************************************************************
*                          Static data definitions
*******************************************************************************/
/** Pin settings contains administration for the gpio pins. 
 *  The index in array is pin number */
static Pin_t pinSettings [101] = {
    {LAT_N, TRIS_N, PORT_N, 0, 0, GPIO_PIN_FIXED},
    {LAT_G, TRIS_G, PORT_G, 15, 1, GPIO_PIN_INPUT},
    {LAT_N, TRIS_N, PORT_N, 0, 2, GPIO_PIN_FIXED},
    {LAT_E, TRIS_E, PORT_E, 5, 3, GPIO_PIN_INPUT},
    {LAT_E, TRIS_E, PORT_E, 6, 4, GPIO_PIN_INPUT},
    {LAT_E, TRIS_E, PORT_E, 7, 5, GPIO_PIN_INPUT},
    {LAT_C, TRIS_C, PORT_C, 1, 6, GPIO_PIN_INPUT},
    {LAT_C, TRIS_C, PORT_C, 2, 7, GPIO_PIN_INPUT},
    {LAT_C, TRIS_C, PORT_C, 3, 8, GPIO_PIN_INPUT},
    {LAT_C, TRIS_C, PORT_C, 4, 9, GPIO_PIN_INPUT},
    {LAT_G, TRIS_G, PORT_G, 6, 10, GPIO_PIN_INPUT},
    {LAT_G, TRIS_G, PORT_G, 7, 11, GPIO_PIN_INPUT},
    {LAT_G, TRIS_G, PORT_G, 8, 12, GPIO_PIN_INPUT},
    {LAT_N, TRIS_N, PORT_N, 0, 13, GPIO_PIN_FIXED},
    {LAT_G, TRIS_G, PORT_G, 9, 14, GPIO_PIN_INPUT},
    {LAT_N, TRIS_N, PORT_N, 0, 15, GPIO_PIN_FIXED},
    {LAT_N, TRIS_N, PORT_N, 0, 16, GPIO_PIN_FIXED},
    {LAT_A, TRIS_A, PORT_A, 0, 17, GPIO_PIN_INPUT},
    {LAT_E, TRIS_E, PORT_E, 8, 18, GPIO_PIN_INPUT},
    {LAT_E, TRIS_E, PORT_E, 9, 19, GPIO_PIN_INPUT},
    {LAT_B, TRIS_B, PORT_B, 5, 20, GPIO_PIN_INPUT},
    {LAT_B, TRIS_B, PORT_B, 4, 21, GPIO_PIN_INPUT},
    {LAT_B, TRIS_B, PORT_B, 3, 22, GPIO_PIN_INPUT},
    {LAT_B, TRIS_B, PORT_B, 2, 23, GPIO_PIN_INPUT},
    {LAT_B, TRIS_B, PORT_B, 1, 24, GPIO_PIN_INPUT},
    {LAT_B, TRIS_B, PORT_B, 0, 25, GPIO_PIN_INPUT},
    {LAT_B, TRIS_B, PORT_B, 6, 26, GPIO_PIN_INPUT},
    {LAT_B, TRIS_B, PORT_B, 7, 27, GPIO_PIN_INPUT},
    {LAT_A, TRIS_A, PORT_A, 9, 28, GPIO_PIN_INPUT},
    {LAT_A, TRIS_A, PORT_A, 10, 29, GPIO_PIN_INPUT},
    {LAT_N, TRIS_N, PORT_N, 0, 30, GPIO_PIN_FIXED},
    {LAT_N, TRIS_N, PORT_N, 0, 31, GPIO_PIN_FIXED},
    {LAT_B, TRIS_B, PORT_B, 8, 32, GPIO_PIN_INPUT},
    {LAT_B, TRIS_B, PORT_B, 9, 33, GPIO_PIN_INPUT},
    {LAT_B, TRIS_B, PORT_B, 10, 34, GPIO_PIN_INPUT},
    {LAT_B, TRIS_B, PORT_B, 11, 35, GPIO_PIN_INPUT},
    {LAT_N, TRIS_N, PORT_N, 0, 36, GPIO_PIN_FIXED},
    {LAT_N, TRIS_N, PORT_N, 0, 37, GPIO_PIN_FIXED},
    {LAT_A, TRIS_A, PORT_A, 1, 38, GPIO_PIN_INPUT},
    {LAT_F, TRIS_F, PORT_F, 13, 39, GPIO_PIN_INPUT},
    {LAT_F, TRIS_F, PORT_F, 12, 40, GPIO_PIN_INPUT},
    {LAT_B, TRIS_B, PORT_B, 12, 41, GPIO_PIN_INPUT},
    {LAT_B, TRIS_B, PORT_B, 13, 42, GPIO_PIN_INPUT},
    {LAT_B, TRIS_B, PORT_B, 14, 43, GPIO_PIN_INPUT},
    {LAT_B, TRIS_B, PORT_B, 15, 44, GPIO_PIN_INPUT},
    {LAT_N, TRIS_N, PORT_N, 0, 45, GPIO_PIN_FIXED},
    {LAT_N, TRIS_N, PORT_N, 0, 46, GPIO_PIN_FIXED},
    {LAT_D, TRIS_D, PORT_D, 14, 47, GPIO_PIN_INPUT},
    {LAT_D, TRIS_D, PORT_D, 15, 48, GPIO_PIN_INPUT},
    {LAT_F, TRIS_F, PORT_F, 4, 49, GPIO_PIN_INPUT},
    {LAT_F, TRIS_F, PORT_F, 5, 50, GPIO_PIN_INPUT},
    {LAT_F, TRIS_F, PORT_F, 3, 51, GPIO_PIN_INPUT},
    {LAT_F, TRIS_F, PORT_F, 2, 52, GPIO_PIN_INPUT},
    {LAT_F, TRIS_F, PORT_F, 8, 53, GPIO_PIN_INPUT},
    {LAT_F, TRIS_F, PORT_F, 7, 54, GPIO_PIN_INPUT},
    {LAT_F, TRIS_F, PORT_F, 6, 55, GPIO_PIN_INPUT},
    {LAT_G, TRIS_G, PORT_G, 3, 56, GPIO_PIN_INPUT},
    {LAT_G, TRIS_G, PORT_G, 0, 57, GPIO_PIN_INPUT},
    {LAT_A, TRIS_A, PORT_A, 2, 58, GPIO_PIN_INPUT},
    {LAT_A, TRIS_A, PORT_A, 3, 59, GPIO_PIN_INPUT},
    {LAT_A, TRIS_A, PORT_A, 4, 60, GPIO_PIN_INPUT},
    {LAT_A, TRIS_A, PORT_A, 5, 61, GPIO_PIN_INPUT},
    {LAT_N, TRIS_N, PORT_N, 0, 62, GPIO_PIN_FIXED},
    {LAT_C, TRIS_C, PORT_C, 12, 63, GPIO_PIN_INPUT},
    {LAT_C, TRIS_C, PORT_C, 15, 64, GPIO_PIN_INPUT},
    {LAT_N, TRIS_N, PORT_N, 0, 65, GPIO_PIN_FIXED},
    {LAT_A, TRIS_A, PORT_A, 14, 66, GPIO_PIN_INPUT},
    {LAT_A, TRIS_A, PORT_A, 15, 67, GPIO_PIN_INPUT},
    {LAT_D, TRIS_D, PORT_D, 8, 68, GPIO_PIN_INPUT},
    {LAT_D, TRIS_D, PORT_D, 9, 69, GPIO_PIN_INPUT},
    {LAT_D, TRIS_D, PORT_D, 10, 70, GPIO_PIN_INPUT},
    {LAT_D, TRIS_D, PORT_D, 11, 71, GPIO_PIN_INPUT},
    {LAT_D, TRIS_D, PORT_D, 0, 72, GPIO_PIN_INPUT},
    {LAT_C, TRIS_C, PORT_C, 13, 73, GPIO_PIN_INPUT},
    {LAT_C, TRIS_C, PORT_C, 14, 74, GPIO_PIN_INPUT},
    {LAT_N, TRIS_N, PORT_N, 0, 75, GPIO_PIN_FIXED},
    {LAT_D, TRIS_D, PORT_D, 1, 76, GPIO_PIN_INPUT},
    {LAT_D, TRIS_D, PORT_D, 2, 77, GPIO_PIN_INPUT},
    {LAT_D, TRIS_D, PORT_D, 3, 78, GPIO_PIN_INPUT},
    {LAT_D, TRIS_D, PORT_D, 12, 79, GPIO_PIN_INPUT},
    {LAT_D, TRIS_D, PORT_D, 13, 80, GPIO_PIN_INPUT},
    {LAT_D, TRIS_D, PORT_D, 4, 81, GPIO_PIN_INPUT},
    {LAT_D, TRIS_D, PORT_D, 5, 82, GPIO_PIN_INPUT},
    {LAT_D, TRIS_D, PORT_D, 6, 83, GPIO_PIN_INPUT},
    {LAT_D, TRIS_D, PORT_D, 7, 84, GPIO_PIN_INPUT},
    {LAT_N, TRIS_N, PORT_N, 0, 85, GPIO_PIN_FIXED},
    {LAT_N, TRIS_N, PORT_N, 0, 86, GPIO_PIN_FIXED},
    {LAT_F, TRIS_F, PORT_F, 0, 87, GPIO_PIN_INPUT},
    {LAT_F, TRIS_F, PORT_F, 1, 88, GPIO_PIN_INPUT},
    {LAT_G, TRIS_G, PORT_G, 1, 89, GPIO_PIN_INPUT},
    {LAT_G, TRIS_G, PORT_G, 0, 90, GPIO_PIN_INPUT},
    {LAT_A, TRIS_A, PORT_A, 6, 91, GPIO_PIN_INPUT},
    {LAT_A, TRIS_A, PORT_A, 7, 92, GPIO_PIN_INPUT},
    {LAT_E, TRIS_E, PORT_E, 0, 93, GPIO_PIN_INPUT},
    {LAT_E, TRIS_E, PORT_E, 1, 94, GPIO_PIN_INPUT},
    {LAT_G, TRIS_G, PORT_G, 14, 95, GPIO_PIN_INPUT},
    {LAT_G, TRIS_G, PORT_G, 12, 96, GPIO_PIN_INPUT},
    {LAT_G, TRIS_G, PORT_G, 13, 97, GPIO_PIN_INPUT},
    {LAT_E, TRIS_E, PORT_E, 2, 98, GPIO_PIN_INPUT},
    {LAT_E, TRIS_E, PORT_E, 3, 99, GPIO_PIN_INPUT},
    {LAT_E, TRIS_E, PORT_E, 4, 100, GPIO_PIN_INPUT}
};

static Port_t portSettings[] = {
    {LAT_N, TRIS_N, PORT_N},
    {LAT_A, TRIS_A, PORT_A},
    {LAT_B, TRIS_B, PORT_B},
    {LAT_C, TRIS_C, PORT_C},
    {LAT_D, TRIS_D, PORT_D},
    {LAT_E, TRIS_E, PORT_E},
    {LAT_F, TRIS_F, PORT_F},
    {LAT_G, TRIS_G, PORT_G}
   
};

/*******************************************************************************
*                          Extern function definitions
*******************************************************************************/
uint16_t gpio_findPin(uint16_t port, uint16_t bitpos)
{
    uint16_t index = 0;
    bool pinFound = false;
    uint16_t pin = 0;
    
    while ((index < 100u) && (!pinFound))
    {
        if ((pinSettings[index].port == (int*)port) && (pinSettings[index].bitpos) == bitpos)
        {
            pinFound = true;
            pin = index;
        }
        index++;
    }
    
    return pin;
}

void GPIO_PinMode(uint16_t pin, GPIO_PinMode_t mode)
{
	uint16_t addval = 0;
	
	switch (mode)
	{
        case GPIO_PIN_OUTPUT:
        {
            addval = 1 << pinSettings[pin].bitpos;
            addval = ~addval;
            *(pinSettings[pin].tris) = *(pinSettings[pin].tris) & addval;
            pinSettings[pin].mode = GPIO_PIN_OUTPUT;
            break;
        }
        case GPIO_PIN_INPUT:
        {
            addval = 1 << pinSettings[pin].bitpos;
            *(pinSettings[pin].tris) = *(pinSettings[pin].tris) | addval;
            pinSettings[pin].mode = GPIO_PIN_INPUT;
            break;
        }
        case GPIO_PIN_PERIPHERAL:
        {
            pinSettings[pin].mode = GPIO_PIN_PERIPHERAL;
            break;
        }
		default:
		{
            pinSettings[pin].mode = GPIO_PIN_FIXED;
			break;
		}
	}
}

int16_t GPIO_PinSet(uint16_t pin, uint8_t value)
{
    int16_t result = RET_OK;
    uint16_t addval = 0;
    
	if (pinSettings[pin].mode == GPIO_PIN_OUTPUT)
    {
        switch(value)
        {
            case 0:
            {
                addval = 1 << pinSettings[pin].bitpos;
                addval = ~addval;
                *(pinSettings[pin].lat) = *(pinSettings[pin].lat) & addval;
                break;
            }
            case 1:
            {
                addval = 1 << pinSettings[pin].bitpos;
                *(pinSettings[pin].lat) = *(pinSettings[pin].lat) | addval;
                break;
            }
            default:
            {
                result = RET_INVALID_PARAMETER;
                break;
            }

        }
    }
    else
    {
        result = RET_INVALID_PARAMETER;
    }
    
    return result;
}

int16_t GPIO_PinGet(uint16_t pin, uint8_t* value)
{
    int16_t result = RET_OK;
    uint16_t addval = 0;
    
	if (pinSettings[pin].mode == GPIO_PIN_INPUT)
    {
        addval = 1 << pinSettings[pin].bitpos;
        addval = addval & *(pinSettings[pin].port);
        if (addval > 0)
        {
            *value = 1;
        }
        else
        {
            *value = 0;
        }
    }
    else
    {
        result = RET_INVALID_PARAMETER;
    }
    
    return result;
}

void GPIO_PortMode(uint16_t port, uint16_t mode)
{
    uint16_t bitpos;
    
    *(portSettings[port].tris) = mode;
    
    for (bitpos = 0; bitpos < 16; bitpos++)
    {
        uint16_t val = mode & (1 << bitpos);
        uint16_t pin = gpio_findPin(*(portSettings[port].port), bitpos);
        
        if (val == 1)
        {
            pinSettings[pin].mode = GPIO_PIN_OUTPUT;
        }
        else
        {
            pinSettings[pin].mode = GPIO_PIN_INPUT;
        }
    }
}

void GPIO_PortSet(uint16_t port, uint16_t value)
{
    *(portSettings[port].lat) = value;
}

uint16_t GPIO_PortGet(uint16_t port)
{
	return *(portSettings[port].port);
}

/*******************************************************************************
*                          End of File
*******************************************************************************/
