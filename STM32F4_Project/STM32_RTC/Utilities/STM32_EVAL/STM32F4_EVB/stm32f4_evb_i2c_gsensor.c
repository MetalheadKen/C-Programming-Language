/**
  ******************************************************************************
  * @file    stm32f4_evb_i2c_gsensor.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    26-March-2013
  * @brief   This file provides a set of functions needed to manage the LIS3DH
  *          LIS3DSH devices mounted on STM32F4-EVB evaluation board
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

  /* File Info : ---------------------------------------------------------------

    Note:
    -----
    - This driver uses the DMA method for sending and receiving data on I2C bus
      which allow higher efficiency and reliability of the communication.

    SUPPORTED FEATURES:
      - IO Read/write : Set/Reset and Read (Polling/Interrupt)
      - Joystick: config and Read (Polling/Interrupt)
      - Touch Screen Features: Single point mode (Polling/Interrupt)
      - TempSensor Feature: accuracy not determined (Polling).

    UNSUPPORTED FEATURES:
      - Row ADC Feature is not supported (not implemented on STM32F4_EVB board)
  ----------------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
#include "stm32f4_evb_i2c_gsensor.h"
#include "lcd_log.h"

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
  * @brief  This file includes the LIS3DH / LIS3DSH devices.
  * @{
  */

/** @defgroup STM32F4_EVB_GSENSOR_Private_TypesDefinitions
  * @{
  */
/**
  * @}
  */

/** @defgroup STM32F4_EVB_GSENSOR_Private_Defines
  * @{
  */
#define TIMEOUT_MAX    0x3000 /*<! The value of the maximal timeout for I2C waiting loops */

/**
  * @}
  */

/** @defgroup STM32F4_EVB_GSENSOR_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup STM32F4_EVB_GSENSOR_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup STM32F4_EVB_GSENSOR_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup STM32F4_EVB_GSENSOR_Private_Functions
  * @{
  */

/********************************************************************************
* i2c_timeoutusercallback														*
********************************************************************************/
void i2c_timeoutusercallback(void)
{
	sEE_LowLevel_DeInit();
	sEE_LowLevel_Init();

	return;
}

/********************************************************************************
* i2c_single_write																*
********************************************************************************/
void i2c_single_write(uint8_t i2c_addr, uint8_t reg, uint8_t data)
{
	uint32_t I2C_TimeOut;
	
	I2C_TimeOut = TIMEOUT_MAX;
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY))
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_Send7bitAddress(I2C1, i2c_addr, I2C_Direction_Transmitter);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_SendData(I2C1, reg); // register address(SUB)
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)) /* EV8 */
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_SendData(I2C1, data); // data(DATA)
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)) /* EV8 */
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_AcknowledgeConfig(I2C1, DISABLE);
	I2C_GenerateSTOP(I2C1, ENABLE);

	return;
}

/********************************************************************************
* i2c_multiple_write															*
********************************************************************************/
void i2c_multiple_write(uint8_t i2c_addr, uint8_t reg, uint8_t *data, uint8_t length)
{
	uint32_t I2C_TimeOut;
	uint8_t i;
	
	I2C_TimeOut = TIMEOUT_MAX;
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY))
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_Send7bitAddress(I2C1, i2c_addr, I2C_Direction_Transmitter);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_SendData(I2C1, reg); // register address(SUB)
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)) /* EV8 */
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	for (i = 0; i < length; i++)
	{
		I2C_SendData(I2C1, *(data + i)); // data(DATA)
		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)) /* EV8 */
		{
			if (I2C_TimeOut-- == 0)
			{
				i2c_timeoutusercallback();
				return;
			}
		}
	}
	I2C_AcknowledgeConfig(I2C1, DISABLE);
	I2C_GenerateSTOP(I2C1, ENABLE);

	return;
}

