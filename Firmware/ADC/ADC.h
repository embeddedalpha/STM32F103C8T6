/**********************************************************************************************************************************
@file:    ADC.H
@author:  Kunal Salvi
@version: V3.05.0
@date:    29/2/2020
@brief:   ADC Header File.
          This file contains the prototype of functions in ADC.c file.
          By calling various functions, the user can configure
          the ADC Hardware Peripheral.

@attention: This file aims at providing the user an abrstraction layer to the CAN peripheral
            and is tested on STM32f103C8T6. This file is free for use to any person or corporation.
            In case of failure of code/product due to third party tampering, the author will not be
            responsible. This code is published under MIT License.

*********************************************************************************************************************************
*/

#ifndef _ADC_H_
#define _ADC_H_


#include "stm32f10x.h"

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

void ADC_Init(ADC_TypeDef *ADC , int conversion_mode, int data_alignment, int DMA_Enable);

/***************************************** Calibration Mode *****************************************************************
//@brief: The function calibrates ADC
//@param:
//      ADC                ADC1 or ADC2
//@return: Returns 1 if Initialization is successful
********************************************************************************************************************************/

int ADC_Calibrate(ADC_TypeDef *ADC);

/***************************************** Channel Initialization Mode *****************************************************************
//@brief: The function calibrates ADC
//@param:
//       channel_type           0  ->  Regular mode
//                              1  ->  Injected mode
//@return: none
********************************************************************************************************************************/

void ADC_Channel_0_Init(int channel_type, int sequence);



#endif
