#ifndef _I2C_H_
#define _I2C_H_


#include "stm32f10x.h"


void I2C_Init(void);
void I2C_Start(void);
void I2C_Send_Address(int address);
void I2C_Data(int data);
void I2C_Rx_Address(int address);
int I2C_RX_Data(void);
void I2C_Stop(void);


#endif
