/**********************************************************************************************************************************
@file:    LIN.h
@author:  Kunal Salvi
@version: V3.05.0
@date:    29/2/2020
@brief:   LIN Header File.
          This file contains the prototype of functions declared in LIN.h file.
          This is the LIN protocol driver file that any application can use.

@attention: This file aims at providing the user an abrstraction layer to the LIN peripheral
            and is tested on STM32f103C8T6. This file is free for use to any person or corporation.
            In case of failure of code/product due to third party tampering, the author will not be
            responsible. This code is published under MIT License.

**********************************************************************************************************************************/

#ifndef _LIN_H_
#define _LIN_H_

#include "stm32f10x.h"

USART_TypeDef *LIN;



int LIN_Init(void);
int LIN_Send_Break(void);
int LIN_Transmit_Data(void);
int LIN_Receive_Data(void);



#endif
