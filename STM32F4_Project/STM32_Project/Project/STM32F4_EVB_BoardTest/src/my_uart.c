#include "my_uart.h"

char uart_buffer[100] = {0};
uint16_t uart_length 	= 0;

/* For "httpd_cgi_ssi.c" */
uint8_t in_out_flag = 0;

/* For "main.c" */
uint8_t in_out_enable = 0;

uint8_t	change_flag = 0;

/* 向 USART3 發送字串 */
void Usart3_Printf(char *string)
{
    while(*string)
		{
        USART_SendData(USART3, (unsigned short int) *string++);
 
        while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);
    }
}

void Usart3_ReadLine(void)
{
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
	{
		if(uart_length >= sizeof(uart_buffer) - 1)
		{
			memset(uart_buffer, 0, sizeof(uart_buffer));
			uart_length = 0;
		}
		
		uart_buffer[uart_length++] = (char)USART_ReceiveData(USART3);		
	}
}

void Usart3_Interrupt(void)
{
	uint32_t i;
	
	Usart3_ReadLine();
	
	if(uart_buffer[uart_length - 1] == '\n')
	{
		if((!strcmp(uart_buffer, "IN\n")) && (change_flag != 1))
		{
			in_out_flag 	= 1;
			in_out_enable = 1;
			change_flag 	= 1;
			
			LCD_Draw16BitBMP((uint16_t *)welcome);
		}		
		else if((!strcmp(uart_buffer, "OUT\n")) && (change_flag != 0))
		{				
			in_out_flag 	= 0;
			in_out_enable = 1;
			change_flag		= 0;
			
			LCD_Draw16BitBMP((uint16_t *)goodbye);			
		}
		
		/*if(!strcmp(uart_buffer, "IO\n"))
			httpd_flag ^= 1;				
		else if(!strcmp(uart_buffer, "Q\n"))
		{	
			if(httpd_flag == 1)
			{
				while(USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);
				USART_SendData(USART3, (unsigned short int)'I');
			}
			else
			{
				while(USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);
				USART_SendData(USART3, (unsigned short int)'O');
			}
		}*/
				
		for(i = 0; i < 30000000; i++);
		LCD_Init();			
		
		memset(uart_buffer, 0, sizeof(uart_buffer));
		uart_length = 0;
	}
}
 
void Usart3_Init(void)
{
		/* 宣告 USART、GPIO 結構體 */
    USART_InitTypeDef USART_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    
		/* 啟用 GPIOB、USART3 的RCC時鐘 */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);  
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
 
	  /* 設定 Pin10、Pin11 連接至 USART3 */
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3);
 
    /* 設定 Pin10 為 TX */
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 
    GPIO_Init(GPIOB, &GPIO_InitStructure); 
 
    /* 設定 Pin11 為RX */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
		
		/* USART 基本參數設定 */
    USART_InitStructure.USART_BaudRate = 9600;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; 
    USART_Init(USART3, &USART_InitStructure);
		
		/* 啟用 USART3 */
    USART_Cmd(USART3, ENABLE);
		USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
		
		/* 啟用 USART3 中斷 */    
    NVIC_EnableIRQ(USART3_IRQn);
}
