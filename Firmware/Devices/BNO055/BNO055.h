/*
 * BNO055.h
 *
 *  Created on: 30-May-2021
 *  Updated on: 31-May-2021
 *      Author: Kunal
 */

#ifndef BNO055_BNO055_H_
#define BNO055_BNO055_H_

#include "main.h"
#include "I2C/I2C.h"
#include "BNO055_REG1.h"
#include "BNO055_REG2.h"

struct I2C_Config BNO055;

void BNO055_Init(I2C_TypeDef *I2C);

void BNO055_Read_Buffer(uint8_t reg, uint8_t *data, int len);

void BNO055_Write_Buffer(unit8_t reg, uint8_t *data, int len);

void BNO055_Write_Single(unit8_t reg, unit8_t data);

unit8_t BNO055_Read_Single(unit8_t reg);

void BNO055_Get_Euler_Angles(short *eu);

void BNO055_Get_Quaternion_Angles(short *qu);

void BNO055_Get_Linear_Accl(short *la);

void BNO055_Get_Gravity_Vector(short *gv);
#endif /* BNO055_BNO055_H_ */
