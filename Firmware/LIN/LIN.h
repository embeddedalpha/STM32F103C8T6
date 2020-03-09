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

/***************************************** LIN Setup Mode *****************************************************************
//@brief: The function sets up the LIN controller.
//@param: none
//@return: none
********************************************************************************************************************************/

void LIN_Setup(void);



/***************************************** Initialization Mode *****************************************************************
//@brief: The function is initializes the LIN controller.
//@param: none
//@return: Return 1 when LIN mode is enabled.
********************************************************************************************************************************/

int LIN_Init(void);



/***************************************** LIN Send Break *****************************************************************
//@brief: The function send a break on LIN bus.
//@param: none
//@return: none
********************************************************************************************************************************/

int LIN_Send_Break(void);



/***************************************** LIN Transmit Data *****************************************************************
//@brief: The function transmit data onto LIN bus.
//@param:
//       LIN_SLAVE_ID         0x00 to 0x3B    Normal Signal or Data carrying frame
//                            0x3C to 0x3D    Carry Diagnostic & Configuration Data
//                            0x3E to 0x3F    Released for future enhancements
//@return: Returns 1 for proper transmission
********************************************************************************************************************************/

int LIN_Transmit_Data(uint8_t LIN_SLAVE_ID);




/***************************************** LIN Receive Data *****************************************************************
//@brief: The function receives data that's onto the bus
//@param: none
//@return: Returns 1 when Normal Signal or Data carrying frame
//         Returns 2 when Carry Diagnostic & Configuration Data
//         Returns 3 when Released for future enhancements
********************************************************************************************************************************/

int LIN_Receive_Data(void);



#endif
