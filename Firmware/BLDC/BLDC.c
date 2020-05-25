#include "BLDC.h"





void BLDC_Timer_Init(void)
{
    RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_TIM1EN;
    GPIOA -> CRH |= (ALT_PUSH_PULL_OUTPUT << (4*(8-8))) | (ALT_PUSH_PULL_OUTPUT << (4*(9-8))) | (ALT_PUSH_PULL_OUTPUT << (4*(10-8)));
    GPIOB -> CRH |= (ALT_PUSH_PULL_OUTPUT << (4*(13-8))) | (ALT_PUSH_PULL_OUTPUT << (4*(14-8))) | (ALT_PUSH_PULL_OUTPUT << (4*(15-8)));
    TIM1->PSC = 23;
    TIM1->ARR = 99;
    TIM1 -> CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1PE ; //PWM1
    TIM1 -> CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2 | TIM_CCMR2_OC1PE ; //PWM2
    TIM1 -> CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2 | TIM_CCMR3_OC3PE ; //PWM3
    TIM1 -> CCER  &= ~(TIM_CCER_CC1P | TIM_CCER_CC1P | TIM_CCER_CC1P);
    TIM1 -> CCER |= TIM_CCER_CC1NP | TIM_CCER_CC1NP | TIM_CCER_CC1NP;
    TIM1 -> CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E;
    TIM1 -> BDTR |= TIM_BDTR_MOE;
    TIM1 -> BDTR |= TIM_BDTR_OSSR;
    TIM1 -> CR1 |= TIM_CR1_ARPE ;
    TIM1 -> EGR |= TIM_EGR_UG;
    TIM1 -> CR1 |= TIM_CR1_CEN;
}

///////////////////////////////////////////////////////////////////////////////////////
void PWM1_Active(void)
{
    TIM1 -> CCER |= TIM_CCER_CC1E;

}
void PWM1N_Active(void)
{
	TIM1 -> CCER |= TIM_CCER_CC1NE;
}

void PWM1_Inactive(void)
{
    TIM1 -> CCER &= ~TIM_CCER_CC1E;

}
void PWM1N_Inactive(void)
{
	TIM1 -> CCER &= ~TIM_CCER_CC1NE;
}

///////////////////////////////////////////////////////////////////////////////////////
void PWM2_Active(void)
{
    TIM1 -> CCER |= TIM_CCER_CC2E;

}
void PWM2N_Active(void)
{
	TIM1 -> CCER |= TIM_CCER_CC2NE;
}

void PWM2_Inactive(void)
{
    TIM1 -> CCER &= ~TIM_CCER_CC2E;

}
void PWM2N_Inactive(void)
{
	TIM1 -> CCER &= ~TIM_CCER_CC2NE;
}
///////////////////////////////////////////////////////////////////////////////////////
void PWM3_Active(void)
{
    TIM1 -> CCER |= TIM_CCER_CC3E;

}

void PWM3N_Active(void)
{
	TIM1 -> CCER |= TIM_CCER_CC3NE;
}

void PWM3_Inactive(void)
{
    TIM1 -> CCER &= ~TIM_CCER_CC3E;

}
void PWM3N_Inactive(void)
{
	TIM1 -> CCER &= ~TIM_CCER_CC3NE;
}
///////////////////////////////////////////////////////////////////////////////////////
void PWM1_Update(uint8_t update)
{
	TIM1 -> CCR1 = update;
}

void PWM2_Update(uint8_t update)
{
	TIM1 -> CCR1 = update;
}

void PWM3_Update(uint8_t update)
{
	TIM1 -> CCR1 = update;
}


///////////////////////////////////////////////////////////////////////////////////////


