void BNO055_Get_Accl_Raw(uint8_t *accl)
{
	short i = 0;
	unit8_t a[6];
	BNO055_Read_Buffer(ACC_DATA_X_LSB, a, 6);
	for(i = 0; i < 4; i++)
	{
		accl[i] = (short)((a[i*2+1] << 8) | a[i*2]);
	}
}

void BNO055_Get_Gyro_Raw(uint8_t *gyro)
{
	short i = 0;
	unit8_t a[6];
	BNO055_Read_Buffer(GYR_DATA_X_LSB, a, 6);
	for(i = 0; i < 4; i++)
	{
		gyro[i] = (short)((a[i*2+1] << 8) | a[i*2]);
	}
}

void BNO055_Get_Magn_Raw(uint8_t *magn)
{
	short i = 0;
	unit8_t a[6];
	BNO055_Read_Buffer(MAG_DATA_X_LSB, a, 6);
	for(i = 0; i < 4; i++)
	{
		magn[i] = (short)((a[i*2+1] << 8) | a[i*2]);
	}
}
