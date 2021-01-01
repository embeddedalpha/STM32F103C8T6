/**********************************************************************************************************************************
@file:    I2C.c
@author:  Kunal Salvi
@version: V5.00.0
@date:    1/1/2021
@brief:   I2C Source File.
          This file contains the functions declared in I2C.h file.
          By calling various  functions, the user can configure
          the I2C Hardware Peripheral in any of the permitted modes.
@attention: This file aims at providing the user an abstraction layer to the I2C peripheral
            and is tested on STM32f103C8T6. This file is free for use to any person or corporation.
            In case of failure of code/product due to third party tampering, the author will not be
            responsible. This code is published under MIT License.
**********************************************************************************************************************************/

#include "I2C.h"


/***************************************** Initialization Mode *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
 * 							I2C2
 * 		  mode ->			I2C_SM_Mode
 * 		  					I2C_FM_Mode
//@return: none
********************************************************************************************************************************/

void I2C_Master_Init(I2C_TypeDef *I2C,uint8_t mode)
{
	if(I2C == I2C1)
	{
		RCC -> APB1ENR |= RCC_APB1ENR_I2C1EN;
		GPIO_Setup(GPIOB,6,ALTERNATE_OPEN_DRAIN_OUTPUT); //SCL
		GPIO_Setup(GPIOB,7,ALTERNATE_OPEN_DRAIN_OUTPUT); //SDA
	}
	else
	{
		RCC -> APB1ENR |= RCC_APB1ENR_I2C2EN;
		GPIO_Setup(GPIOB,10,ALTERNATE_OPEN_DRAIN_OUTPUT); //SCL
		GPIO_Setup(GPIOB,11,ALTERNATE_OPEN_DRAIN_OUTPUT); //SDA
	}

	if (mode == I2C_SM_Mode)
	{
		I2C -> CR2 |= (uint16_t)30; //30MHz PCLK1
		I2C -> CCR |= I2C_CCR_FS | I2C_CCR_DUTY | 0x0003;
		I2C -> TRISE = (uint16_t)8;
		I2C -> CR1 |= I2C_CR1_PE;
	}
	else if(mode == I2C_FS_Mode)
	{
		I2C -> CR2 |= (uint16_t)30; //30MHz PCLK1
		I2C -> CCR = 12;
		I2C -> TRISE = 29;
		I2C -> CR1 |= I2C_CR1_PE;
	}

}

/***************************************** Master Start *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
// 							I2C2
//@return: none
********************************************************************************************************************************/


void I2C_Master_Start(I2C_TypeDef *I2C)
{
I2C->CR1 |= I2C_CR1_START;
while(!(I2C->SR1 & I2C_SR1_SB)){}
}

/***************************************** Master Send Address *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
// 							I2C2
//        data		 ->     ~
//@return: none
********************************************************************************************************************************/


void I2C_Master_Address_Send(I2C_TypeDef *I2C, uint8_t data)
{
	I2C -> DR = data;
	while(!(I2C->SR1 & I2C_SR1_ADDR)){}
}


/***************************************** Master Send Data *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
// 							I2C2
//        data		 ->     ~
//@return: none
********************************************************************************************************************************/


void I2C_Master_Send_Data(I2C_TypeDef *I2C, uint8_t data)
{
	while(!(I2C->SR1 & I2C_SR1_TXE)){}
	I2C -> DR = (uint8_t)data;
}


/***************************************** Master Receive Data *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
// 							I2C2
//@return: RX_Data
********************************************************************************************************************************/


uint8_t I2C_Master_Rx_Data(I2C_TypeDef *I2C)
{
	uint8_t data = 0;
	data = I2C->DR;
	while(!(I2C->SR1 & I2C_SR1_RXNE)){}
return data;
}


/***************************************** Master Stop *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
// 							I2C2
//@return: none
********************************************************************************************************************************/


void I2C_Master_Stop(I2C_TypeDef *I2C)
{
	while(!(I2C->SR1 & I2C_SR1_TXE)){}
	while(!(I2C->SR1 & I2C_SR1_BTF)){}
	I2C->CR1 |= I2C_CR1_STOP;
}
