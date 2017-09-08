/**
  ******************************************************************************
  * @file    CAN/CAN_Networking/main.c
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

/** @addtogroup CAN_Networking
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define KEY_PRESSED     0x00
#define KEY_NOT_PRESSED 0x01

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
CAN_InitTypeDef        CAN_InitStructure;
CAN_FilterInitTypeDef  CAN_FilterInitStructure;
CanTxMsg TxMessage;
uint8_t ubKeyNumber = 0x0;

/* Private function prototypes -----------------------------------------------*/
static void NVIC_Config(void);
static void CAN_Config(void);
void LED_Display(uint8_t Ledstatus);
void Init_RxMes(CanRxMsg *RxMessage);
/* Private functions ---------------------------------------------------------*/

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

    /* NVIC configuration */
    NVIC_Config();

    /* Initialize LEDs mounted on EVAL board */
    STM_EVAL_LEDInit(LED1);
    STM_EVAL_LEDInit(LED2);
    STM_EVAL_LEDInit(LED3);
    STM_EVAL_LEDInit(LED4);

    /* Initialize Key Button mounted on EVAL board */
    STM_EVAL_PBInit(BUTTON_KEY, BUTTON_MODE_GPIO);

    /* CAN configuration */
    CAN_Config();

    while(1) {
        while(STM_EVAL_PBGetState(BUTTON_KEY) == KEY_PRESSED) {
            if(ubKeyNumber == 0x4) {
                ubKeyNumber = 0x00;
            } else {
                LED_Display(++ubKeyNumber);
                TxMessage.Data[0] = ubKeyNumber;
                CAN_Transmit(CANx, &TxMessage);
                /* Wait until one of the mailboxes is empty */
                while((CAN_GetFlagStatus(CANx, CAN_FLAG_RQCP0) !=RESET) || \
                        (CAN_GetFlagStatus(CANx, CAN_FLAG_RQCP1) !=RESET) || \
                        (CAN_GetFlagStatus(CANx, CAN_FLAG_RQCP2) !=RESET));

                while(STM_EVAL_PBGetState(BUTTON_KEY) != KEY_NOT_PRESSED) {
                }
            }
        }
    }
}

/**
  * @brief  Configures the CAN.
  * @param  None
  * @retval None
  */
