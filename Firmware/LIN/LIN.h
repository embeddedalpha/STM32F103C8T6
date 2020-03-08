#ifndef _LIN_H_
#define _LIN_H_

#include "stm32f10x.h"

USART_TypeDef *LIN;



int LIN_Init(void);
int LIN_Send_Break(void);
int LIN_Transmit_Data(void);
int LIN_Receive_Data(void);



#endif
