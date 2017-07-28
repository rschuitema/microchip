/*******************************************************************************
* Description      : processor definition header for the supported processors
*******************************************************************************/
#ifndef _PROCESSOR_H_
#define _PROCESSOR_H_

#ifdef __cplusplus
    extern "C" {
#endif

/*******************************************************************************
*                          Include files
*******************************************************************************/
#ifdef __XC8__
	#ifdef __18F452
		#include <p18f452.h>
	#endif
	#ifdef __18F4550
		#include <p18f4550.h>
	#endif
#endif

#ifdef __XC16__
    #ifdef __dsPIC33FJ256GP710__
        #include <p33FJ256GP710.h>
    #endif
    #ifdef __PIC24FJ128GA010__
        #include <p24FJ128GA010.h>
    #endif
#endif

#ifdef __cplusplus
    }
#endif

#endif
/*******************************************************************************
*                          End of File
*******************************************************************************/
