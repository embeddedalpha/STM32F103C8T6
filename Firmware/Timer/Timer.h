#ifndef _TIMER_H_
#define _TIMER_H_



#include "stm32f10x.h"

#define TIMER_CLOCK_GENERAL 36000000
#define TIMER_CLOCK_ADVANCED 72000000


void Timer_Delay_Init(TIM_TypeDef *timer);
void Timer_Delay_us(TIM_TypeDef *timer,float usSeconds);
void Timer_Delay_ms(TIM_TypeDef *timer,float msSeconds);
void Timer_Delay_s(TIM_TypeDef *timer,float Seconds);


void Up_Counter(TIM_TypeDef *timer, uint16_t count);
void Down_Counter(TIM_TypeDef *timer, uint16_t count);
void CenterAligned_Counter(TIM_TypeDef *timer, uint16_t count);

uint16_t Timer_Input_Capture_Channel_1(TIM_TypeDef *TIM);
uint16_t Timer_Input_Capture_Channel_2(TIM_TypeDef *TIM);
uint16_t Timer_Input_Capture_Channel_3(TIM_TypeDef *TIM);
uint16_t Timer_Input_Capture_Channel_4(TIM_TypeDef *TIM);

uint32_t Timer_Input_PWM_Capture_Channel_1(TIM_TypeDef *TIM);
uint32_t Timer_Input_PWM_Capture_Channel_2(TIM_TypeDef *TIM);

void Output_Compare_Channel_1(TIM_Typedef *timer, uint16_t compare_value_1, uint16_t compare_Value_2);
void Output_Compare_Channel_2(TIM_Typedef *timer, uint16_t compare_value_1, uint16_t compare_Value_2);
void Output_Compare_Channel_3(TIM_Typedef *timer, uint16_t compare_value_1, uint16_t compare_Value_2);
void Output_Compare_Channel_4(TIM_Typedef *timer, uint16_t compare_value_1, uint16_t compare_Value_2);

void PWM_Channel_1_Init(TIM_Typedef *timer, uint16_t frequency);
void PWM_Channel_2_Init(TIM_Typedef *timer, uint16_t frequency);
void PWM_Channel_3_Init(TIM_Typedef *timer, uint16_t frequency);
void PWM_Channel_4_Init(TIM_Typedef *timer, uint16_t frequency);

void PWM_Channel_1_Update(TIM_Typedef *timer, uint16_t duty_cycle);
void PWM_Channel_2_Update(TIM_Typedef *timer, uint16_t duty_cycle);
void PWM_Channel_3_Update(TIM_Typedef *timer, uint16_t duty_cycle);
void PWM_Channel_4_Update(TIM_Typedef *timer, uint16_t duty_cycle);

void One_Pulse_Mode_Channel_1(TIM_Typedef *timer, uint16_t t_delay);
void One_Pulse_Mode_Channel_2(TIM_Typedef *timer, uint16_t t_delay);










#endif
