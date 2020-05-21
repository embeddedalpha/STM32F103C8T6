#include "stm32f10x.h"
#include "board.h"
#include "SPI.h"
#include "W25QxxFLASH.h"
#include "data.h"
#include <stdio.h>



int main(void)
{

	W25Qx_Init();
	int length = sizeof(y)/sizeof(data[0]);
	int increment = length /256;

	for(int i = 0; i<increment; i++)
	{
		for(int j = 0; j < 256; j++){
			flash_data_TX[i] = data[j + (i*256)];
		}
		 W25Qx_Write_Flash((i*256),255);
	}

    while(1)
    {
    }
}


