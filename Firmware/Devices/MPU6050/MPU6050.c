#include "MPU6050.h"


int power(float base, uint8_t exp)
{
	int result = 1;
	for(exp; exp > 0; exp--)
	{
		result = result * base;
	}
	return result;
}


void MPU6050_SPI_Init(void)
{
	struct SPI_Master_Parameters MPU6050;

	MPU6050->Baudrate = 1; //9 MHz
	MPU6050->BiDirectional_Mode = Duplex;
	MPU6050->CPHA = 1;
	MPU6050->CPOL = 1;
	MPU6050->DataFormat = Bit_8;
	MPU6050->LSBorMSB = MSB;
	MPU6050->Slave_Management = Software_Managed;

	SPI_Master_Config(SPI1,MPU6050);
	SPI_Master_Enable(SPI1);

	MPU6050_Write_Single_Byte(0x19,0x02);
	MPU6050_Write_Single_Byte(0x6b,0x01);
	MPU6050_Write_Single_Byte(0x1a,0x00);
	MPU6050_Write_Single_Byte(0x1b,0x18);
	MPU6050_Write_Single_Byte(0x1c,0x08);



}





void MPU6050_Write_Single_Byte(uint8_t address,uint8_t data)
{
	address = (uint8_t)((1 << 7) | (address >> 1));
	SPI_NSS_HIGH(GPIOA);
	SPI_NSS_LOW(GPIOA);
	SPI_Master_TX(SPI1,address);
	SPI_Master_TX(SPI1,data);
}

uint8_t MPU6050_Read_Single_Byte(uint8_t address)
{
	address = (uint8_t)((0 << 7) | (address >> 1));
	SPI_NSS_HIGH(GPIOA);
	SPI_NSS_LOW(GPIOA);
	SPI_Master_TX(SPI1,address);
	return SPI_Master_RX(SPI1);
}

uint16_t *MPU6050_Gyro_Raw(void)
{
	uint16_t Gyro_Data[3];
	uint16_t Gyro_Data[0] = (uint16_t)((MPU6050_Read_Single_Byte(ACCEL_X_HIGH) << 8) | (MPU6050_Read_Single_Byte(ACCEL_X_LOW)));
	uint16_t Gyro_Data[1] = (uint16_t)((MPU6050_Read_Single_Byte(ACCEL_Y_HIGH) << 8) | (MPU6050_Read_Single_Byte(ACCEL_Y_LOW)));
	uint16_t Gyro_Data[2] = (uint16_t)((MPU6050_Read_Single_Byte(ACCEL_Z_HIGH) << 8) | (MPU6050_Read_Single_Byte(ACCEL_Z_LOW)));

	return Gyro_Data;
}

uint16_t *MPU6050_Accl_Raw(void)
{
	uint16_t Accl_Data[3];
	uint16_t Accl_Data[0] = (uint16_t)((MPU6050_Read_Single_Byte(GYRO_X_HIGH) << 8) | (MPU6050_Read_Single_Byte(GYRO_X_LOW)));
	uint16_t Accl_Data[1] = (uint16_t)((MPU6050_Read_Single_Byte(GYRO_Y_HIGH) << 8) | (MPU6050_Read_Single_Byte(GYRO_Y_LOW)));
	uint16_t Accl_Data[2] = (uint16_t)((MPU6050_Read_Single_Byte(GYRO_Z_HIGH) << 8) | (MPU6050_Read_Single_Byte(GYRO_Z_LOW)));

	return Accl_Data;
}

uint16_t MPU6050_Temp_Raw(void)
{
	uint16_t Temp_Data;
	Temp_Data = (uint16_t)((MPU6050_Read_Single_Byte(TEMP_X_HIGH) << 8) | (MPU6050_Read_Single_Byte(TEMP_X_LOW)));

	return Temp_Data;
}


void MPU6050_Reset(void)
{
	int x,y;
	MPU6050_Write_Single_Byte(0x6B,0x80);
	do {
		x = MPU6050_Read_Single_Byte(0x6B);
		y = x & 0x80;
	} while (!(y == 0x80));
}

