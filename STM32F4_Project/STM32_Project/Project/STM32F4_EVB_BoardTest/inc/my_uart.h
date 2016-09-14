/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MY_UART_H
#define __MY_UART_H

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

/* By Include "my_bmp.h" */	 
extern void LCD_Draw16BitBMP(const uint16_t *);
extern void LCD_Init(void);

/* By Include "my_uart.c" */	 	 
extern char uart_buffer[100];
extern uint16_t uart_length;
	 
/* By Include "photo.h" */	 
extern const unsigned short welcome[];
extern const unsigned short goodbye[];
	 
void Usart3_Init(void);
void Usart3_Interrupt(void);
void Usart3_Printf(char *);
void Usart3_ReadLine(void);

#ifdef __cplusplus
}
#endif

#endif /* __MY_UART_H */
