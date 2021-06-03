/*
 * MPU9250.c
 *
 *  Created on: 30-04-2021
 *  Updated on: 02-06-2021
 *      Author: Kunal Salvi
 */


#include "MPU9250.h"

void MPU9250_Init(I2C_TypeDef *I2C)
{
	MPU9250.I2C = I2C;
	MPU9250.mode = Fast_Mode;
	I2C_Master_Init(MPU9250);

	MPU9250_Write_byte(MPU9250_Address, 0x1A, 0x02);
	MPU9250_Write_byte(MPU9250_Address, 0x1B, 0x018);
	MPU9250_Write_byte(MPU9250_Address, 0x1C, 0x018);
	MPU9250_Write_byte(MPU9250_Address, 0x1D, 0x0A);

	MPU9250_Write_byte(MPU9250_Address, 0x6B, 0x00);
	MPU9250_Write_byte(MPU9250_Address, 0x6C, 0x7f);

}

void MPU9250_Write_byte(uint8_t device_address, uint8_t reg_address, uint8_t data)
{
	I2C_Master_Start(MPU9250);
	I2C_Master_Send_Address(MPU9250, device_address, write);
	I2C_Master_Send_Data(MPU9250, reg_address);
	I2C_Master_Send_Data(MPU9250, data);
	I2C_Master_Stop(MPU9250);
}

void MPU9250_Write_Multiple_Bytes(uint8_t device_address, uint8_t reg_address, uint8_t *data, uint16_t length)
{
	int i;
	I2C_Master_Start(MPU9250);
	I2C_Master_Send_Address(MPU9250, device_address, write);
	I2C_Master_Send_Data(MPU9250, reg_address);
	for(i = 0 ; i < length; i++)
	{
		I2C_Master_Send_Data(MPU9250, data[i]);
	}
	I2C_Master_Stop(MPU9250);
}

uint8_t MPU9250_Read_Byte(uint8_t device_address, uint8_t reg_address)
{
	uint8_t temp;
	I2C_Master_Start(MPU9250);
	I2C_Master_Send_Address(MPU9250, device_address, write);
	I2C_Master_Send_Data(MPU9250, reg_address);
	I2C_Master_Start(MPU9250);
	I2C_Master_Send_Address(MPU9250, device_address, read);
	temp = I2C_Master_Receive_Data(MPU9250);
	I2C_Master_Send_NACK(MPU9250);
	I2C_Master_Stop(MPU9250);
	return temp;

}

void MPU9250_Read_Multiple_Bytes(uint8_t device_address, uint8_t reg_address,uint8_t *data, uint16_t length)
{
	int i;
	I2C_Master_Start(MPU9250);
	I2C_Master_Send_Address(MPU9250, device_address, write);
	I2C_Master_Send_Data(MPU9250, reg_address);
	I2C_Master_Start(MPU9250);
	I2C_Master_Send_Address(MPU9250, device_address, read);
	for (i = 0; i < length; i++) {
		data[i] = I2C_Master_Receive_Data(MPU9250);
	}
	I2C_Master_Send_NACK(MPU9250);
	I2C_Master_Stop(MPU9250);

}

void MPU9250_Read_Accl_Data(short *array)
{
	uint8_t raw[6];
    MPU9250_Read_Multiple_Bytes(MPU9250_ADDRESS,ACCEL_XOUT_H, raw, 6);
    array[0]= (short)((raw[0] << 8) | raw[1]); //ACCL_X
    array[1]= (short)((raw[2] << 8) | raw[3]); //ACCL_Y
    array[2]= (short)((raw[4] << 8) | raw[5]); //ACCL_Z
}

void MPU9250_Read_Gyro_Data(short *array)
{
	uint8_t raw[6];
    MPU9250_Read_Multiple_Bytes(MPU9250_ADDRESS,GYRO_XOUT_H, raw, 6);
    array[0]= (short)((raw[0] << 8) | raw[1]); //GYRO_X
    array[1]= (short)((raw[2] << 8) | raw[3]); //GYRO_Y
    array[2]= (short)((raw[4] << 8) | raw[5]); //GYRO_Z
}

void MPU9250_Read_Magn_Data(short *array)
{
	uint8_t raw[6];
    MPU9250_Read_Multiple_Bytes(AK8963_ADDRESS,AK8963_XOUT_H, raw, 6);
    array[0]= (short)((raw[0] << 8) | raw[1]); //MAGN_X
    array[1]= (short)((raw[2] << 8) | raw[3]); //MAGN_Y
    array[2]= (short)((raw[4] << 8) | raw[5]); //MAGN_Z
}

