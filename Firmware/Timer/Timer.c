#include "Timer.h"

void Timer_Delay_Init(TIM_TypeDef *timer)
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



void Timer_Delay_us(TIM_TypeDef *timer,float usSeconds)
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

void Timer_Delay_ms(TIM_TypeDef *timer,float msSeconds)
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

void Timer_Delay_s(TIM_TypeDef *timer,float Seconds){

	timer->SR = 0;
	timer->PSC = 65535;
	timer -> ARR = (Seconds*TIMER_CLOCK_ADVANCED)/2; 
	timer->CR1 |= TIM_CR1_URS;
	timer->CR1 |= TIM_CR1_CEN;
	while(!(timer->SR & TIM_SR_UIF)){} //WAIT TIIL UIF BIT IS SET
}

//************************************************** COUNTER MODE **************************************************

void Up_Counter(TIM_TypeDef *timer, uint16_t count)
{
timer -> SR = 0; //clear SR reg
timer -> ARR = count; // value to which the counter counts
if(timer == TIM1)
{
timer -> PSC = 71;    // Prescalar
}
else
{
timer -> PSC = 35; 
}
timer -> CR1 &= ~TIM_CR1_DIR; //Upcounting mode  
timer -> CR1 |= TIM_CR1_URS; //only upcounting generates event
timer -> CR1 |= TIM_CR1_CEN; // Enable Timer
while(!(timer ->SR & TIM_SR_UIF)){}
}
//

void Down_Counter(TIM_TypeDef *timer, uint16_t count)
{
timer -> SR = 0; //clear SR reg
timer -> ARR = count; // value to which the counter counts
if(timer == TIM1)
{
timer -> PSC = 71;    // Prescalar
}
else
{
timer -> PSC = 35; 
}
timer -> CR1 |= TIM_CR1_DIR; //Downcounting mode  
timer -> CR1 |= TIM_CR1_URS; //only upcounting generates event
timer -> CR1 |= TIM_CR1_CEN; // Enable Timer
while(!(timer ->SR & TIM_SR_UIF)){}
}
//

void CenterAligned_Counter(TIM_TypeDef *timer, uint16_t count)
{
timer -> SR = 0; //clear SR reg
timer -> ARR = count; // value to which the counter counts
if(timer == TIM1)
{
timer -> PSC = 71;    // Prescalar
}
else
{
timer -> PSC = 35; 
}
timer -> CR1 |= (TIM_CR1_CMS_1 | TIM_CR1_CMS_0); //CMS[1:0] = [1:1]
timer -> CR1 |= TIM_CR1_URS; //only upcounting generates event
timer -> CR1 |= TIM_CR1_CEN; // Enable Timer
while(!(timer ->SR & TIM_SR_UIF)){}
}
//

