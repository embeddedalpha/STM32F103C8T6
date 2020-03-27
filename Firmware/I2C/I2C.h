/**********************************************************************************************************************************
@file:    I2C.H
@author:  Kunal Salvi
@version: V3.05.0
@date:    27/3/2020
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
#define i2c_device_write 0
#define i2c_device_read  1

I2C_TypeDef *I2C;

/***************************************** Initialization Mode *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: none
//@return: none
********************************************************************************************************************************/

void I2C_Master_Init(void);


/***************************************** Generate Start Condition *****************************************************************
//@brief: The function generates a start condition.
//@param: none
//@return: none
********************************************************************************************************************************/

void I2C_Master_Start(void);



/***************************************** Read Address *****************************************************************
//@brief: The function sends device address as read command.
//@param:
//        data          device address
//@return: none
********************************************************************************************************************************/

void I2C_Master_Address_Read(uint8_t data);



/***************************************** Write Address *****************************************************************
//@brief: The function sends device address as write command.
//@param:
//        data          device address
//@return: none
********************************************************************************************************************************/

void I2C_Master_Address_Write(uint8_t data);




/***************************************** Send Data *****************************************************************
//@brief: The function sends data onto the I2C bus.
//@param:
//        data          data to be sent
//@return: none
********************************************************************************************************************************/

void I2C_Master_Send_Data( uint8_t data);


/***************************************** Read Data *****************************************************************
//@brief: The function receives data from the I2C bus.
//@param: none
//@return: data from the device
********************************************************************************************************************************/

int I2C_Master_Rx_Data(void);



/***************************************** Stops Transfer  *****************************************************************
//@brief: The function terminates all transfers.
//@param: none
//@return: none
********************************************************************************************************************************/

void I2C_Master_Stop(void);




#endif
