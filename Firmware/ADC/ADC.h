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
#include "Board.h"

const float ADC_Sampling_Time_1_16us = 0; //1.16 us
const float ADC_Sampling_Time_1_66us = 1; //1.667 us
const float ADC_Sampling_Time_2_16us = 2; //2.16 us
const float ADC_Sampling_Time_3_41us = 3; //3.41 us
const float ADC_Sampling_Time_4_50us = 4; //4.50 us
const float ADC_Sampling_Time_5_67us = 5; //5.67 us
const float ADC_Sampling_Time_7_00us = 6; //7.00 us
const float ADC_Sampling_Time_21_us =  7; //21.0 us

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
//       sequence               1 : 10 Regular Channels
//                              1 : 4  Injected Channels
//       sampling_time          ADC_Sampling_Time_1_16us = 0; //1.16 us
//                              ADC_Sampling_Time_1_66us = 1; //1.667 us
//                              ADC_Sampling_Time_2_16us = 2; //2.16 us
//                              ADC_Sampling_Time_3_41us = 3; //3.41 us
//                              ADC_Sampling_Time_4_50us = 4; //4.50 us
//                              ADC_Sampling_Time_5_67us = 5; //5.67 us
//                              ADC_Sampling_Time_7_00us = 6; //7.00 us
//                              ADC_Sampling_Time_21_us =  7; //21.0 us
//@return: none
********************************************************************************************************************************/

void ADC_Channel_0_Init(ADC_TypeDef *ADC,int channel_type, int sequence, int sampling_time);
void ADC_Channel_1_Init(ADC_TypeDef *ADC,int channel_type, int sequence, int sampling_time);
void ADC_Channel_2_Init(ADC_TypeDef *ADC,int channel_type, int sequence, int sampling_time);
void ADC_Channel_3_Init(ADC_TypeDef *ADC,int channel_type, int sequence, int sampling_time);

/***************************************** Channel Initialization Mode *****************************************************************
//@brief: The function calibrates ADC
//@param:
//       ADC                    ADC1 or ADC2
//       sequence               1 : 10 Regular Channels
//       sampling_time          ADC_Sampling_Time_1_16us = 0; //1.16 us
//                              ADC_Sampling_Time_1_66us = 1; //1.667 us
//                              ADC_Sampling_Time_2_16us = 2; //2.16 us
//                              ADC_Sampling_Time_3_41us = 3; //3.41 us
//                              ADC_Sampling_Time_4_50us = 4; //4.50 us
//                              ADC_Sampling_Time_5_67us = 5; //5.67 us
//                              ADC_Sampling_Time_7_00us = 6; //7.00 us
//                              ADC_Sampling_Time_21_us =  7; //21.0 us
//@return: none
********************************************************************************************************************************/

void ADC_Channel_4_Init(ADC_TypeDef *ADC,int sequence, int sampling_time);
void ADC_Channel_5_Init(ADC_TypeDef *ADC,int sequence, int sampling_time);
void ADC_Channel_6_Init(ADC_TypeDef *ADC,int sequence, int sampling_time);
void ADC_Channel_7_Init(ADC_TypeDef *ADC,int sequence, int sampling_time);
void ADC_Channel_8_Init(ADC_TypeDef *ADC,int sequence, int sampling_time);


/***************************************** Channel Initialization Mode *****************************************************************
//@brief: The function calibrates ADC
//@param:
//       channel_type           0  ->  Regular mode
//                              1  ->  Injected mode
//       no_of_conversions      1 : 16 [ For Regular Channels ]
//                              1 : 4  [ For Injected Channels ]
//@return: none
********************************************************************************************************************************/

void ADC_Sequence_Setup(ADC_TypeDef *ADC,int channel_type, int no_of_conversions);
#endif
