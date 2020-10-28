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


void SPI_Master_Config(SPI_TypeDef *SPI,struct SPI_Master_Parameters SPI_M)
{

SPI ->CR1 |= SPI_CR1_MSTR;
SPI->CR1 |= SPI_M.Baudrate << 3;
SPI->CR1 |= SPI_M.CPOL << 1;
SPI->CR1 |= SPI_M.CPHA << 0;
SPI->CR1 |= SPI_M.DataFormat << 11;
SPI->CR1 |= SPI_M.LSBorMSB << 7;
SPI->CR1 |= SPI_M.CRC_Enable << 13;
SPI->CR1 |= SPI_M.BiDirectional_Mode << 15;
SPI->CR1 |= SPI_M.TxorRX << 14;
SPI->CR2 |= SPI_M.TxDMA << 1;
SPI->CR2 |= SPI_M.RxDMA << 0;
SPI->CR1 |= SPI_M.Slave_Management << 9;
SPI->CR1 |= SPI_CR1_SSI;
SPI->CRCPR |= SPI_M.CRC_Polynomial;
SPI->CR1 |= SPI_M.CRC_Enable << 13;
}



void SPI_Master_IRQ_Config(SPI_TypeDef *SPI,struct SPI_Master_IRQ_Parameters SPIM_I)
{
SPI->CR2 |= (SPIM_I.TX_Interrupt) << 7;
SPI->CR2 |= (SPIM_I.RX_Interrupt) << 6;
SPI->CR2 |= (SPIM_I.Error_Interrupt) << 5;
}

void SPI_Master_Enable(SPI_TypeDef *SPI)
{

	SPI -> CR1 |= SPI_CR1_SPE;
}

void SPI_Master_TX(SPI_TypeDef *SPI,int data)
{

	SPI -> DR = data;
	while(!(SPI -> SR & SPI_SR_TXE));
}

int SPI_Master_RX(SPI_TypeDef *SPI)
{
	while((SPI -> SR & SPI_SR_RXNE));
	return SPI->DR;
}

void SPI_NSS_Pin_Setup(GPIO_TypeDef *PORT)
{

	if(NSS_Pin < 8)
	{
		PORT ->CRL |= ALT_PUSH_PULL_OUTPUT << NSS_Pin;
	}
	else
	{
		PORT->CRH |= ALT_PUSH_PULL_OUTPUT << NSS_Pin;
	}
}

void SPI_NSS_LOW(GPIO_TypeDef *PORT)
{
	PORT ->BSRR |= (16 + NSS_Pin);
}

void SPI_NSS_HIGH(GPIO_TypeDef *PORT)
{
	PORT ->BSRR |= NSS_Pin;
}

uint8_t SPI_Master_TXRX(SPI_TypeDef *SPI,uint8_t data)
{
	SPI -> DR = data;
	while(!(SPI -> SR & SPI_SR_TXE));
	while((SPI -> SR & SPI_SR_RXNE));
	return SPI->DR;
}

/******************************************     Slave Configuration     ******************************************/

void SPI_Slave_Config(SPI_TypeDef *SPI,struct SPI_Slave_Parameters SPI_S)
{
SPI->CR1 |= SPI_S.Baudrate << 3;
SPI->CR1 |= SPI_S.CPOL << 1;
SPI->CR1 |= SPI_S.CPHA << 0;
SPI->CR1 |= SPI_S.DataFormat << 11;
SPI->CR1 |= SPI_S.LSBorMSB << 7;
SPI->CR1 |= SPI_S.CRC_Enable << 13;
SPI->CR1 |= SPI_S.BiDirectional_Mode << 15;
SPI->CR1 |= SPI_S.TxorRX << 14;
SPI -> CR1 &= ~SPI_CR1_MSTR;
SPI->CR2 |= SPI_S.TxDMA << 1;
SPI->CR2 |= SPI_S.RxDMA << 0;
}


void SPI_Slave_IRQ_Config(SPI_TypeDef *SPI,struct SPI_Slave_IRQ_Parameters SPIS_I)
{
	SPI->CR2 |= (SPIS_I.TX_Interrupt) << 7;
	SPI->CR2 |= (SPIS_I.RX_Interrupt) << 6;
	SPI->CR2 |= (SPIS_I.Error_Interrupt) << 5;
}

void SPI_Slave_TX(SPI_TypeDef *SPI,int data)
{
	SPI -> DR = data;
}

int SPI_Slave_RX(SPI_TypeDef *SPI)
{
	return SPI->DR;
}


void SPI_Slave_Enable(SPI_TypeDef *SPI)
{
	SPI -> CR1 |= SPI_CR1_SPE;
}