/********************************************************************************
* i2c_single_read																*
********************************************************************************/
void i2c_single_read(uint8_t i2c_addr, uint8_t reg, uint8_t *data)
{
	uint32_t I2C_TimeOut;
	
	I2C_TimeOut = TIMEOUT_MAX;
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY))
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_Send7bitAddress(I2C1, i2c_addr, I2C_Direction_Transmitter);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_SendData(I2C1, reg);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)) /* EV8 */
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_Send7bitAddress(I2C1, i2c_addr | I2C_READ_BIT, I2C_Direction_Receiver);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_AcknowledgeConfig(I2C1, DISABLE);
	I2C_GenerateSTOP(I2C1, ENABLE);
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_RXNE) == RESET)
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	*data = I2C_ReceiveData(I2C1);

	return;
}

/********************************************************************************
* i2c_multiple_read																*
********************************************************************************/
void i2c_multiple_read(uint8_t i2c_addr, uint8_t reg, uint8_t *data, uint8_t length)
{
	uint32_t I2C_TimeOut;
	uint8_t NumByteToRead, i;
	
	I2C_TimeOut = TIMEOUT_MAX;
	NumByteToRead = length;
	i = 0;
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY))
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_Send7bitAddress(I2C1, i2c_addr, I2C_Direction_Transmitter);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_SendData(I2C1, reg); //Register Address
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)) /* EV8 */
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_Send7bitAddress(I2C1, i2c_addr | I2C_READ_BIT, I2C_Direction_Receiver);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
	{
		if (I2C_TimeOut-- == 0)
		{
			i2c_timeoutusercallback();
			return;
		}
	}
	I2C_AcknowledgeConfig(I2C1, ENABLE);
	while (NumByteToRead)
	{
		if (NumByteToRead == 1) // n-1 byte
		{
			I2C_AcknowledgeConfig(I2C1, DISABLE);
			I2C_GenerateSTOP(I2C1, ENABLE);
			while (I2C_GetFlagStatus(I2C1, I2C_FLAG_RXNE) == RESET)
			{
				if (I2C_TimeOut-- == 0)
				{
					i2c_timeoutusercallback();
					return;
				}
			}
			*(data + i) = I2C_ReceiveData(I2C1);
			NumByteToRead--;
			i++;
		}
		if (I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED))
		{
			*(data + i) = I2C_ReceiveData(I2C1);
			NumByteToRead--;
			i++;
		}
	}

	return;
}

/**
  * @brief  Initializes peripherals used by the I2C GSensor driver.
  * @param  None
  * @retval None
  */
void GSensor_Init(void)
{
	uint8_t RegValue[7];

	// skip i2c initialize
	i2c_single_read(GSENSOR_I2C_ADDR, Who_Am_I, RegValue);
	switch (RegValue[0])
	{
		case LIS331DLH_ID:
			LCD_DisplayStringLine(LCD_LINE_17, (uint8_t *)" GSensor : LIS331DLH");
			break;
		case LIS3DH_ID:
			LCD_DisplayStringLine(LCD_LINE_17, (uint8_t *)" GSensor : LIS3DH");
			break;
		case LIS331DL_ID:
			LCD_DisplayStringLine(LCD_LINE_17, (uint8_t *)" GSensor : LIS331DL");
			break;
		case LIS3DSH_ID:
			LCD_DisplayStringLine(LCD_LINE_17, (uint8_t *)" GSensor : LIS3DSH");
			break;
		default:
			LCD_DisplayStringLine(LCD_LINE_17, (uint8_t *)" GSensor : detect error");
			break;
	}
	  //    i2c_single_write(GSENSOR_I2C_ADR_WRITE, LIS3DH_CTRL_REG1, 0x67);
     //   i2c_single_write(GSENSOR_I2C_ADR_WRITE, LIS3DH_CTRL_REG2, 0x00);
     //   i2c_single_write(GSENSOR_I2C_ADR_WRITE, LIS3DH_CTRL_REG3, 0x00);
     //   i2c_single_write(GSENSOR_I2C_ADR_WRITE, LIS3DH_CTRL_REG4, 0x10);
     //   i2c_single_write(GSENSOR_I2C_ADR_WRITE, LIS3DH_CTRL_REG5, 0x00);
     //   i2c_single_write(GSENSOR_I2C_ADR_WRITE, LIS3DH_CTRL_REG6, 0x00);
}

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
