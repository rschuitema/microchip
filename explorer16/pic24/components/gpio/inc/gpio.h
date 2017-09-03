/*******************************************************************************
* Description      : digital io interface
*******************************************************************************/
#ifndef _GPIO_H_
#define _GPIO_H_

#ifdef __cplusplus
    extern "C" {
#endif

/*******************************************************************************
*                          Include files
*******************************************************************************/
#include "system.h"
#include "pindefinitions.h"
#include "portdefinitions.h"

/*******************************************************************************
*                          Macro definitions
*******************************************************************************/
#define PIN_LOW   (0)
#define PIN_HIGH  (1)

/*******************************************************************************
*                          Type definitions
*******************************************************************************/
typedef enum
{
    GPIO_PIN_INPUT = 0,
    GPIO_PIN_OUTPUT,
    GPIO_PIN_PERIPHERAL,
    GPIO_PIN_FIXED
} GPIO_PinMode_t;

/*******************************************************************************
*                          Extern Function Prototypes
*******************************************************************************/
/**
 * Set the mode of \a pin to \a mode
 *
 * \param [in]  pin     The pin to configure
 * \param [in]  mode    The mode to configure
 */
void GPIO_PinMode(uint16_t pin, GPIO_PinMode_t mode);

/**
 * Set the value of \a pin to \a value
 *
 * \param [in]  pin     The pin to set
 * \param [in]  value   The value to set 
 */
int16_t GPIO_PinSet(uint16_t pin, uint8_t value);

int16_t GPIO_PinGet(uint16_t pin, uint8_t* value);

void GPIO_PortMode(uint16_t port, uint16_t mode);

void GPIO_PortSet(uint16_t port, uint16_t value);

uint16_t GPIO_PortGet(uint16_t port);


#ifdef __cplusplus
    }
#endif

#endif
/*******************************************************************************
*                          End of File
*******************************************************************************/
