#include "BNO055.h"


//accelerometer config

void BNO055_Init()
{
I2C_Master_Init();
}

void BNO055_GET_ACC_DATA(void)
{
	uint16_t ACC_X, ACC_Y, ACC_Z;
	for(int i = 0 ; i< 10; i++)
	{
		BNO055_Buffer[i] = 0;
	}

	BNO055_Read(ACC_DATA_Z_MSB,6);
	ACC_X = (BNO055_Buffer[0] << 8) | BNO055_Buffer[1];
	ACC_Y = (BNO055_Buffer[2] << 8) | BNO055_Buffer[3];
	ACC_Z = (BNO055_Buffer[4] << 8) | BNO055_Buffer[5];

	BNO055_ACCL_DATA_Buffer[0] = ACC_X;
	BNO055_ACCL_DATA_Buffer[1] = ACC_Y;
	BNO055_ACCL_DATA_Buffer[2] = ACC_Z;
}

void BNO055_GET_GYR_DATA(void)
{
	uint16_t GYR_X, GYR_Y, GYR_Z;
	for(int i = 0 ; i< 10; i++)
	{
		BNO055_Buffer[i] = 0;
	}

	BNO055_Read(GYR_DATA_Z_MSB,6);
	GYR_X = (BNO055_Buffer[0] << 8) | BNO055_Buffer[1];
	GYR_Y = (BNO055_Buffer[2] << 8) | BNO055_Buffer[3];
	GYR_Z = (BNO055_Buffer[4] << 8) | BNO055_Buffer[5];

	BNO055_GYR_DATA_Buffer[0] = GYR_X;
	BNO055_GYR_DATA_Buffer[1] = GYR_Y;
	BNO055_GYR_DATA_Buffer[2] = GYR_Z;
}


void BNO055_GET_MAG_DATA(void)
{
	uint16_t MAG_X, MAG_Y, MAG_Z;
	for(int i = 0 ; i< 10; i++)
	{
		BNO055_Buffer[i] = 0;
	}

	BNO055_Read(GYR_DATA_Z_MSB,6);
	MAG_X = (BNO055_Buffer[0] << 8) | BNO055_Buffer[1];
	MAG_Y = (BNO055_Buffer[2] << 8) | BNO055_Buffer[3];
	MAG_Z = (BNO055_Buffer[4] << 8) | BNO055_Buffer[5];

	BNO055_MAG_DATA_Buffer[0] = MAG_X;
	BNO055_MAG_DATA_Buffer[1] = MAG_Y;
	BNO055_MAG_DATA_Buffer[2] = MAG_Z;
}



void BNO055_Read(uint8_t reg, uint8_t bytes)
{
	I2C_Master_Start();
	I2C_Master_Address_Write(BNO055_Address);
	I2C_Master_Start();
	for(int i = 0; i < bytes; i++)
	{
		BNO055_Buffer[i] = I2C_Master_Rx_Data();
		I2C_Gen_Ack();
	}
	I2C_Master_Stop();
}



void BNO055_Power_Mode(uint8_t mode);
