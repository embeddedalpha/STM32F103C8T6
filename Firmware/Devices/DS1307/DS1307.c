#include "DS1307.h"



/***************************************** DS1307 Init *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
// 							I2C2
//@return: none
********************************************************************************************************************************/

void DS1307_Init(I2C_TypeDef *I2C)
{
	I2C_Master_Init(I2C,I2C_FS_Mode);
	I2C_Master_Start(I2C);
	I2C_Master_Address_Send(I2C,DS1307_Write);
	I2C_Master_Send_Data(I2C,0x00);
	I2C_Master_Send_Data(I2C,0x00);
	I2C_Master_Stop(I2C);

}


/***************************************** DS1307 Set Date & Time *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
// 							I2C2
//        DS1307_RTC -> RTC structure
//@return: none
********************************************************************************************************************************/

void DS1307_Set_Date_Time(I2C_TypeDef *I2C,DS1307_RTC *rtc)
{
	I2C_Master_Start(I2C);
	I2C_Master_Address_Send(I2C,DS1307_Write);
	I2C_Master_Send_Data(I2C,0x00);
	I2C_Master_Send_Data(I2C,rtc->seconds);
	I2C_Master_Send_Data(I2C,rtc->minutes);
	I2C_Master_Send_Data(I2C,rtc->hour);

	I2C_Master_Send_Data(I2C,rtc->weekday);

	I2C_Master_Send_Data(I2C,rtc->date);
	I2C_Master_Send_Data(I2C,rtc->month);
	I2C_Master_Send_Data(I2C,rtc->year);

	I2C_Master_Stop(I2C);
}


/***************************************** DS1307 Get Date & Time *****************************************************************
//@brief: The function sets up the I2C controller in Master mode.
//@param: I2C_TypeDef -> 	I2C1
// 							I2C2
//        DS1307_RTC -> RTC structure
//@return: none
********************************************************************************************************************************/

void DS1307_Get_Date_Time(I2C_TypeDef *I2C,DS1307_RTC *rtc)
{
	I2C_Master_Start(I2C);
	I2C_Master_Address_Send(I2C,DS1307_Read);
	I2C_Master_Send_Data(I2C,0x00);
	I2C_Master_Send_Data(I2C,rtc->seconds);
	I2C_Master_Send_Data(I2C,rtc->minutes);
	I2C_Master_Send_Data(I2C,rtc->hour);

	I2C_Master_Send_Data(I2C,rtc->weekday);

	I2C_Master_Send_Data(I2C,rtc->date);
	I2C_Master_Send_Data(I2C,rtc->month);
	I2C_Master_Send_Data(I2C,rtc->year);

	I2C_Master_Stop(I2C);

}
