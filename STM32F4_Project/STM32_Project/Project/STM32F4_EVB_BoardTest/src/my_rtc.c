#include "my_rtc.h"

RTC_TimeTypeDef  RTC_TimeStructure1;
RTC_DateTypeDef  RTC_DateStructure1;
RTC_InitTypeDef  RTC_InitStructure1;
RTC_AlarmTypeDef RTC_AlarmStructure1;

__IO uint32_t uwAsynchPrediv = 0;
__IO uint32_t uwSynchPrediv = 0;
uint8_t aShowTime[50] = {0};

uint8_t rtc_high[3] = {0};
uint8_t rtc_med[3]	= {0};
uint8_t rtc_low[3]  = {0};

void RTC_Config(void)
{
    /* Enable the PWR clock */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);

    /* Allow access to RTC */
    PWR_BackupAccessCmd(ENABLE);

#if defined (RTC_CLOCK_SOURCE_LSI)  /* LSI used as RTC source clock*/
    /* The RTC Clock may varies due to LSI frequency dispersion */
    /* Enable the LSI OSC */
    RCC_LSICmd(ENABLE);

    /* Wait till LSI is ready */
    while(RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET) {
    }

    /* Select the RTC Clock Source */
    RCC_RTCCLKConfig(RCC_RTCCLKSource_LSI);

    /* ck_spre(1Hz) = RTCCLK(LSI) /(uwAsynchPrediv + 1)*(uwSynchPrediv + 1)*/
    uwSynchPrediv = 0xFF;
    uwAsynchPrediv = 0x7F;

#elif defined (RTC_CLOCK_SOURCE_LSE) /* LSE used as RTC source clock */
    /* Enable the LSE OSC */
    RCC_LSEConfig(RCC_LSE_ON);

    /* Wait till LSE is ready */
    while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET) {
    }

    /* Select the RTC Clock Source */
    RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
    /* ck_spre(1Hz) = RTCCLK(LSE) /(uwAsynchPrediv + 1)*(uwSynchPrediv + 1)*/
    uwSynchPrediv = 0xFF;
    uwAsynchPrediv = 0x7F;

#else
#error Please select the RTC Clock source inside the main.c file
#endif /* RTC_CLOCK_SOURCE_LSI */

    /* Enable the RTC Clock */
    RCC_RTCCLKCmd(ENABLE);

    /* Wait for RTC APB registers synchronisation */
    RTC_WaitForSynchro();

    /* Configure the RTC data register and RTC prescaler */
    RTC_InitStructure1.RTC_AsynchPrediv = uwAsynchPrediv;
    RTC_InitStructure1.RTC_SynchPrediv = uwSynchPrediv;
    RTC_InitStructure1.RTC_HourFormat = RTC_HourFormat_24;
    RTC_Init(&RTC_InitStructure1);

    /* Set the alarm 05h:20min:30s */
    RTC_AlarmStructure1.RTC_AlarmTime.RTC_H12     = RTC_H12_AM;
    RTC_AlarmStructure1.RTC_AlarmTime.RTC_Hours   = 0x05;
    RTC_AlarmStructure1.RTC_AlarmTime.RTC_Minutes = 0x20;
    RTC_AlarmStructure1.RTC_AlarmTime.RTC_Seconds = 0x30;
    RTC_AlarmStructure1.RTC_AlarmDateWeekDay = 0x31;
    RTC_AlarmStructure1.RTC_AlarmDateWeekDaySel = RTC_AlarmDateWeekDaySel_Date;
    RTC_AlarmStructure1.RTC_AlarmMask = RTC_AlarmMask_DateWeekDay;

    /* Configure the RTC Alarm A register */
    RTC_SetAlarm(RTC_Format_BCD, RTC_Alarm_A, &RTC_AlarmStructure1);

    /* Enable RTC Alarm A Interrupt */
    RTC_ITConfig(RTC_IT_ALRA, ENABLE);

    /* Enable the alarm */
    RTC_AlarmCmd(RTC_Alarm_A, ENABLE);

    RTC_ClearFlag(RTC_FLAG_ALRAF);

    /* Set the date: Friday September 02th 2016 */
    RTC_DateStructure1.RTC_Year = 0x16;
    RTC_DateStructure1.RTC_Month = RTC_Month_September;
    RTC_DateStructure1.RTC_Date = 0x06;
    RTC_DateStructure1.RTC_WeekDay = RTC_Weekday_Saturday;
    RTC_SetDate(RTC_Format_BCD, &RTC_DateStructure1);

    /* Set the time to 02h 30mn 00s PM */
    RTC_TimeStructure1.RTC_H12     = RTC_H12_AM;
    RTC_TimeStructure1.RTC_Hours   = 0x10;
    RTC_TimeStructure1.RTC_Minutes = 0x10;
    RTC_TimeStructure1.RTC_Seconds = 0x00;

    RTC_SetTime(RTC_Format_BCD, &RTC_TimeStructure1);

    /* Indicator for the RTC configuration */
    RTC_WriteBackupRegister(RTC_BKP_DR0, 0x32F2);
}

