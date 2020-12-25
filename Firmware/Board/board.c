#include "board.h"

void Delay_Init(TIM_TypeDef *timer)
{
if(timer == TIM1)
{
RCC ->APB2ENR |= RCC_APB2ENR_TIM1EN;
}
else if(timer == TIM2)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
}
else if(timer == TIM3)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM3EN;
}
else if(timer == TIM3)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
}
}

//************************************************** uSECOND DELAY **************************************************



void Delay_us(TIM_TypeDef *timer,float usSeconds)
{

	timer->SR = 0;
	timer->PSC = 1;
	if(timer == TIM1)
	{
	timer -> ARR = (usSeconds*TIMER_CLOCK_ADVANCED)/2;
	}
	else
	{
	timer -> ARR = (usSeconds*TIMER_CLOCK_GENERAL)/2;
	}
	timer->CR1 |= TIM_CR1_URS;
	timer->CR1 |= TIM_CR1_CEN;
	while(!(timer ->SR & TIM_SR_UIF)){} //WAIT TIIL UIF BIT IS SET
}
//

//************************************************** mSECOND DELAY **************************************************

void Delay_ms(TIM_TypeDef *timer,float msSeconds)
{

	timer->SR = 0;
	if(timer == TIM1){
	timer->PSC = 72;
	timer -> ARR = (msSeconds*TIMER_CLOCK_ADVANCED)/2;
	}
	else{
	timer->PSC = 36;
	timer -> ARR = (msSeconds*TIMER_CLOCK_GENERAL)/2;
	}
	timer->CR1 |= TIM_CR1_URS;
	timer->CR1 |= TIM_CR1_CEN;
	while(!(timer->SR & TIM_SR_UIF)){} //WAIT TIIL UIF BIT IS SET
}

//************************************************** SECONDS DELAY **************************************************

void Delay_s(TIM_TypeDef *timer,float Seconds){

	timer->SR = 0;
	timer->PSC = 65535;
	timer -> ARR = (Seconds*TIMER_CLOCK_ADVANCED)/2;
	timer->CR1 |= TIM_CR1_URS;
	timer->CR1 |= TIM_CR1_CEN;
	while(!(timer->SR & TIM_SR_UIF)){} //WAIT TIIL UIF BIT IS SET
}


//************************************************** Setup GPIO MODE **************************************************





void GPIO_Setup(GPIO_TypeDef *PORT, uint8_t pin, uint8_t type)
{

	if(PORT == GPIOA)
	{
		RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
	}
	else if(PORT == GPIOB)
	{
		RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN;
	}
	else if(PORT == GPIOC)
	{
		RCC -> APB2ENR |= RCC_APB2ENR_IOPCEN;
	}

	if(type == ALTERNATE_OPEN_DRAIN_OUTPUT || type == ALTERNATE_PUSH_PULL_OUTPUT || type == ANALOG_INPUT)
	{
		RCC -> APB1ENR |= RCC_APB2ENR_AFIOEN;
	}

	if(pin < 8)
	{
		PORT ->CRL |= (type << pin*4);
	}
	else {
		PORT ->CRH |= (type << pin*4);
	}

}
