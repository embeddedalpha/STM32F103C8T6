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

//************************************************** INPUT CAPTURE MODE **************************************************


uint16_t Timer_Input_Capture_Channel_1(TIM_TypeDef *TIM)
{
	if(TIM == TIM1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}
	if(TIM == TIM2)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	if(TIM == TIM3)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
	if(TIM == TIM4)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}

	TIM->CCMR1 |= TIM_CCMR1_CC1S_0; //INPUT : CHANNEL 1
	TIM -> CCMR1 |= (TIM_CCMR1_IC1F_0 | TIM_CCMR1_IC1F_1);
	TIM -> CCER &= ~TIM_CCER_CC1P;
	TIM -> CCMR1 &= ~TIM_CCMR1_IC1PSC;
	TIM -> CCER |= TIM_CCER_CC1E;
	TIM -> CR1 |= TIM_CR1_CEN;
	TIM->  SR = ~TIM_SR_CC2IF;
	
	while(!(TIM -> SR & TIM_SR_CC1IF)){}
	return (uint16_t)TIM->CCR1;
}


uint16_t Timer_Input_Capture_Channel_2(TIM_TypeDef *TIM)
{
	if(TIM == TIM1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	}
	if(TIM == TIM2)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	if(TIM == TIM3)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
	if(TIM == TIM4)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}

	TIM->CCMR1 |= TIM_CCMR1_CC1S_0; //INPUT : CHANNEL 1
	TIM -> CCMR1 |= (TIM_CCMR1_IC2F_0 | TIM_CCMR1_IC2F_1);
	TIM -> CCER &= ~TIM_CCER_CC2P;
	TIM -> CCMR1 &= ~TIM_CCMR1_IC2PSC;
	TIM -> CCER |= TIM_CCER_CC2E;
	TIM -> CR1 |= TIM_CR1_CEN;
	TIM ->SR = ~TIM_SR_CC2IF;
	while(!(TIM -> SR & TIM_SR_CC2IF)){}
	return (uint16_t)TIM->CCR2;
}


uint16_t Timer_Input_Capture_Channel_3(TIM_TypeDef *TIM)
{
	if(TIM == TIM1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}
	if(TIM == TIM2)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	if(TIM == TIM3)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
	if(TIM == TIM4)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}

	TIM->CCMR2 |= TIM_CCMR2_CC3S_0; //INPUT : CHANNEL 1
	TIM -> CCMR2 |= (TIM_CCMR2_IC3F_0 | TIM_CCMR2_IC3F_1);
	TIM -> CCER &= ~TIM_CCER_CC3P;
	TIM -> CCMR2 &= ~TIM_CCMR2_IC3PSC;
	TIM -> CCER |= TIM_CCER_CC3E;
	TIM -> CR1 |= TIM_CR1_CEN;
	while(!(TIM -> SR & TIM_SR_CC3IF)){}
	return (uint16_t)TIM->CCR3;
}


uint16_t Timer_Input_Capture_Channel_4(TIM_TypeDef *TIM)
{
	if(TIM == TIM1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}
	if(TIM == TIM2)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	if(TIM == TIM3)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
	if(TIM == TIM4)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}

	TIM->CCMR2 |= TIM_CCMR2_CC4S_0; //INPUT : CHANNEL 1
	TIM -> CCMR2 |= (TIM_CCMR2_IC4F_0 | TIM_CCMR2_IC4F_1);
	TIM -> CCER &= ~TIM_CCER_CC4P;
	TIM -> CCMR2 &= ~TIM_CCMR2_IC4PSC;
	TIM -> CCER |= TIM_CCER_CC4E;
	TIM -> CR1 |= TIM_CR1_CEN;
	while((TIM -> SR & TIM_SR_CC4IF)){}
	return (uint16_t)TIM->CCR4;
}

//************************************************** PWM INPUT MODE **************************************************


