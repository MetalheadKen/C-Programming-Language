/**
  ******************************************************************************
  * @file    main.c
  * @author  MCD Application Team
  * @version V1.0.0RC4
  * @date    21-December-2012
  * @brief   This file provides main program functions
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
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
#include "global_includes.h"
#include <stdio.h>
#include <string.h>
#include "stm324xg_eval_lcd.h"
#include "photo.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define LENGTH 	320
#define WIDTH	 	240
#define HEADER	54

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
FATFS fs;
FIL  file;

uint32_t ret_length = 0;
char write[] = "This is a FAT FS example on STM32 using MSD interface."; 
char read[256] ;
unsigned char image[LENGTH * WIDTH + HEADER];
uint8_t color[4];
uint32_t internel_buffer = 0xC0260000;

/* Private function prototypes -----------------------------------------------*/
void SDCardConfig (void);
uint32_t SD_ReadBMP(uint32_t, const char *);
void LCD_ShowBMP(uint32_t);
void LCD_ShowMonoPict(const uint32_t *);
static void Delay(__IO uint32_t);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  __IO uint32_t i = 0, j = 0;
  
  /*!< At this stage the microcontroller clock setting is already configured, 
  this is done through SystemInit() function which is called from startup
  file (startup_stm32fxxx_xx.s) before to branch to application main.
  To reconfigure the default setting of SystemInit() function, refer to
  system_stm32fxxx.c file
  */  
  
  memset (read, 0 , sizeof(read));
  memset (image, 0 , sizeof(image));

  /* Init the hardware */
  BSP_Init();
  
  /* SD Card Configuration */
  SDCardConfig();
	
	STM324xG_LCD_Init();	
  LCD_Clear(Black);
  LCD_SetBackColor(Black);
  LCD_SetTextColor(White);
  
	/* Write TXT file
	
  if (f_open(&file, "0:/STM32_File.txt", FA_CREATE_ALWAYS | FA_WRITE) != FR_OK)
  {
    LCD_ErrLog("Cannot open 'STM32 File.txt' file\n");
  }
  else
  {
    LCD_DbgLog("'STM32 File.txt' file opened for write\n");
  }

  if (f_write(&file, write, sizeof(write), &ret_length) != FR_OK)
  {
    LCD_ErrLog("Cannot write on 'STM32 File.txt' file\n");
  }
  else
  {
    LCD_DbgLog("'Data written in file\n");
  }  
  
  f_close(&file);*/	
	
	
	
	/* Read TXT file	
	if ( f_mount( 0, &fs ) != FR_OK )
	{
		LCD_DisplayStringLine(Line0, (uint8_t *)"Can not mount SD CARD !!!");
	}		
		
	if (f_open(&file, "0:/test.txt", FA_OPEN_ALWAYS | FA_READ) != FR_OK)
	{
		LCD_DisplayStringLine(Line1, (uint8_t *)"Can not open file !!!");
	}

	if (f_read(&file, read, sizeof(read), &ret_length) != FR_OK)
	{
		LCD_DisplayStringLine(Line2, (uint8_t *)"Can not read file");
	}
	else
	{
		LCD_DisplayStringLine(Line2, (uint8_t *)read);
	}		
 
	f_close(&file);
	*/
	
	/* Read BMP file
		
	/*if ( f_mount( 0, &fs ) != FR_OK )
	{
		LCD_DisplayStringLine(Line0, (uint8_t *)"Can not mount SD CARD !!!");
	}		
		
	if (f_open(&file, "0:/photo.bmp", FA_OPEN_ALWAYS | FA_READ) != FR_OK)
	{
		LCD_DisplayStringLine(Line1, (uint8_t *)"Can not open file !!!");
	}

	for(i = 0; i < LENGTH * WIDTH; i++)
	{
		if(f_gets(color, sizeof(color), &file))
			image[i] = ASSEMBLE_RGB(color[0], color[1], color[2]);
	}
	
	
	if (f_read(&file, image, sizeof(image), &ret_length) != FR_OK)
	{
		LCD_DisplayStringLine(Line2, (uint8_t *)"Can not read file");
	}
	*/
 
	//SD_ReadBMP(internel_buffer, (const char *)"0:/photo.bmp");
	
	//f_close(&file);	
	
	if ( f_mount( 0, &fs ) != FR_OK )
	{
		LCD_DisplayStringLine(Line0, (uint8_t *)"Can not mount SD CARD !!!");
	}		
	
	if (f_open(&file, "0:/photo3.bmp", FA_OPEN_ALWAYS | FA_READ) != FR_OK)
	{
		LCD_DisplayStringLine(Line1, (uint8_t *)"Can not open file !!!");
	}
	
	if (f_read(&file, image, sizeof(image), &ret_length) != FR_OK)
	{
		LCD_DisplayStringLine(Line2, (uint8_t *)"Can not read file");
	}
	
	while (1)
  {
		/*LCD_DrawMonoPict((const uint32_t *)photo);
		Delay(100); //Delay 1 sec.
		
		LCD_DrawMonoPict((const uint32_t *)photo1);
		Delay(100);
		
		LCD_ShowMonoPict((const uint32_t *)image);
		Delay(100);*/
		
		//LCD_WriteBMP(internel_buffer);
		LCD_ShowBMP((uint32_t)image);
		Delay(100);
		
	}
	
	f_close(&file);
}

