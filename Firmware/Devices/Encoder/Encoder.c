#include "Encoder.h"



void Encoder_Init(TIM_TypeDef *timer)
{
	timer ->ARR = encoder_upper_limit;
	timer -> SMCR |= TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0 ;
	//no input filter in this example
	timer -> CCMR1 |= TIM_CCMR1_CC1S_0;
	timer -> CCMR2 |= TIM_CCMR2_CC1S_0;
	timer -> CR1 |= TIM_CR1_CEN;
}

uint16_t Enocder_Read(TIM_TypeDef *timer)
{
return timer -> CNT;
}