uint32_t Timer_Input_PWM_Capture_Channel_1(TIM_TypeDef *TIM)
{
	if(TIM == TIM1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}
	if(TIM == TIM2)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	if(TIM == TIM3)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
	if(TIM == TIM4)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}
	TIM -> CCMR1 |= TIM_CCMR1_CC1S_0; //IC1 mapped to T1
	TIM -> CCMR1 |= TIM_CCMR1_CC2S_1; //IC2 mapped to T1

	TIM -> CCMR1 |= (TIM_CCMR1_IC1F_0 | TIM_CCMR1_IC1F_1);
	TIM -> CCMR1 |= (TIM_CCMR1_IC2F_0 | TIM_CCMR1_IC2F_1);

	TIM -> CCER &= ~TIM_CCER_CC1P; //non inverted
	TIM -> CCER |= TIM_CCER_CC2P; //inverted

	TIM -> SMCR |= TIM_SMCR_TS_2 | TIM_SMCR_TS_0; //trigger select

	TIM -> SMCR |= TIM_SMCR_SMS_2;

	TIM -> CCMR1 &= ~TIM_CCMR1_IC1PSC;
	TIM -> CCMR1 &= ~TIM_CCMR1_IC2PSC;

	TIM -> CCER |= TIM_CCER_CC1E;
	TIM -> CCER |= TIM_CCER_CC2E;

	TIM -> CR1 |= TIM_CR1_CEN;

	return (TIM->CCR1 << 16 | TIM->CCR2);
}

uint32_t Timer_Input_PWM_Capture_Channel_2(TIM_TypeDef *TIM)
{
	if(TIM == TIM1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}
	if(TIM == TIM2)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	if(TIM == TIM3)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
	if(TIM == TIM4)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}
	TIM -> CCMR2 |= TIM_CCMR2_CC3S_0; //IC1 mapped to T1
	TIM -> CCMR2 |= TIM_CCMR2_CC4S_1; //IC2 mapped to T1

	TIM -> CCMR2 |= (TIM_CCMR2_IC3F_0 | TIM_CCMR2_IC3F_1);
	TIM -> CCMR2 |= (TIM_CCMR2_IC4F_0 | TIM_CCMR2_IC4F_1);

	TIM -> CCER &= ~TIM_CCER_CC3P; //non inverted
	TIM -> CCER |= TIM_CCER_CC4P; //inverted

	TIM -> SMCR |= TIM_SMCR_TS_2 | TIM_SMCR_TS_0; //trigger select

	TIM -> SMCR |= TIM_SMCR_SMS_2;

	TIM -> CCMR2 &= ~TIM_CCMR2_IC3PSC;
	TIM -> CCMR2 &= ~TIM_CCMR2_IC4PSC;

	TIM -> CCER |= TIM_CCER_CC3E;
	TIM -> CCER |= TIM_CCER_CC4E;

	TIM -> CR1 |= TIM_CR1_CEN;

	return (TIM->CCR3 << 16 | TIM->CCR4);
}


//************************************************** OUTPUT COMPARE MODE **************************************************

void Output_Compare_Channel_1(TIM_Typedef *timer, uint16_t compare_value_1, uint16_t compare_Value_2)
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
else if(timer == TIM4)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM4EN;
}
timer -> CCMR1 |= TIM_CCMR1_OC1M0;
timer -> CCER &= ~TIM_CCER_CC1P;
timer -> ARR = compare_value_1;
timer -> CCR1 = compare_value_2;
timer -> CR1 |= TIM_CR1_CEN;
}
//

void Output_Compare_Channel_2(TIM_Typedef *timer, uint16_t compare_value_1, uint16_t compare_Value_2)
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
else if(timer == TIM4)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM4EN;
}
timer -> CCMR1 |= TIM_CCMR1_OC2M0;
timer -> CCER &= ~TIM_CCER_CC2P;
timer -> ARR = compare_value_1;
timer -> CCR1 = compare_value_2;
timer -> CR1 |= TIM_CR1_CEN;
}
//

