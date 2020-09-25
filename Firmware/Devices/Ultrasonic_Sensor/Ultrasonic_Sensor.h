#ifndef _Sonar_
#define _Sonar_

#define TIMER_CLOCK_ADVANCED 72000000
#define TIMER_CLOCK_GENERAL 72000000

#include "stm32f10x.h"


//these are 
TIM_TypeDef *delay_timer;
TIM_TypeDef *timer_used;
GPIO_TypeDef *port;
static int trigger_pin_static;
static int echo_pin_static;


void Ultrasonic_Senosor_Init(TIM_TypeDef *timer, GPIO_TypeDef *gpio, int trigger_pin, int echo_pin);
float Ultrasonic_Senosor_Read_Meters(void);
float Ultrasonic_Senosor_Read_Centimeters(void);












#endif
