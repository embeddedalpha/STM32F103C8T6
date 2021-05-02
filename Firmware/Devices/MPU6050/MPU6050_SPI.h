/*
 * MPU6050_SPI.c
 *
 *  Created on: May 02, 2021
 *      Author: Kunal
 */


#include "MPU6050_SPI.h"



void MPU6050_SPI_Init(SPI_TypeDef *SPI)
{
	MPU6050.SPI = SPI;
	MPU6050.clock_phase = 1;
	MPU6050.clock_polarity = 1;
	SPI_Master_Init(MPU6050);
	SPI_Master_SS_Deselect(MPU6050);
	SPI_Master_SS_Select(MPU6050);
	SPI_Master_TX(MPU6050, 0x19);
	SPI_Master_TX(MPU6050, 0x07);
	SPI_Master_TX(MPU6050, 0x6B);
	SPI_Master_TX(MPU6050, 0x00);
	SPI_Master_TX(MPU6050, 0x1B);
	SPI_Master_TX(MPU6050, 0x18);
	SPI_Master_TX(MPU6050, 0x6B);
	SPI_Master_TX(MPU6050, 0x00);
	SPI_Master_SS_Deselect(MPU6050);

}




void MPU6050_SPI_Read(uint8_t address, uint8_t *array,int length)
{
	uint8_t data;
	int var = 0;
	data = address | (1 << 7);
	SPI_Master_TX(MPU6050, data);
	for (; var < length; var++) {
		array[var] = SPI_Master_RX(MPU6050);
	}

}

void PU6050_SPI_Get_Raw_Data(short *mp)
{
	uint8_t  data[14];
	SPI_Master_SS_Deselect(MPU6050);
	SPI_Master_SS_Select(MPU6050);
	MPU6050_SPI_Read(0x3B, data, 14);
	//Accelerometer raw data
	mp[0] = (short)(data[0]<<8) | data[1];
	mp[1] = (short)(data[2]<<8) | data[3];
	mp[2] = (short)(data[4]<<8) | data[5];

	//Temperature raw data
	mp[3] = (short)(data[6]<<8) | data[7];

	//Gyroscope raw data
	mp[4] = (short)(data[8]<<8) | data[9];
	mp[5] = (short)(data[10]<<8) | data[11];
	mp[6] = (short)(data[12]<<8) | data[13];

}



