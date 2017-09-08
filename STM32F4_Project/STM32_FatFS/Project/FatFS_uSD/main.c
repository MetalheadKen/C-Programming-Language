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

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
FATFS fs;
FIL  file;

uint32_t ret_length = 0;
char write[] = "This is a FAT FS example on STM32 using MSD interface.";
char read[256] ;
/* Private function prototypes -----------------------------------------------*/
void SDCardConfig (void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
    __IO uint32_t i = 0;

    /*!< At this stage the microcontroller clock setting is already configured,
    this is done through SystemInit() function which is called from startup
    file (startup_stm32fxxx_xx.s) before to branch to application main.
    To reconfigure the default setting of SystemInit() function, refer to
    system_stm32fxxx.c file
    */

    memset (read, 0, sizeof(read));

    /* Init the hardware */
    BSP_Init();

    /* SD Card Configuration */
    SDCardConfig();

    //LCD_Init();
    STM324xG_LCD_Init();

    /* Clear the LCD */
    LCD_Clear(Black);

    /* Set the LCD Back Color */
    LCD_SetBackColor(Grey);

    /* Set the LCD Text Color */
    LCD_SetTextColor(Blue);

    /*
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

    f_close(&file);
    */

#if 1
    if ( f_mount( 0, &fs ) != FR_OK ) {
        LCD_DisplayStringLine(Line0, (uint8_t *)"Can not mount SD CARD !!!");
    }

    if (f_open(&file, "0:/test.txt", FA_OPEN_ALWAYS | FA_READ) != FR_OK) {
        LCD_DisplayStringLine(Line1, (uint8_t *)"Can not open file !!!");
    }

    if (f_read(&file, read, sizeof(read), &ret_length) != FR_OK) {
        LCD_DisplayStringLine(Line2, (uint8_t *)"Can not read file");
    } else {
        LCD_DisplayStringLine(Line2, (uint8_t *)read);
    }

    f_close(&file);
#endif

    while (1) {

    }
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
    if(Status == SD_OK) {
        LCD_DbgLog("'SDIO SD intialized\n");

#ifndef STM32F10X_HD
#ifndef USE_USB /* USE_USB should be defined in global_includes.h when using USB applications */
        /* Check if the SD card supports high-speed mode */
        Status = SD_HighSpeed();
        if (Status == SD_OK) {
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
    } else {
        LCD_ErrLog("SDIO SD initialization failed \n");
    }
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
