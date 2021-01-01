#include "stm32f10x.h"
#include "DS1307.h"



int main(void)
{

	DS1307_RTC DS1307RTC;

	DS1307_Init(I2C1);

	DS1307RTC.hour = 0x10; //10:40:00
	DS1307RTC.minutes = 0x40;
	DS1307RTC.seconds = 0x00;
	DS1307RTC.day = 0x01;
	DS1307RTC.month = 0x01;
	DS1307RTC.year = 0x21;
	DS1307RTC.weekday = 6;
	DS1307_Set_Date_Time(I2C1,&DS1307RTC);


    while(1)
    {
    	DS1307_Set_Date_Time(I2C1,&DS1307RTC);
    }

    return 0;
}

