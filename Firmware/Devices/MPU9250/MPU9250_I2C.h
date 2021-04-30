/*
 * MPU9250.c
 *
 *  Created on: 30-04-2021
 *      Author: Kunal Salvi
 */

#ifndef MPU9250_MPU9250_H_
#define MPU9250_MPU9250_H_

#include "main.h"
#include "I2C/I2C.h"
#include "MPU9250_REG.h"

#define MPU9250_Address	0x68
//#define MPU9250_Address	0x69    Un-comment to use any of one to use

void MPU9250_Init(I2C_TypeDef *I2C);

void MPU9250_Write_byte(I2C_TypeDef *I2C,uint8_t device_address, uint8_t reg_address, uint8_t data);

void MPU9250_Write_Multiple_Bytes(I2C_TypeDef *I2C,uint8_t device_address, uint8_t reg_address, uint8_t *data, uint16_t length);

uint8_t MPU9250_Read_Byte(I2C_TypeDef *I2C,uint8_t device_address, uint8_t reg_address);

void MPU9250_Read_Multiple_Bytes(I2C_TypeDef *I2C,uint8_t device_address, uint8_t reg_address,uint8_t *data, uint16_t length);

void MPU9250_Read_Accl_Data(I2C_TypeDef *I2C, int16_t *array);

void MPU9250_Read_Gyro_Data(I2C_TypeDef *I2C, int16_t *array);

void MPU9250_Read_Magn_Data(I2C_TypeDef *I2C, int16_t *array);

void MPU9250_Calibrate_Accl(I2C_TypeDef *I2C, uint16_t *array);

void MPU9250_Calibrate_Gyro(I2C_TypeDef *I2C, uint16_t *array);

void MPU9250_Calibrate_Magn(I2C_TypeDef *I2C, uint16_t *array);

#endif /* MPU9250_MPU9250_H_ */
