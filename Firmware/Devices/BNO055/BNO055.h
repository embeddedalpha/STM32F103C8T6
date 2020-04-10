#ifndef _BNO055_H_
#define _BNO055_H_

#include "BNO055_REG1.h"
#include "BNO055_REG2.h"

#include "i2c.h"

#define BNO055_Address	0x28



void BNO055_Init();

void Accelerometer_CONFIG(uint8_t G_Range, uint8_t Bandwidth, uint8_t OpMode);

void Gyroscope_CONFIG(uint8_t G_Range, uint8_t Bandwidth, uint8_t OpMode);

void Magnetometer_CONFIG(uint8_t DataRate, uint8_t OpMode, uint8_t PowerMode);


#endif
