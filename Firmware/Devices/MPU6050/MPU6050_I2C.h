/*
 * MPU6050.h
 *
 *  Created on: 25-Apr-2021
 *      Author: Kunal
 */

#ifndef MPU6050_MPU6050_I2C_H_
#define MPU6050_MPU6050_I2C_H_

#include "main.h"
#include "GPIO/GPIO.h"
#include "I2C/I2C.h"


void MPU6050_Init(I2C_TypeDef *I2C);

short * MPU6050_Get_Data(void);




#endif /* MPU6050_MPU6050_I2C_H_ */
