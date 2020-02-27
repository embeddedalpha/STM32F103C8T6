#include "WS2812B.h"



void RGB_Zero()
{
	GPIOA->BSRR |= GPIO_BSRR_BS0;
	Timer_Delay_us(0.5);
	GPIOA->BRR |= GPIO_BRR_BR0;
	//Timer_Delay_us(1.05);
	
}

void RGB_One()
{
	GPIOA->BSRR |= GPIO_BSRR_BS0;
	Timer_Delay_us(1.05);
	GPIOA->BRR |= GPIO_BRR_BR0;
	//Timer_Delay_us(0.5);
	
}


void RGB_Reset()
{
	GPIOA->BSRR |= GPIO_BSRR_BS0;
	GPIOA->BRR |= GPIO_BRR_BR0;
	Timer_Delay_us(50);
	GPIOA->BSRR |= GPIO_BSRR_BS0;
}



void WS2812B_Init()
{

	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	GPIOA->CRL |= GPIO_CRL_MODE0_1 | GPIO_CRL_MODE0_0 | GPIO_CRL_CNF0_1;

}
void WS2812B_RGB(uint8_t red, uint8_t green, uint8_t blue){

	uint8_t rgb[24];
	
	for(int g = 23; g <=16; g--)
	{
		int dummy = green >> (g-16);
		if(dummy & 1) rgb[g] = 1;
		else rgb[g] = 0;
	}
	for(int r = 15; r <=8; r--)
	{
		int dummy = red >> (r-8);
		if(dummy & 1) rgb[r] = 1;
		else rgb[r] = 0;
	}
	for(int b = 23; b <=16; b--)
	{
		int dummy = blue >> (b-16);
		if(dummy & 1) rgb[b] = 1;
		else rgb[b] = 0;
	}
	
	for(int out = 23; out <= 0; out--)
	{
	if(rgb[out] == 1) RGB_One();
		else RGB_Zero();
	}
	

}
