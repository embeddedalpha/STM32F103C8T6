/*
*********************************************************************************************************************************
@file:    SPI.c
@author:  Kunal Salvi
@version: V3.05.0
@date:    29/2/2020
@brief:   SPI Driver File.
		  This file contains the functions declared in SPI.h file.
		  By calling various "Init" functions, the user can configure
		  the SPI Hardware Peripheral in any of the permitted modes.
@attention: This file aims at providing the user an abstraction layer to the SPI peripheral
			and is tested on STM32f103C8T6. This file is free for use to any person or corporation.
			In case of failure of code/product due to third party tampering, the author will not be
			responsible. This code is published under MIT License.
*********************************************************************************************************************************
*/
#include "SPI.h"


/******************************************     Master Configuration     ******************************************/


void SPI_Config(SPI_TypeDef *SPI,uint8_t baudrate,
											 uint8_t CPHA,uint8_t CPOL,uint8_t data_format, uint8_t LSBorMSB)
{
	if(SPI == SPI1)
	{
		RCC ->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_SPI1EN | RCC_APB2ENR_AFIOEN;
		GPIO_Setup(GPIOA,7,ALTERNATE_PUSH_PULL_OUTPUT); //MOSI
		GPIO_Setup(GPIOA,5,ALTERNATE_PUSH_PULL_OUTPUT); //CLK
		GPIO_Setup(GPIOA,6,FLOATING_INPUT); //MOSI
		//GPIO_Setup(GPIOA,4,GENERAL_PUSH_PULL_OUTPUT);//NSS
		
		SPI ->CR1 |= ((baudrate << 3) | (CPHA << 0) | (CPOL << 1) | (data_format << 11) | (LSBorMSB << 7));
		
	}
	else if(SPI == SPI2)
	{
		RCC ->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN;
		RCC ->APB1ENR |= RCC_APB1ENR_SPI2EN;
		GPIO_Setup(GPIOB,15,ALTERNATE_PUSH_PULL_OUTPUT); //MOSI
		GPIO_Setup(GPIOB,13,ALTERNATE_PUSH_PULL_OUTPUT); //CLK
		GPIO_Setup(GPIOB,14,FLOATING_INPUT); //MOSI
		//GPIO_Setup(GPIOB,12,GENERAL_PUSH_PULL_OUTPUT);//NSS		
		
		SPI ->CR1 |= ((baudrate << 3) | (CPHA << 0) | (CPOL << 1) | (data_format << 11) | (LSBorMSB << 7));
	}
	
}
//

void SPI_Simplex_Config(SPI_TypeDef *SPI, uint8_t TXorRX)
{
	SPI ->CR1 |= SPI_CR1_BIDIMODE;
	if(TXorRX)
	{
	SPI ->CR1 |= SPI_CR1_BIDIOE;
	}
	else
	{
	SPI ->CR1 &= ~SPI_CR1_BIDIOE;
	}
}
//

void SPI_CRC_Enable(SPI_TypeDef *SPI, uint16_t CRC_Polynomial)
{
SPI->CR1 |= SPI_CR1_CRCEN;
SPI->CRCPR = CRC_Polynomial;
}
//

void SPI_DMA_Enable(SPI_TypeDef *SPI, uint8_t TXorRX)
{
	if(TXorRX)
	{
	SPI ->CR2 |= SPI_CR2_TXDMAEN;
	}
		else
     {
		 SPI->CR2 |= SPI_CR2_RXDMAEN;
		 }
}
//

void SPI_Enable(SPI_TypeDef *SPI)
{

	SPI->CR1 |= SPI_CR1_SPE;
}
//

void SPI_Master_Enable(SPI_TypeDef *SPI)
{
SPI ->CR1 |= SPI_CR1_MSTR;
}
//

void SPI_Slave_Enable(SPI_TypeDef *SPI)
{
SPI ->CR1 &= ~SPI_CR1_MSTR;
}
//

void SPI_TX(SPI_TypeDef *SPI,uint8_t data)
{

	SPI -> DR = data;
	while(!(SPI -> SR & SPI_SR_TXE));
}
//

int SPI_RX(SPI_TypeDef *SPI)
{
	while((SPI -> SR & SPI_SR_RXNE));
	return SPI->DR;
}
//


uint8_t SPI_TXRX(SPI_TypeDef *SPI,uint8_t data)
{
	SPI -> DR = data;
	while(!(SPI -> SR & SPI_SR_TXE));
	while((SPI -> SR & SPI_SR_RXNE));
	return (uint8_t)(SPI->DR);
}
//

void SPI_NSS_Pin_Setup(GPIO_TypeDef *PORT, uint8_t pin)
{
	NSS_Pin = pin;

	if(NSS_Pin < 8)
	{
		GPIO_Setup(PORT,NSS_Pin,GENERAL_PUSH_PULL_OUTPUT);
	}
	else
	{
		PORT->CRH |= (uint16_t)(ALTERNATE_PUSH_PULL_OUTPUT << NSS_Pin);
	}
}
//

void SPI_NSS_LOW(GPIO_TypeDef *PORT)
{
	PORT ->BSRR |= (uint16_t)(16 + NSS_Pin);
}
//

void SPI_NSS_HIGH(GPIO_TypeDef *PORT)
{
	PORT ->BSRR |= NSS_Pin;
}
//
