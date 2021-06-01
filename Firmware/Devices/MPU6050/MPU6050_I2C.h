/*
 * MPU6050.h
 *
 *  Created on: 25-Apr-2021
 *      Author: Kunal Salvi
 */

#ifndef MPU6050_MPU6050_I2C_H_
#define MPU6050_MPU6050_I2C_H_

#include "main.h"
#include "GPIO/GPIO.h"
#include "I2C/I2C.h"
#include "MPU6050_Reg.h"

struct I2C_Config MPU6050;
#define MPU6050_Dev_Add	0x78

void MPU6050_I2C_Init(I2C_TypeDef *I2C);
void MPU6050_I2C_Write_Single(uint8_t reg, uint8_t data);
void MPU6050_I2C_Write_Burst(uint8_t reg, unit8_t *data, int len);
unit8_t MPU6050_I2C_Read_Single(uint8_t reg);
void MPU6050_I2C_Read_Burst(uint8_t reg, unit8_t *data, int len);
void MPU6050_I2C_Get_Raw_Data(uint16_t *accl_x,
		                  uint16_t *accl_y,
						  uint16_t *accl_z,
						  uint16_t *gyro_x,
						  uint16_t *gyro_y,
						  uint16_t *gyro_z);
void MPU6050_I2C_Get_Filtered_Data(uint16_t *accl_x,
                                   uint16_t *accl_y,
		                           uint16_t *accl_z,
		                           uint16_t *gyro_x,
		                           uint16_t *gyro_y,
		                           uint16_t *gyro_z);


#endif /* MPU6050_MPU6050_I2C_H_ */
