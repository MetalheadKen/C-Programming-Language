/**
  ******************************************************************************
  * @file    stm32f4_evb_i2c_tsc.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    26-March-2013
  * @brief   This file provides a set of functions needed to manage the TI TSC2003
  *          devices mounted on STM32F4-EVB evaluation board
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
#include "stm32f4_evb_i2c_tsc.h"

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup STM32_EVAL
  * @{
  */

/** @addtogroup STM32F4_EVB
  * @{
  */

/** @defgroup STM32F4_EVB_TSC
  * @brief  This file includes the TI TSC2003 devices.
  * @{
  */


/** @defgroup STM32F4_EVB_TSC_Private_TypesDefinitions
  * @{
  */
/**
  * @}
  */


/** @defgroup STM32F4_EVB_TSC_Private_Defines
  * @{
  */
#define TIMEOUT_MAX    0x3000 /*<! The value of the maximal timeout for I2C waiting loops */
/**
  * @}
  */


/** @defgroup STM32F4_EVB_TSC_Private_Macros
  * @{
  */
/**
  * @}
  */


/** @defgroup STM32F4_EVB_TSC_Private_Variables
  * @{
  */
TSC_STATE TSC_State;              /*<! The global structure holding the TS state */

uint32_t TSC_TimeOut = TIMEOUT_MAX; /*<! Value of Timeout when I2C communication fails */
/**
  * @}
  */


/** @defgroup STM32F4_EVB_TSC_Private_FunctionPrototypes
  * @{
  */
static void TSC_I2C_Config(void);
static void TSC_DMA_Config(TSC_DMADirection_TypeDef Direction, uint8_t* buffer);
static void TSC_EXTI_Config(void);

#define DeviceAddress 0x90	// A1=A0=0
#define I2C_WRITE	DeviceAddress
#define	I2C_READ	DeviceAddress + 1


/**
  * @}
  */


/** @defgroup STM32F4_EVB_TSC_Private_Functions
  * @{
  */

void EnableTouchPanelIRQ(void)
{
	uint8_t pWords[] = {0, 0};

	// Enable TSC2003 /PENIRQ
	HWI2CWrite(0xD0);
	HWI2CRead(pWords);
}

/**
  * @brief  Initializes and Configures the two IO_Expanders Functionalities
  *         (IOs, Touch Screen ..) and configures all STM32F4_EVB necessary
  *         hardware (GPIOs, APB clocks ..).
  * @param  None
  * @retval TSC_OK if all initializations done correctly. Other value if error.
  */
uint8_t TSC_Config(void)
{

	TSC_I2C_Config();
	TSC_ITConfig(TSC_ITSRC_TSC);
	EnableTouchPanelIRQ();

	return TSC_OK;
}

/**
  * @brief  Configures The selected interrupts on the IO Expanders.
  * @param  TSC_ITSRC_Source: the source of the interrupts. Could be one or a
  *         combination of the following parameters:
  *   @arg  TSC_ITSRC_JOYSTICK: Joystick IO intputs.
  *   @arg  TSC_ITSRC_TSC: Touch Screen interrupts.
  *   @arg  TSC_ITSRC_INMEMS: MEMS interrupt lines.
  * @retval TSC_OK: if all initializations are OK. Other value if error.
  */
uint8_t TSC_ITConfig(uint32_t TSC_ITSRC_Source)
{
	/* Configure the Interrupt line as EXTI source */
	TSC_EXTI_Config();

	return TSC_OK;
}

