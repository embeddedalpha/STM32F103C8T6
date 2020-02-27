#include "Ultrasonic_Sensor.h"


void Ultrasonic_Senosor_Init(TIM_TypeDef *timer, GPIO_TypeDef *gpio, int trigger_pin, int echo_pin)
{

	//For Timer Selection
	if(timer == TIM1)
	{
		timer_used = TIM1;
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	timer->SR = 0;
	timer->PSC = 71;
	timer -> ARR = 25000; 
	timer->CR1 |= TIM_CR1_URS;
	
	}
	else if (timer == TIM2)
	{
		timer_used = TIM2;
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	timer->SR = 0;
	timer->PSC = 35;
	timer -> ARR = 25000; 
	timer->CR1 |= TIM_CR1_URS;

	}
	else if (timer == TIM3)
	{
		timer_used = TIM3;
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	timer->SR = 0;
	timer->PSC = 1;
	timer -> ARR = 25000; 
	timer->CR1 |= TIM_CR1_URS;
	timer->CR1 |= TIM_CR1_CEN;
	}
	else if(timer == TIM4)
	{
		timer_used = TIM4;
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	timer->SR = 0;
	timer->PSC = 35;
	timer -> ARR = 25000; 
	timer->CR1 |= TIM_CR1_URS;
	
	}
	else
	{
		timer_used = TIM1;
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	timer->SR = 0;
	timer->PSC = 35;
	timer -> ARR = 25000; 
	timer->CR1 |= TIM_CR1_URS;
	
	}
	
	//For IO Port Selection
	if(gpio == GPIOA)
	{
		port = gpio;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	}
	if (gpio == GPIOB)
	{
		port = gpio;
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	}
	
	//For Trigger Pin
	if(trigger_pin < 8)
	{
		trigger_pin_static =  trigger_pin;
		gpio ->CRL |= 3 << (4 * trigger_pin);
	}
	else{
		trigger_pin_static = trigger_pin;
	gpio ->CRH |= 3 << (4 * (trigger_pin-8));
	}
	
	//For Echo Pin
		if(echo_pin < 8)
	{
		gpio ->CRL |= 8 << (4 * echo_pin);
	}
	else{
	gpio ->CRH |= 8 << (4 * (echo_pin-8));
	}
	
	
}
//

void Timer_Delay_us(int usSeconds)
{
delay_timer->SR = 0;
	delay_timer->PSC = 1;
	delay_timer -> ARR = (usSeconds*TIMER_CLOCK_ADVANCED)/2; 
	delay_timer->CR1 |= TIM_CR1_URS;
	delay_timer->CR1 |= TIM_CR1_CEN;
	while(!(TIM1->SR & TIM_SR_UIF)){} //WAIT TIIL UIF BIT IS SET
}
	//

float Ultrasonic_Senosor_Read_Meters(void)
{
	int distance;
	int time;
port ->BSRR |= 1 <<  trigger_pin_static; //trigger pin high
	Timer_Delay_us(10);
port -> BSRR |= 1 << (trigger_pin_static + 16); //trigger pin low
	timer_used -> CR1 |= TIM_CR1_CEN; //start timer
while(!(port -> BSRR & echo_pin_static)	){} //wait till echo pin goes high
	time = timer_used -> CNT; //copy timer counter value
	timer_used -> CR1 &= ~TIM_CR1_CEN; //stop the timer
	distance = ((time * 0.000001 ) * 360)/2;
	
return distance;
}
	//

float Ultrasonic_Senosor_Read_Centimeters(void)
{
	int distance;
	int time;
port ->BSRR |= 1 <<  trigger_pin_static; //trigger pin high
	Timer_Delay_us(10);
port -> BSRR |= 1 << (trigger_pin_static + 16); //trigger pin low
	timer_used -> CR1 |= TIM_CR1_CEN; //start timer
while(!(port -> BSRR & echo_pin_static)	){} //wait till echo pin goes high
	time = timer_used -> CNT; //copy timer counter value
	timer_used -> CR1 &= ~TIM_CR1_CEN; //stop the timer
	distance = ((time * 0.0001 ) * 360)/2;
	
return distance;
}
//
