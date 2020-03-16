#include <stdio.h>
#include "stm32f10x.h"
#include "ADC.h"
#include "DMA.h"
#include "Debug.h"

int array[4];

int main(void){

 //Initialize UART for debugging
 InitConsole();
 
 //Initialize ADC
 ADC_Init(ADC1 , 1, 0, 1);  
 
 //Calibarte ADC
 ADC_Calibarte(ADC1);
 
 //Setup number for conversions
 ADC_Sequence_Setup(ADC1, 0, 4); 
 
 //Initialize the channels
  ADC_Channel_0_Init(ADC1, 0, 1, ADC_Sampling_Time_7_00us);
  ADC_Channel_1_Init(ADC1, 0, 1, ADC_Sampling_Time_7_00us);
  ADC_Channel_2_Init(ADC1, 0, 1, ADC_Sampling_Time_7_00us);
  ADC_Channel_3_Init(ADC1, 0, 1, ADC_Sampling_Time_7_00us);
 
 while(1)
 {
  ADC1_DMA(&array, 4, 16, 16, 0);
  printConsole("Vertical X   : %d", array[0]);
  printConsole("Vertical Y   : %d", array[1]);
  printConsole("Horizontal X : %d", array[2]);
  printConsole("Horizontal Y : %d", array[3]);
 } 
}
