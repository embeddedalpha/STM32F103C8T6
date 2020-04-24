#ifndef _BNO055_H_
#define _BNO055_H_

#include "BNO055_REG1.h"
#include "BNO055_REG2.h"

#include "i2c.h"

#define BNO055_Address	0x28

#define BNO055_Normal_Mode 0x00
#define BNO055_Low_Normal_Mode 0x01
#define BNo055_Suspend_Mode 0x02



void BNO055_Init();

void Accelerometer_CONFIG(uint8_t G_Range, uint8_t Bandwidth, uint8_t OpMode);

void Gyroscope_CONFIG(uint8_t G_Range, uint8_t Bandwidth, uint8_t OpMode);

void Magnetometer_CONFIG(uint8_t DataRate, uint8_t OpMode, uint8_t PowerMode);

void BNO055_Write(uint8_t reg, uint8_t data);

void BNO055_Read(uint8_t reg, uint8_t bytes);

#endif
