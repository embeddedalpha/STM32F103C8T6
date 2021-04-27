
/*
 * MPU9250.c
 *
 *  Created on: 27-04-2021
 *      Author: Kunal Salvi
 */


#include "MPU9250.h"



void MPU9250_Init(I2C_TypeDef *I2C)
{
	I2C_Init(I2C, Fast_Mode);
	MPU9250_Write_byte(I2C, 0x1A, 0x02); //Gyroscope Digital LPF Fs = 1KHz Bandwidth = 92 Hz Delay(ms) = 3.9
	MPU9250_Write_byte(I2C, 0x1B, 0x18); //Gyroscope Full Scale = +2000 dps
	MPU9250_Write_byte(I2C, 0x1C, 0x18); //Accelerometer Full Scale = +16G
	MPU9250_Write_byte(I2C, 0x1D, 0x0A); //Accelerometer Digitak LPF Fs = 1KHz Bandwidth = 92 Hz Delay(ms) = 7.8
	MPU9250_Write_byte(I2C, 0x6B, 0x00);
	MPU9250_Write_byte(I2C, 0x6C, 0x7F);

}

void MPU9250_Write_byte(I2C_TypeDef *I2C, uint8_t reg_address, uint8_t data)
{
	I2C_Master_Start(I2C);
	I2C_Master_Send_Address(I2C, MPU9250_Address, write);
	I2C_Master_Send_Data(I2C, reg_address);
	I2C_Master_Send_Data(I2C, data);
	I2C_Master_Stop(I2C);
}

void MPU9250_Write_Multiple_Bytes(I2C_TypeDef *I2C, uint8_t reg_address, uint8_t *data, uint16_t length)
{
	uint16_t i;
	I2C_Master_Start(I2C);
	I2C_Master_Send_Address(I2C, MPU9250_Address, write);
	I2C_Master_Send_Data(I2C, reg_address);
	for(i = 0 ; i < length; i++)
	{
		I2C_Master_Send_Data(I2C, data[i]);
	}
	I2C_Master_Stop(I2C);
}

uint8_t MPU9250_Read_Byte(I2C_TypeDef *I2C, uint8_t reg_address)
{
	uint8_t temp;
	I2C_Master_Start(I2C);
	I2C_Master_Send_Address(I2C, MPU9250_Address, write);
	I2C_Master_Send_Data(I2C, reg_address);
	I2C_Master_Start(I2C);
	I2C_Master_Send_Address(I2C, MPU9250_Address, read);
	temp = I2C_Master_Receive_Data(I2C);
	I2C_Master_Send_NACK(I2C);
	I2C_Master_Stop(I2C);
	return temp;

}

void MPU9250_Read_Multiple_Bytes(I2C_TypeDef *I2C, uint8_t reg_address,uint8_t *data, uint16_t length)
{
	int i;
	I2C_Master_Start(I2C);
	I2C_Master_Send_Address(I2C, MPU9250_Address, write);
	I2C_Master_Send_Data(I2C, reg_address);
	I2C_Master_Start(I2C);
	I2C_Master_Send_Address(I2C, MPU9250_Address, read);
	for (i = 0; i < length; i++) {
		data[i] = I2C_Master_Receive_Data(I2C);
	}
	I2C_Master_Send_NACK(I2C);
	I2C_Master_Stop(I2C);

}

