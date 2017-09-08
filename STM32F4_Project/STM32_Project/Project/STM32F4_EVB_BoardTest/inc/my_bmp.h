/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MY_BMP_H
#define __MY_BMP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdio.h"
#include "string.h"
#include "stm324xg_eval_lcd.h"
#include "photo.h"

#define BMP_LENGTH 	320
#define BMP_WIDTH	 	240
#define BMP_HEADER  54

/* By Include "my_bmp.c" */
extern unsigned char image[BMP_LENGTH * BMP_WIDTH + BMP_HEADER];

void LCD_ShowBMP(uint32_t);
void LCD_DrawGrayPict(const uint8_t *);
void LCD_Draw16BitBMP(const uint16_t *);

#ifdef __cplusplus
}
#endif

#endif /* __MY_BMP_H */
