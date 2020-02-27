#include "W5500_TCP.h"



//Basic Setting
//1>    MODE REGISTER = 0X28
//2>    INTERRUPT MASK REGISTER = 0X00
//3>    Retry Time-value Register 0 = 0X0F COMBINING BOTH GIVES 400MS 
//      Retry Time-value Register 1 = 0XA0
//4>    Retry Count Register = 0X07

//NETWORK SETTING
//1>    SHAR[0 - 5] = MAC ADDRESS GIVEN BY USER
//2>    GAR[0 - 3] = GATEWAY IP ADDRESS GIVEN BY USER
//3>    SUBR[0 - 3] =  subnet mask address GIVEN BY USER
//4>    SIPR[0 - 3] = Source IP Address GIVEN BY USER

void TCP_Config(){
W5500_Write(uint16_t address_phase, uint8_t control_phase, uint8_t data[] );
}
