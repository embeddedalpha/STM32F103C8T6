#include "MCP2512_CAN_Controller.h"

void MCP2515_Init(void) {
	MCP2515.Baudrate = 8;
	MCP2515.CPHA = 1;
	MCP2515.CPOL = 1;
	MCP2515.DataFormat = Bit_8;
	MCP2515.LSBorMSB = MSB;
	MCP2515.BiDirectional_Mode = Duplex;
	SPI_Master_Config(MCP2515);
	SPI_Master_Enable();
	NSS_Pin = 4;
	SPI_NSS_Pin_Setup();

}

uint8_t MCP2515_Read(uint8_t address) {
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(MCP2515_Read_INST);
	SPI_Master_TX(address);
	uint8_t data = SPI_Master_RX();
	SPI_NSS_HIGH();
	return data;
}

uint8_t MCP2515_Read_RX_Buffer(uint8_t buffer) {
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(buffer);
	uint8_t data = SPI_Master_RX();
	SPI_NSS_HIGH();
	return data;
}

void MCP2515_Write(uint8_t address, uint8_t data) {
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(MCP2512_Write_INST);
	SPI_Master_TX(address);
	SPI_Master_TX(data);
	SPI_NSS_HIGH();
}

void MCP2515_Load_TX_Buffer(uint8_t buffer, uint8_t data) {
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(buffer);
	SPI_Master_TX(data);
	SPI_NSS_HIGH();

}

void MCP2515_Request_To_Send(uint8_t RTS_Buffer) {
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(RTS_Buffer);
	SPI_NSS_HIGH();
}

void MCP2515_Bit_Modify(uint8_t address, uint8_t mask, uint8_t data) {
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(MCP2515_Bit_Modify_INST);
	SPI_Master_TX(address);
	SPI_Master_TX(mask);
	SPI_Master_TX(data);
	SPI_NSS_HIGH();
}

uint8_t MCP2515_Read_Status(void) {
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(MCP25125_Read_Status_INST);
	uint8_t data = SPI_Master_RX();
	SPI_NSS_HIGH();
	return data;
}

uint8_t MCP2515_Rx_Status(void) {
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(MCP2512_R5_Status_INST);
	uint8_t data = SPI_Master_RX();
	SPI_NSS_HIGH();
	return data;
}

