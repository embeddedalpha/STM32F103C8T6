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



/***************************************** Channel Sequence Setup *****************************************************************
//@brief: The function sets up channel sequence
//@param:
//       channel_type           0  ->  Regular mode
//                              1  ->  Injected mode
//       no_of_conversions      1 : 16 [ For Regular Channels ]
//                              1 : 4  [ For Injected Channels ]
//@return: none
********************************************************************************************************************************/

void ADC_Sequence_Setup(ADC_TypeDef *ADC,int channel_type, int no_of_conversions)
{
switch(channel_type)
{
case 0 : {
	ADC ->SQR1 |= (no_of_conversions - 1)<< 20;
	break;}

case 1 :{
	ADC ->JSQR |= (no_of_conversions - 1) << 20;
	break;}
}
}




/***************************************** Channel Initialization Mode *****************************************************************
//@brief: These functions sets up the ADC channel.
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

void ADC_Channel_0_Init(ADC_TypeDef *ADC,int channel_type, int sequence, int sampling_time)
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
GPIOA -> CRL   |= ANALOG_INPUT << (4*0);
ADC ->SMPR2 |=  sampling_time << (4*0);
	switch(channel_type)
	{
	case 0 :
	{
        ADC -> SQR3 |= sequence << (5*0);
		break;
	};

	case 1 :
	{
        ADC -> JSQR |= sequence << (5*0);
		break;
	};
	}
}
//


void ADC_Channel_1_Init(ADC_TypeDef *ADC,int channel_type, int sequence, int sampling_time)
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
GPIOA -> CRL   |= ANALOG_INPUT << (4*1);
ADC ->SMPR2 |=  sampling_time << (4*1);
	switch(channel_type)
	{
	case 0 :
	{
        ADC -> SQR3 |= sequence << (5*1);
		break;
	};

	case 1 :
	{
        ADC -> JSQR |= sequence << (5*1);
		break;
	};
	}
}
//

void ADC_Channel_2_Init(ADC_TypeDef *ADC,int channel_type, int sequence, int sampling_time)
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
GPIOA -> CRL   |= ANALOG_INPUT << (4*2);
ADC ->SMPR2 |=  sampling_time << (4*2);
	switch(channel_type)
	{
	case 0 :
	{
        ADC -> SQR3 |= sequence << (5*2);
		break;
	};

	case 1 :
	{
        ADC -> JSQR |= sequence << (5*2);
		break;
	};
	}
}
//

void ADC_Channel_3_Init(ADC_TypeDef *ADC,int channel_type, int sequence, int sampling_time)
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
GPIOA -> CRL   |= ANALOG_INPUT << (4*3);
ADC ->SMPR2 |=  sampling_time << (4*3);
	switch(channel_type)
	{
	case 0 :
	{
        ADC -> SQR3 |= sequence << (5*3);
		break;
	};

	case 1 :
	{
        ADC -> JSQR |= sequence << (5*3);
		break;
	};
	}
}
//

/***************************************** Channel Initialization Mode *****************************************************************
//@brief: These functions sets up the ADC channel.
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

void ADC_Channel_4_Init(ADC_TypeDef *ADC, int sequence, int sampling_time)
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
GPIOA -> CRL   |= ANALOG_INPUT << (4*4);
ADC ->SMPR2 |=  sampling_time << (4*4);
ADC -> SQR3 |= sequence << (5*4);
}
//


void ADC_Channel_5_Init(ADC_TypeDef *ADC, int sequence, int sampling_time)
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
GPIOA -> CRL   |= ANALOG_INPUT << (4*5);
ADC ->SMPR2 |=  sampling_time << (4*5);
ADC -> SQR3 |= sequence << (5*5);

}
//


void ADC_Channel_6_Init(ADC_TypeDef *ADC, int sequence, int sampling_time)
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
GPIOA -> CRL   |= ANALOG_INPUT << (4*5);
ADC ->SMPR2 |=  sampling_time << (4*5);
ADC -> SQR3 |= sequence << (5*6);

}
//


void ADC_Channel_7_Init(ADC_TypeDef *ADC, int sequence, int sampling_time)
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
GPIOA -> CRL   |= ANALOG_INPUT << (4*5);
ADC ->SMPR2 |=  sampling_time << (4*5);
ADC -> SQR2 |= sequence << (5*0);

}
//


void ADC_Channel_8_Init(ADC_TypeDef *ADC, int sequence, int sampling_time)
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
GPIOA -> CRL   |= ANALOG_INPUT << (4*5);
ADC ->SMPR2 |=  sampling_time << (4*5);
ADC -> SQR2 |= sequence << (5*1);

}
//


void ADC_Channel_9_Init(ADC_TypeDef *ADC, int sequence, int sampling_time)
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
GPIOA -> CRL   |= ANALOG_INPUT << (4*5);
ADC ->SMPR2 |=  sampling_time << (4*5);
ADC -> SQR2 |= sequence << (5*2);

}
//



void ADC_Temperature_Init(ADC_TypeDef *ADC)
{

}



/***************************************** Analog Watchdog Mode *****************************************************************
//@brief: These functions sets up the ADC watchdog.
//@param:
//       ADC                    ADC1 or ADC2
//       upper_limit            From 0 to 2^(11)
//       lower_limit            upper_limit >
//       channel_mode           0  ->  Regular
//                              1  ->  Injected
//       awd_channel_type       0  ->  multiple channel
//                              1  ->  single channel
//       awd_channel_selection  0 : 9 channels
 //@return: none
********************************************************************************************************************************/

void ADC_Analog_Watchdog_Init(ADC_TypeDef *ADC, int upper_limit, int lower_limit, int channel_mode, int awd_channel_type, int awd_channel_selection)
{
ADC -> LTR = lower_limit;
ADC ->HTR = upper_limit;
switch (channel_mode)
{
case 0 :
{
ADC ->CR1 |= ADC_CR1_AWDEN;
break;
}

case 1 :
{
ADC->CR1 |= ADC_CR1_JAWDEN;
break;
}

}

switch ( awd_channel_type)
{
case 0 :
{
ADC ->CR1 &= ~ADC_CR1_AWDSGL;
break;
}

case 1 :
{
ADC ->CR1 |= ADC_CR1_AWDSGL;
break;
}

}


ADC -> CR1 |= awd_channel_selection << 0;


}





/***************************************** External Trigger Conversion *****************************************************************
//@brief: These functions sets up the ADC watchdog.
//@param:
//       ADC                    ADC1 or ADC2
//       channel_type           0  ->  Regular channel
//                              1  ->  Injected channel
//       source                 0  ->  TIM1_CC1 event
//                              1  ->  TIM1_CC2 event
//                              2  ->  TIM1_CC3 event
//                              3  ->  TIM2_CC2 event
//                              4  ->  TIM3_TRGO event
//                              5  ->  TIM4_CC4 event
//                              6  ->  EXTI line 11
//                              7  ->  Software control bit SWSTART
//@return: none
********************************************************************************************************************************/


void ADC_Ext_Trigger_Conversion(ADC_TypeDef *ADC,int channel_type,uint8_t source)
{
	switch(channel_type){
	case 0 :
	{
		ADC -> CR2 |= (source) << 17 | 1 << 20;
	    break;
	}
	case 1:
	{
     	ADC -> CR2 |= (source) << 12 | 1 << 15;
	}
	default : break;
	}

}
/******************************************************************************************************************************/

