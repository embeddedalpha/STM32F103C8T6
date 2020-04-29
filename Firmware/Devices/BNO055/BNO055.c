#include "BNO055.h"


//accelerometer config

void BNO055_Init()
{
I2C_Master_Init();
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



void BNO055_Power_Mode(uint8_t mode){}


//////////////////////////////////////////////////////////////////////////////////////
//                                          QUATERNION ANGLE
//////////////////////////////////////////////////////////////////////////////////////

void BNO055_GET_Quaternion_DATA(void)
{
	uint16_t QUA_X, QUA_Y, QUA_Z, QUA_W;
	for(int i = 0 ; i< 10; i++)
	{
		BNO055_Buffer[i] = 0;
	}

	BNO055_Read(QUA_DATA_W_LSB,8);

	QUA_W = (BNO055_Buffer[0] << 8) | BNO055_Buffer[1];
	QUA_X = (BNO055_Buffer[2] << 8) | BNO055_Buffer[3];
	QUA_Y = (BNO055_Buffer[4] << 8) | BNO055_Buffer[5];
	QUA_Z = (BNO055_Buffer[6] << 8) | BNO055_Buffer[7];

	BNO055_QUATERNION_Buffer[0] = (float)(QUA_W / 16384.0f);
	BNO055_QUATERNION_Buffer[1] = (float)(QUA_X / 16384.0f);
	BNO055_QUATERNION_Buffer[2] = (float)(QUA_Y / 16384.0f);
	BNO055_QUATERNION_Buffer[3] = (float)(QUA_Z / 16384.0f);
}


//////////////////////////////////////////////////////////////////////////////////////
//                                          EULER ANGLE
//////////////////////////////////////////////////////////////////////////////////////

void BNO055_GET_Euler_DATA(void)
{
	uint16_t RAW, PITCH, ROLL;
	for(int i = 0 ; i< 10; i++)
	{
		BNO055_Buffer[i] = 0;
	}

	BNO055_Read(EUL_Heading_LSB,6);

	RAW = (BNO055_Buffer[0] << 8) | BNO055_Buffer[1];
	PITCH = (BNO055_Buffer[2] << 8) | BNO055_Buffer[3];
	ROLL = (BNO055_Buffer[4] << 8) | BNO055_Buffer[5];


	BNO055_EULER_ANGLE_Buffer[0] = (float)(RAW / 16.0f);
	BNO055_EULER_ANGLE_Buffer[1] = (float)(PITCH / 16.0f);
	BNO055_EULER_ANGLE_Buffer[2] = (float)(ROLL / 16.0f);

}

//////////////////////////////////////////////////////////////////////////////////////
//                                          GRAVITY VECTOR
//////////////////////////////////////////////////////////////////////////////////////

void BNO055_GET_Gravity_Vector_DATA(void)
{
	uint16_t GRV_X, GRV_Y, GRV_Z;
	for(int i = 0 ; i< 10; i++)
	{
		BNO055_Buffer[i] = 0;
	}

	BNO055_Read(GRV_Data_X_LSB,6);

	GRV_X = (BNO055_Buffer[0] << 8) | BNO055_Buffer[1];
	GRV_Y = (BNO055_Buffer[2] << 8) | BNO055_Buffer[3];
	GRV_Z = (BNO055_Buffer[4] << 8) | BNO055_Buffer[5];


	BNO055_GRAVITY_VECTOR_Buffer[0] = (float)(GRV_X / 100.0f);
	BNO055_GRAVITY_VECTOR_Buffer[1] = (float)(GRV_Y / 100.0f);
	BNO055_GRAVITY_VECTOR_Buffer[2] = (float)(GRV_Z / 100.0f);

}

//////////////////////////////////////////////////////////////////////////////////////
//                                          LINEAR ACCELERATION
//////////////////////////////////////////////////////////////////////////////////////

void BNO055_GET_Linear_Acceleration_DATA(void)
{
	uint16_t LIN_X, LIN_Y, LIN_Z;
	for(int i = 0 ; i< 10; i++)
	{
		BNO055_Buffer[i] = 0;
	}

	BNO055_Read(GRV_Data_X_LSB,6);

	LIN_X = (BNO055_Buffer[0] << 8) | BNO055_Buffer[1];
	LIN_Y = (BNO055_Buffer[2] << 8) | BNO055_Buffer[3];
	LIN_Z = (BNO055_Buffer[4] << 8) | BNO055_Buffer[5];


	BNO055_LINEAR_ACCL_Buffer[0] = (float)(LIN_X / 100.0f);
	BNO055_LINEAR_ACCL_Buffer[1] = (float)(LIN_Y / 100.0f);
	BNO055_LINEAR_ACCL_Buffer[2] = (float)(LIN_Z / 100.0f);

}

//////////////////////////////////////////////////////////////////////////////////////
//                                          COMPASS DATA
//////////////////////////////////////////////////////////////////////////////////////

void BNO055_GET_Compass_DATA(void)
{
	uint16_t LIN_X, LIN_Y, LIN_Z;
	for(int i = 0 ; i< 10; i++)
	{
		BNO055_Buffer[i] = 0;
	}

	BNO055_Read(GRV_Data_X_LSB,6);

	LIN_X = (BNO055_Buffer[0] << 8) | BNO055_Buffer[1];
	LIN_Y = (BNO055_Buffer[2] << 8) | BNO055_Buffer[3];
	LIN_Z = (BNO055_Buffer[4] << 8) | BNO055_Buffer[5];


	BNO055_LINEAR_ACCL_Buffer[0] = (float)(LIN_X / 100.0f);
	BNO055_LINEAR_ACCL_Buffer[1] = (float)(LIN_Y / 100.0f);
	BNO055_LINEAR_ACCL_Buffer[2] = (float)(LIN_Z / 100.0f);

}

//////////////////////////////////////////////////////////////////////////////////////
//                                          RAW  DATA
//////////////////////////////////////////////////////////////////////////////////////

void BNO055_GET_GYRO_DATA(void)
{
	uint16_t GYRO_X, GYRO_Y, GYRO_Z;
	for(int i = 0 ; i< 10; i++)
	{
		BNO055_Buffer[i] = 0;
	}

	BNO055_Read(GYRO_DATA_X_LSB,6);

	GYRO_X = (BNO055_Buffer[0] << 8) | BNO055_Buffer[1];
	GYRO_Y = (BNO055_Buffer[2] << 8) | BNO055_Buffer[3];
	GYRO_Z = (BNO055_Buffer[4] << 8) | BNO055_Buffer[5];

	BNO055_GYRO_DATA_Buffer[0] = (float)(GYRO_X / 16.0f);
	BNO055_GYRO_DATA_Buffer[1] = (float)(GYRO_Y / 16.0f);
	BNO055_GYRO_DATA_Buffer[2] = (float)(GYRO_Z / 16.0f);
}


void BNO055_GET_ACCL_DATA(void)
{
	uint16_t ACCL_X, ACCL_Y, ACCL_Z;
	for(int i = 0 ; i< 10; i++)
	{
		BNO055_Buffer[i] = 0;
	}

	BNO055_Read(ACC_DATA_X_LSB,6);

	ACCL_X = (BNO055_Buffer[0] << 8) | BNO055_Buffer[1];
	ACCL_Y = (BNO055_Buffer[2] << 8) | BNO055_Buffer[3];
	ACCL_Z = (BNO055_Buffer[4] << 8) | BNO055_Buffer[5];

	BNO055_ACCL_DATA_Buffer[0] = (float)(ACCL_X / 0.01f);
	BNO055_ACCL_DATA_Buffer[1] = (float)(ACCL_Y / 0.01f);
	BNO055_ACCL_DATA_Buffer[2] = (float)(ACCL_Z / 0.01f);
}


void BNO055_GET_MAG_DATA(void)
{
	uint16_t MAG_X, MAG_Y, MAG_Z;
	for(int i = 0 ; i< 10; i++)
	{
		BNO055_Buffer[i] = 0;
	}

	BNO055_Read(MAG_DATA_X_LSB,6);

	MAG_X = (BNO055_Buffer[0] << 8) | BNO055_Buffer[1];
	MAG_Y = (BNO055_Buffer[2] << 8) | BNO055_Buffer[3];
	MAG_Z = (BNO055_Buffer[4] << 8) | BNO055_Buffer[5];

	BNO055_MAG_DATA_Buffer[0] = (float)(MAG_X / 16.0f);
	BNO055_MAG_DATA_Buffer[1] = (float)(MAG_Y / 16.0f);
	BNO055_MAG_DATA_Buffer[2] = (float)(MAG_Z / 16.0f);
}

