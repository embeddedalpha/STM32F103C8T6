#ifndef _BNO055_H_
#define _BNO055_H_

#include "BNO055_REG1.h"
#include "BNO055_REG2.h"
#include "i2c.h"

#define BNO055_Address	0x28

#define BNO055_Normal_Mode 0x00
#define BNO055_Low_Normal_Mode 0x01
#define BNo055_Suspend_Mode 0x02



uint8_t BNO055_Buffer[10];

float BNO055_QUATERNION_Buffer[4];
float BNO055_GRAVITY_VECTOR_Buffer[3];
float BNO055_LINEAR_ACCL_Buffer[3];
float BNO055_EULER_ANGLE_Buffer[3];
float BNO055_COMPASS_DATA_Buffer[3];
float BNO055_IMU_DATA_Buffer[3];
float BNO055_M4G_DATA_Buffer[3];
float BNO055_NDOF_DATA_Buffer[3];

float BNO055_GYRO_DATA_Buffer[3];
float BNO055_ACCL_DATA_Buffer[3];
float BNO055_MAG_DATA_Buffer[3];


void BNO055_Init();
void BNO055_Write(uint8_t reg, uint8_t data);
void BNO055_Read(uint8_t reg, uint8_t bytes);
void BNO055_Power_Mode(uint8_t mode);


void BNO055_GET_Quaternion_DATA(void);
void BNO055_GET_Euler_DATA(void);
void BNO055_GET_Gravity_Vector_DATA(void);
void BNO055_GET_Linear_Acceleration_DATA(void);
void BNO055_GET_Compass_DATA(void);
void BNO055_GET_GYRO_DATA(void);
void BNO055_GET_ACCL_DATA(void);
void BNO055_GET_MAG_DATA(void);



#endif
