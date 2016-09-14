/**
  ******************************************************************************
  * @file    stm32f4_evb_i2c_gsensor.h
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    26-March-2013
  * @brief   This file contains all the functions prototypes for the
  *          stm32f4_evb_i2c_gsensor.c driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
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
#ifndef __STM32F4_EVB_GSENSOR_H
#define __STM32F4_EVB_GSENSOR_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4_evb.h"

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup STM32_EVAL
  * @{
  */

/** @addtogroup STM32F4_EVB
  * @{
  */

/** @defgroup STM32F4_EVB_GSENSOR
  * @{
  */
#define I2C_READ_BIT		0x01

// G Sensor
#define GSENSOR_I2C_ADDR	0x31 //0x30
#define GSENSOR_I2C_ADR_WRITE	0x30 //0x30  //Add by chain
//#define GSENSOR_I2C_ADDR	0x3C
#define MULTIPLE_RW			0x80
#define LIS331DLH_ID		0x32
#define LIS3DH_ID			0x33
#define LIS331DL_ID			0x3B
#define LIS3DSH_ID			0x3F

// LIS3DH Reg
#define STATUS_AUX			0x07
#define OUT1_L				0x08
#define OUT1_H				0x09
#define OUT2_L				0x0A
#define OUT2_H				0x0B
#define OUT3_L				0x0C
#define OUT3_H				0x0D
#define INT_COUNTER			0x0E
#define Who_Am_I			0x0F
#define TEMP_CFG_REG		0x1F
#define LIS3DH_CTRL_REG1	0x20
#define LIS3DH_CTRL_REG2	0x21
#define LIS3DH_CTRL_REG3	0x22
#define LIS3DH_CTRL_REG4	0x23
#define LIS3DH_CTRL_REG5	0x24
#define LIS3DH_CTRL_REG6	0x25
#define REFERENCE			0x26
#define STATUS_REG			0x27
#define OUTX_L				0x28
#define OUTX_H				0x29
#define OUTY_L				0x2A
#define OUTY_H				0x2B
#define OUTZ_L				0x2C
#define OUTZ_H				0x2D
#define FIFO_CTRL_REG		0x2E
#define FIFO_SRC_REG		0x2F
#define INT1_CFG			0x30
#define INT1_SRC			0x31
#define INT1_THS			0x32
#define INT1_DURATION		0x33
#define CLICK_CFG			0x38
#define CLICK_SRC			0x39
#define CLICK_THS			0x3A
#define TIME_LIMIT			0x3B
#define TIME_LATENCY		0x3C
#define TIME_WINDOW			0x3D

// LIS3DSH Reg
#define OUT_T				0x0C
#define INFO_1				0x0D
#define INFO_2				0x0E
#define Who_Am_I			0x0F
#define OFF_X				0x10
#define OFF_Y				0x11
#define OFF_Z				0x12
#define CS_X				0x13
#define CS_Y				0x14
#define CS_Z				0x15
#define LC_L				0x16
#define LC_H				0x17
#define STAT				0x18
#define PEAK1				0x19
#define PEAK2				0x1A
#define VFC_1				0x1B
#define VFC_2				0x1C
#define VFC_3				0x1D
#define VFC_4				0x1E
#define THRS3				0x1F
#define LIS3DSH_CTRL_REG4	0x20
#define LIS3DSH_CTRL_REG1	0x21
#define LIS3DSH_CTRL_REG2	0x22
#define LIS3DSH_CTRL_REG3	0x23
#define LIS3DSH_CTRL_REG5	0x24
#define LIS3DSH_CTRL_REG6	0x25
#define STATUS_REG			0x27
#define OUTX_L				0x28
#define OUTX_H				0x29
#define OUTY_L				0x2A
#define OUTY_H				0x2B
#define OUTZ_L				0x2C
#define OUTZ_H				0x2D
#define ST1_0				0x40
#define ST1_1				0x41
#define ST1_2				0x42
#define ST1_3				0x43
#define ST1_4				0x44
#define ST1_5				0x45
#define ST1_6				0x46
#define ST1_7				0x47
#define ST1_8				0x48
#define ST1_9				0x49
#define ST1_A				0x4A
#define ST1_B				0x4B
#define ST1_C				0x4C
#define ST1_D				0x4D
#define ST1_E				0x4E
#define ST1_F				0x4F
#define TIM4_1				0x50
#define TIM3_1				0x51
#define TIM2_1_L			0x52
#define TIM2_1_H			0x53
#define TIM1_1_L			0x54
#define TIM1_1_H			0x55
#define THRS2_1				0x56
#define THRS1_1				0x57
#define MASK1_B				0x59
#define MASK1_A				0x5A
#define SETT1				0x5B
#define PR1					0x5C
#define TC1_L				0x5D
#define TC1_H				0x5E
#define OUTS1				0x5F
#define ST2_0				0x60
#define ST2_1				0x61
#define ST2_2				0x62
#define ST2_3				0x63
#define ST2_4				0x64
#define ST2_5				0x65
#define ST2_6				0x66
#define ST2_7				0x67
#define ST2_8				0x68
#define ST2_9				0x69
#define ST2_A				0x6A
#define ST2_B				0x6B
#define ST2_C				0x6C
#define ST2_D				0x6D
#define ST2_E				0x6E
#define ST2_F				0x6F
#define TIM4_2				0x70
#define TIM3_2				0x71
#define TIM2_2_L			0x72
#define TIM2_2_H			0x73
#define TIM1_2_L			0x74
#define TIM1_2_H			0x75
#define THRS2_2				0x76
#define THRS1_2				0x77
#define DES2				0x78
#define MASK2_B				0x79
#define MASK2_A				0x7A
#define SETT2				0x7B
#define PR2					0x7C
#define TC2_L				0x7D
#define TC2_H				0x7E
#define OUTS2				0x7F

