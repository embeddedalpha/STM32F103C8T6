#include "stm32f10x.h"
#include "SPI.h"
#include "board.h"

#define length 50;




int TX;
int TXptr = &TX;




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
	//a.RxDMA = ENABLE;


	SPI_Master_Config(SPI1,a);
	SPI_Master_Enable(SPI1);


	//SPI DMA TX
	DMA1_Channel3->CPAR = SPI1->DR;
	DMA1_Channel3->CMAR = TXptr;
	DMA1_Channel3-> CNDTR = length;
	DMA1_Channel3->CCR = (3 << 12) | (2 << 8) | (2 << 10)  | (1 << 4) | (1 << 7);



	GPIOA->BSRR |= GPIO_BSRR_BS4;
	GPIOA->BSRR |= GPIO_BSRR_BSR4;
	DMA1_Channel3->CCR |= 1 <<0; //enable channel 3
	GPIOA->BSRR |= GPIO_BSRR_BS4;
	DMA1_Channel3->CCR &= ~(1 <<0);

    while(1)
    {

    }
}


