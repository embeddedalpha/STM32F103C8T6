/*
 * SPI.c
 *
 *  Created on: Feb 27, 2021
 *      Author: Kunal
 */


#include "SPI.h"


void SPI_Master_Init(SPI_Config SPI)
{
	if(SPI.SPI == SPI1)
	{
		RCC ->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_SPI1EN;
		GPIO_Pin_Setup(GPIOA, 4, GEN_PUSH_PULL_OUTPUT); //CSS
		GPIO_Pin_Setup(GPIOA, 5, ALT_PUSH_PULL_OUTPUT); //CLK
		GPIO_Pin_Setup(GPIOA, 6, FLOATING_INPUT);       //MISO
		GPIO_Pin_Setup(GPIOA, 7, ALT_PUSH_PULL_OUTPUT); //MOSI


	}

	if(SPI.SPI == SPI2)
	{
		RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN;
		RCC -> APB1ENR |= RCC_APB1ENR_SPI2EN;
		GPIO_Pin_Setup(GPIOB, 12, GEN_PUSH_PULL_OUTPUT); //CSS
		GPIO_Pin_Setup(GPIOB, 13, ALT_PUSH_PULL_OUTPUT); //CLK
		GPIO_Pin_Setup(GPIOB, 14, FLOATING_INPUT);       //MISO
		GPIO_Pin_Setup(GPIOB, 15, ALT_PUSH_PULL_OUTPUT); //MOSI
	}


	SPI.SPI->CR1 |= (
					SPI.crc << 13 |
					SPI.frame_format << 11 |
					SPI.lsb_or_msb << 7 |
					SPI.clock_speed << 3 |
					SPI.clock_polarity << 1 |
					SPI.clock_phase
					);
	SPI.SPI->CR2 |= (
					SPI.txDMA << 1 |
					SPI.rxDMA
					);
	if(SPI.interrupts)
	{
		SPI.SPI -> CR2 |= (SPI.err_int << 5 |
						   SPI.tx_int << 7 |
						   SPI.rxDMA << 6) ;
	}

	if(SPI.mode)
	{
		SPI.SPI -> CR1 |= SPI_CR1_BIDIMODE | (SPI.onlyTXorRX << 14);

	}
	else
	{
		SPI.SPI -> CR1 &= ~SPI_CR1_BIDIMODE;
	}

	SPI.SPI -> CR1 |= SPI_CR1_MSTR | SPI_CR1_SPE;
}



void SPI_Master_TX(SPI_Config SPI, uint16_t data)
{
	SPI.SPI->DR = data;
	while(!(SPI.SPI -> SR & SPI_SR_TXE));
}



uint16_t SPI_Master_RX(SPI_Config SPI)
{
	while(!(SPI.SPI -> SR & SPI_SR_RXNE));
	return SPI.SPI -> DR;
}

////////////////////////////////////////////////////////////////////////////////////////

void SPI_Slave_Init(SPI_Config SPI)
{
	if(SPI.SPI == SPI1)
		{
			RCC ->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_SPI1EN;
			GPIO_Pin_Setup(GPIOA, 4, FLOATING_INPUT); //CSS
			GPIO_Pin_Setup(GPIOA, 5, FLOATING_INPUT); //CLK
			GPIO_Pin_Setup(GPIOA, 6, ALT_PUSH_PULL_OUTPUT);       //MISO
			GPIO_Pin_Setup(GPIOA, 7, FLOATING_INPUT); //MOSI


		}

	if(SPI.SPI == SPI2)
		{
			RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
			RCC -> APB1ENR |= RCC_APB1ENR_SPI2EN;
			GPIO_Pin_Setup(GPIOB, 12, FLOATING_INPUT); //CSS
			GPIO_Pin_Setup(GPIOB, 13, FLOATING_INPUT); //CLK
			GPIO_Pin_Setup(GPIOB, 14, ALT_PUSH_PULL_OUTPUT);       //MISO
			GPIO_Pin_Setup(GPIOB, 15, FLOATING_INPUT); //MOSI
		}

	SPI.SPI -> CR1 |= ( SPI.frame_format << 11 |
					    SPI.lsb_or_msb << 7|
					   SPI.clock_polarity << 1 |
					   SPI.clock_polarity );

	SPI.SPI->CR2 |= (
						SPI.txDMA << 1 |
						SPI.rxDMA
						);
		if(SPI.interrupts)
		{
			SPI.SPI -> CR2 |= (SPI.err_int << 5 |
							   SPI.tx_int << 7 |
							   SPI.rxDMA << 6) ;
		}

		if(SPI.mode)
		{
			SPI.SPI -> CR1 |= SPI_CR1_BIDIMODE | (SPI.onlyTXorRX << 14);

		}
		else
		{
			SPI.SPI -> CR1 &= ~SPI_CR1_BIDIMODE;
		}

		SPI.SPI -> CR1 &= ~SPI_CR1_MSTR;

		SPI.SPI -> CR1 |=  SPI_CR1_SPE;

}


void SPI_Slave_TX(SPI_Config SPI, uint16_t data)
{
	SPI.SPI->DR = data;
	while(!(SPI.SPI -> SR & SPI_SR_TXE));
}



uint16_t SPI_Slave_RX(SPI_Config SPI)
{
	while(!(SPI.SPI -> SR & SPI_SR_RXNE));
	return SPI.SPI -> DR;
}


void SPI_Disable(SPI_Config SPI)
{

while(SPI.SPI -> SR & SPI_SR_RXNE);
while(SPI.SPI -> SR & SPI_SR_TXE);
while(~(SPI.SPI -> SR & SPI_SR_BSY));
SPI.SPI -> CR1 &= ~SPI_CR1_SPE;

}


///////////////////////////////////////////////////////////////////////////////////////

// NVIC_EnableIRQ(SPI1_IRQn);



/*
void SPI1_IRQHandler(void)
{
	if(SPI1->SR & SPI_SR_TXE)
	{
		//Your code goes here
	}

	if(SPI1->SR & SPI_SR_RXNE)
	{
		//Your code goes here
	}

	if(SPI1->SR & SPI_SR_OVR)
	{
		//Your code goes here
	}

	if(SPI1->SR & SPI_SR_MODF)
	{
		//Your code goes here
	}

	if(SPI1->SR & SPI_SR_CRCERR)
	{
		//Your code goes here
	}

	if(SPI1->SR & SPI_SR_UDR)
	{
		//Your code goes here
	}

}*/