/** @defgroup STM32F4_EVB_GSENSOR_Exported_Types
  * @{
  */

/* #define USE_Delay */

#ifdef USE_Delay
#include "main.h"

  #define _delay_     Delay  /* !< User can provide more timing precise _delay_ function
                                   (with 10ms time base), using SysTick for example */
#else
  #define _delay_     delay      /* !< Default _delay_ function with less precise timing */
#endif

/*------------------------------------------------------------------------------
    Hardware Configuration
------------------------------------------------------------------------------*/
/**
  * @brief  I2C port definitions
  */
#define GSENSOR_I2C						I2C1
#define GSENSOR_I2C_CLK					RCC_APB1Periph_I2C1
#define GSENSOR_I2C_SCL_PIN				GPIO_Pin_6
#define GSENSOR_I2C_SCL_GPIO_PORT		GPIOB
#define GSENSOR_I2C_SCL_GPIO_CLK		RCC_AHB1Periph_GPIOB
#define GSENSOR_I2C_SCL_SOURCE			GPIO_PinSource6
#define GSENSOR_I2C_SCL_AF				GPIO_AF_I2C1
#define GSENSOR_I2C_SDA_PIN				GPIO_Pin_9
#define GSENSOR_I2C_SDA_GPIO_PORT		GPIOB
#define GSENSOR_I2C_SDA_GPIO_CLK		RCC_AHB1Periph_GPIOB
#define GSENSOR_I2C_SDA_SOURCE			GPIO_PinSource9
#define GSENSOR_I2C_SDA_AF				GPIO_AF_I2C1
#define GSENSOR_I2C_DR					((uint32_t)0x40005410)

/* I2C clock speed configuration (in Hz)
  WARNING:
   Make sure that this define is not already declared in other files (ie.
  STM32F4_EVB.h file). It can be used in parallel by other modules. */
#ifndef I2C_SPEED
	#define I2C_SPEED					100000
#endif /* I2C_SPEED */

/**
  * @brief  GSENSOR DMA definitions
  */
#define GSENSOR_DMA_CLK					RCC_AHB1Periph_DMA1
#define GSENSOR_DMA_CHANNEL				DMA_Channel_1
#define GSENSOR_DMA_TX_STREAM			DMA1_Stream6
#define GSENSOR_DMA_RX_STREAM			DMA1_Stream0
#define GSENSOR_DMA_TX_TCFLAG			DMA_FLAG_TCIF6
#define GSENSOR_DMA_RX_TCFLAG			DMA_FLAG_TCIF0

/**
  * @brief  IO Expander Interrupt line on EXTI
  */
#define GSENSOR_IT1_PIN					GPIO_Pin_0
#define GSENSOR_IT1_GPIO_PORT			GPIOB
#define GSENSOR_IT1_GPIO_CLK			RCC_AHB1Periph_GPIOB
#define GSENSOR_IT1_EXTI_PORT_SOURCE	EXTI_PortSourceGPIOB
#define GSENSOR_IT1_EXTI_PIN_SOURCE		EXTI_PinSource0
#define GSENSOR_IT1_EXTI_LINE			EXTI_Line0
#define GSENSOR_IT1_EXTI_IRQn			EXTI0_IRQn
#define GSENSOR_IT2_PIN					GPIO_Pin_1
#define GSENSOR_IT2_GPIO_PORT			GPIOB
#define GSENSOR_IT2_GPIO_CLK			RCC_AHB1Periph_GPIOB
#define GSENSOR_IT2_EXTI_PORT_SOURCE	EXTI_PortSourceGPIOB
#define GSENSOR_IT2_EXTI_PIN_SOURCE		EXTI_PinSource1
#define GSENSOR_IT2_EXTI_LINE			EXTI_Line1
#define GSENSOR_IT2_EXTI_IRQn			EXTI1_IRQn

/** @defgroup STM32F4_EVB_GSENSOR_Exported_Functions
  * @{
  */

/**
  * @brief  Configuration and initialization functions
  */
void GSensor_Init(void);


#ifdef __cplusplus
}
#endif
#endif /* __STM32F4_EVB_GSENSOR_H */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
/******************* (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
