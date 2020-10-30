#ifndef _MPU6050_H_
#define _MPU6050_H_




#include "stm32f10x.h"
#include "board.h"
#include "SPI.h"



#define ACCEL_X_HIGH	0x3B
#define ACCEL_X_LOW 	0x3C
#define ACCEL_Y_HIGH	0x3D
#define ACCEL_Y_LOW 	0x3E
#define ACCEL_Z_HIGH	0x3F
#define ACCEL_Z_LOW 	0x40

#define GYRO_X_HIGH	    0x43
#define GYRO_X_LOW 	    0x44
#define GYRO_Y_HIGH	    0x45
#define GYRO_Y_LOW 	    0x46
#define GYRO_Z_HIGH	    0x47
#define GYRO_Z_LOW 	    0x48

#define TEMP_X_HIGH	    0x41
#define TEMP_X_LOW 	    0x42

int power(float base, uint8_t exp);

void MPU6050_SPI_Init(void);
int MPU6050_Self_Test_Gyro(void);
void MPU6050_Write_Single_Byte(uint8_t address,uint8_t data);
uint8_t MPU6050_Read_Single_Byte(uint8_t address);
uint16_t *MPU6050_Gyro_Raw(void);
uint16_t *MPU6050_Accl_Raw(void);
uint16_t *MPU6050_Temp_Raw(void);
void MPU6050_Reset(void);
void MPU6050_Sleep_Enable(void);
void MPU6050_Sleep_Disable(void);
void MPU6050_FIFO_Enable(void);
uint16_t MPU6050_Read_FIFO(void);




#endif
