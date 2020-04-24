#include "BNO055.h"


//accelerometer config

void BNO055_Init()
{
I2C_Master_Init();
}

void BNO055_Write(uint8_t reg, uint8_t data)
{
	I2C_Master_Start();
	I2C_Master_Address_Write(BNO055_Address);
	I2C_Master_Send_Data(reg);
	I2C_Master_Send_Data(data);
	I2C_Master_Stop();
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


void Accelerometer_CONFIG(uint8_t G_Range, uint8_t Bandwidth, uint8_t OpMode)
{

}

void Gyroscope_CONFIG(uint8_t G_Range, uint8_t Bandwidth, uint8_t OpMode)
{

}

void Magnetometer_CONFIG(uint8_t DataRate, uint8_t OpMode, uint8_t PowerMode)
{

}
