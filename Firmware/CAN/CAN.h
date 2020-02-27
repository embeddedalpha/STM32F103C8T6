#ifndef _CAN_H_
#define _CAN_H_


#include "stm32f10x.h"
#include "stdio.h"
#include "stdlib.h"


void CAN_Sleep_Mode_Start();
void CAN_Sleep_Mode_Stop();
void CAN_Init_Mode_Start();
void CAN_Init_Mode_Stop();
void CAN_Normal_Mode();
void CAN_TX_Mailbox_0(uint32_t identifier, int length, int data[] );
void CAN_TX_Mailbox_1(uint32_t identifier, int length, int data[] );
void CAN_TX_Mailbox_2(uint32_t identifier, int length, int data[] );


















#endif