void Output_Compare_Channel_3(TIM_Typedef *timer, uint16_t compare_value_1, uint16_t compare_Value_2)
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
else if(timer == TIM4)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM4EN;
}
timer -> CCMR2 |= TIM_CCMR1_OC3M0;
timer -> CCER &= ~TIM_CCER_CC3P;
timer -> ARR = compare_value_1;
timer -> CCR1 = compare_value_2;
timer -> CR1 |= TIM_CR1_CEN;
}
//

void Output_Compare_Channel_4(TIM_Typedef *timer, uint16_t compare_value_1, uint16_t compare_Value_2)
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
else if(timer == TIM4)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM4EN;
}
timer -> CCMR2 |= TIM_CCMR1_OC3M0;
timer -> CCER &= ~TIM_CCER_CC3P;
timer -> ARR = compare_value_1;
timer -> CCR1 = compare_value_2;
timer -> CR1 |= TIM_CR1_CEN;
}
//

//************************************************** PWM MODE *****************************************************

void PWM_Channel_1_Init(TIM_Typedef *timer, uint16_t frequency)
{ 
if(timer == TIM1)
{
RCC ->APB2ENR |= RCC_APB2ENR_TIM1EN;
timer->PSC = ((TIMER_CLOCK_ADVANCED) / ((frequency)*(100)))-1; 
}
else if(timer == TIM2)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
else if(timer == TIM3)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM3EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
else if(timer == TIM4)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM4EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
 
 timer->ARR = 100; 
 timer->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2|TIM_CCMR1_OC1PE; 
 timer->BDTR |= TIM_BDTR_MOE; 
 timer->CCER |= TIM_CCER_CC1E; 
 timer->CR1 |= TIM_CR1_ARPE;  
 timer->EGR |= TIM_EGR_UG; 
 timer->CR1 |= TIM_CR1_CEN;
}
//

void PWM_Channel_1_Update(TIM_Typedef *timer, uint16_t duty_cycle)
{ 
 timer->CCR1 = duty_cycle;
}
//

void PWM_Channel_2_Init(TIM_Typedef *timer, uint16_t frequency)
{ 
if(timer == TIM1)
{
RCC ->APB2ENR |= RCC_APB2ENR_TIM1EN;
timer->PSC = ((TIMER_CLOCK_ADVANCED) / ((frequency)*(100)))-1; 
}
else if(timer == TIM2)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
else if(timer == TIM3)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM3EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
else if(timer == TIM4)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM4EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
 
 timer->ARR = 100; 
 timer->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2|TIM_CCMR1_OC2PE; 
 timer->BDTR |= TIM_BDTR_MOE; 
 timer->CCER |= TIM_CCER_CC2E; 
 timer->CR1 |= TIM_CR1_ARPE;  
 timer->EGR |= TIM_EGR_UG; 
 timer->CR1 |= TIM_CR1_CEN;
}
//

void PWM_Channel_2_Update(TIM_Typedef *timer, uint16_t duty_cycle)
{ 
 timer->CCR1 = duty_cycle;
}
//

void PWM_Channel_3_Init(TIM_Typedef *timer, uint16_t frequency)
{ 
if(timer == TIM1)
{
RCC ->APB2ENR |= RCC_APB2ENR_TIM1EN;
timer->PSC = ((TIMER_CLOCK_ADVANCED) / ((frequency)*(100)))-1; 
}
else if(timer == TIM2)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
else if(timer == TIM3)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM3EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
else if(timer == TIM4)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM4EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
 
 timer->ARR = 100; 
 timer->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2|TIM_CCMR2_OC3PE; 
 timer->BDTR |= TIM_BDTR_MOE; 
 timer->CCER |= TIM_CCER_CC3E; 
 timer->CR1 |= TIM_CR1_ARPE;  
 timer->EGR |= TIM_EGR_UG; 
 timer->CR1 |= TIM_CR1_CEN;
}
//

void PWM_Channel_3_Update(TIM_Typedef *timer, uint16_t duty_cycle)
{ 
 timer->CCR1 = duty_cycle;
}
//

