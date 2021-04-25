/*
 * MPU6050.c
 *
 *  Created on: 25-Apr-2021
 *      Author: Kunal
 */


#include "MPU6050_I2C.h"

void MPU6050_Init(I2C_TypeDef *I2C)
{
	I2C_Init(I2C, Fast_Mode);
	I2C_Master_Start(I2C);
	I2C_Master_Send_Address(I2C, 0x68, write);
	I2C_Master_Send_Data(I2C, 0x19);
	I2C_Master_Send_Data(I2C, 0x07);
	I2C_Master_Send_Data(I2C, 0x6B);
	I2C_Master_Send_Data(I2C, 0x00);
	I2C_Master_Send_Data(I2C, 0x1A);
	I2C_Master_Send_Data(I2C, 0x00);
	I2C_Master_Send_Data(I2C, 0x1B);
	I2C_Master_Send_Data(I2C, 0x18);
	I2C_Master_Send_Data(I2C, 0x6B);
	I2C_Master_Send_Data(I2C, 0x00);
	I2C_Master_Stop(I2C);


}

short * MPU6050_Get_Data(I2C_TypeDef *I2C)
{
	short data[7];
	I2C_Master_Send_Address(I2C, 0x68, read);
	I2C_Master_Send_Data(I2C, 0x3B);
	//Accelerometer Data
	data[0] = ((I2C_Master_Receive_Data(I2C) << 8) | I2C_Master_Receive_Data(I2C)/16384.0);
	data[1] = ((I2C_Master_Receive_Data(I2C) << 8) | I2C_Master_Receive_Data(I2C)/16384.0);
	data[2] = ((I2C_Master_Receive_Data(I2C) << 8) | I2C_Master_Receive_Data(I2C)/16384.0);
	//Temperature Data
	data[3] = ((I2C_Master_Receive_Data(I2C) << 8) | I2C_Master_Receive_Data(I2C)/340.0) + 36.53;
	//Gyroscope Data
	data[4] = ((I2C_Master_Receive_Data(I2C) << 8) | I2C_Master_Receive_Data(I2C)/16.4);
	data[5] = ((I2C_Master_Receive_Data(I2C) << 8) | I2C_Master_Receive_Data(I2C)/16.4);
	data[6] = ((I2C_Master_Receive_Data(I2C) << 8) | I2C_Master_Receive_Data(I2C)/16.4);


}