void MCP2515_TX_Standard_Frame(uint8_t buffer, uint16_t standard_id,
		uint8_t data[8], uint8_t dlc) {
	switch (buffer) {
	case 0: {
		uint16_t mask1 = 0x0007;
		uint16_t mask2 = 0x078F;
		uint8_t status, tx_req, a_bat, a_bort, mloa, txerr;
		MCP2515_Bit_Modify(TXB0CTRL, (1 << 3), (1 << 3));
		MCP2515_Request_To_Send(MCP2515_RTS_TXB0_INST);
		MCP2515_Bit_Modify(TXB0CTRL, (7 << 4),
				((0 << 4) | (0 << 5) | (0 << 6)));
		do {
			status = MCP2515_Read(TXB0CTRL);
			tx_req = ((1 << 3) & status) >> 3;
			status = MCP2515_Read(CANCTRL_TX0);
			a_bat = ((1 << 4) & status) >> 4;
		} while (!((tx_req == 0) || (a_bat == 1)));
		MCP2515_Bit_Modify(TXB0CTRL, (3 << 0), 0x00); //priority
		uint16_t stdid_lower = standard_id & mask1;
		stdid_lower = stdid_lower << 5;
		MCP2515_Write(TXB0SIDL, stdid_lower);
		uint16_t stdid_higher = standard_id & mask2;
		stdid_higher = stdid_higher >> 3;
		MCP2515_Write(TXB0SIDH, stdid_higher);
		MCP2515_Write(TXB0DLC, dlc);

		MCP2515_Write(TXB0D0, data[0]);
		MCP2515_Write(TXB0D1, data[1]);
		MCP2515_Write(TXB0D2, data[2]);
		MCP2515_Write(TXB0D3, data[3]);
		MCP2515_Write(TXB0D4, data[4]);
		MCP2515_Write(TXB0D5, data[5]);
		MCP2515_Write(TXB0D6, data[6]);
		MCP2515_Write(TXB0D7, data[7]);

		do {
			status = MCP2515_Read(TXB0CTRL);
			a_bort = (1 << 6 & status) >> 6;
			mloa = (1 << 5 & status) >> 5;
			txerr = (1 << 4 & status) >> 4;

		} while ((a_bort != 0) & (mloa != 0) & (txerr != 0));

		break;
	}

	case 1: {
		uint16_t mask1 = 0x0007;
		uint16_t mask2 = 0x078F;
		uint8_t status, tx_req, a_bat, a_bort, mloa, txerr;
		MCP2515_Bit_Modify(TXB1CTRL, (1 << 3), (1 << 3));
		MCP2515_Request_To_Send(MCP2515_RTS_TXB1_INST);
		MCP2515_Bit_Modify(TXB1CTRL, (7 << 4),
				((0 << 4) | (0 << 5) | (0 << 6)));
		do {
			status = MCP2515_Read(TXB1CTRL);
			tx_req = ((1 << 3) & status) >> 3;
			status = MCP2515_Read(CANCTRL_TX1);
			a_bat = ((1 << 4) & status) >> 4;
		} while (!((tx_req == 0) || (a_bat == 1)));
		MCP2515_Bit_Modify(TXB1CTRL, (3 << 0), 0x00); //priority
		uint16_t stdid_lower = standard_id & mask1;
		stdid_lower = stdid_lower << 5;
		MCP2515_Write(TXB1SIDL, stdid_lower);
		uint16_t stdid_higher = standard_id & mask2;
		stdid_higher = stdid_higher >> 3;
		MCP2515_Write(TXB1SIDH, stdid_higher);
		MCP2515_Write(TXB1DLC, dlc);

		MCP2515_Write(TXB1D0, data[0]);
		MCP2515_Write(TXB1D1, data[1]);
		MCP2515_Write(TXB1D2, data[2]);
		MCP2515_Write(TXB1D3, data[3]);
		MCP2515_Write(TXB1D4, data[4]);
		MCP2515_Write(TXB1D5, data[5]);
		MCP2515_Write(TXB1D6, data[6]);
		MCP2515_Write(TXB1D7, data[7]);

		do {
			status = MCP2515_Read(TXB1CTRL);
			a_bort = (1 << 6 & status) >> 6;
			mloa = (1 << 5 & status) >> 5;
			txerr = (1 << 4 & status) >> 4;

		} while ((a_bort != 0) & (mloa != 0) & (txerr != 0));

		break;
	}

	case 2: {
		uint16_t mask1 = 0x0007;
		uint16_t mask2 = 0x078F;
		uint8_t status, tx_req, a_bat, a_bort, mloa, txerr;
		MCP2515_Bit_Modify(TXB2CTRL, (1 << 3), (1 << 3));
		MCP2515_Request_To_Send(MCP2515_RTS_TXB2_INST);
		MCP2515_Bit_Modify(TXB2CTRL, (7 << 4),
				((0 << 4) | (0 << 5) | (0 << 6)));
		do {
			status = MCP2515_Read(TXB2CTRL);
			tx_req = ((1 << 3) & status) >> 3;
			status = MCP2515_Read(CANCTRL_TX2);
			a_bat = ((1 << 4) & status) >> 4;
		} while (!((tx_req == 0) || (a_bat == 1)));
		MCP2515_Bit_Modify(TXB2CTRL, (3 << 0), 0x00); //priority
		uint16_t stdid_lower = standard_id & mask1;
		stdid_lower = stdid_lower << 5;
		MCP2515_Write(TXB2SIDL, stdid_lower);
		uint16_t stdid_higher = standard_id & mask2;
		stdid_higher = stdid_higher >> 3;
		MCP2515_Write(TXB2SIDH, stdid_higher);
		MCP2515_Write(TXB2DLC, dlc);

		MCP2515_Write(TXB2D0, data[0]);
		MCP2515_Write(TXB2D1, data[1]);
		MCP2515_Write(TXB2D2, data[2]);
		MCP2515_Write(TXB2D3, data[3]);
		MCP2515_Write(TXB2D4, data[4]);
		MCP2515_Write(TXB2D5, data[5]);
		MCP2515_Write(TXB2D6, data[6]);
		MCP2515_Write(TXB2D7, data[7]);

		do {
			status = MCP2515_Read(TXB2CTRL);
			a_bort = (1 << 6 & status) >> 6;
			mloa = (1 << 5 & status) >> 5;
			txerr = (1 << 4 & status) >> 4;

		} while ((a_bort != 0) & (mloa != 0) & (txerr != 0));

		break;
	}

	default: {
		break;
	}

	}

}

