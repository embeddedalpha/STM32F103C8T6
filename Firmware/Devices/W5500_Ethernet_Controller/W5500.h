#ifndef _WS5500_
#define _WS5500_

#include "stm32f10xx.h"
#include "SPI.h"


static SPI_Typedef 

uint16_t address_phase;
uint8_t  control_phase;
uint8_t  data;

#define Higher_Bit_Mask 0xFF00
#define Lower_Bit_Mask  0x00FF

//***********************************************************************************************************************************************
//Control Phase  [BSB4] [BSB3]  [BSB2]  [BSB1]  [BSB0]  [RWB]   [OM1]   [OM2]
//                  7       6       5       4       3       2       1       0

#define Common_Reg  0
//Socket 0 (uint8_t)
#define Socket0_Reg         (uint8_t)1
#define Socket0_TX_Buffer   (uint8_t)2
#define Socket0_RX_Buffer   (uint8_t)3

//Socket 1
#define Socket1_Reg         (uint8_t)5
#define Socket1_TX_Buffer   (uint8_t)6
#define Socket1_RX_Buffer   (uint8_t)7

//Socket 2
#define Socket2_Reg         (uint8_t)9
#define Socket2_TX_Buffer   (uint8_t)10
#define Socket2_RX_Buffer   (uint8_t)11

//Socket 3
#define Socket3_Reg         (uint8_t)13
#define Socket3_TX_Buffer   (uint8_t)14
#define Socket3_RX_Buffer   (uint8_t)15

//Socket 4
#define Socket4_Reg         (uint8_t)17
#define Socket4_TX_Buffer   (uint8_t)18
#define Socket4_RX_Buffer   (uint8_t)19

//Socket 5
#define Socket5_Reg         (uint8_t)21
#define Socket5_TX_Buffer   (uint8_t)22
#define Socket5_RX_Buffer   (uint8_t)23

//Socket 6
#define Socket6_Reg         (uint8_t)25
#define Socket6_TX_Buffer   (uint8_t)26
#define Socket6_RX_Buffer   (uint8_t)27

//Socket 7
#define Socket7_Reg         (uint8_t)29
#define Socket7_TX_Buffer   (uint8_t)30
#define Socket7_RX_Buffer   (uint8_t)31

// Read/Write Access Mode Bit

#define Read_Byte           (uint8_t)0
#define Write_Byte          (uint8_t)4

//SPI Operation Mode Bits

#define VDM                 (uint8_t)0
#define FDM1                (uint8_t)1
#define FDM2                (uint8_t)2
#define FDM3                (uint8_t)3
//***********************************************************************************************************************************************

//***********************************************************************************************************************************************
//Common Register Block

//Offset Address for Common Register
#define Mode    0x0000
//Gateway Address
#define Gateway_Address_0   0x0001
#define Gateway_Address_1   0x0002
#define Gateway_Address_2   0x0003
#define Gateway_Address_3   0x0004

//Subnet Mask Address
#define Subnet_Mask_Address_0 0x0005
#define Subnet_Mask_Address_1 0x0006
#define Subnet_Mask_Address_2 0x0007
#define Subnet_Mask_Address_3 0x0008

//Source Hardware Address
#define Source_Hardware_Address_0 0x0009
#define Source_Hardware_Address_1 0x000a
#define Source_Hardware_Address_2 0x000b
#define Source_Hardware_Address_3 0x000c
#define Source_Hardware_Address_4 0x000d
#define Source_Hardware_Address_5 0x000e

//Source IP Address
#define Source_IP_Address_0 0x000f
#define Source_IP_Address_1 0x0010
#define Source_IP_Address_2 0x0011
#define Source_IP_Address_3 0x0012

//Interrupt Low Level Timer
#define Interrupt_Low_Level_Timer_0   0x0013
#define Interrupt_Low_Level_Timer_1   0x0014

//Interrupt 
#define Interrupt_W5500     0x0015

//Interrupt Mask 
#define Interrupt_Mask      0x0016

//Socket Interrupt 
#define Socket_Interrupt    0x0017

//Socket_Interrupt_Mask
#define Socket_Interrupt_Mask 0x0018

//Retry Time
#define Retry_Time_0 0x0019
#define Retry Time_1 0x001a

//Retry Count 
#define Retry_Count 0x001b

//PPP LCP Request Timer
#define PPP_LCP_Request_Timer   0x1c

//PPP LCP Magic number
#define PPP_LCP_Magic_number    0x1d

//PPP Destination MAC Address
#define PPP_Destination_MAC_Address_0 0x1e
#define PPP_Destination_MAC_Address_1 0x1f
#define PPP_Destination_MAC_Address_2 0x20
#define PPP_Destination_MAC_Address_3 0x21
#define PPP_Destination_MAC_Address_4 0x22
#define PPP_Destination_MAC_Address_5 0x23

//PPP Session Identification
#define PPP_Session_Identification_0  0x24
#define PPP_Session_Identification_1  0x25

//PPP Maximum Segment Size
#define PPP_Maximum_Segment_Size_0    0x26
#define PPP_Maximum_Segment_Size_1    0x27

//Unreachable IP address
#define Unreachable_IP_address_0    0x28
#define Unreachable_IP_address_1    0x29
#define Unreachable_IP_address_2    0x2a
#define Unreachable_IP_address_3    0x2b

//Unreachable Port
#define Unreachable_Port_0  0x002c
#define Unreachable_Port_1  0x002d

//PHY Configuration
#define PHY_Configuration  0x002e

//Chip Version
#define Chip_Version    0x0039
//***********************************************************************************************************************************************

//***********************************************************************************************************************************************
//Socket Register Block

//Offset Address in Socket n Register Block (0≤n≤7)

//Socket n Mode
#define Socket_n_Mode    0x0000

//Socket n Command 
#define Socket_n_Command    0x0001

//Socket n Interrupt  
#define Socket_n_Interrupt    0x0002

//Socket n Status
#define Socket_n_Status   0x0003

//Socket n Source Port
#define Socket_n_Source_Port_0   0x0004
#define Socket n Source Port_1   0x0005

//Socket n Destination Hardware Address


void W5500_Write(uint16_t address_phase, uint8_t control_phase, uint8_t data[] );

#endif
