#include "stm32f10x.h"
#include "SPI.h"
#include "board.h"

#define length 50;


    int i = 0;
    int j = 0;
	uint8_t TX1[50];
	uint8_t TX2[50];
	uint8_t TX3[50];

	uint8_t RX1[50];
	uint8_t RX2[50];
	uint8_t RX3[50];

	uint32_t TXFinal[3] = {(uint32_t)(&TX1),(uint32_t)(&TX2),(uint32_t)(&TX3)};
	uint32_t RXFinal[3] = {(uint32_t)(&RX1),(uint32_t)(&RX2),(uint32_t)(&RX3)};

void SPI1_IRQHandler(voi)
{
	uint32_t sr = SPI1->SR ;
	if(sr & SPI_SR_TXE)
	{
		DMA1_Channel3->CCR |= 1 <<0; //enable channel 3
	}
	if(sr & SPI_SR_RXNE)
	{
		DMA1_Channel2->CCR |= 1 <<0; //enable channel 2
	}
}


void DMA1_Channel2_IRQHandler(void)
{
	uint32_t sr = DMA1->ISR;

	if(sr = (1 <<5))
	{
		if( i < 3)
		{
			DMA1_Channel2->CMAR = RXFinal[i];
			i++;
			DMA1_Channel2->CCR &= ~(1 << 0);
		}
		else {
	        DMA1_Channel2 -> CCR &= ~(1 << 0);
	        SPI1->CR1 &= ~SPI_CR1_SPE;
		}
	}

}

void DMA1_Channel3_IRQHandler(void)
{
	uint32_t sr = DMA1->ISR;
	if(sr = (1 <<5))
		{
			if( j < 3)
			{
				DMA1_Channel3->CMAR = TXFinal[j];
				j++;
				DMA1_Channel3->CCR &= ~(1 << 0);
			}
			else {
		        DMA1_Channel3 -> CCR &= ~(1 << 0);
		        DMA1_Channel2 -> CCR &= ~(1 << 0);
		        SPI1->CR1 &= ~SPI_CR1_SPE;
			}
		}
}

int main(void)
{



	struct SPI_Master_Parameters a;
	struct SPI_Master_IRQ_Parameters ai;

	RCC ->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_SPI1EN | RCC_APB2ENR_AFIOEN;
	RCC -> AHBENR |= RCC_AHBENR_DMA1EN;

	GPIOA->CRL |= ALT_PUSH_PULL_OUTPUT << (4*7);
	GPIOA->CRL |= ALT_PUSH_PULL_OUTPUT << (4*5);
	GPIOA->CRL |= ALT_PUSH_PULL_OUTPUT << (4*4);
	GPIOA->CRL |= FLOATING_INPUT << (4*6);

	a.Baudrate = 4; //18 MHz
	a.DataFormat = Bit_8;
	a.BiDirectional_Mode = Duplex;
	a.CPOL = 1;
	a.CPHA = 1;
	a.LSBorMSB = MSB;
	a.Slave_Management = Software_Managed;
	a.TxDMA = ENABLE;
	a.RxDMA = ENABLE;

	ai.TX_Interrupt = Enable;
	ai.RX_Interrupt = Enable;

	SPI_Master_Config(SPI1,a);
	SPI_Master_IRQ_Config(SPI1,ai);
	SPI_Master_Enable(SPI1);


	//SPI DMA TX
	DMA1_Channel3->CPAR = SPI1->DR;
	DMA1_Channel3->CMAR = TXFinal[1];
	DMA1_Channel3-> CNDTR = 50;
	DMA1_Channel3->CCR = (3 << 12) | (2 << 8) | (2 << 10) | (1 << 1) | (1 << 4);

	//SPI DMA RX
	DMA1_Channel2->CPAR = SPI1->DR;
	DMA1_Channel2->CMAR = RXFinal[1];
	DMA1_Channel2-> CNDTR = 50;
	DMA1_Channel2->CCR = (2 << 12) | (2 << 8) | (2 << 10) | (1 << 1) ;


	NVIC_EnableIRQ(SPI1_IRQn);
	NVIC_EnableIRQ(DMA1_Channel2_IRQn);
	NVIC_EnableIRQ(DMA1_Channel3_IRQn);






    while(1)
    {

    }
}


