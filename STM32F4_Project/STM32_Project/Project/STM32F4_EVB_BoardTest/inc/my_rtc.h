/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MY_RTC_H
#define __MY_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4_evb.h"
#include "stm324xg_eval_lcd.h"

#define RTC_CLOCK_SOURCE_LSE          /* LSE used as RTC source clock */
/* #define RTC_CLOCK_SOURCE_LSI */    /* LSI used as RTC source clock. The RTC Clock
                                         may varies due to LSI frequency dispersion. */

/* By Include "my_rtc.c" */
extern RTC_TimeTypeDef  RTC_TimeStructure1;
extern RTC_DateTypeDef  RTC_DateStructure1;
extern RTC_InitTypeDef  RTC_InitStructure1;
extern RTC_AlarmTypeDef RTC_AlarmStructure1;

extern __IO uint32_t uwAsynchPrediv;
extern __IO uint32_t uwSynchPrediv;
extern uint8_t aShowTime[50];

/* By Include "my_uart.c" */
extern uint8_t in_out_enable;

void RTC_Config(void);
void RTC_Setting(void);
void RTC_TimeShow(void);
void RTC_DateShow(void);
void RTC_AlarmShow(void);

#ifdef __cplusplus
}
#endif

#endif /* __MY_RTC_H */
