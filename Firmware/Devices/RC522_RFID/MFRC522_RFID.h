#ifndef _RC552_RFID_H_
#define _RC552_RFID_H_


//1. VCC
//2. RST
//3. GND
//4. IRQ
//5. MISO
//6. MOSI
//7. SCK
//8. SS


#include "stm32f10x.h"
#include "stdbool.h"
#include "SPI.h"
#include "board.h"

struct Command_and_Status
{
	uint8_t		CommandReg				= 0x01 ;	// starts and stops command execution
	uint8_t		ComIEnReg				= 0x02 ;	// enable and disable interrupt request control bits
	uint8_t		DivIEnReg				= 0x03 ;	// enable and disable interrupt request control bits
	uint8_t		ComIrqReg				= 0x04 ;	// interrupt request bits
	uint8_t		DivIrqReg				= 0x05 ;	// interrupt request bits
	uint8_t		ErrorReg				= 0x06 ;	// error bits showing the error status of the last command executed
	uint8_t		Status1Reg				= 0x07 ;	// communication status bits
	uint8_t		Status2Reg				= 0x08 ;	// receiver and transmitter status bits
	uint8_t		FIFODataReg				= 0x09 ;	// input and output of 64 byte FIFO buffer
	uint8_t		FIFOLevelReg			= 0x0A ;	// number of bytes stored in the FIFO buffer
	uint8_t		WaterLevelReg			= 0x0B ;	// level for FIFO underflow and overflow warning
	uint8_t		ControlReg				= 0x0C ;	// miscellaneous control registers
	uint8_t		BitFramingReg			= 0x0D ;	// adjustments for bit-oriented frames
	uint8_t		CollReg					= 0x0E ;	//bit position of the first bit-collision detected on the RF interface
}Command_and_Status;


struct Command
{
	uint8_t		ModeReg 				= 0x11;		//defines general modes for transmitting and receiving
	uint8_t		TxModeReg  				= 0x11;		//defines transmission data rate and framing
	uint8_t		RxModeReg   			= 0x11;		//defines reception data rate and framing
	uint8_t		TxControlReg 			= 0x11;		//controls the logical behavior of the antenna driver pins TX1 and TX2
	uint8_t		TxASKReg 				= 0x11;		//controls the setting of the transmission modulation Table 63 on page 51
	uint8_t		TxSelReg 				= 0x11;		//selects the internal sources for the antenna driver Table 65 on page 51
	uint8_t		RxSelReg 				= 0x11;		//selects internal receiver settings Table 67 on page 52
	uint8_t		RxThresholdReg 			= 0x11;		//selects thresholds for the bit decoder Table 69 on page 53
	uint8_t		DemodReg 				= 0x11;		//defines demodulator settings Table 71 on page 53
	uint8_t		MfTxReg 				= 0x11;		//controls some MIFARE communication transmit parameters Table 77 on page 55
	uint8_t		MfRxReg 				= 0x11;		//controls some MIFARE communication receive parameters Table 79 on page 55
	uint8_t		SerialSpeedReg			= 0x11;		//selects the speed of the serial UART interface
}Command;



struct Configuration
{
	uint8_t		CRCResultRegH			= 0x21 ;	// shows the MSB and LSB values of the CRC calculation
	uint8_t		CRCResultRegL			= 0x22 ;
	uint8_t		ModWidthReg				= 0x24 ;	// controls the ModWidth setting?
	uint8_t		RFCfgReg				= 0x26 ;	// configures the receiver gain
	uint8_t		GsNReg					= 0x27 ;	// selects the conductance of the antenna driver pins TX1 and TX2 for modulation
	uint8_t		CWGsPReg				= 0x28 ;	// defines the conductance of the p-driver output during periods of no modulation
	uint8_t		ModGsPReg				= 0x29 ;	// defines the conductance of the p-driver output during periods of modulation
	uint8_t		TModeReg				= 0x2A ;	// defines settings for the internal timer
	uint8_t		TPrescalerReg			= 0x2B ;	// the lower 8 bits of the TPrescaler value. The 4 high bits are in TModeReg.
	uint8_t		TReloadRegH				= 0x2C ;	// defines the 16-bit timer reload value
	uint8_t		TReloadRegL				= 0x2D ;
	uint8_t		TCounterValueRegH		= 0x2E ;	// shows the 16-bit timer value
	uint8_t		TCounterValueRegL		= 0x2F ;
}Configuration;


