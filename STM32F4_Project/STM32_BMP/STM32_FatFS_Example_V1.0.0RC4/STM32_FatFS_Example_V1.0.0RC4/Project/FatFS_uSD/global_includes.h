/**
  ******************************************************************************
  * @file    global_includes.h 
  * @author  MCD Application Team
  * @version V1.0.0RC4
  * @date    21-December-2012
  * @brief   general includes for all the project files
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
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GLOBAL_INCLUDES_H__
#define __GLOBAL_INCLUDES_H__

/* Includes ------------------------------------------------------------------*/
#if defined (STM32F2XX)
  #include "stm32f2xx.h"
  #include "stm322xg_eval.h"
  #include "stm322xg_eval_lcd.h"
  #include "stm322xg_eval_ioe.h"
  #include "stm322xg_eval_sdio_sd.h"

#elif defined (STM32F4XX)
  #include "stm32f4xx.h"
  #include "stm324xg_eval.h"
  #include "stm324xg_eval_lcd.h"
  #include "stm324xg_eval_ioe.h"
  #include "stm324xg_eval_sdio_sd.h"

#elif defined (STM32F10X_HD)
  #include "stm32f10x.h"
  #include "stm3210e_eval.h"
  #include "stm3210e_eval_lcd.h"
  #include "stm3210e_eval_sdio_sd.h"
#endif

#include "ff.h"
#include "lcd_log.h"
#include "bsp.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
//#define USE_USB    // Uncomment this line if the application is based on USB: 
                     //  when using USB applications the SDHS mode is not supported */

/* Exported types ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __GLOBAL_INCLUDES_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

