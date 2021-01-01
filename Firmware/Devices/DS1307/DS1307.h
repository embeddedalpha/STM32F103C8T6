#ifndef	_DS1307_H_
#define _DS1307_H_


#include "stm32f10x.h"
#include "board.h"
#include "I2C.h"


#define DS1307_Read		0xD1
#define DS1307_Write	0xD0


typedef struct{
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hour;
	uint8_t weekday;
	uint8_t date;
	uint8_t month;
	uint8_t year;
}DS1307_RTC;


/***************************************** DS1307 Init *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
// 							I2C2
//@return: none
********************************************************************************************************************************/

void DS1307_Init(I2C_TypeDef *I2C);


/***************************************** DS1307 Set Date & Time *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
// 							I2C2
//        DS1307_RTC -> RTC structure
//@return: none
********************************************************************************************************************************/

void DS1307_Set_Date_Time(I2C_TypeDef *I2C,DS1307_RTC *rtc);


/***************************************** DS1307 Get Date & Time *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
// 							I2C2
//        DS1307_RTC -> RTC structure
//@return: none
********************************************************************************************************************************/

void DS1307_Get_Date_Time(I2C_TypeDef *I2C,DS1307_RTC *rtc);





#endif
