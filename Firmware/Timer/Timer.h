#ifndef _TIMER_H_
#define _TIMER_H_

#include "stm32f10x.h"



void Timer_Delay_us(float usSeconds);
void Timer_Delay_ms(float msSeconds);
void Timer_Delay_s(float Seconds);

int Input_Trigger_channel_1(TIM_TypeDef *TIMER);
int Input_Trigger_channel_2(TIM_TypeDef *TIMER);
int Input_Trigger_channel_3(TIM_TypeDef *TIMER);
int Input_Trigger_channel_4(TIM_TypeDef *TIMER);


//input capture
//output capture
//pwm 
//one pulse
//delay











#endif