void PWM_Channel_4_Init(TIM_Typedef *timer, uint16_t frequency)
{ 
if(timer == TIM1)
{
RCC ->APB2ENR |= RCC_APB2ENR_TIM1EN;
timer->PSC = ((TIMER_CLOCK_ADVANCED) / ((frequency)*(100)))-1; 
}
else if(timer == TIM2)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
else if(timer == TIM3)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM3EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
else if(timer == TIM4)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM4EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
 
 timer->ARR = 100; 
 timer->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2|TIM_CCMR2_OC4PE; 
 timer->BDTR |= TIM_BDTR_MOE; 
 timer->CCER |= TIM_CCER_CC4E; 
 timer->CR1 |= TIM_CR1_ARPE;  
 timer->EGR |= TIM_EGR_UG; 
 timer->CR1 |= TIM_CR1_CEN;
}
//

void PWM_Channel_4_Update(TIM_Typedef *timer, uint16_t duty_cycle)
{ 
 timer->CCR1 = duty_cycle;
}
//

//************************************************** ONE PULSE MODE *****************************************************

void One_Pulse_Mode_Channel_1(TIM_Typedef *timer, uint16_t t_delay)
{  
if(timer == TIM1)
{
RCC ->APB2ENR |= RCC_APB2ENR_TIM1EN;
timer->PSC = ((TIMER_CLOCK_ADVANCED) / ((frequency)*(100)))-1; 
}
else if(timer == TIM2)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
else if(timer == TIM3)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM3EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
else if(timer == TIM4)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM4EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
timer -> CCMR1 | TIM_CCMR1_CC1S_1;
timer -> CCER |= TIM_CCER_CC1P;
timer -> SMCR |= TIM_SMCR_TS_2 | TIM_SMCR_TS_0;
timer -> SMCR |= TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1;
timer -> CCR1 = t_delay;
timer -> ARR = 100;
timer -> CR1 |= TIM_CR1_CEN;
}
//

void One_Pulse_Mode_Channel_2(TIM_Typedef *timer, uint16_t t_delay)
{  
if(timer == TIM1)
{
RCC ->APB2ENR |= RCC_APB2ENR_TIM1EN;
timer->PSC = ((TIMER_CLOCK_ADVANCED) / ((frequency)*(100)))-1; 
}
else if(timer == TIM2)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
else if(timer == TIM3)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM3EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
else if(timer == TIM4)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM4EN;
timer->PSC = ((TIMER_CLOCK_GENERAL) / ((frequency)*(100)))-1; 
}
timer -> CCMR1 | TIM_CCMR1_CC2S_1;
timer -> CCER |= TIM_CCER_CC2P;
timer -> SMCR |= TIM_SMCR_TS_2 | TIM_SMCR_TS_1;
timer -> SMCR |= TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1;
timer -> CCR1 = t_delay;
timer -> ARR = 100;
timer -> CR1 |= TIM_CR1_CEN;
}
//




void PWM_Complementary_Ch_1_Init(uint16_t freq)
{

	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_TIM1EN;
	GPIOA->CRH |= GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8_1 | GPIO_CRH_MODE8_0;
	GPIOB->CRH |= GPIO_CRH_CNF13_1 | GPIO_CRH_MODE13_1 | GPIO_CRH_MODE13_0;
	TIM1->PSC = 71;
	TIM1->ARR = 100;
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1PE;
	TIM1->BDTR |= (uint16_t)120;
	TIM1->BDTR |= TIM_BDTR_MOE;
	TIM1 -> BDTR |= TIM_BDTR_OSSR | TIM_BDTR_OSSI ;
	TIM1->CCER |= TIM_CCER_CC1E | TIM_CCER_CC1NE | TIM_CCER_CC1NP;
	TIM1->CR1 |= TIM_CR1_ARPE;
    TIM1->EGR |= TIM_EGR_UG;
	TIM1->CR1 |= TIM_CR1_CEN;

}

void PWM_Comp_Ch_1_Update(uint16_t duty_cycle)
{
	TIM1 -> CCR1 = duty_cycle;
}
