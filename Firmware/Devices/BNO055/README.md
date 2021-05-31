# BNO055 Drvier v1
### Created on 30 May 2021

#### Datasheet: https://cdn-shop.adafruit.com/datasheets/BST_BNO055_DS000_12.pdf

#### Functions for data trasnfer and initializations 
```C
void BNO055_Init(I2C_TypeDef *I2C);
int BNO055_Calibrate(void);
void BNO055_Read_Buffer(uint8_t reg, uint8_t *data, int len);
void BNO055_Write_Buffer(unit8_t reg, uint8_t *data, int len);
void BNO055_Write_Single(unit8_t reg, unit8_t data);
unit8_t BNO055_Read_Single(unit8_t reg);
void BNO055_Get_Euler_Angles(short *eu);
void BNO055_Get_Quaternion_Angles(short *qu);
void BNO055_Get_Linear_Accl(short *la);
void BNO055_Get_Gravity_Vector(short *gv);
uint8_t BNO055_Get_Chip_ID(void);
uint8_t BNO055_Get_MAG_ID(void);
uint8_t BNO055_Get_ACC_ID(void);
uint8_t BNO055_Get_GYR_ID(void);
uint8_t BNO055_Temp(void);
void BNO055_Get_Accl_Raw(uint8_t *accl);
void BNO055_Get_Gyro_Raw(uint8_t *gyro);
void BNO055_Get_Magn_Raw(uint8_t *magn);
```

#### As STM32F103C8T6 has 2 I2C hardware blocks, the user can pass either I2C1 or I2C2 in BNO055_Init function to initialize BNO055

```c
BNO055_Init(I2C1);
```

#### By default, NDOF mode is enabled by BNO055 (can be changed to different mode and will be added soon).

#### To get raw values from device:

```c
uint8_t acc[6], gyro[6], magn[6];
BNO055_Get_Accl_Raw(accl);
BNO055_Get_Gyro_Raw(gyro);
BNO055_Get_Magn_Raw(magn);
```

##### To get Euler Angles:
```C
short eu[3];
BNO055_Init(I2C1);
BNO055_Get_Euler_Angles(eu);
```

##### To get Quaternion Angles:
```C
short qu[4];
BNO055_Init(I2C1);
BNO055_Get_Quaternion_Angles(qu);
```

##### To get Linear Accleration:
```C
short la[3];
BNO055_Init(I2C1);
BNO055_Get_Linear_Accl(la);
```

##### To get Gravity Vector:
```C
short gv[3];
BNO055_Init(I2C1);
BNO055_Get_Gravity_Vector(gv);
```
