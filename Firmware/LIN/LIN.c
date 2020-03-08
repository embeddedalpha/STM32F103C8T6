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

#include "LIN.h"

int LIN_Init(void)
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
LIN ->CR2 |= USART_CR2_LINEN;

return 1;
}

int LIN_Send_Break(void)
{
LIN -> CR1 |= USART_CR1_SBK;
}

int LIN_Transmit_Data(void)
{
LIN -> CR1 |= USART_CR1_TE;
LIN_Send_Break();

}

int LIN_Receive_Data(void)
{}
