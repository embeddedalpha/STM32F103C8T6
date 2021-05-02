/*
 * MPU6050_SPI.h
 *
 *  Created on: 01-May-2021
 *      Author: Kunal
 */

#ifndef MPU6050_MPU6050_SPI_H_
#define MPU6050_MPU6050_SPI_H_

#include "main.h"
#include "GPIO/GPIO.h"
#include "SPI/SPI.h"

struct SPI_Config MPU6050;


void MPU6050_Init(SPI_Config *SPI);

short * MPU6050_Get_Raw_Data(void);

#endif /* MPU6050_MPU6050_SPI_H_ */

