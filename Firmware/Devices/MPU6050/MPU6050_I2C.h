/*
 * MPU6050.h
 *
 *  Created on: 26-Apr-2021
 *      Author: Kunal
 */

#ifndef MPU6050_MPU6050_I2C_H_
#define MPU6050_MPU6050_I2C_H_

#include "main.h"
#include "GPIO/GPIO.h"
#include "I2C/I2C.h"


void MPU6050_Init(I2C_TypeDef *I2C);

short *MPU6050_Get_Raw_Data(I2C_TypeDef *I2C);




#endif /* MPU6050_MPU6050_I2C_H_ */
