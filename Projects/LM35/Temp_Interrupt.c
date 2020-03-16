#include <stdio.h>
#include "stm32f10x.h"
#include "ADC.h"
#include "Debug.h"



float Set_Alarm_Temp_High = 85;
float Set_Alarm_Temp_Low  = 10;

void ADC_IRQnHandler(void)
{
    int temp = (int) ((float)(ADC1->DR) * 0.08058);
    
    if((temp < Set_Alarm_Temp_Low) | (temp > Set_Alarm_Temp_High))
    {
      printConsole("Raise the Alarm !!!!! \n Temp : %d", temp);  
    }
    
}

int main(void)
{
    //Initialize UART for debugging
 InitConsole();
 //Initialize ADC
 ADC_Init(ADC1 , 1, 0, 0);  
 //Calibarte ADC
 ADC_Calibarte(ADC1);
 //Setup number for conversions
 ADC_Sequence_Setup(ADC1, 0, 1); 
  //Initialize the channels
  ADC_Channel_0_Init(ADC1, 0, 1, ADC_Sampling_Time_7_00us);  
  
  NVIC_Enable(ADC_IRQn);
  
    return 0;
}
