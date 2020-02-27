#include "CAN.h"


void CAN_Sleep_Mode_Start(){

	CAN1->MCR |= CAN_MCR_RESET;
while((CAN1->MSR & CAN_MSR_SLAK) != 1){}
}

void CAN_Sleep_Mode_Stop(){

	CAN1->MCR &= ~CAN_MCR_RESET;
while((CAN1->MSR & CAN_MSR_SLAK) == 1){}
}

void CAN_Init_Mode_Start()
{

	CAN1->MCR |= CAN_MCR_INRQ;
	while(!(CAN1->MSR & CAN_MSR_INAK)){}
		RCC->APB1ENR |= RCC_APB1ENR_CAN1EN ;
RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
GPIOA -> CRH |= (0xB << 11) | (0xB << 12);
	CAN1->BTR = 0x001c0008;		
		
}

void CAN_Init_Mode_Stop()
{
	CAN1->MCR &= ~CAN_MCR_INRQ;
	while((CAN1->MSR & CAN_MSR_INAK) == 1){}	
}

void CAN_Normal_Mode(){

	CAN_Sleep_Mode_Stop();
	CAN_Init_Mode_Stop();

}

void CAN_TX_Mailbox_0(uint32_t identifier, int length, int data[] ){
	
	//EMPTY STATE
		while((CAN1->TSR & CAN_TSR_TME0) == 1){}
	CAN1->sTxMailBox[0].TDTR |= (CAN_TDT0R_DLC | length);
	CAN1->sTxMailBox[0].TIR &= ~CAN_TI0R_STID;
	CAN1->sTxMailBox[0].TIR |= (identifier << 18);
	CAN1->sTxMailBox[0].TDLR |= CAN_TDL0R_DATA0 << data[0];
	CAN1->sTxMailBox[0].TDLR |= CAN_TDL0R_DATA1 << data[1];
	CAN1->sTxMailBox[0].TDLR |= CAN_TDL0R_DATA2 << data[2];
	CAN1->sTxMailBox[0].TDLR |= CAN_TDL0R_DATA3 << data[3];
	CAN1->sTxMailBox[0].TDHR |= CAN_TDH0R_DATA4 << data[4];
  CAN1->sTxMailBox[0].TDHR |= CAN_TDH0R_DATA5 << data[5];
	CAN1->sTxMailBox[0].TDHR |= CAN_TDH0R_DATA6 << data[6];
	CAN1->sTxMailBox[0].TDHR |= CAN_TDH0R_DATA7 << data[7];
	CAN1->sTxMailBox[0].TIR |= CAN_TI0R_TXRQ;
	
			//PENDING STATE
	while((CAN1->TSR & CAN_TSR_RQCP0) != 0){}
	while((CAN1->TSR & CAN_TSR_TXOK0) != 0){}
	while((CAN1->TSR & CAN_TSR_TME0) != 0){}
		

}

void CAN_TX_Mailbox_1(uint32_t identifier, int length, int data[] ){
	
	//EMPTY STATE
		while((CAN1->TSR & CAN_TSR_TME1) == 1){}
	CAN1->sTxMailBox[1].TDTR |= (CAN_TDT0R_DLC | length);
	CAN1->sTxMailBox[1].TIR &= ~CAN_TI0R_STID;
	CAN1->sTxMailBox[1].TIR |= (identifier << 18);
	CAN1->sTxMailBox[1].TDLR |= CAN_TDL0R_DATA0 << data[0];
	CAN1->sTxMailBox[1].TDLR |= CAN_TDL0R_DATA1 << data[1];
	CAN1->sTxMailBox[1].TDLR |= CAN_TDL0R_DATA2 << data[2];
	CAN1->sTxMailBox[1].TDLR |= CAN_TDL0R_DATA3 << data[3];
	CAN1->sTxMailBox[1].TDHR |= CAN_TDH0R_DATA4 << data[4];
  CAN1->sTxMailBox[1].TDHR |= CAN_TDH0R_DATA5 << data[5];
	CAN1->sTxMailBox[1].TDHR |= CAN_TDH0R_DATA6 << data[6];
	CAN1->sTxMailBox[1].TDHR |= CAN_TDH0R_DATA7 << data[7];
	CAN1->sTxMailBox[1].TIR |= CAN_TI0R_TXRQ;
	
			//PENDING STATE
	while((CAN1->TSR & CAN_TSR_RQCP1) != 0){}
	while((CAN1->TSR & CAN_TSR_TXOK1) != 0){}
	while((CAN1->TSR & CAN_TSR_TME1) != 0){}
		

}

void CAN_TX_Mailbox_2(uint32_t identifier, int length, int data[] ){
	
	//EMPTY STATE
		while((CAN1->TSR & CAN_TSR_TME1) == 1){}
	CAN1->sTxMailBox[2].TDTR |= (CAN_TDT0R_DLC | length);
	CAN1->sTxMailBox[2].TIR &= ~CAN_TI0R_STID;
	CAN1->sTxMailBox[2].TIR |= (identifier << 18);
	CAN1->sTxMailBox[2].TDLR |= CAN_TDL0R_DATA0 << data[0];
	CAN1->sTxMailBox[2].TDLR |= CAN_TDL0R_DATA1 << data[1];
	CAN1->sTxMailBox[2].TDLR |= CAN_TDL0R_DATA2 << data[2];
	CAN1->sTxMailBox[2].TDLR |= CAN_TDL0R_DATA3 << data[3];
	CAN1->sTxMailBox[2].TDHR |= CAN_TDH0R_DATA4 << data[4];
  CAN1->sTxMailBox[2].TDHR |= CAN_TDH0R_DATA5 << data[5];
	CAN1->sTxMailBox[2].TDHR |= CAN_TDH0R_DATA6 << data[6];
	CAN1->sTxMailBox[2].TDHR |= CAN_TDH0R_DATA7 << data[7];
	CAN1->sTxMailBox[2].TIR |= CAN_TI0R_TXRQ;
	
			//PENDING STATE
	while((CAN1->TSR & CAN_TSR_RQCP2) != 0){}
	while((CAN1->TSR & CAN_TSR_TXOK2) != 0){}
	while((CAN1->TSR & CAN_TSR_TME2) != 0){}
		
}

