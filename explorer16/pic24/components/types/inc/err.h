/*******************************************************************************
* Description      : error definitions
*******************************************************************************/
#ifndef _ERR_H_
#define _ERR_H_

#ifdef __cplusplus
    extern "C" {
#endif

/*******************************************************************************
*                          Definitions
*******************************************************************************/

/* error base definitions */
#define ERR_GEN_BASE				(0x0000)
#define ERR_I2C_BASE                (0x0010)
#define ERR_RTC_BASE                (0x0020)
#define ERR_EEP_BASE                (0x0030)
#define ERR_LCD_BASE				(0x0040)
#define ERR_IOEXP_BASE				(0x0050)
#define ERR_SPI_BASE				(0x0060)
#define ERR_SDCARD_BASE             (0x0070)
#define ERR_UART_BASE               (0x0080)
#define ERR_FILE_BASE               (0x0090)

/* general error definitions */
#define ERR_OK					(ERR_GEN_BASE)
#define ERR_INVALID_PARAMETER	(ERR_GEN_BASE + 0x01)
#define ERR_NOT_SUPPORTED		(ERR_GEN_BASE + 0x02)
#define ERR_FAILED				(ERR_GEN_BASE + 0x03)

#ifdef __cplusplus
    }
#endif

#endif
/*******************************************************************************
*                          End of File
*******************************************************************************/
