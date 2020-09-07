/**********************************************************************************************************************************
@file:    Analog_Microphone.c
@author:  Kunal Salvi
@version: V1.0
@date:    7/9/2020
@brief:   Analog Microphone Source File.
          This file contains the functions declared in Analog_Microphone.h file.
          By calling various functions, the user can configure
          the ADC Hardware Peripheral for Microphone application.
@attention: This file aims at providing the user an abstraction layer to the ADC peripheral
            and is tested on STM32f103C8T6. This file is free for use to any person or corporation.
            In case of failure of code/product due to third party tampering, the author will not be
            responsible. This code is published under MIT License.
**********************************************************************************************************************************/



#include "Analog_Microphone.h"


/***************************************** Setup Mode *****************************************************************
//@brief: The function sets up the necessary parameters for the hardware ADC.
//@param:
//      ADC                ADC1 or ADC2
//      channel			   0:15
//      sampling_time      ADC_Sampling_Time_1_16us = 0; //1.16 us
//                         ADC_Sampling_Time_1_66us = 1; //1.667 us
//                         ADC_Sampling_Time_2_16us = 2; //2.16 us
//                         ADC_Sampling_Time_3_41us = 3; //3.41 us
//                         ADC_Sampling_Time_4_50us = 4; //4.50 us
//                         ADC_Sampling_Time_5_67us = 5; //5.67 us
//                         ADC_Sampling_Time_7_00us = 6; //7.00 us
//                         ADC_Sampling_Time_21_us =  7; //21.0 us
//      sequence           1:16
//      data_alignment     0  ->  Right Alignment
//                         1  ->  Left Alignment
//@return: none
********************************************************************************************************************************/

void Analog_Mic_Setup(ADC_TypeDef *ADC, uint8_t channel,uint8_t sampling_time, uint8_t sequence, uint8_t data_alignment)
{
	ADC_Init(ADC,1,data_alignment,0);
	ADC_Calibrate(ADC);
	ADC_Sequence_Setup(ADC,0,channel);
	RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
	GPIOA -> CRL   |= ANALOG_INPUT << (4*0);
	ADC ->SMPR2 |=  sampling_time << (4*0);
	ADC -> SQR3 |= sequence << (5*0);

}




/***************************************** Setup Mode *****************************************************************
//@brief: The function returns the data from the ADC Data Register
//@param:
//      ADC                ADC1 or ADC2
//@return: 12 bit ADC Data
********************************************************************************************************************************/

uint16_t Analog_Mic_Data(ADC_TypeDef *ADC)
{
	return ADC->DR;
}




/***************************************** Setup Mode *****************************************************************
//@brief: The function turns ADC on and off
//@param:
//      ADC                ADC1 or ADC2
//      on_off             1 or true   ->  ON
//                         0 or false  ->  OFF
//@return: 12 bit ADC Data
********************************************************************************************************************************/

void Analog_Mic(ADC_TypeDef *ADC,bool on_off)
{
	if (on_off) {
		ADC -> CR2 |= ADC_CR2_ADON;

	}
	else {
		ADC -> CR2 &= ~ADC_CR2_ADON;
	}

}