struct Test_Register
{
	uint8_t		TestSel1Reg				= 0x31 ;	// general test signal configuration
	uint8_t		TestSel2Reg				= 0x32 ;	// general test signal configuration
	uint8_t		TestPinEnReg			= 0x33 ;	// enables pin output driver on pins D1 to D7
	uint8_t		TestPinValueReg			= 0x34 ;	// defines the values for D1 to D7 when it is used as an I/O bus
	uint8_t		TestBusReg				= 0x35 ;	// shows the status of the internal test bus
	uint8_t		AutoTestReg				= 0x36 ;	// controls the digital self-test
	uint8_t		VersionReg				= 0x37 ;	// shows the software version
	uint8_t		AnalogTestReg			= 0x38 ;	// controls the pins AUX1 and AUX2
	uint8_t		TestDAC1Reg				= 0x39 ;	// defines the test value for TestDAC1
	uint8_t		TestDAC2Reg				= 0x3A ;	// defines the test value for TestDAC2
	uint8_t		TestADCReg				= 0x3B ;	// shows the value of ADC I and Q channels
}Test_Register;


struct General_Command {
	uint8_t 	Idle 					= 0b0000; 	//no action, cancels current command execution
	uint8_t		Mem  					= 0b0001; 	//stores 25 bytes into the internal buffer
	uint8_t		Generate_RandomID 		= 0b0010; 	//generates a 10-byte random ID number
	uint8_t		CalcCRC 				= 0b0011; 	//activates the CRC co-processor or performs a self test
	uint8_t		Transmit 				= 0b0100;	//transmits data from the FIFO buffer
	uint8_t		NoCmdChange 			= 0b0111; 	//no command change, can be used to modify the CommandReg register bits without affecting the command, for example, the PowerDown bit
	uint8_t		Receive  				= 0b1000; 	//activates the receiver circuits
	uint8_t		Transceive 				= 0b1100; 	//transmits data from FIFO buffer to antenna and automatically activates the receiver after transmission
	uint8_t		MFAuthent 				= 0b1110; 	//performs the MIFARE standard authentication as a reader
	uint8_t		SoftReset 				= 0b1111; 	//resets the MRFC522
}GeneralCommand;

#define PowerDown								1<<4
#define Analog_Receiver_Off						1<<5
#define Analog_Receiver_ON						0<<5


#define Allow_Transmitter_Interrupt_Request		1<<6
#define Deny_Transmitter_Interrupt_Request		0<<6
#define Allow_Receiver_Interrupt_Request		1<<5
#define Deny_Receiver_Interrupt_Request			0<<5
#define Allow_Idle_Interrupt_Request			1<<4
#define Deny_Idle_Interrupt_Request				0<<4
#define Allow_High_Alert_Interrupt_Request		1<<3
#define Deny_High_Alert_Interrupt_Request		0<<3
#define Allow_Low_Alert_Interrupt_Request		1<<2
#define Deny_Low_Alert_Interrupt_Request		0<<2
#define Allow_Error_Interrupt_Request			1<<1
#define Deny_Error_Interrupt_Request			0<<1
#define Allow_Timer_Interrupt_Request			1<<0
#define Deny_Timer_Interrupt_Request			0<<0

#define IRQpin_isCMOS							1<<7
#define Allow_MFIN_Active_Interrupt_Request		1<<4
#define Allow_CRC_Interrupt_Request				1<<2



uint8_t MFRC522_V1[] =
{
		0x00, 0xC6, 0x37,  0xD5, 0x32, 0xB7, 0x57, 0x5C,
		0xC2, 0xD8, 0x7C,  0x4D, 0xD9, 0x70, 0xC7, 0x73,
		0x10, 0xE6, 0xD2,  0xAA, 0x5E, 0xA1, 0x3E, 0x5A,
		0x14, 0xAF, 0x30,  0x61, 0xC9, 0x70, 0xDB, 0x2E,
		0x64, 0x22, 0x72,  0xB5, 0xBD, 0x65, 0xF4, 0xEC,
		0x22, 0xBC, 0xD3,  0x72, 0x35, 0xCD, 0xAA, 0x41,
		0x1F, 0xA7, 0xF3,  0x53, 0x14, 0xDE, 0x7E, 0x02,
		0xD9, 0x0F, 0xB5,  0x5E, 0x25, 0x1D, 0x29, 0x79
};




uint8_t MFRC522_V2[] =
{
		0x00, 0xEB, 0x66, 0xBA, 0x57, 0xBF, 0x23, 0x95,
		0xD0, 0xE3, 0x0D, 0x3D, 0x27, 0x89, 0x5C, 0xDE,
		0x9D, 0x3B, 0xA7, 0x00, 0x21, 0x5B, 0x89, 0x82,
		0x51, 0x3A, 0xEB, 0x02, 0x0C, 0xA5, 0x00, 0x49,
		0x7C, 0x84, 0x4D, 0xB3, 0xCC, 0xD2, 0x1B, 0x81,
		0x5D, 0x48, 0x76, 0xD5, 0x71, 0x61, 0x21, 0xA9,
		0x86, 0x96, 0x83, 0x38, 0xCF, 0x9D, 0x5B, 0x6D,
		0xDC, 0x15, 0xBA, 0x3E, 0x7D, 0x95, 0x3B, 0x2F
};


#endif
