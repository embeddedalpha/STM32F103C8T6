/*
 * BNO055.h
 *
 *  Created on: 30-May-2021
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


#endif /* BNO055_BNO055_H_ */