uint8_t HWI2CWrite(uint8_t Command)
{
	/* Enable the I2C peripheral */
	I2C_GenerateSTART(TSC_I2C, ENABLE);

	/* Test on SB Flag */
	TSC_TimeOut = TIMEOUT_MAX;
	while (I2C_GetFlagStatus(TSC_I2C,I2C_FLAG_SB) == RESET)
	{
		if (TSC_TimeOut-- == 0) return(TSC_TimeoutUserCallback());
	}

	/* Transmit the slave address and enable writing operation */
	I2C_Send7bitAddress(TSC_I2C, I2C_WRITE, I2C_Direction_Transmitter);

	/* Test on ADDR Flag */
	TSC_TimeOut = TIMEOUT_MAX;
	while (!I2C_CheckEvent(TSC_I2C, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
	{
		if (TSC_TimeOut-- == 0) return(TSC_TimeoutUserCallback());
	}

	/* Transmit the first address for r/w operations */
	I2C_SendData(TSC_I2C, Command);

	/* Test on TXE FLag (data dent) */
	TSC_TimeOut = TIMEOUT_MAX;
	while ((!I2C_GetFlagStatus(TSC_I2C,I2C_FLAG_TXE)) && (!I2C_GetFlagStatus(TSC_I2C,I2C_FLAG_BTF)))
	{
		if (TSC_TimeOut-- == 0) return(TSC_TimeoutUserCallback());
	}

	/* Send STOP Condition */
	I2C_GenerateSTOP(TSC_I2C, ENABLE);

	return (1);
}

uint8_t HWI2CRead(uint8_t *bytesBuf)
{
	uint8_t TSC_BufferRX[2] = {0x00, 0x00};

	/* Configure DMA Peripheral */
	TSC_DMA_Config(TSC_DMA_RX, (uint8_t*)TSC_BufferRX);

	/* Enable DMA NACK automatic generation */
	I2C_DMALastTransferCmd(TSC_I2C, ENABLE);

	/* Enable the I2C peripheral */
	I2C_GenerateSTART(TSC_I2C, ENABLE);

	/* Test on SB Flag */
	TSC_TimeOut = TIMEOUT_MAX;
	while (!I2C_GetFlagStatus(TSC_I2C,I2C_FLAG_SB))
	{
		if (TSC_TimeOut-- == 0) return(TSC_TimeoutUserCallback());
	}

	/* Send TSCxpander address for read */
	I2C_Send7bitAddress(TSC_I2C, I2C_READ, I2C_Direction_Receiver);

	/* Test on ADDR Flag */
	TSC_TimeOut = TIMEOUT_MAX;
	while (!I2C_CheckEvent(TSC_I2C, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
	{
		if (TSC_TimeOut-- == 0) return(TSC_TimeoutUserCallback());
	}

	/* Enable I2C DMA request */
	I2C_DMACmd(TSC_I2C,ENABLE);

	/* Enable DMA RX Channel */
	DMA_Cmd(TSC_DMA_RX_STREAM, ENABLE);

	/* Wait until DMA Transfer Complete */
	TSC_TimeOut = 2 * TIMEOUT_MAX;
	while (!DMA_GetFlagStatus(TSC_DMA_RX_STREAM,TSC_DMA_RX_TCFLAG))
	{
		if (TSC_TimeOut-- == 0) return(TSC_TimeoutUserCallback());
	}

	/* Send STOP Condition */
	I2C_GenerateSTOP(TSC_I2C, ENABLE);

	/* Disable DMA RX Channel */
	DMA_Cmd(TSC_DMA_RX_STREAM, DISABLE);

	/* Disable I2C DMA request */
	I2C_DMACmd(TSC_I2C,DISABLE);

	/* Clear DMA RX Transfer Complete Flag */
	DMA_ClearFlag(TSC_DMA_RX_STREAM,TSC_DMA_RX_TCFLAG);

	/* return a pointer to the TSC_Buffer */
	bytesBuf[0] = (uint8_t)TSC_BufferRX[0];
	bytesBuf[0] = (uint8_t)TSC_BufferRX[0];

	return(1);
}

uint16_t TSC2003Read(uint8_t source)
{
	uint8_t pCommand, pWords[] = {0, 0};

	// command byte= [C3 C2 C1 C0 0 1 0 0]
	pCommand = ((source << 4) | 0x04);
	HWI2CWrite(pCommand);
	HWI2CRead(pWords);
	// adjusted data MSB=bit#11 & LSB=bit#0
	// and save only 10 MSBs for reducing noise
	return ((uint16_t) (pWords[0] << 2) | (uint16_t) (pWords[1] >> 6));
}

/**
  * @brief  Returns Status and positions of the Touch screen.
  * @param  None
  * @retval Pointer to TS_STATE structure holding Touch Screen information.
  */
TSC_STATE* TSC_TS_GetState(void)
{
	uint16_t xDiff, yDiff , x , y;
	static uint16_t _x = 0, _y = 0;

	/* Check if the Touch detect event happened */
//	TSC_State.TouchDetected = !GPIO_ReadInputDataBit(TSC_IT_GPIO_PORT, TSC_IT_PIN);
//	if (TSC_State.TouchDetected) 
	{
		// Read X Axis ([C3 C2 C1 C0]=[1100]
		x = TSC2003Read(0xC);
		// Read Y Axis ([C3 C2 C1 C0]=[1101]
		y = TSC2003Read(0xD);
		xDiff = x > _x? (x - _x): (_x - x);
		yDiff = y > _y? (y - _y): (_y - y);
		if (xDiff + yDiff > 5)
		{
			_x = x;
			_y = y;
		}
	}
	/* Update the X position */
	TSC_State.X = _x;
	/* Update the Y position */
	TSC_State.Y = _y;
	/* Update the Z position index */
	TSC_State.Z = TSC2003Read(0xE);
	EnableTouchPanelIRQ();
	/* Return pointer to the updated structure */
	return &TSC_State;
}

/**
  * @brief  Configure the I2C Peripheral used to communicate with IO_Expanders.
  * @param  None
  * @retval None
  */
static void TSC_I2C_Config(void)
{
	I2C_InitTypeDef I2C_InitStructure;

//	if ((TSC_I2C->CR1 & I2C_CR1_PE) != I2C_CR1_PE)
	{
		/* TSC_I2C configuration */
		I2C_InitStructure.I2C_Mode					= I2C_Mode_I2C;
		I2C_InitStructure.I2C_DutyCycle				= I2C_DutyCycle_2;
		I2C_InitStructure.I2C_OwnAddress1			= 0xA0;
		I2C_InitStructure.I2C_Ack					= I2C_Ack_Enable;
		I2C_InitStructure.I2C_AcknowledgedAddress	= I2C_AcknowledgedAddress_7bit;
		I2C_InitStructure.I2C_ClockSpeed			= I2C_SPEED;
		I2C_Init(TSC_I2C, &I2C_InitStructure);
	}
}

/**
  * @brief  Configure the DMA Peripheral used to handle communication via I2C.
  * @param  None
  * @retval None
  */

static void TSC_DMA_Config(TSC_DMADirection_TypeDef Direction, uint8_t* buffer)
{
	DMA_InitTypeDef DMA_InitStructure;

	RCC_AHB1PeriphClockCmd(TSC_DMA_CLK, ENABLE);
	DMA_InitStructure.DMA_Channel				= TSC_DMA_CHANNEL;
	DMA_InitStructure.DMA_PeripheralBaseAddr	= TSC_I2C_DR;
	DMA_InitStructure.DMA_Memory0BaseAddr		= (uint32_t)buffer;
	DMA_InitStructure.DMA_PeripheralInc			= DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc				= DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize	= DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryDataSize		= DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Mode					= DMA_Mode_Normal;
	DMA_InitStructure.DMA_Priority				= DMA_Priority_Low;
	DMA_InitStructure.DMA_FIFOMode				= DMA_FIFOMode_Enable;
	DMA_InitStructure.DMA_FIFOThreshold			= DMA_FIFOThreshold_1QuarterFull;
	DMA_InitStructure.DMA_MemoryBurst			= DMA_MemoryBurst_Single;
	DMA_InitStructure.DMA_PeripheralBurst		= DMA_PeripheralBurst_Single;
	if (Direction == TSC_DMA_RX)
	{
		DMA_InitStructure.DMA_DIR				= DMA_DIR_PeripheralToMemory;
		DMA_InitStructure.DMA_BufferSize		= 2;
		DMA_DeInit(TSC_DMA_RX_STREAM);
		DMA_Init(TSC_DMA_RX_STREAM, &DMA_InitStructure);
	}
	else if (Direction == TSC_DMA_TX)
	{
		DMA_InitStructure.DMA_DIR				= DMA_DIR_MemoryToPeripheral;
		DMA_InitStructure.DMA_BufferSize		= 1;
		DMA_DeInit(TSC_DMA_TX_STREAM);
		DMA_Init(TSC_DMA_TX_STREAM, &DMA_InitStructure);
	}
}


/**
  * @brief  Configures the IO expander Interrupt line and GPIO in EXTI mode.
  * @param  None
  * @retval None
  */
static void TSC_EXTI_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;

	/* Enable GPIO clock */
	RCC_AHB1PeriphClockCmd(TSC_IT_GPIO_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	/* Configure Button pin as input floating */
	GPIO_InitStructure.GPIO_Pin		= TSC_IT_PIN;
	GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd	= GPIO_PuPd_NOPULL;
	GPIO_Init(TSC_IT_GPIO_PORT, &GPIO_InitStructure);

	/* Connect Button EXTI Line to Button GPIO Pin */
	SYSCFG_EXTILineConfig(TSC_IT_EXTI_PORT_SOURCE, TSC_IT_EXTI_PIN_SOURCE);

	/* Configure Button EXTI line */
	EXTI_InitStructure.EXTI_Line	= TSC_IT_EXTI_LINE;
	EXTI_InitStructure.EXTI_Mode	= EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	/* Enable and set Button EXTI Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = TSC_IT_EXTI_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
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
