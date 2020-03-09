/**********************************************************************************************************************************
@file:    LIN.c
@author:  Kunal Salvi
@version: V3.05.0
@date:    29/2/2020
@brief:   LIN Source File.
          This file contains the functions declared in LIN.h file. This  is
          the LIN protocol driver file that any application can use.

@attention: This file aims at providing the user an abrstraction layer to the LIN peripheral
            and is tested on STM32f103C8T6. This file is free for use to any person or corporation.
            In case of failure of code/product due to third party tampering, the author will not be
            responsible. This code is published under MIT License.

**********************************************************************************************************************************/


#include "LIN.h"

/***************************************** LIN Setup Mode *****************************************************************
//@brief: The function sets up the LIN controller.
//@param: none
//@return: none
********************************************************************************************************************************/

void LIN_Setup(void)
{

if(LIN == USART1)
{
LIN -> BRR = (234 << 4 |6 << 0 );
}
else
{
LIN -> BRR = (117 << 4 | 3 << 0 );
}
LIN ->CR2 &= ~(USART_CR2_CLKEN | USART_CR2_STOP);
LIN -> CR3 &= ~(USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN);
LIN -> CR1 &= ~(USART_CR1_M);
LIN -> CR2 |= USART_CR2_STOP;

}
//




/***************************************** Initialization Mode *****************************************************************
//@brief: The function is initializes the LIN controller.
//@param: none
//@return: Return 1 when LIN mode is enabled.
********************************************************************************************************************************/

int LIN_Init(void)
{
	LIN ->CR2 |= USART_CR2_LINEN;
	return 1;
}
//




/***************************************** LIN Send Break *****************************************************************
//@brief: The function send a break on LIN bus.
//@param: none
//@return: none
********************************************************************************************************************************/
void LIN_Send_Break(void)
{
LIN -> CR1 |= USART_CR1_SBK;
}
//




/***************************************** LIN Transmit Data *****************************************************************
//@brief: The function transmit data onto LIN bus.
//@param:
//       LIN_SLAVE_ID         0x00 to 0x3B    Normal Signal or Data carrying frame
//                            0x3C to 0x3D    Carry Diagnostic & Configuration Data
//                            0x3E to 0x3F    Released for future enhancements
//@return: Returns 1 for proper transmission
********************************************************************************************************************************/

int LIN_Transmit_Data(uint8_t LIN_SLAVE_ID)
{
LIN -> CR1 |= USART_CR1_TE;
LIN_Send_Break();
LIN -> DR = 0x55;
while(!(LIN->SR & USART_SR_TXE));
while(!(LIN->SR & USART_SR_TC));
uint8_t P0 = (LIN_SLAVE_ID &(1 << 0)) ^ (LIN_SLAVE_ID &(1 << 1)) ^ (LIN_SLAVE_ID &(1 << 2)) ^ (LIN_SLAVE_ID(1 << 4)) ;
uint8_t P1 = !((LIN_SLAVE_ID &(1 << 1)) ^ (LIN_SLAVE_ID &(1 << 3)) ^ (LIN_SLAVE_ID &(1 << 4)) ^ (LIN_SLAVE_ID(1 << 5)));
uint_t PID = (P0 << 6) | (P1 << 7) | LIN_SLAVE_ID;
LIN -> DR = PID;
while(!(LIN->SR & USART_SR_TXE));
while(!(LIN->SR & USART_SR_TC));
}
//




/***************************************** LIN Receive Data *****************************************************************
//@brief: The function receives data that's onto the bus
//@param: none
//@return: Returns 1 when Normal Signal or Data carrying frame
//         Returns 2 when Carry Diagnostic & Configuration Data
//         Returns 3 when Released for future enhancements
********************************************************************************************************************************/

int LIN_Receive_Data(void)
{
LIN -> CR2 |= UASRT_CR2_LBDL;
LIN -> CR1 |= USART_CR1_RE;
while(!(LIN->SR & USART_SR_LBD));

}
//



