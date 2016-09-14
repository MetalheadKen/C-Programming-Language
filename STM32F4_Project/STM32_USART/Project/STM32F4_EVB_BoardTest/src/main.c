#include "stm32f4xx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

GPIO_InitTypeDef  GPIO_InitStructure;
char buffer[100] = {0};

int length = 0;

void Uart_Init(void);
void Usart3_Printf(char *);
void Usart3_ReadLine(void);
 
int main(void)
{
	int i;
	
  Uart_Init();
	
	/* GPIOG Peripheral clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

  /* Configure PG6 and PG8 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOF, &GPIO_InitStructure); 
		
  while(1)
	{
		GPIO_ToggleBits(GPIOF,GPIO_Pin_7);
		for(i = 0; i < 30000000; i++);
		
		Usart3_Printf("A\n");
	}	
}

/* USART3 ���_��� */
/* ��ƦW�٬��x��]�w�A�u�n������ USART3 ����ƿ�J�A�o�Ө�ƴN�|�Q�۰ʰ���]����@�Ӧr���N�|�Q����@���^ */
void USART3_IRQHandler(void)
{
	/*
		Usart3_ReadLine();
	
    if(!strcmp(buffer, "AAA"))
			Usart3_Printf("This is AAA.\n");
		
		if(!strcmp(buffer, "BBB"))
			Usart3_Printf("This is BBB.\n");
		
		if(!strcmp(buffer, "CCC"))
			Usart3_Printf("This is CCC.\n");
	*/
		
		if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
		{
			if(length >= sizeof(buffer) - 1)
			{
				memset(buffer, 0, sizeof(buffer));
				length = 0;
			}
			
			buffer[length++] = (char)USART_ReceiveData(USART3);
			
			if(buffer[length - 1] == '\n')
			{
				Usart3_Printf(buffer);
				memset(buffer, 0, sizeof(buffer));
				length = 0;
			}
		}
}

/* �V USART3 �o�e�r�� */
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
			length = (length >= (sizeof(buffer) - 1)) ? 0 : length;
				
			if(USART_ReceiveData(USART3))
			{
				buffer[length++] = (char)USART_ReceiveData(USART3);
			}
			
			buffer[length] = '\0';
	}
}
 
void Uart_Init(void)
{
		/* �ŧi USART�BGPIO ���c�� */
    USART_InitTypeDef USART_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    
		/* �ҥ� GPIOB�BUSART3 ��RCC���� */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);  
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
 
	  /* �]�w Pin10�BPin11 �s���� USART3 */
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3);
 
    /* �]�w Pin10 �� TX */
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 
    GPIO_Init(GPIOB, &GPIO_InitStructure); 
 
    /* �]�w Pin11 ��RX */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
		
		/* USART �򥻰ѼƳ]�w */
    USART_InitStructure.USART_BaudRate = 9600;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; 
    USART_Init(USART3, &USART_InitStructure);
		
		/* �ҥ� USART3 */
    USART_Cmd(USART3, ENABLE);
		USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
		
		/* �ҥ� USART3 ���_ */    
    NVIC_EnableIRQ(USART3_IRQn);
}
