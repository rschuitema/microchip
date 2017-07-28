/*******************************************************************************
* Description      : implementation of simple delay routines
*******************************************************************************/

/*******************************************************************************
*                          Include files
*******************************************************************************/
#include <stdint.h>
#include "delay.h"

/*******************************************************************************
*                          Static data definitions
*******************************************************************************/
#ifndef _WIN32
static uint16_t temp_count;
#endif

/*******************************************************************************
*                          Extern function definitions
*******************************************************************************/
/**
 * This function gives a defined delay in ms.
 * The header file defines certain delays.
 */
#ifdef __dsPIC33F__
/* assuming 40MHz */
void DEL_WaitMs(uint16_t aDelayCount) 
{
	temp_count = aDelayCount + 1;
	asm volatile("outer: dec _temp_count");	
	asm volatile("cp0 _temp_count");
	asm volatile("bra z, done");
	asm volatile("do #3200, inner");	
	asm volatile("nop");
	asm volatile("inner: nop");
	asm volatile("bra outer");
	asm volatile("done:");
}
	

/**
 * This function gives a defined delay in ms.
 * The header file defines certain delays.
 * \todo    test this function.
 * function costs 43*count+9 cycles
 */
void DEL_WaitUs(uint16_t aDelayCount)
{
	temp_count = aDelayCount + 1;
	asm volatile("outer1: dec _temp_count");	
	asm volatile("cp0 _temp_count");
	asm volatile("bra z, done1");
	asm volatile("do #17, inner1");	
	asm volatile("nop");
	asm volatile("inner1: nop");
	asm volatile("bra outer1");
	asm volatile("done1:");
}		
#endif

#ifdef __PIC24F__
/* assuming 32 MHz */
void DEL_WaitMs(uint16_t aDelayCount) 
{
	temp_count = aDelayCount;
	asm volatile("outer: dec _temp_count");	
	asm volatile("cp0 _temp_count");
	asm volatile("bra z, done");
	asm volatile("repeat #249");	
	asm volatile("nop");
	asm volatile("bra outer");
	asm volatile("done:");
}
	

/**
 * This function gives a defined delay in ms.
 * The header file defines certain delays.
 * \todo    test this function.
 * function costs 43*count+9 cycles
 */
void DEL_WaitUs(uint16_t aDelayCount)
{
	temp_count = aDelayCount;
	asm volatile("outer1: dec _temp_count");	
	asm volatile("cp0 _temp_count");
	asm volatile("bra z, done1");
	asm volatile("repeat #1");	
	asm volatile("nop");
	asm volatile("bra outer1");
	asm volatile("done1:");
}		
#endif

#ifdef _WIN32

void DEL_WaitMs(uint16_t aDelayCount) 
{
	Sleep(aDelayCount);
}

void DEL_WaitUs(uint16_t aDelayCount) 
{
	Sleep(aDelayCount);
}

#endif
