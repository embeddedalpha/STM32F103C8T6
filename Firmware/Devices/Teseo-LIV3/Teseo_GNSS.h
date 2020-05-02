
#ifndef _GNSS_H_
#define _GNSS_H_



#include "stm32f10x.h"
#include "board.h"
#include "Debug.h"
#include "Teseo_GNSS_MSG_File.h"

void Teseo_GNSS_Init(void);

void Teseo_GNSS_ST_AGNSS(void);

void Teseo_GNSS_Predictive_AGNSS(void);

void Teseo_GNSS_RealTime_AGNSS(void);

void Teseo_GNSS_Geofencing(uint8_t circle_number, float radius[8]);

void Teset_GNSS_Odometer(void);

char GNSS_Get_Status(void)
{
	printConsole("$PSTMNMEAREQUEST,100000,");
}













#endif