static void CAN_Config(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    /* CAN GPIOs configuration **************************************************/

    /* Enable GPIO clock */
    RCC_AHB1PeriphClockCmd(CAN_GPIO_CLK, ENABLE);

    /* Connect CAN pins to AF9 */
    GPIO_PinAFConfig(CAN_GPIO_PORT, CAN_RX_SOURCE, CAN_AF_PORT);
    GPIO_PinAFConfig(CAN_GPIO_PORT, CAN_TX_SOURCE, CAN_AF_PORT);

    /* Configure CAN RX and TX pins */
    GPIO_InitStructure.GPIO_Pin = CAN_RX_PIN | CAN_TX_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_Init(CAN_GPIO_PORT, &GPIO_InitStructure);

    /* CAN configuration ********************************************************/
    /* Enable CAN clock */
    RCC_APB1PeriphClockCmd(CAN_CLK, ENABLE);

    /* CAN register init */
    CAN_DeInit(CANx);

    /* CAN cell init */
    /* �T��ɶ�Ĳ�o�q��Ҧ� */
    CAN_InitStructure.CAN_TTCM = DISABLE;
    /* �n��N CAN_MCR �Ȧs���� INRQ��i��m1�H��M0��A�@���w�鰻����128��11��s�����ʦ�(1)�A�N�h�X���u���A */
    CAN_InitStructure.CAN_ABOM = DISABLE;
    /* �ίv�Ҧ��q�L�M�� CAN_MCR �Ȧs���� SLEEP ��A�ѳn���� */
    CAN_InitStructure.CAN_AWUM = DISABLE;
    /* CAN �ʥ]�۰ʭ��o���즨�\���� */
    CAN_InitStructure.CAN_NART = DISABLE;
    /* �b�������X�� FIFO ���Q��w�A���� FIFO �ɫʥ]���QŪ�X�A�U�@�Ӧ��쪺�ʥ]�|�л\�즳���ʥ] */
    CAN_InitStructure.CAN_RFLM = DISABLE;
    /* �o�e FIFO �u���ťѫʥ]���ХܲŨM�w */
    CAN_InitStructure.CAN_TXFP = DISABLE;
    /* CAN �w��u�@�b���`�Ҧ� */
    CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;
    /* ���s�P�B���D�e��1�Ӯɶ���� */
    CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;

    /* CAN Baudrate = 1 MBps (CAN clocked at 30 MHz) */
    /* �ɶ��q1��6�Ӯɶ���� */
    CAN_InitStructure.CAN_BS1 = CAN_BS1_6tq;
    /* �ɶ��q2��8�Ӯɶ���� */
    CAN_InitStructure.CAN_BS2 = CAN_BS2_8tq;
    /* PCLK / [(CAN_SJW_1tq + CAN_BS1_6tq + BS2_BS2_8tq) * (CAN_Prescaler)] = (30Mhz / (1 + 6 + 8) * 2) = 1Mbps �]�w�F�@�Ӯɶ���쪺����2 */
    CAN_InitStructure.CAN_Prescaler = 2;
    CAN_Init(CANx, &CAN_InitStructure);

    /* CAN filter init */
    /* ���w�F�ݪ�l�ƪ��L�o��0 */
    CAN_FilterInitStructure.CAN_FilterNumber = 0;
    /* ���w�F�L�o���N�Q��l�ƨ쪺�Ҧ����Хܲū̽���Ҧ� */
    CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
    /* ���X�F�L�o����e1��32��L�o�� */
    CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
    /* �Ψӳ]�w�L�o���Хܲ� (32���e�ɬ��䰪�q��A16���e�ɬ��Ĥ@��) */
    CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000;
    /* �Ψӳ]�w�L�o���Хܲ� (32���e�ɬ���C�q��A16���e�ɬ��ĤG��) */
    CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;
    /* �Ψӳ]�w�L�o���̽��ХܲũΪ̹L�o���Хܲ� (32���e�ɬ��䰪�q��A16���e�ɬ��Ĥ@��) */
    CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
    /* �Ψӳ]�w�L�o���̽��ХܲũΪ̹L�o���Хܲ� (32���e�ɬ���C�q��A16���e�ɬ��ĤG��) */
    CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
    /* �]�w�F���V�L�o���� FIFO0 */
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment = 0;
    /* �P��L�o�� */
    CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
    CAN_FilterInit(&CAN_FilterInitStructure);

    /* Transmit Structure preparation */
    /* Arbition Filed �ΨӧP�_�u���v�A�d��0x000~0x7FFF */
    TxMessage.StdId = 0x321;
    /* Arbition Filed ���צ�11 bits (Standard Identifier) �M 29 bits (Extended Identifier) ��� */
    TxMessage.ExtId = 0x01;
    /* RTR �����ݶǿ�n�D�A RTR = Dominant(0) ���ƭn�ǥX�A RTR = Recessive(1)�A���ƭn���� */
    TxMessage.RTR = CAN_RTR_DATA;
    /* IDE���Хܲũ��i�A Standard Identifier �� Dominant(0) �A Extended Identifier �� Recessive(1) */
    TxMessage.IDE = CAN_ID_STD;
    /* DLC ����ƪ��׽X�A�O���F Data Field ���j�p */
    TxMessage.DLC = 1;

    /* Enable FIFO 0 message pending Interrupt */
    CAN_ITConfig(CANx, CAN_IT_FMP0, ENABLE);
}

/**
  * @brief  Configures the NVIC for CAN.
  * @param  None
  * @retval None
  */
static void NVIC_Config(void)
{
    NVIC_InitTypeDef  NVIC_InitStructure;

    NVIC_InitStructure.NVIC_IRQChannel = CAN1_RX0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

/**
  * @brief  Initializes the Rx Message.
  * @param  RxMessage: pointer to the message to initialize
  * @retval None
  */
void Init_RxMes(CanRxMsg *RxMessage)
{
    uint8_t ubCounter = 0;

    RxMessage->StdId = 0x00;
    RxMessage->ExtId = 0x00;
    RxMessage->IDE = CAN_ID_STD;
    RxMessage->DLC = 0;
    RxMessage->FMI = 0;
    for (ubCounter = 0; ubCounter < 8; ubCounter++) {
        RxMessage->Data[ubCounter] = 0x00;
    }
}

/**
  * @brief  Turn ON/OFF the dedicated led
  * @param  Ledstatus: Led number from 0 to 3.
  * @retval None
  */
void LED_Display(uint8_t Ledstatus)
{
    /* Turn off all leds */
    STM_EVAL_LEDOff(LED1);
    STM_EVAL_LEDOff(LED2);
    STM_EVAL_LEDOff(LED3);
    STM_EVAL_LEDOff(LED4);

    switch(Ledstatus) {
        case(1):
            STM_EVAL_LEDOn(LED1);
            break;

        case(2):
            STM_EVAL_LEDOn(LED2);
            break;

        case(3):
            STM_EVAL_LEDOn(LED3);
            break;

        case(4):
            STM_EVAL_LEDOn(LED4);
            break;
        default:
            break;
    }
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
