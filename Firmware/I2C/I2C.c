/*
 * I2C.c
 *
 *  Created on: 23-Apr-2021
 *  Updated on: 01-Jun-2021
 *      Author: Kunal
 */


#include "I2C.h"



int I2C_Master_Init(I2C_Config I2C)
{
	if(I2C.I2C == I2C1)
	{
		RCC -> APB1ENR |= RCC_APB1ENR_I2C1EN;
		GPIO_Pin_Setup(GPIOB, 6, ALT_OPEN_DRAIN_OUTPUT);
		GPIO_Pin_Setup(GPIOB, 7, ALT_OPEN_DRAIN_OUTPUT);
	}
	else
	{
		RCC -> APB1ENR |= RCC_APB1ENR_I2C2EN;
		GPIO_Pin_Setup(GPIOB, 10, ALT_OPEN_DRAIN_OUTPUT);
		GPIO_Pin_Setup(GPIOB, 11, ALT_OPEN_DRAIN_OUTPUT);
	}
	if (I2C.mode)
	{
		I2C.I2C -> CR2 |= (uint16_t)30;
		I2C.I2C -> CCR |= I2C_CCR_FS | I2C_CCR_DUTY ;
		I2C.I2C -> CCR |= 3;
		I2C.I2C -> TRISE = 10;
		I2C.I2C -> CR1 |= I2C_CR1_PE;
	}
	else
	{
		I2C.I2C -> CR2 |= (uint16_t)30;
		I2C.I2C -> CCR = 42;
		I2C.I2C -> TRISE = 30;
		I2C.I2C -> CR1 |= I2C_CR1_PE;
	}

	if(I2C.I2C -> SR2 & I2C_SR2_MSL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void I2C_Master_Start(I2C_Config I2C)
{
	I2C.I2C -> CR1 |= I2C_CR1_START;
	while(!(I2C.I2C -> SR1 & I2C_SR1_SB)){}
}

void I2C_Master_Send_Address(I2C_Config I2C, char address,char RW)
{
	I2C.I2C -> DR = address | RW;
	while(!(I2C.I2C->SR1 & I2C_SR1_ADDR));
	while(I2C.I2C -> SR1 & I2C_SR1_ADDR)
	{
		READ_REG(I2C.I2C -> SR1);
		READ_REG(I2C.I2C -> SR2);
		if(!(I2C.I2C -> SR1 & I2C_SR1_ADDR))
		{
			break;
		}
	}
}

void I2C_Master_Send_Data(I2C_Config I2C, char data)
{
	while(!(I2C.I2C->SR1 & I2C_SR1_TXE));
	I2C.I2C -> DR = data;
	while(!(I2C.I2C->SR1 & I2C_SR1_TXE));
}

char I2C_Master_Receive_Data(I2C_Config I2C)
{
	char temp = 0;
	while(!(I2C.I2C->SR1 & I2C_SR1_RXNE));
	temp = I2C.I2C -> DR;
	I2C.I2C -> CR1 |= I2C_CR1_ACK;
	return temp;
}

void I2C_Master_Stop(I2C_Config I2C)
{
	while(!(I2C.I2C->SR1 & I2C_SR1_TXE));
	while(!(I2C.I2C->SR1 & I2C_SR1_BTF));
	I2C.I2C -> CR1 |= I2C_CR1_STOP;
}

void I2C_Master_Send_NACK(I2C_Config I2C)
{
	I2C.I2C -> CR1 &= ~I2C_CR1_ACK;
}
