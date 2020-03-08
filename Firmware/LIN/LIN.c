

#include "LIN.h"

int LIN_Init(void)
{

if(LIN == USART1)
{
LIN -> BRR = (234 << 4 |6 << 0 );
}
else
{
LIN -> BRR = (117 << 4 | 3 << 0 );
}
LIN ->CR2 &= ~(USART_CR2_CLKEN | USART_CR2_STOP);
LIN -> CR3 &= ~(USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN);
LIN -> CR1 &= ~(USART_CR1_M);
LIN -> CR2 |= USART_CR2_STOP;
LIN ->CR2 |= USART_CR2_LINEN;

return 1;
}

int LIN_Send_Break(void)
{
LIN -> CR1 |= USART_CR1_SBK;
}

int LIN_Transmit_Data(void)
{
LIN -> CR1 |= USART_CR1_TE;
LIN_Send_Break();

}

int LIN_Receive_Data(void)
{}
