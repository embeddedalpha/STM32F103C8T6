/*
 * I2C.c
 *
 *  Created on: 23-Apr-2021
 *      Author: Kunal
 */


#include "I2C.h"



void I2C_Init(I2C_TypeDef *I2C, uint8_t mode)
{
	if(I2C == I2C1)
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
	if(mode)
	{
		I2C -> CR2 |= (uint16_t)30;
		I2C -> CCR |= I2C_CCR_FS | I2C_CCR_DUTY ;
		I2C -> CCR |= 3;
		I2C -> TRISE = 10;
		I2C -> CR1 |= I2C_CR1_PE;
	}
	else
	{
		I2C -> CR2 |= (uint16_t)30;
		I2C -> CCR = 42;
		I2C -> TRISE = 30;
		I2C -> CR1 |= I2C_CR1_PE;
	}
}


void I2C_Master_Start(I2C_TypeDef *I2C)
{
	I2C->CR1 |= I2C_CR1_START;
	while(!(I2C->SR1 & I2C_SR1_SB)){}
}

void I2C_Master_Send_Address(I2C_TypeDef *I2C, char address,char RW)
{
	int temp;
	I2C->DR = address | RW;
	while(!(I2C->SR1 & I2C_SR1_ADDR));
	while(I2C -> SR1 & I2C_SR1_ADDR)
	{
		temp = I2C -> SR1;
		temp = I2C -> SR2;
		if(!(I2C->SR1 & I2C_SR1_ADDR))
		{
			break;
		}
	}
}

void I2C_Master_Send_Data(I2C_TypeDef *I2C, char data)
{

	while(!(I2C->SR1 & I2C_SR1_TXE));
	I2C -> DR = data;
	while(!(I2C->SR1 & I2C_SR1_TXE));
}

char I2C_Master_Receive_Data(I2C_TypeDef *I2C)
{
	char temp = 0;
	while(!(I2C->SR1 & I2C_SR1_RXNE));
	temp = I2C -> DR;
	I2C -> CR1 |= I2C_CR1_ACK;
	return temp;
}

void I2C_Master_Stop(I2C_TypeDef *I2C)
{
	while(!(I2C->SR1 & I2C_SR1_TXE));
	while(!(I2C->SR1 & I2C_SR1_BTF));
	I2C -> CR1 |= I2C_CR1_STOP;

}

void I2C_Master_Send_NACK(I2C_TypeDef *I2C)
{
	I2C -> CR1 &= ~I2C_CR1_ACK;
}