/**
  * @brief  SD Card Configuration.
  * @param  None
  * @retval None
  */
void SDCardConfig (void)
{
  SD_Error Status;

  /* SD Init */
  Status = SD_Init();

  /* Verify the SDIO SD */
  if(Status == SD_OK)
  {
    LCD_DbgLog("'SDIO SD intialized\n");

#ifndef STM32F10X_HD
  #ifndef USE_USB /* USE_USB should be defined in global_includes.h when using USB applications */
    /* Check if the SD card supports high-speed mode */
    Status = SD_HighSpeed();
    if (Status == SD_OK)
    {
      /* For SDIO High Speed mode the SDIO clock (coming from the PLL through Q divider)
         is set to 48 MHz, but this is not functional (silicon bug). As workaround we have 
         to configure the SDIO clock to 67.2 MHz and disable the bypass mode to output 
         33.6 MHz for SD card. for this configuration, the PLL_Q value should be set 
         to 5.

         For SDIO High Speed mode, the normal config opeartion consist to enable the
         bypass mode (call SDIO_Init() function w/ SDIO_ClockBypass member of SDIO_InitStruct
         set to SDIO_ClockBypass_Enable) to drive directly the SDIO_CK output signal (48 MHz).
         Due to this limitation, the bypass mode should be disabled and the clock is 
         divided according to the CLKDIV value before driving the SDIO_CK output signal
         (67.2 / 2 = 33.6 MHz).
      */ 
      /* Clear PLLQ bits */
      RCC->PLLCFGR &= ~ RCC_PLLCFGR_PLLQ;

      /* Set PLLQ bits to 5 */
      RCC->PLLCFGR |= 5 << 24;
      LCD_DbgLog("'Switch to high-speed mode\n");
    }
  #endif /* USE_USB */
#endif /* STM32F10X_HD */
  }
  else
  {
    LCD_ErrLog("SDIO SD initialization failed \n");
  }
}

/*Delay for each 10ms*/
static void Delay(__IO uint32_t nCount)
{
  __IO uint32_t index = 0; 
	
  for(index = (100000 * nCount); index != 0; index--);
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {}
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

uint32_t SD_ReadBMP(uint32_t Address, const char* BmpName)
{
  uint32_t index = 0, size = 0, i1 = 0;
  uint32_t BmpAddress;
  FIL F1;

  f_open (&F1, BmpName, FA_READ);
	f_read (&F1, image, 30, &ret_length);

	BmpAddress = (uint32_t)image;

	/* Read bitmap size */
	size = *(uint16_t *) (BmpAddress + 2);
	size |= (*(uint16_t *) (BmpAddress + 4)) << 16;  

	/* Get bitmap data address offset */
	index = *(uint16_t *) (BmpAddress + 10);
	index |= (*(uint16_t *) (BmpAddress + 12)) << 16;  
	
	f_close (&F1);
	
	f_open (&F1, BmpName, FA_READ);
	
	do
	{
		if (size < 256*2)
		{
			i1 = size;
		}
		else
		{
			i1 = 256*2;
		}
		size -= i1;
		f_read (&F1, image, i1, &ret_length);

		for (index = 0; index < i1; index++)
		{
			*(__IO uint8_t*) (Address) = *(__IO uint8_t *)BmpAddress;

			BmpAddress++;  
			Address++;
		}  

		BmpAddress = (uint32_t)image;
	}
	while (size > 0);

	f_close (&F1);

	return 1;
}

void LCD_ShowBMP(uint32_t BmpAddress)
{
  uint32_t index = 0, size = 0;
  /* Read bitmap size */
  size = *(__IO uint16_t *) (BmpAddress + 2);
  size |= (*(__IO uint16_t *) (BmpAddress + 4)) << 16;
  /* Get bitmap data address offset */
  index = *(__IO uint16_t *) (BmpAddress + 10);
  index |= (*(__IO uint16_t *) (BmpAddress + 12)) << 16;
  size = (size - index)/2;
  BmpAddress += index;
  /* Set GRAM write direction and BGR = 1 */
  /* I/D=00 (Horizontal : decrement, Vertical : decrement) */
  /* AM=1 (address is updated in vertical writing direction) */
  LCD_WriteReg(LCD_REG_3, 0x1008);
 
  LCD_WriteRAM_Prepare();
 
  for(index = 0; index < size; index++)
  {
    LCD_WriteRAM(*(__IO uint16_t *)BmpAddress);
    BmpAddress += 2;
  }
 
  /* Set GRAM write direction and BGR = 1 */
  /* I/D = 01 (Horizontal : increment, Vertical : decrement) */
  /* AM = 1 (address is updated in vertical writing direction) */
  LCD_WriteReg(LCD_REG_3, 0x1018);
}

void LCD_ShowMonoPict(const uint32_t *Pict)
{
  uint32_t index = 0, i = 0;
  LCD_SetCursor(0, (LCD_PIXEL_WIDTH - 1)); 
  LCD_WriteRAM_Prepare(); /* Prepare to write GRAM */
  for(index = 0; index < LENGTH * WIDTH; index++)
  {
    LCD_WriteRAM(Pict[index]);
  }
}
