#ifndef _TIMER_
#define _TIMER_

#include "stm32f10x.h"

#define TIMER_CLOCK_GENERAL 36000000
#define TIMER_CLOCK_ADVANCED 72000000

void Timer_Delay_Init(TIM_TypeDef *timer);

//************************************************** uSECOND DELAY **************************************************
void Timer_Delay_us(TIM_TypeDef *timer,float usSeconds);


//************************************************** mSECOND DELAY **************************************************
void Timer_Delay_ms(TIM_TypeDef *timer,float msSeconds);

//************************************************** SECONDS DELAY **************************************************
void Timer_Delay_s(TIM_TypeDef *timer,float Seconds);

//************************************************** COUNTER MODE **************************************************

void Up_Counter(TIM_TypeDef *timer, uint16_t count);
void Down_Counter(TIM_TypeDef *timer, uint16_t count);
void CenterAligned_Counter(TIM_TypeDef *timer, uint16_t count);

//************************************************** INPUT CAPTURE MODE **************************************************

int Input_Capture_Channel_1(TIM_TypeDef *timer);
int Input_Capture_Channel_2(TIM_TypeDef *timer);
int Input_Capture_Channel_3(TIM_TypeDef *timer);
int Input_Capture_Channel_4(TIM_TypeDef *timer);



#endif
