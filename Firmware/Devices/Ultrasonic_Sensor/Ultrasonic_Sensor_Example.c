#include "stm32f10x.h"                  // Device header
#include "Ultrasonic_Sensor.h"

int main(void)
{
	
delay_timer = TIM1;
	float distance;
	Ultrasonic_Senosor_Init(TIM2,GPIOA,2,3);
	
	
	
	
	
	
	while(1){}
	
	distance = Ultrasonic_Senosor_Read_Meters();
	
}

