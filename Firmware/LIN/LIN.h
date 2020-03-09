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

/*
 * LIN Frame
 * |0000000000000|1|0_01010101_1|0_[ID 6:0]_[Parity 1:0]_1|Data [8:0]|
 * 13 SYNC Break bits
 * 1  Delimiter bits
 * 10 SYNC Field bits [1 START BIT | 8 SYNC BITS (0X55) | 1 STOP BIT]
 * 10 IDENTIFIER bits [1 START BIT | 6 ID BITS | 2 PARITY BITS | 1 STOP BIT |
 */
#ifndef _LIN_H_
#define _LIN_H_

#include "stm32f10x.h"

USART_TypeDef *LIN;

uint8_t LIN_TX_Buffer[8];
uint8_t LIN_RX_Buffer[10];

void LIN_Setup(void);
int LIN_Init(void);
int LIN_Send_Break(void);
int LIN_Send_Break(void);
int LIN_Transmit_Data(uint8_t LIN_SLAVE_ID);
int LIN_Receive_Data(void);



#endif

