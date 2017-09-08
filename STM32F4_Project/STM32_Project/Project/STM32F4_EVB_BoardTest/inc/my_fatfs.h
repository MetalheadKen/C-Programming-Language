/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MY_FATFS_H
#define __MY_FATFS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "ff.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "lcd_log.h"
#include "stm32f4xx.h"
#include "stm32f4_evb_sdio_sd.h"

/* By Include "my_fatfs.c" */
extern FATFS 		fs;
extern FIL			file;
extern char 		write_in[];
extern char 		write_out[];
extern uint32_t ret_length;

/* By Inlcude "my_uart.c" */
extern uint8_t 	in_out_enable;

/* By Include "my_rtc.c" */
extern uint8_t 					rtc_high[3];
extern uint8_t 					rtc_med[3];
extern uint8_t 					rtc_low[3];
extern RTC_TimeTypeDef  RTC_TimeStructure1;
extern RTC_DateTypeDef  RTC_DateStructure1;

void SDCard_Config(void);
void InOut_Write(uint8_t);

#ifdef __cplusplus
}
#endif

#endif /* __MY_FATFS_H */
