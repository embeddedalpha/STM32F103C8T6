#ifndef _BNO055_REG_1_H_
#define _BNO055_REG_1_H_

//READ WRITE

#define MAG_RADIUS_MSB	0x6a
#define MAG_RADIUS_LSB  0x69

#define ACC_RADIUS_MSB	0x68
#define ACC_RADIUS_LSB	0x67

//GYROSCOPE OFFSET
#define GYR_OFFSET_Z_MSB	0x66
#define GYR_OFFSET_Z_LSB	0x65
#define GYR_OFFSET_Y_MSB	0x64
#define GYR_OFFSET_Y_LSB	0x63
#define GYR_OFFSET_X_MSB	0x62
#define GYR_OFFSET_X_LSB	0x61

//MAGNETOMETER OFFSET
#define MAG_OFFSET_Z_MSB	0x60
#define MAG_OFFSET_Z_LSB	0x5F
#define MAG_OFFSET_Y_MSB	0x5E
#define MAG_OFFSET_Y_LSB	0x5D
#define MAG_OFFSET_X_MSB	0x5C
#define MAG_OFFSET_X_LSB	0x5B

//ACCELEROMETER OFFSET
#define ACC_OFFSET_Z_MSB	0x5A
#define ACC_OFFSET_Z_LSB	0x59
#define ACC_OFFSET_Y_MSB	0x58
#define ACC_OFFSET_Y_LSB	0x57
#define ACC_OFFSET_X_MSB	0x56
#define ACC_OFFSET_X_LSB	0x55

#define AXIS_MAP_SIGN		0x42
#define AXIS_MAP_CONFIG		0x41
#define TEMP_SOURCE	        0x40
#define SYS_TRIGGER      	0x3F
#define PWR_MODE      	    0x3E
#define OPR_MODE			0x3D
#define UNIT_SEL			0x3B
#define SYS_ERR				0x3A
#define SYS_STATUS			0x39
#define SYS_CLK_STATUS		0x38
#define INT_STA				0x37
#define ST_RESULT			0x36
#define CALIB_STAT			0x35
#define TEMP				0x34

//GRAVITY VECTOR DATA
#define GRV_Data_Z_MSB      0x33
#define GRV_Data_Z_LSB      0x32
#define GRV_Data_Y_MSB      0x31
#define GRV_Data_Y_LSB      0x30
#define GRV_Data_X_MSB      0x2F
#define GRV_Data_X_LSB      0x2E

//LINEAR ACCELERATION DATA
#define LIA_Data_Z_MSB      0x2D
#define LIA_Data_Z_LSB      0x2C
#define LIA_Data_Y_MSB      0x2B
#define LIA_Data_Y_LSB      0x2A
#define LIA_Data_X_MSB      0x29
#define LIA_Data_X_LSB      0x28

//QUATERNION DATA
#define QUA_Data_Z_MSB      0x27
#define QUA_Data_Z_LSB      0x26
#define QUA_Data_Y_MSB      0x25
#define QUA_Data_Y_LSB      0x24
#define QUA_Data_X_MSB      0x23
#define QUA_Data_X_LSB      0x22
#define QUA_Data_W_MSB      0x21
#define QUA_Data_W_LSB      0x20

//EULER DATA
#define EUL_Pitch_MSB		0x1F
#define EUL_Pitch_LSB		0x1E
#define EUL_Roll_MSB		0x1D
#define EUL_Roll_LSB		0x1C
#define EUL_Heading_MSB		0x1B
#define EUL_Heading_LSB		0x1A

//GYROSCOPE DATA
#define GYR_DATA_Z_MSB		0x19
#define GYR_DATA_Z_LSB		0x18
#define GYR_DATA_Y_MSB		0x17
#define GYR_DATA_Y_LSB		0x16
#define GYR_DATA_X_MSB		0x15
#define GYR_DATA_X_LSB		0x14

//MAGNETOMETER DATA
#define MAG_DATA_Z_MSB		0x13
#define MAG_DATA_Z_LSB		0x12
#define MAG_DATA_Y_MSB		0x11
#define MAG_DATA_Y_LSB		0x10
#define MAG_DATA_X_MSB		0x0F
#define MAG_DATA_X_LSB		0x0E

//ACCELEROMETER DATA
#define ACC_DATA_Z_MSB		0x0D
#define ACC_DATA_Z_LSB		0x0C
#define ACC_DATA_Y_MSB		0x0B
#define ACC_DATA_Y_LSB		0x0A
#define ACC_DATA_X_MSB		0x09
#define ACC_DATA_X_LSB		0x08

#define PAGE_ID				0x07
#define BL_Rev_ID 			0x06
#define SW_REV_ID_MSB		0x05
#define SW_REV_ID_LSB 		0x04
#define GYR_ID				0x03
#define MAG_ID 			    0x02
#define ACC_ID				0x01
#define CHIP_ID				0x00

#endif