void MPU6050_Sleep_Enable(void)
{
	MPU6050_Write_Single_Byte(0x6B,0x40);
}

void MPU6050_Sleep_Disable(void)
{
	MPU6050_Write_Single_Byte(0x6B,0x00);
}


void MPU6050_FIFO_Enable(void)
{
	MPU6050_Write_Single_Byte(0x23,0x78);
	MPU6050_Write_Single_Byte(0x6a,0x40);
}

uint16_t MPU6050_Read_FIFO(void)
{
	uint16_t x;
	x = (uint16_t)((MPU6050_Read_Single_Byte(0x72) << 8) | (MPU6050_Read_Single_Byte(0x73)));
	return x;
}

//int MPU6050_Self_Test_Gyro(void)
//{
//	float FT_XG, FT_YG, FT_ZG;
//	int passx,passy,passz;
//	float Percetage_STR_X, Percetage_STR_Y, Percetage_STR_Z;
//	//Read Test Registers before Self_Test is enabled
//	uint8_t Self_Test_Disabled_X = MPU6050_Read_Single_Byte(0x0D);
//	uint8_t Self_Test_Disabled_Y = MPU6050_Read_Single_Byte(0x0E);
//	uint8_t Self_Test_Disabled_Z = MPU6050_Read_Single_Byte(0x0F);
//
//	//Enable Self Test
//	MPU6050_Write_Single_Byte(0x1B,0xE0);
//	//Read Test Registers before Self_Test
//	uint8_t Sel_Test_Enabled_X = MPU6050_Read_Single_Byte(0x0D);
//	uint8_t Sel_Test_Enabled_Y = MPU6050_Read_Single_Byte(0x0E);
//	uint8_t Sel_Test_Enabled_Z = MPU6050_Read_Single_Byte(0x0F);
//
//
//	uint8_t Self_Test_Response_X = Sel_Test_Enabled_X - Self_Test_Disabled_X;
//	uint8_t Self_Test_Response_Y = Sel_Test_Enabled_Y - Self_Test_Disabled_Y;
//	uint8_t Self_Test_Response_Z = Sel_Test_Enabled_Z - Self_Test_Disabled_Z;
//
//	uint8_t XG_TEST = 0x1F & Self_Test_Enabled_X;
//	if(XG_TEST != 0)
//	{
//		FT_XG = (float)(25 * 131 * power(1.046,(XG_TEST-1)));
//	}
//	else
//	{
//		FT_XG = 0;
//	}
//
//	uint8_t XY_TEST = 0x1F & Self_Test_Enabled_Y;
//	if(XY_TEST != 0)
//	{
//		FT_YG = -(float)(25 * 131 * power(1.046,(XY_TEST-1)));
//	}
//	else
//	{
//		FT_YG = 0;
//	}
//
//	uint8_t XZ_TEST = 0x1F & Self_Test_Enabled_Z;
//	if(XZ_TEST != 0)
//	{
//		FT_ZG = (float)(25 * 131 * power(1.046,(XZ_TEST-1)));
//	}
//	else
//	{
//		FT_ZG = 0;
//	}
//
//	if( (FT_XG != 0) && (FT_YG != 0) && (FT_ZG != 0) )
//	{
//		Percetage_STR_X = (Self_Test_Response_X - FT_XG)/FT_XG;
//
//		Percetage_STR_Y = (Self_Test_Response_Y - FT_YG)/FT_YG;
//
//		Percetage_STR_Z = (Self_Test_Response_Z - FT_ZG)/FT_ZG;
//
//	}
//
//	if( (Percetage_STR_X >= 0) && (Percetage_STR_X <=14))
//	{
//		passx =1;
//	}
//	if( (Percetage_STR_Y >= 0) && (Percetage_STR_Y <=14))
//	{
//		passy =1;
//	}
//	if( (Percetage_STR_Z >= 0) && (Percetage_STR_Z <=14))
//	{
//		passz =1;
//	}
//
//	if( (passx == 1) && (passy == 1) && (passz == 1))
//	{
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
