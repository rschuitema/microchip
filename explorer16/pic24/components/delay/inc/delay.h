/*******************************************************************************
* Description      : Simple delay routines
*******************************************************************************/
#ifndef _DEL_H_
#define _DEL_H_

#ifdef __cplusplus
    extern "C" {
#endif

/*******************************************************************************
*                          Include files
*******************************************************************************/
#include "system.h"

/*******************************************************************************
*                          Macro definitions
*******************************************************************************/
#ifdef __dsPIC33F__
/* assuming 40MHz */
#define DEL_1MS             (((SYS_FOSC_HZ * 0.001) / 6410) + 1)
#define DEL_2MS             (((SYS_FOSC_HZ * 0.002) / 6410) + 1)
#define DEL_5MS             (((SYS_FOSC_HZ * 0.005) / 6410) + 1)
#define DEL_10MS            (((SYS_FOSC_HZ * 0.010) / 6410) + 1)
#define DEL_15MS            (((SYS_FOSC_HZ * 0.015) / 6410) + 1)
#define DEL_1S              (((SYS_FOSC_HZ * 1) / 6410) + 1) 

#define DEL_10US            (((SYS_FOSC_HZ * 0.00001) -9) /43)
#define DEL_100US           (((SYS_FOSC_HZ * 0.0001) -9) /43)
#define DEL_200US           (((SYS_FOSC_HZ * 0.0002) -9) /43)
#endif

#ifdef __PIC24F__
/* assuming 32MHz */
#define DEL_1MS             (((((SYS_FOSC_HZ * 0.001)/2)-9)/256)+1)
#define DEL_2MS             (((((SYS_FOSC_HZ * 0.002)/2)-9)/256)+1)
#define DEL_5MS             (((((SYS_FOSC_HZ * 0.005)/2)-9)/256)+1)
#define DEL_10MS            (((((SYS_FOSC_HZ * 0.010)/2)-9)/256)+1)
#define DEL_15MS            (((((SYS_FOSC_HZ * 0.015)/2)-9)/256)+1)
#define DEL_1S              (((((SYS_FOSC_HZ * 1)/2)-9)/256)+1) 

#define DEL_5US             (((((SYS_FOSC_HZ * 0.000005)/2)-9)/8)+1)
#define DEL_10US            (((((SYS_FOSC_HZ * 0.00001)/2)-9)/8)+1)
#define DEL_20US            (((((SYS_FOSC_HZ * 0.00002)/2)-9)/8)+1)
#define DEL_50US            (((((SYS_FOSC_HZ * 0.00005)/2)-9)/8)+1)
#define DEL_70US            (((((SYS_FOSC_HZ * 0.00007)/2)-9)/8)+1)
#define DEL_100US           (((((SYS_FOSC_HZ * 0.0001)/2)-9)/8)+1)
#define DEL_200US           (((((SYS_FOSC_HZ * 0.0002)/2)-9)/8)+1)
#define DEL_400US           (((((SYS_FOSC_HZ * 0.0004)/2)-9)/8)+1)
#define DEL_500US           (((((SYS_FOSC_HZ * 0.0005)/2)-9)/8)+1)
#endif

#ifdef _WIN32
#define DEL_1MS             (1u)
#define DEL_2MS             (2u)
#define DEL_5MS             (5u)
#define DEL_10MS            (10u)
#define DEL_15MS            (15u)
#define DEL_1S              (1000u) 

#define DEL_10US            (1u)
#define DEL_100US           (1u)
#define DEL_200US           (1u)
#endif
/*******************************************************************************
*                          Extern Function Prototypes
*******************************************************************************/
/**
 * Delay for \a aDelayCount of mili seconds
 *
 * \param [in]  aDelayCount     Delay in miliseconds
 */
void DEL_WaitMs(uint16_t aDelayCount);

/**
 * Delay for \a aDelayCount of microseconds
 *
 * \param [in]  aDelayCount     Delay in microseconds
 */
void DEL_WaitUs(uint16_t aDelayCount);

#ifdef __cplusplus
    }
#endif

#endif
/*******************************************************************************
*                          End of File
*******************************************************************************/
