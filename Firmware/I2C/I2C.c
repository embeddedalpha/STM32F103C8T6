/*
 * I2C.h
 *
 *  Created on: 23-Apr-2021
 *  Updated on: 30-May-2021
 *      Author: Kunal
 */

#ifndef I2C_I2C_H_
#define I2C_I2C_H_

#include "main.h"
#include "GPIO/GPIO.h"

#define Fast_Mode	1
#define Normal_Mode	2
#define read 0
#define write 1

typedef struct I2C_Config
{
	I2C_TypeDef *I2C;
	bool mode;

}I2C_Config;

void I2C_Master_Init(I2C_Config I2C);

void I2C_Master_Start(I2C_Config I2C);

void I2C_Master_Send_Address(I2C_Config I2C, char address,char RW);

void I2C_Master_Send_Data(I2C_Config I2C, char data);

char I2C_Master_Receive_Data(I2C_Config I2C);

void I2C_Master_Stop(I2C_Config I2C);

void I2C_Master_Send_NACK(I2C_Config I2C);

#endif /* I2C_I2C_H_ */
