#include "RFID.h"

void RFID_SPI_Init(void)
{

	SPI_Master_Init(SPI1,0,0,8,1,8);
	SPI1_Pin_Config_PortA();

}
	
