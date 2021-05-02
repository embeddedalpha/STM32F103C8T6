/*
 * MPU6050_SPI.h
 *
 *  Created on: May 02, 2021
 *      Author: Kunal Salvi
 */

#ifndef MPU6050_MPU6050_SPI_H_
#define MPU6050_MPU6050_SPI_H_

#include "main.h"
#include "GPIO/GPIO.h"
#include "SPI/SPI.h"

struct SPI_Config MPU6050;


void MPU6050_SPI_Init(SPI_TypeDef *SPI);

void PU6050_SPI_Get_Raw_Data(short *mp);

void MPU6050_SPI_Read(uint8_t address, uint8_t *array,int length);

#endif /* MPU6050_MPU6050_SPI_H_ */
