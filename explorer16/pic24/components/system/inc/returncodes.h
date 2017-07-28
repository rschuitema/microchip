/*******************************************************************************
* Description      : return code definitions
*******************************************************************************/
#ifndef _RETURNCODE_H_
#define _RETURNCODE_H_

#ifdef __cplusplus
    extern "C" {
#endif

/*******************************************************************************
*                          Definitions
*******************************************************************************/

/* error base definitions */
#define RET_BASE				(0x0000)

/* general error definitions */
#define RET_OK					(RET_BASE)
#define RET_INVALID_PARAMETER	(RET_BASE + 0x01)
#define RET_NOT_SUPPORTED		(RET_BASE + 0x02)
#define RET_FAILED				(RET_BASE + 0x03)

#ifdef __cplusplus
    }
#endif

#endif
/*******************************************************************************
*                          End of File
*******************************************************************************/
