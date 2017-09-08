/**
  ******************************************************************************
  * @file    WWDG/WWDG_Example/main.c
  * @author  MCD Application Team
  * @version V1.7.0
  * @date    22-April-2016
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2016 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F4xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup WWDG_Example
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
__IO uint32_t uwTimingDelay = 0;

/* Private function prototypes -----------------------------------------------*/
static void Delay(__IO uint32_t nTime);

/* Private functions ---------------------------------------------------------*/
void BSP_Init(void);
void WWDG_Config(void);

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
    /*!< At this stage the microcontroller clock setting is already configured,
         this is done through SystemInit() function which is called from startup
         files (startup_stm32f40_41xxx.s/startup_stm32f427_437xx.s/startup_stm32f429_439xx.s)
         before to branch to application main.
         To reconfigure the default setting of SystemInit() function, refer to
         system_stm32f4xx.c file
       */

    BSP_Init();

    /* �ˬd�t�άO�_�o�� Window Watch Dog ���m */
    if (RCC_GetFlagStatus(RCC_FLAG_WWDGRST) != RESET) {
        /* WWDGRST �X�Ц��]�m */
        STM_EVAL_LEDOn(LED1);

        /* �M�����m�X�� */
        RCC_ClearFlag();
    } else {
        /* WWDGRST �X�ШS���]�m*/
        STM_EVAL_LEDOff(LED1);
    }

    /* �]�w SysTick Timer �C 1ms ���ͤ��_  */
    if (SysTick_Config(SystemCoreClock / 1000)) {
        /* �إߥ��� */
        while (1);
    }

    WWDG_Config();

    while (1) {
        /* Toggle LED2 */
        STM_EVAL_LEDToggle(LED2);

        /* Insert 40 ms delay */
        Delay(40);

        /* Update WWDG counter */
        WWDG_SetCounter(127);
    }
}

void BSP_Init(void)
{
    /* LED ��l�� */
    STM_EVAL_LEDInit(LED1);
    STM_EVAL_LEDInit(LED2);

    /* Button ��l�� */
    STM_EVAL_PBInit(BUTTON, BUTTON_MODE_EXTI);
}

/* �إ� Window Watch Dog */
void WWDG_Config(void)
{
    /* �}�� WWDG clock */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);

    /* WWDG clock counter = (PCLK1 (42MHz)/4096)/8 = 1281 Hz (~780 us) */
    WWDG_SetPrescaler(WWDG_Prescaler_8);

    /* �]�m���f���Ȭ� 80 */
    /* WWDG �p�ƭȥ����n�C�� 80 �M�j�� 64 �ɨ�s�A�_�h�|���ͨt�έ��m */
    WWDG_SetWindowValue(80);

    /* �}�� WWDG �ó]�m�p�ƭȬ� 127 */
    /* WWDG timeout = ~780 us * 64 = 49.92 ms
     In this case the refresh window is:
           ~780 * (127-80) = 36.6ms < refresh window < ~780 * 64 = 49.9ms */
    WWDG_Enable(127);
}

/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in milliseconds.
  * @retval None
  */
static void Delay(__IO uint32_t nTime)
{
    uwTimingDelay = nTime;

    while(uwTimingDelay != 0);
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1) {
    }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
