#ifndef _SD_H_
#define _SD_H_

#include "stm32f10x.h"
#include "SPI.h"
#include "board.h"


//https://openlabpro.com/guide/raw-sd-readwrite-using-pic-18f4550/
//https://openlabpro.com/guide/interfacing-microcontrollers-with-sd-card/
//http://www.rjhcoding.com/avrc-sd-interface-3.php
//http://users.ece.utexas.edu/~valvano/EE345M/SD_Physical_Layer_Spec.pdf


#define CMD0	(0 + 64)
#define CMD1	(1 + 64)
#define CMD8	(8 + 64)
#define CMD9	(9 + 64)
#define CMD10	(10 + 64)
#define CMD12	(12 + 64)
#define CMD16	(16 + 64)
#define CMD17	(17 + 64)
#define CMD18	(18 + 64)
#define CMD23	(23 + 64)
#define CMD24	(24 + 64)
#define CMD25	(25 + 64)
#define CMD55	(55 + 64)
#define CMD58	(58 + 64)

#define ACMD41  41
#define ACMD23  23

#define SD_Idle                 (1 << 0)
#define SD_Erase_Reset          (1 << 1)
#define SD_Illegal_Command      (1 << 2)
#define SD_Command_CRC_Error    (1 << 3)
#define SD_Erase_Sequence_Error (1 << 4)
#define SD_Address_Error        (1 << 5)
#define SD_Parameter_Error      (1 << 6)

#define SD_CRC 0x95

//Set 400KHz sclk

void SD_Send_Commands(uint8_t command, unsigned long arg, uint8_t sdCRC);
void SD_Init(void);
int SD_Respose(void);
int SD_Write_Data(char *filepath, char *filename, char *data);
char * SD_Read_Data(char *filepath, char *filename);
char * SD_List_Files_in_Directory(char *directory);











#endif
