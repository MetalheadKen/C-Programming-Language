#include "main.h"
#include "global_includes.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define SYSTEMTICK_PERIOD_MS 	10

/*--------------- LCD Messages ---------------*/
#define MESSAGE1   			"      Welcome!      "
#define MESSAGE2   			"                    "
#define MESSAGE3   			"     Community      "
#define MESSAGE4   		 	"  Management System "
#define ERROR_MESSAGE1 	"  System ERROR !!!  "
#define ERROR_MESSAGE2 	"  It has restarted  "

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t timingdelay;
__IO uint32_t LocalTime = 0; /* this variable is used to create a time reference incremented by 10ms */
static __IO uint32_t uwTimingDelay;

/* Private functions -----------------------------------------------*/
void LCD_Init(void);
void BSP_Init(void);
void WWDG_Config(void);

int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured to 
       168 MHz, this is done through SystemInit() function which is called from
       startup file (startup_stm32f4xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f4xx.c file
     */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

#ifdef SERIAL_DEBUG
  DebugComPort_Init();
#endif

  LCD_Init();
	BSP_Init();	
	Usart3_Init();
	RTC_Setting();
	SDCard_Config();
	
	#if USE_WWDG
	/* �ˬd�t�άO�_�o�� Window Watch Dog ���m */
  if (RCC_GetFlagStatus(RCC_FLAG_WWDGRST) != RESET)
  { 
    /* WWDGRST �X�Ц��]�m�A��X���~�T�� */
    STM_EVAL_LEDOn(LED1);
		
		LCD_Clear(Black);
		LCD_SetBackColor(Black);
		LCD_SetTextColor(White);
		
		LCD_DisplayStringLine(Line3, (uint8_t *)ERROR_MESSAGE1);		
		LCD_DisplayStringLine(Line5, (uint8_t *)ERROR_MESSAGE2);

    /* �M�����m�X�� */
    RCC_ClearFlag();
  }
  else
  {
    /* WWDGRST �X�ШS���]�m*/
    STM_EVAL_LEDOff(LED1);
  }

  /* �]�w SysTick Timer �C 1ms ���ͤ��_  */
  if (SysTick_Config(SystemCoreClock / 1000))
  { 
    /* �إߥ��� */ 
    while (1);
  }	
	#endif /* USE_WWDG */
	
  /* �إ� Ethernet (GPIOs, clocks, MAC, DMA) */
  ETH_BSP_Config();
 
  /* ��l�� the LwIP stack */
  LwIP_Init();
  
  /* Http webserver Init */
  httpd_init();
	
	#if USE_WWDG
	WWDG_Config();
	#endif /* USE_WWDG */
	
	LCD_Init();
		
	while (1)
  {
		uint32_t i;
			
    /* �ˬd�ʥ]�O�_�w�ǰe */
    if (ETH_CheckFrameReceived())
    { 
      /* �����A�Ӻ������ʥ] */
      LwIP_Pkt_Handle();
    }
    /* handle periodic timers for LwIP */
    LwIP_Periodic_Handle(LocalTime);
		
		/* �g�J���i�X�J */
		if(in_out_enable == 1)
		{
			InOut_Write(in_out_flag);
		}
		
		#if USE_WWDG
		/* �ݤ��� 36.6ms �� 49.9ms �ɨ�s�ݪ����A�_�h�|���m�t�� */
    for(i = 0; i < 0xFFFFF; i++);
		
		/* Update WWDG counter */
    WWDG_SetCounter(127);
		#endif /* USE_WWDG */
  }
	
}

void BSP_Init(void)
{
	/* LED ��l�� */
  STM_EVAL_LEDInit(LED1);
  STM_EVAL_LEDInit(LED2);
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
	
	/* Button ��l�� */
	STM_EVAL_PBInit(BUTTON_TAMPER, BUTTON_MODE_EXTI);
	STM_EVAL_PBInit(BUTTON_WAKEUP, BUTTON_MODE_EXTI);
}

#ifdef USE_LCD
void LCD_Init(void)
{
  STM324xG_LCD_Init();

  LCD_Clear(Black);
  LCD_SetBackColor(Black);
  LCD_SetTextColor(White);
	
  LCD_DisplayStringLine(Line0, (uint8_t*)MESSAGE1);
  LCD_DisplayStringLine(Line1, (uint8_t*)MESSAGE2);
  LCD_DisplayStringLine(Line2, (uint8_t*)MESSAGE3);
  LCD_DisplayStringLine(Line3, (uint8_t*)MESSAGE4);  
}
#endif /* USE_WWDG */

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
  * @param  nCount: number of 10ms periods to wait for.
  * @retval None
  */
void Delay(uint32_t nCount)
{
  /* Capture the current local time */
  timingdelay = LocalTime + nCount;  

  /* wait until the desired delay finish */
  while(timingdelay > LocalTime)
  {     
  }
}

void TimingDelay_Decrement(void)
{
	if (uwTimingDelay != 0x00)
	{
		uwTimingDelay--;
	}
}

/* Updates the system local time */
void Time_Update(void)
{
	LocalTime += SYSTEMTICK_PERIOD_MS;
}


#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{
	while (1)
	{
	}
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
