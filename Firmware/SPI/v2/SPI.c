/*
 * SPI.c
 *
 *  Created on: Feb 27, 2021
 *      Author: Kunal
 */


#include "SPI.h"


void SPI_Master_Init(SPI_Master_Config SPI)
{
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

	SPI.SPI -> CR1 |= SPI_CR1_MSTR | SPI_CR1_SPE;
}



void SPI_Master_TX(SPI_Master_Config SPI, uint16_t data)
{
	SPI.SPI->DR = data;
	while(!(SPI.SPI -> SR & SPI_SR_TXE));
}



uint16_t SPI_Master_RX(SPI_Master_Config SPI)
{
	while(!(SPI.SPI -> SR & SPI_SR_RXNE));
	return SPI.SPI -> DR;
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
