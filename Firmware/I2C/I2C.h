/**********************************************************************************************************************************
@file:    I2C.H
@author:  Kunal Salvi
@version: V5.0.0
@date:    1/1/2021
@brief:   I2C Header File.
          This file contains the prototype of functions in I2C.c file.
          By calling various functions, the user can configure
          the I2C Hardware Peripheral in any of the permitted modes.
@attention: This file aims at providing the user an abstraction layer to the I2C peripheral
            and is tested on STM32f103C8T6. This file is free for use to any person or corporation.
            In case of failure of code/product due to third party tampering, the author will not be
            responsible. This code is published under MIT License.
**********************************************************************************************************************************/

#ifndef _I2C_H_
#define _I2C_H_


#include "stm32f10x.h"
#include "board.h"


#define I2C_SM_Mode	1
#define I2C_FS_Mode	2

/***************************************** Initialization Mode *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
 * 		          I2C2
 *        mode ->		I2C_SM_Mode
 * 		  	I2C_FM_Mode
//@return: none
********************************************************************************************************************************/

void I2C_Master_Init(I2C_TypeDef *I2C,uint8_t mode);



/***************************************** Master Start *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
// 			I2C2
//@return: none
********************************************************************************************************************************/

void I2C_Master_Start(I2C_TypeDef *I2C);



/***************************************** Master Send Address *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
// 			I2C2
//        data  ->     ~
//@return: none
********************************************************************************************************************************/

void I2C_Master_Address_Send(I2C_TypeDef *I2C, uint8_t data);



/***************************************** Master Send Data *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
// 			I2C2
//        data	->     ~
//@return: none
********************************************************************************************************************************/

void I2C_Master_Send_Data(I2C_TypeDef *I2C, uint8_t data);



/***************************************** Master Receive Data *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
// 			I2C2
//@return: RX_Data
********************************************************************************************************************************/

uint8_t I2C_Master_Rx_Data(I2C_TypeDef *I2C);



/***************************************** Master Stop *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
// 			I2C2
//@return: none
********************************************************************************************************************************/

void I2C_Master_Stop(I2C_TypeDef *I2C);



#endif
