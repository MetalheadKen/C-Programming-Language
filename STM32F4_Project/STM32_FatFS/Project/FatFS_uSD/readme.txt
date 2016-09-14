/**
  @page FatFS_uSD   FatFS example in single drive(uSD Card) configuration 
  
  @verbatim
  ******************** (C) COPYRIGHT 2012 STMicroelectronics *******************
  * @file    Project\FatFS_uSD\readme.txt 
  * @author  MCD Application Team
  * @version V1.0.0RC4
  * @date    21-December-2012
  * @brief   Description of the FatFS example in single drive(uSD Card) configuration.
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
   @endverbatim


@par Example Description 

This example illustrates how to use the FatFS in single drive(uSD Card) configuration. 

The principle of the example, built around FatFS R0.09, is quite simple:
 - Mount the FatFS on the uSD Card drive.
 - Open for write.
 - write a text in the file.
 - Close the file
 - Read back the file
 - Display the written text 

@note
 - The latest FatFS sources (R0.09) are used.
 - The “ffconf.h” in the project sources directory could be used to :
   - Enable/disable long file name: _USE_LFN
   - Select the Max drive number to be used : _VOLUMES
 - The “lcd_log.c” utility is used to display the operations messages on the LCD.


@par Hardware and Software environment

  -  This example is based and has been tested on the STM32F10x High Density, STM32F2xx
     and STM32F4xx devices on STM3210E-EVAL (MB672 Rev D), STM322xG-EVAL (MB786 RevB) 
     and STM324xG-EVAL (MB786 RevC) boards, and can be tailored to any other development board.    

  - STM322xG-EVAL and STM324xG-EVAL Set-up
   - Connect an uSD Card (maximum 4 GB) to the MSD connector (CN6).
         @note Make sure that jumper JP16 is set to position 1-2 (MSD).
  - STM3210E-EVAL Set-up
   - Jumper JP17 should be connected.
   - Jumper JP20 should be not connected.

@par How to use it ? 
  - Open the STM32_FATFS_USBH_SD.eww workspace.
  - In the workspace toolbar select the project config:
   - STM3210E-EVAL: to configure the project for STM32F10x High Density devices   
   - STM322xG-EVAL: to configure the project for STM32F2xx devices
   - STM324xG-EVAL: to configure the project for STM32F4xx devices
  - Rebuild all files: Project->Rebuild all
  - Load project image: Project->Debug
  - Run program: Debug->Go(F5)

    
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