void RTC_Setting(void)
{
    NVIC_InitTypeDef  NVIC_InitStructure;
    EXTI_InitTypeDef  EXTI_InitStructure;

    if (RTC_ReadBackupRegister(RTC_BKP_DR0) != 0x32F2) {
        /* RTC configuration  */
        RTC_Config();
        /* Display the RTC Time and Alarm */
        RTC_TimeShow();
        RTC_AlarmShow();
    } else {
        /* Check if the Power On Reset flag is set */
        if (RCC_GetFlagStatus(RCC_FLAG_PORRST) != RESET) {
            /* Power On Reset occurred     */
            STM_EVAL_LEDOn(LED3);
        }
        /* Check if the Pin Reset flag is set */
        else if (RCC_GetFlagStatus(RCC_FLAG_PINRST) != RESET) {
            /* External Reset occurred */
            STM_EVAL_LEDOn(LED4);
        }

        /* Enable the PWR clock */
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);

        /* Allow access to RTC */
        PWR_BackupAccessCmd(ENABLE);

        /* Wait for RTC APB registers synchronisation */
        RTC_WaitForSynchro();

        /* Clear the RTC Alarm Flag */
        RTC_ClearFlag(RTC_FLAG_ALRAF);

        /* Clear the EXTI Line 17 Pending bit (Connected internally to RTC Alarm) */
        EXTI_ClearITPendingBit(EXTI_Line17);

        /* Display the RTC Time and Alarm */
        RTC_TimeShow();
        RTC_AlarmShow();
    }

    /* RTC Alarm A Interrupt Configuration */
    /* EXTI configuration *******************************************************/
    EXTI_ClearITPendingBit(EXTI_Line17);
    EXTI_InitStructure.EXTI_Line = EXTI_Line17;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    /* Enable the RTC Alarm Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = RTC_Alarm_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

/**
  * @brief  Display the current time.
  * @param  None
  * @retval None
  */
void RTC_TimeShow(void)
{
    /* Get the current Time */
    RTC_GetTime(RTC_Format_BIN, &RTC_TimeStructure1);

    /* Display time Format : hh:mm:ss */
    rtc_high[2] = ((RTC_TimeStructure1.RTC_Hours / 10) + 0x30);
    rtc_high[1] = ((RTC_TimeStructure1.RTC_Hours % 10) + 0x30);
    rtc_high[0] = '\0';
    rtc_med[2]  = ((RTC_TimeStructure1.RTC_Minutes / 10) + 0x30);
    rtc_med[1] 	= ((RTC_TimeStructure1.RTC_Minutes % 10) + 0x30);
    rtc_med[0] 	= '\0';
    rtc_low[2]  = ((RTC_TimeStructure1.RTC_Seconds / 10) + 0x30);
    rtc_low[1] 	= ((RTC_TimeStructure1.RTC_Seconds % 10) + 0x30);
    rtc_low[0]	= '\0';

    uint8_t time_display[] = {' ', ' ', ' ', ' ', ' ', rtc_high[2], rtc_high[1], ':', rtc_med[2], rtc_med[1], ':', rtc_low[2], rtc_low[1], '\0'};

    LCD_Clear(Black);
    LCD_SetBackColor(Black);
    LCD_SetTextColor(White);

    LCD_DisplayStringLine(Line0, (uint8_t *)"    Current Time   ");
    LCD_DisplayStringLine(Line1, time_display);
}

/**
  * @brief  Display the current date.
  * @param  None
  * @retval None
  */
void RTC_DateShow(void)
{
    /* Get the current Time */
    RTC_GetDate(RTC_Format_BIN, &RTC_DateStructure1);

    /* Display Date Format : 20yy/mm/dd */
    rtc_high[2] = ((RTC_DateStructure1.RTC_Year / 10) + 0x30);
    rtc_high[1] = ((RTC_DateStructure1.RTC_Year % 10) + 0x30);
    rtc_high[0] = '\0';
    rtc_med[2]  = ((RTC_DateStructure1.RTC_Month / 10) + 0x30);
    rtc_med[1] 	= ((RTC_DateStructure1.RTC_Month % 10) + 0x30);
    rtc_med[0] 	= '\0';
    rtc_low[2]  = ((RTC_DateStructure1.RTC_Date / 10) + 0x30);
    rtc_low[1] 	= ((RTC_DateStructure1.RTC_Date % 10) + 0x30);
    rtc_low[0]	= '\0';

    uint8_t date_display[] = {' ', ' ', ' ', ' ', ' ', '2', '0', rtc_high[2], rtc_high[1], '/', rtc_med[2], rtc_med[1], '/', rtc_low[2], rtc_low[1], '\0'};

    LCD_DisplayStringLine(Line3, (uint8_t *)"    Current Date   ");
    LCD_DisplayStringLine(Line4, date_display);
}

/**
  * @brief  Display the current Alarm.
  * @param  None
  * @retval None
  */
void RTC_AlarmShow(void)
{
    uint8_t showalarm[50] = {0};

    /* Get the current Alarm */
    RTC_GetAlarm(RTC_Format_BIN, RTC_Alarm_A, &RTC_AlarmStructure1);
}
