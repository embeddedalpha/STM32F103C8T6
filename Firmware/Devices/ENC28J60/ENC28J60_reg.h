#ifndef _ENC28J60_REG_H_
#define _ENC28J60_REG_H_

//BANKS

#define BANK0 0
#define BANK1 1
#define BANK2 2
#define BANK3 3


//Same for all Banks
#define ECON1     0x1f
#define ECON2     0x1e
#define ESTAT     0x1d
#define EIR       0x1c
#define EIE       0x1b


//BANK0
	const int ERDPTL = 0x00;
	const int ERDPTH = 0x01;
	const int EWRPTL = 0x02;
	const int EWRPTH = 0x03;
	const int ETXSTL = 0x04;
	const int ETXSTH = 0x05;
	const int ETXNDL = 0x06;
	const int ETXNDH = 0x07;
	const int ERXSTL = 0x08;
	const int ERXSTH = 0x09;
	const int ERXNDL = 0x0A;
	const int ERXNDH = 0x0B;
	const int ERXRDPTL = 0x0C;
	const int ERXRDPTH = 0x0D;
	const int ERXWRPTL = 0x0E;
	const int ERXWRPTH = 0x0F;
	const int EDMASTL = 0x10;
	const int EDMASTH = 0x11;
	const int EDMANDL = 0x12;
	const int EDMANDH = 0x13;
	const int EDMADSTL = 0x14;
	const int EDMADSTH = 0x15;
	const int EDMACSL = 0x16;
	const int EDMACSH = 0x17;



//BANK1
	const int EHT0 = 0x00;
	const int EHT1 = 0x01;
	const int EHT2 = 0x02;
	const int EHT3 = 0x03;
	const int EHT4 = 0x04;
	const int EHT5 = 0x05;
	const int EHT6 = 0x06;
	const int EHT7 = 0x07;
	const int EPMM0 = 0x08;
	const int EPMM1 = 0x09;
	const int EPMM2 = 0x0A;
	const int EPMM3 = 0x0B;
	const int EPMM4 = 0x0C;
	const int EPMM5 = 0x0D;
	const int EPMM6 = 0x0E;
	const int EPMM7 = 0x0F;
	const int EPMCSL = 0x10;
	const int EPMCSH = 0x11;
	const int EPMOL = 0x14;
	const int EPMOH = 0x15;
	const int EWOLIE = 0x16;
	const int EWOLIR = 0x17;
	const int ERXFCON = 0x18;
	const int EPKTCNT = 0x19;



//BANK2
	const int MACON1 = 0x00;
	const int MACON2 = 0x01;
	const int MACON3 = 0x02;
	const int MACON4 = 0x03;
	const int MABBIPG = 0x04;
	const int MAIPGL = 0x06;
	const int MAIPGH = 0x07;
	const int MACLCON1 = 0x08;
	const int MACLCON2 = 0x09;
	const int MAMXFLL = 0x0A;
	const int MAMXFLH = 0x0B;
	const int MAPHSUP = 0x0D;
	const int MICON = 0x11;
	const int MICMD = 0x12;
	const int MIREGADR = 0x14;
	const int MIWRL = 0x16;
	const int MIWRH = 0x17;
	const int MIRDL = 0x18;
	const int MIRDH = 0x19;



//BANK3
	const int MAADR1 = 0x00;
	const int MAADR0 = 0x01;
	const int MAADR3 = 0x02;
	const int MAADR2 = 0x03;
	const int MAADR5 = 0x04;
	const int MAADR4 = 0x05;
	const int EBSTSD = 0x06;
	const int EBSTCON = 0x07;
	const int EBSTCSL = 0x08;
	const int EBSTCSH = 0x09;
	const int MISTAT = 0x0A;

	const int EREVID = 0x12;
	const int ECOCON = 0x15;

	const int EFLOCON = 0x17;
	const int EPAUSL = 0x18;
	const int EPAUSH = 0x19;


	//Physical Layer Registers

	#define PHCON1 0x00
	#define PHSTAT1 0x01
	#define PHID1   0x02
	#define PHID2  0x03
	#define PHCON2 0x10
	#define PHSTAT2 0x11
	#define PHIE   0x12
	#define PHIR 0x13
	#define PHILCON 0x14


	//SPI Commands

#define Read_Control_Register  0x1F
#define Read_Buffer_Memory     0x1D
#define Write_Control_Register  0x5F
#define Write_Buffer_Memory 0x7A
#define Bit_Field_Set 0x9F
#define Bit_Field_Clear 0xBF
#define System_Command 0xFF

#endif
