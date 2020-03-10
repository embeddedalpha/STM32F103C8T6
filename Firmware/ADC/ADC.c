/**********************************************************************************************************************************
@file:    ADC.c
@author:  Kunal Salvi
@version: V3.05.0
@date:    29/2/2020
@brief:   ADC Source File.
          This file contains the functions declared in CAN.h file.
          By calling various functions, the user can configure
          the ADC Hardware Peripheral.

@attention: This file aims at providing the user an abrstraction layer to the CAN peripheral
            and is tested on STM32f103C8T6. This file is free for use to any person or corporation.
            In case of failure of code/product due to third party tampering, the author will not be
            responsible. This code is published under MIT License.

**********************************************************************************************************************************/

#include "ADC.h"

/*
 * STM32F103C8T6 has 10 ADC channels, 0:7 from PA0 to PA7 and 8:9 from PB0 to PB1
 *
 */

/***************************************** Initialization Mode *****************************************************************
//@brief: The function sets up the ADC in Initialization mode.
//@param:
//      ADC                ADC1 or ADC2
//      conversion_mode    0  ->  Single Conversion Mode
//                         1  ->  Continuous  Conversion Mode
//      data_alignment     0  ->  Right Alignment
//                         1  ->  Left Alignment
//      DMA_Enable         0  ->  DMA disabled
//                         1  ->  DMA enabled
//@return: Returns 1 if Initialization is successful
********************************************************************************************************************************/

void ADC_Init(ADC_TypeDef *ADC , int conversion_mode, int data_alignment, int DMA_enable)
{
//Setup ADC Clock
if(ADC == ADC1){RCC -> APB2ENR |= RCC_APB2ENR_ADC1EN;}
if(ADC == ADC2){RCC -> APB2ENR |= RCC_APB2ENR_ADC2EN;}
//Setup ADC prescaler to 6
RCC ->CFGR |= RCC_CFGR_ADCPRE_DIV6; //12 MHz
//Wake up ADC from sleep mode
ADC -> CR2 |= ADC_CR2_ADON;
//Setup Conversion Mode
switch(conversion_mode)
{
case 0 :
{
    ADC -> CR2 &= ~ADC_CR2_CONT; //Single conversion mode
	break;
};

case 1 :
{
	 ADC -> CR2 |= ADC_CR2_CONT; //Continuous conversion mode
	break;
};
}
//Setup Data Alignment
switch(data_alignment)
{
case 0 :
{
    ADC -> CR2 &= ~ADC_CR2_ALIGN; //Right Alignment
	break;
};

case 1 :
{
	 ADC -> CR2 |= ADC_CR2_ALIGN; //Left Alignment
	break;
};
}
//Setup DMA
switch(DMA_enable)
{
case 0 :
{
    ADC -> CR2 &= ~ADC_CR2_DMA; //DMA disabled
	break;
};

case 1 :
{
	 ADC -> CR2 |= ADC_CR2_DMA; //DMA enabled
	break;
};
}


}
//

/***************************************** Calibration Mode *****************************************************************
//@brief: The function calibrates ADC
//@param:
//      ADC                ADC1 or ADC2
//@return: Returns 1 if Initialization is successful
********************************************************************************************************************************/

int ADC_Calibrate(ADC_TypeDef *ADC)
{
	ADC -> CR2 |= ADC_CR2_RSTCAL;
    while((ADC ->CR2 & ADC_CR2_RSTCAL));
    ADC ->CR2 |= ADC_CR2_CAL;
    while(!(ADC ->CR2 & ADC_CR2_CAL));
    return 1;
}
//

/***************************************** Channel Initialization Mode *****************************************************************
//@brief: The function calibrates ADC
//@param:
//       channel_type           0  ->  Regular mode
//                              1  ->  Injected mode
//       no_of_sequences        1 : 16
//@return: none
********************************************************************************************************************************/

void ADC_Sequence_Setup(int channel_type, int no_of_sequences)
{}

/***************************************** Channel Initialization Mode *****************************************************************
//@brief: The function calibrates ADC
//@param:
//       channel_type           0  ->  Regular mode
//                              1  ->  Injected mode
//       sequence               1 : 16
//@return: none
********************************************************************************************************************************/

void ADC_Channel_0_Init(int channel_type, int sequence, int sampling_time)
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
GPIOA -> CRL   |= ANALOG_INPUT << 1;
	switch(channel_type)
	{
	case 0 :
	{

		break;
	};

	case 1 :
	{

		break;
	};
	}
}
//
