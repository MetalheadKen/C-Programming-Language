/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
#include "tcp_echoclient.h"
#include "stm32f4_evb.h"
#include "lcd_log.h"

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern __IO uint8_t EthLinkStatus;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* By Include "main.c" */
extern void LCD_Init(void);

/* By Include "my_uart.h" */
extern void Usart3_Interrupt(void);

#ifdef USB_OTG_HS_DEDICATED_EP1_ENABLED
extern uint32_t USBD_OTG_EP1IN_ISR_Handler	(USB_OTG_CORE_HANDLE *pdev);
extern uint32_t USBD_OTG_EP1OUT_ISR_Handler	(USB_OTG_CORE_HANDLE *pdev);
#endif

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
    /* Go to infinite loop when Hard Fault exception occurs */
    while (1) {
    }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
    /* Go to infinite loop when Memory Manage exception occurs */
    while (1) {
    }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
    /* Go to infinite loop when Bus Fault exception occurs */
    while (1) {
    }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
    /* Go to infinite loop when Usage Fault exception occurs */
    while (1) {
    }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
    TimingDelay_Decrement();
    /* Update the LocalTime by adding SYSTEMTICK_PERIOD_MS each SysTick interrupt */
    Time_Update();
}

/**
  * @brief  This function handles External line 2 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI2_IRQHandler(void)
{
    EXTI_ClearITPendingBit(EXTI_Line2);
    STM_EVAL_LEDToggle(LED2);
}

void EXTI15_10_IRQHandler(void)
{
    if (EXTI_GetITStatus(EXTI_Line15) != RESET) {
        if (EthLinkStatus == 0) {
            /*connect to tcp server */
            tcp_echoclient_connect();
        }
        /* Clear the EXTI line  pending bit */
        EXTI_ClearITPendingBit(KEY_BUTTON_EXTI_LINE);
    }

    if (EXTI_GetITStatus(ETH_LINK_EXTI_LINE) != RESET) {
        Eth_Link_ITHandler(DP83848_PHY_ADDRESS);
        /* Clear interrupt pending bit */
        EXTI_ClearITPendingBit(ETH_LINK_EXTI_LINE);
    }

    if(EXTI_GetITStatus(TAMPER_BUTTON_EXTI_LINE) != RESET) {
        /* Display the current date and time */
        RTC_TimeShow();
        RTC_DateShow();

        for(uint32_t i = 0; i < 0x06FFFFFF; i++);

        LCD_Init();

        /* Clear the Tamper Button EXTI line pending bit */
        EXTI_ClearITPendingBit(TAMPER_BUTTON_EXTI_LINE);
    }
}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f40xx.s/startup_stm32f427x.s).                         */
/******************************************************************************/

void EXTI0_IRQHabdler(void)
{
    if(EXTI_GetITStatus(WAKEUP_BUTTON_EXTI_LINE) != RESET) {
        /* Display the current alarm */
        RTC_AlarmShow();

        /* Clear the Wakeup Button EXTI line pending bit */
        EXTI_ClearITPendingBit(WAKEUP_BUTTON_EXTI_LINE);
    }

#if USE_WWDG
    if (EXTI_GetITStatus(KEY_BUTTON_EXTI_LINE) != RESET) {
        /* Clear the Key Button EXTI Line Pending Bit */
        EXTI_ClearITPendingBit(KEY_BUTTON_EXTI_LINE);

        /* As the following address is invalid (not mapped), a Hardfault exception
          will be generated with an infinite loop and when the WWDG counter falls to 63
        the WWDG reset occurs */
        *(__IO uint32_t *) 0xA0001000 = 0xFF;
    }
#endif
}

void USART1_IRQHandler(void)
{
    uint8_t RxByte;

    RxByte = (USART_ReceiveData(EVAL_COM1) & 0x7F);
    USART_SendData(EVAL_COM1, RxByte);
}

/* USART3 中斷函數 */
/* 函數名稱為官方設定，只要偵測到 USART3 有資料輸入，這個函數就會被自動執行（收到一個字元就會被執行一次） */
void USART3_IRQHandler(void)
{
    Usart3_Interrupt();
}

void SDIO_IRQHandler(void)
{
    /* Process All SDIO Interrupt Sources */
    SD_ProcessIRQSrc();
}

/**
  * @brief  This function handles DMA2 Stream3 or DMA2 Stream6 global interrupts
  *         requests.
  * @param  None
  * @retval None
  */
void SD_SDIO_DMA_IRQHANDLER(void)
{
    /* Process DMA2 Stream3 or DMA2 Stream6 Interrupt Sources */
    SD_ProcessDMAIRQ();
}

void RTC_Alarm_IRQHandler(void)
{
    if(RTC_GetITStatus(RTC_IT_ALRA) != RESET) {
        STM_EVAL_LEDToggle(LED1);
        RTC_ClearITPendingBit(RTC_IT_ALRA);
        EXTI_ClearITPendingBit(EXTI_Line17);
    }
}

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
