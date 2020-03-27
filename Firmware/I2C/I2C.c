/**********************************************************************************************************************************
@file:    I2C.c
@author:  Kunal Salvi
@version: V3.05.0
@date:    27/3/2020
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
//@param: none
//@return: none
********************************************************************************************************************************/

void I2C_Master_Init(void)
{

	if(I2C == I2C1)
	{
		RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
		GPIOB->CRL |=  (ALT_OPEN_DRAIN_OUTPUT << (4*4)) |  (ALT_OPEN_DRAIN_OUTPUT << (4*3)); //PB7 PB6
	}
	else
	{
		RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;
		GPIOB->CRH |=  (ALT_OPEN_DRAIN_OUTPUT << (4*2)) |  (ALT_OPEN_DRAIN_OUTPUT << (4*3)); //PB10 PB11
	}

	I2C -> CR2 |= (uint16_t)30; //30MHz PCLK1
	I2C -> CCR |= I2C_CCR_FS | I2C_CCR_DUTY | 0x0003;
	I2C -> TRISE = (uint16_t)10;
	I2C -> CR1 |= I2C_CR1_PE;
}
//******************************************************************************************************************************




/***************************************** Generate Start Condition *****************************************************************
//@brief: The function generates a start condition.
//@param: none
//@return: none
********************************************************************************************************************************/

void I2C_Master_Start(){
I2C->CR1 |= I2C_CR1_START;
while(!(I2C->SR1 & I2C_SR1_SB)){}
}
//*******************************************************************************************************************************



/***************************************** Write Address *****************************************************************
//@brief: The function sends device address as write command.
//@param:
//        data          device address
//@return: none
********************************************************************************************************************************/

void I2C_Master_Address_Write(uint8_t data)
{
	I2C -> DR = (uint8_t)(data << 1) | i2c_device_write;
while(!(I2C->SR1 & I2C_SR1_ADDR)){}
}




/***************************************** Read Address *****************************************************************
//@brief: The function sends device address as read command.
//@param:
//        data          device address
//@return: none
********************************************************************************************************************************/

void I2C_Master_Address_Read(uint8_t data)
{
I2C -> DR = (uint8_t)(data << 1) | i2c_device_read;
while(!(I2C->SR1 & I2C_SR1_ADDR)){}
}
//*******************************************************************************************************************************




/***************************************** Send Data *****************************************************************
//@brief: The function sends data onto the I2C bus.
//@param:
//        data          data to be sent
//@return: none
********************************************************************************************************************************/

void I2C_Master_Send_Data( uint8_t data)
{
	while(!(I2C->SR1 & I2C_SR1_TXE)){}
	I2C -> DR = (uint8_t)data;
}
//*******************************************************************************************************************************



/***************************************** Read Data *****************************************************************
//@brief: The function receives data from the I2C bus.
//@param: none
//@return: data from the device
********************************************************************************************************************************/

int I2C_Master_Rx_Data(void)
{
	uint8_t data = 0;
	data = I2C->DR;
	while(!(I2C->SR1 & I2C_SR1_RXNE)){}
return data;
}
//*******************************************************************************************************************************



/***************************************** Stops Transfer  *****************************************************************
//@brief: The function terminates all transfers.
//@param: none
//@return: none
********************************************************************************************************************************/

void I2C_Master_Stop(void)
{
	while(!(I2C->SR1 & I2C_SR1_TXE)){}
	while(!(I2C->SR1 & I2C_SR1_BTF)){}
	I2C->CR1 |= I2C_CR1_STOP;
}

