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
	/* 檢查系統是否發生 Window Watch Dog 重置 */
  if (RCC_GetFlagStatus(RCC_FLAG_WWDGRST) != RESET)
  { 
    /* WWDGRST 旗標有設置，輸出錯誤訊息 */
    STM_EVAL_LEDOn(LED1);
		
		LCD_Clear(Black);
		LCD_SetBackColor(Black);
		LCD_SetTextColor(White);
		
		LCD_DisplayStringLine(Line3, (uint8_t *)ERROR_MESSAGE1);		
		LCD_DisplayStringLine(Line5, (uint8_t *)ERROR_MESSAGE2);

    /* 清除重置旗標 */
    RCC_ClearFlag();
  }
  else
  {
    /* WWDGRST 旗標沒有設置*/
    STM_EVAL_LEDOff(LED1);
  }

  /* 設定 SysTick Timer 每 1ms 產生中斷  */
  if (SysTick_Config(SystemCoreClock / 1000))
  { 
    /* 建立失敗 */ 
    while (1);
  }	
	#endif /* USE_WWDG */
	
  /* 建立 Ethernet (GPIOs, clocks, MAC, DMA) */
  ETH_BSP_Config();
 
  /* 初始化 the LwIP stack */
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
			
    /* 檢查封包是否已傳送 */
    if (ETH_CheckFrameReceived())
    { 
      /* 接收乙太網路的封包 */
      LwIP_Pkt_Handle();
    }
    /* handle periodic timers for LwIP */
    LwIP_Periodic_Handle(LocalTime);
		
		/* 寫入住戶進出入 */
		if(in_out_enable == 1)
		{
			InOut_Write(in_out_flag);
		}
		
		#if USE_WWDG
		/* 需介於 36.6ms 到 49.9ms 時刷新看門狗，否則會重置系統 */
    for(i = 0; i < 0xFFFFF; i++);
		
		/* Update WWDG counter */
    WWDG_SetCounter(127);
		#endif /* USE_WWDG */
  }
	
}

void BSP_Init(void)
{
	/* LED 初始化 */
  STM_EVAL_LEDInit(LED1);
  STM_EVAL_LEDInit(LED2);
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
	
	/* Button 初始化 */
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

/* 建立 Window Watch Dog */
void WWDG_Config(void)
{
  /* 開啟 WWDG clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);

  /* WWDG clock counter = (PCLK1 (42MHz)/4096)/8 = 1281 Hz (~780 us) */
  WWDG_SetPrescaler(WWDG_Prescaler_8);

  /* 設置窗口的值為 80 */
	/* WWDG 計數值必須要低於 80 和大於 64 時刷新，否則會產生系統重置 */
  WWDG_SetWindowValue(80);

  /* 開啟 WWDG 並設置計數值為 127 */
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