void MCP2515_TX_Extended_Frame(uint8_t buffer, uint16_t standard_id,
		uint32_t extended_id, uint8_t data[8], uint8_t dlc) {
	switch (buffer) {
	case 0: {

		uint16_t mask1 = 0x0007;
		uint16_t mask2 = 0x078F;
		uint32_t mask3 = 0x00030000;
		uint32_t mask4 = 0x0000FF00;
		uint32_t mask5 = 0x000000FF;

		uint8_t status, tx_req, a_bat, a_bort, mloa, txerr;

		MCP2515_Bit_Modify(TXB0CTRL, (1 << 3), (1 << 3));
		MCP2515_Request_To_Send(MCP2515_RTS_TXB0_INST);
		MCP2515_Bit_Modify(TXB0CTRL, (7 << 4),
				((0 << 4) | (0 << 5) | (0 << 6)));
		do {
			status = MCP2515_Read(TXB0CTRL);
			tx_req = ((1 << 3) & status) >> 3;
			status = MCP2515_Read(CANCTRL_TX0);
			a_bat = ((1 << 4) & status) >> 4;
		} while (!((tx_req == 0) || (a_bat == 1)));

		MCP2515_Bit_Modify(TXB0CTRL, (3 << 0), 0x00); //priority
		uint8_t extid_higher = (extended_id & mask3) >> 16;
		uint8_t extid_mid = (extended_id & mask4) >> 8;
		uint8_t extid_lower = (extended_id & mask5);

		uint16_t stdid_higher = (standard_id & mask2) >> 3;
		uint16_t stdid_lower = (standard_id & mask1) << 5;

		MCP2515_Write(TXB0SIDH, stdid_higher);
		MCP2515_Write(TXB0EID8, extid_mid);
		MCP2515_Write(TXB0EID0, extid_lower);
		MCP2515_Write(TXB0SIDL, (stdid_lower | (1 << 3) | extid_higher));
		MCP2515_Write(TXB0DLC, dlc);

		MCP2515_Write(TXB0D0, data[0]);
		MCP2515_Write(TXB0D1, data[1]);
		MCP2515_Write(TXB0D2, data[2]);
		MCP2515_Write(TXB0D3, data[3]);
		MCP2515_Write(TXB0D4, data[4]);
		MCP2515_Write(TXB0D5, data[5]);
		MCP2515_Write(TXB0D6, data[6]);
		MCP2515_Write(TXB0D7, data[7]);

		do {
			status = MCP2515_Read(TXB0CTRL);
			a_bort = (1 << 6 & status) >> 6;
			mloa = (1 << 5 & status) >> 5;
			txerr = (1 << 4 & status) >> 4;

		} while ((a_bort != 0) & (mloa != 0) & (txerr != 0));

		break;
	}

	case 1: {

		uint16_t mask1 = 0x0007;
		uint16_t mask2 = 0x078F;
		uint32_t mask3 = 0x00030000;
		uint32_t mask4 = 0x0000FF00;
		uint32_t mask5 = 0x000000FF;

		uint8_t status, tx_req, a_bat, a_bort, mloa, txerr;

		MCP2515_Bit_Modify(TXB1CTRL, (1 << 3), (1 << 3));
		MCP2515_Request_To_Send(MCP2515_RTS_TXB1_INST);
		MCP2515_Bit_Modify(TXB1CTRL, (7 << 4),
				((0 << 4) | (0 << 5) | (0 << 6)));
		do {
			status = MCP2515_Read(TXB1CTRL);
			tx_req = ((1 << 3) & status) >> 3;
			status = MCP2515_Read(CANCTRL_TX1);
			a_bat = ((1 << 4) & status) >> 4;
		} while (!((tx_req == 0) || (a_bat == 1)));

		MCP2515_Bit_Modify(TXB1CTRL, (3 << 0), 0x00); //priority

		uint8_t extid_higher = (extended_id & mask3) >> 16;
		uint8_t extid_mid = (extended_id & mask4) >> 8;
		uint8_t extid_lower = (extended_id & mask5);

		uint16_t stdid_higher = (standard_id & mask2) >> 3;
		uint16_t stdid_lower = (standard_id & mask1) << 5;

		MCP2515_Write(TXB1SIDH, stdid_higher);
		MCP2515_Write(TXB1EID8, extid_mid);
		MCP2515_Write(TXB1EID0, extid_lower);
		MCP2515_Write(TXB1SIDL, (stdid_lower | (1 << 3) | extid_higher));
		MCP2515_Write(TXB1DLC, dlc);

		MCP2515_Write(TXB1D0, data[0]);
		MCP2515_Write(TXB1D1, data[1]);
		MCP2515_Write(TXB1D2, data[2]);
		MCP2515_Write(TXB1D3, data[3]);
		MCP2515_Write(TXB1D4, data[4]);
		MCP2515_Write(TXB1D5, data[5]);
		MCP2515_Write(TXB1D6, data[6]);
		MCP2515_Write(TXB1D7, data[7]);

		do {
			status = MCP2515_Read(TXB1CTRL);
			a_bort = (1 << 6 & status) >> 6;
			mloa = (1 << 5 & status) >> 5;
			txerr = (1 << 4 & status) >> 4;

		} while ((a_bort != 0) & (mloa != 0) & (txerr != 0));

		break;
	}
	case 2: {

		uint16_t mask1 = 0x0007;
		uint16_t mask2 = 0x078F;
		uint32_t mask3 = 0x00030000;
		uint32_t mask4 = 0x0000FF00;
		uint32_t mask5 = 0x000000FF;

		uint8_t status, tx_req, a_bat, a_bort, mloa, txerr;

		MCP2515_Bit_Modify(TXB2CTRL, (1 << 3), (1 << 3));
		MCP2515_Request_To_Send(MCP2515_RTS_TXB2_INST);
		MCP2515_Bit_Modify(TXB2CTRL, (7 << 4),
				((0 << 4) | (0 << 5) | (0 << 6)));
		do {
			status = MCP2515_Read(TXB2CTRL);
			tx_req = ((1 << 3) & status) >> 3;
			status = MCP2515_Read(CANCTRL_TX2);
			a_bat = ((1 << 4) & status) >> 4;
		} while (!((tx_req == 0) || (a_bat == 1)));

		MCP2515_Bit_Modify(TXB2CTRL, (3 << 0), 0x00); //priority

		uint8_t extid_higher = (extended_id & mask3) >> 16;
		uint8_t extid_mid = (extended_id & mask4) >> 8;
		uint8_t extid_lower = (extended_id & mask5);

		uint16_t stdid_higher = (standard_id & mask2) >> 3;
		uint16_t stdid_lower = (standard_id & mask1) << 5;

		MCP2515_Write(TXB2SIDH, stdid_higher);
		MCP2515_Write(TXB2EID8, extid_mid);
		MCP2515_Write(TXB2EID0, extid_lower);
		MCP2515_Write(TXB2SIDL, (stdid_lower | (1 << 3) | extid_higher));
		MCP2515_Write(TXB2DLC, dlc);

		MCP2515_Write(TXB2D0, data[0]);
		MCP2515_Write(TXB2D1, data[1]);
		MCP2515_Write(TXB2D2, data[2]);
		MCP2515_Write(TXB2D3, data[3]);
		MCP2515_Write(TXB2D4, data[4]);
		MCP2515_Write(TXB2D5, data[5]);
		MCP2515_Write(TXB2D6, data[6]);
		MCP2515_Write(TXB2D7, data[7]);

		do {
			status = MCP2515_Read(TXB2CTRL);
			a_bort = (1 << 6 & status) >> 6;
			mloa = (1 << 5 & status) >> 5;
			txerr = (1 << 4 & status) >> 4;

		} while ((a_bort != 0) & (mloa != 0) & (txerr != 0));

		break;
	}
	default: {
		break;
	}
	}
}

uint8_t MCP2515_RX_Buffer0() {

}

