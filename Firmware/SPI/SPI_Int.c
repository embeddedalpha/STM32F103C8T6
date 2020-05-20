#include "stm32f10x.h"
#include "SPI.h"
#include "board.h"

    int i = 0;
	uint8_t TX[10] = {1,2,3,4,5,6,7,8,9,10};
	uint8_t RX[10];

void SPI1_IRQHandler(void)
{
	GPIOA->BSRR &= ~GPIO_BSRR_BR4;
uint16_t sr = SPI1 -> SR;
if(sr & SPI_SR_TXE) SPI1 -> DR =  TX[i];

if(sr & SPI_SR_RXNE) RX[i] = SPI1 -> DR;
GPIOA->BSRR |= GPIO_BSRR_BS4;
i++;
}

int main(void)
{


	struct SPI_Master_Parameters a;
	struct SPI_Master_IRQ_Parameters ai;

	RCC ->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_SPI1EN | RCC_APB2ENR_AFIOEN;
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
	ai.TX_Interrupt = Enable;
	ai.RX_Interrupt = Enable;
	SPI_Master_Config(SPI1,a);
	SPI_Master_IRQ_Config(SPI1,ai);
	SPI_Master_Enable(SPI1);

	NVIC_EnableIRQ(SPI1_IRQn);

    while(1){}
}
