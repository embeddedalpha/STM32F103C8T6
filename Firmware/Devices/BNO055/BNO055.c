/*
 * BNO055.c
 *
 *  Created on: 30-May-2021
 *  Updated on: 31-May-2021
 *      Author: Kunal
 */


#include "BNO055.h"


void BNO055_Init(I2C_TypeDef *I2C)
{

	Delay_Config();
	Delay_ms(650);
	BNO055.I2C = I2C;
	BNO055.mode = Fast_Mode;
	I2C_Master_Init(BNO055);
	BNO055_Write_Single(OPR_MODE, 0x0C);
	Delay_ms(20);

}

void BNO055_Read_Buffer(uint8_t reg, uint8_t *data, int len)
{
	int i=0;
	I2C_Master_Start(BNO055);
	I2C_Master_Send_Address(BNO055, 0x29, write);
	I2C_Master_Send_Data(BNO055, reg);
	I2C_Master_Start(BNO055);
	I2C_Master_Send_Address(BNO055, 0x29, read);
	for(i = 0;i < len; i++)
	{
		data[i] = I2C_Master_Receive_Data(BNO055);
	}
	I2C_Master_Send_NACK(BNO055);
	I2C_Master_Stop(BNO055);

}

void BNO055_Write_Buffer(unit8_t reg, uint8_t *data, int len)
{
	int i;
	I2C_Master_Start(BNO055);
	I2C_Master_Send_Address(BNO055, 0x29, write);
	for(i = 0; i < len; i++)
	I2C_Master_Send_Data(BNO055, data[i]);
	I2C_Master_Stop(BNO055);
}

void BNO055_Write_Single(unit8_t reg, unit8_t data)
{
	I2C_Master_Start(BNO055);
	I2C_Master_Send_Address(BNO055, 0x29, write);
	I2C_Master_Send_Data(BNO055, data);
	I2C_Master_Stop(BNO055);
}

unit8_t BNO055_Read_Single(unit8_t reg)
{
	uint8_t temp;
	I2C_Master_Start(BNO055);
	I2C_Master_Send_Address(BNO055, 0x29, write);
	I2C_Master_Send_Data(BNO055, reg);
	I2C_Master_Start(BNO055);
	I2C_Master_Send_Address(BNO055, 0x29, read);
	temp =I2C_Master_Receive_Data(BNO055);
	I2C_Master_Send_NACK(BNO055);
	I2C_Master_Stop(BNO055);

	return temp;
}

void BNO055_Get_Euler_Angles(short *eu)
{
	short i = 0;
	uint8_t a[6];
	BNO055_Read_Buffer(EUL_Heading_LSB, a, 6);
	for(i = 0; i<3; i++)
	{
		eu[i] = (short)((a[i*2+1] << 8) | a[i*2])/16;
	}
}

void BNO055_Get_Quaternion_Angles(short *qu)
{
	short i = 0;
	unit8_t a[8];
	BNO055_Read_Buffer(QUA_Data_W_LSB, a, 8);
	for(i = 0; i < 4; i++)
	{
		qu[i] = (short)((a[i*2+1] << 8) | a[i*2])/16384;
	}
}

void BNO055_Get_Linear_Accl(short *la)
{
	short i = 0;
	unit8_t a[6];
	BNO055_Read_Buffer(LIA_Data_X_LSB, a, 6);
	for(i = 0; i < 4; i++)
	{
		la[i] = (short)((a[i*2+1] << 8) | a[i*2])/4;
	}
}

void BNO055_Get_Gravity_Vector(short *gv)
{
	short i = 0;
	unit8_t a[6];
	BNO055_Read_Buffer(GRV_Data_X_LSB, a, 6);
	for(i = 0; i < 4; i++)
	{
		gv[i] = (short)((a[i*2+1] << 8) | a[i*2])/4;
	}
}


int BNO055_Calibrate(void)
{
	unit8_t calib;
	int i = 0;

	do {
		calib = BNO055_Read_Single(CALIB_STAT);
		i++;

	} while ((calib == 0xC0 || calib == 0x3F) && i < 1000);
	if(i > 1000)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


