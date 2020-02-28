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

//************************************************** APPEND ARRAY **************************************************

void Append_Arrays(int data_1[], int data_1_length, int data_2[], int data_2_length)
{
int i,j;
for(i = 0; i< data_1_length; i++)
{
buffer[i] = data_1[i];	
}
for(j = 0;  j < data_2_length; j++)
{
buffer[data_1_length + j] = data_2[j];	
}	
}

//************************************************** Init Buffer **************************************************

void Init_Buffer(void)
{
int i = 0;
for(i = 0; i< 100; i++)
{
buffer[i] = -1;
}
}
//


