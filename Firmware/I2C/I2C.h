/*
 * I2C.h
 *
 *  Created on: 23-Apr-2021
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

void I2C_Init(I2C_TypeDef *I2C, uint8_t mode);

void I2C_Master_Start(I2C_TypeDef *I2C);

void I2C_Master_Send_Address(I2C_TypeDef *I2C, char address,char RW);

void I2C_Master_Send_Data(I2C_TypeDef *I2C, char data);

char I2C_Master_Receive_Data(I2C_TypeDef *I2C);

void I2C_Master_Stop(I2C_TypeDef *I2C);

void I2C_Master_Send_NACK(I2C_TypeDef *I2C);

#endif /* I2C_I2C_H_ */
