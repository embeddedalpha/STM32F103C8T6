void Ethernet_RMII_Init(void)
{
	RCC->AHBENR |= RCC_AHBENR_ETHMACEN | RCC_AHBENR_ETHMACRXEN | RCC_AHBENR_ETHMACTXEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;
	AFIO->MAPR |= AFIO_MAPR_MII_RMII_SEL;

	//REDUCED MEDIA - INDEPENDENT INTERFACE: RMII
	GPIO_Setup(GPIOB,12,ALTERNATE_PUSH_PULL_OUTPUT); //TXD0
	GPIO_Setup(GPIOB,13,ALTERNATE_PUSH_PULL_OUTPUT); //TXD1
	GPIO_Setup(GPIOB,11,ALTERNATE_PUSH_PULL_OUTPUT); //TX_EN
	GPIO_Setup(GPIOC,4,FLOATING_INPUT); //RXD0
	GPIO_Setup(GPIOC,5,FLOATING_INPUT); //RXD1
    GPIO_Setup(GPIOA,7,FLOATING_INPUT); //CRS_DV
	GPIO_Setup(GPIOC,1,ALTERNATE_PUSH_PULL_OUTPUT); //MDC
	GPIO_Setup(GPIOA,2,ALTERNATE_PUSH_PULL_OUTPUT); //MDIO
}
//

void Ethernet_MII_Init(void)
{

	RCC->AHBENR |= RCC_AHBENR_ETHMACEN | RCC_AHBENR_ETHMACRXEN | RCC_AHBENR_ETHMACTXEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;
	AFIO->MAPR &= ~AFIO_MAPR_MII_RMII_SEL;
	//MEDIA - INDEPENDENT INTERFACE: MII

	//TX SECTION
	GPIO_Setup(GPIOC,3,FLOATING_INPUT); //TX_CLK
	GPIO_Setup(GPIOB,12,ALTERNATE_PUSH_PULL_OUTPUT); //TXD0
	GPIO_Setup(GPIOB,13,ALTERNATE_PUSH_PULL_OUTPUT); //TXD1
	GPIO_Setup(GPIOC,2,ALTERNATE_PUSH_PULL_OUTPUT); //TXD2
	GPIO_Setup(GPIOB,8,ALTERNATE_PUSH_PULL_OUTPUT); //TXD3
	GPIO_Setup(GPIOB,11,ALTERNATE_PUSH_PULL_OUTPUT); //TX_EN

	//RX SECTION
	GPIO_Setup(GPIOA,1,FLOATING_INPUT); //RX_CLK
	GPIO_Setup(GPIOC,4,FLOATING_INPUT); //RXD0
	GPIO_Setup(GPIOC,5,FLOATING_INPUT); //RXD1
	GPIO_Setup(GPIOB,0,FLOATING_INPUT); //RXD2
	GPIO_Setup(GPIOB,1,FLOATING_INPUT); //RXD3
	GPIO_Setup(GPIOB,10,FLOATING_INPUT); //RX_ER

	//CRS & COL
	GPIO_Setup(GPIOA,0,FLOATING_INPUT); //CRS
	GPIO_Setup(GPIOA,3,FLOATING_INPUT); //COL

  //MDC & MDIO
	GPIO_Setup(GPIOC,1,ALTERNATE_PUSH_PULL_OUTPUT); //MDC
	GPIO_Setup(GPIOA,2,ALTERNATE_PUSH_PULL_OUTPUT); //MDIO

    GPIO_Setup(GPIOA,7,FLOATING_INPUT); //RX_DV
	GPIO_Setup(GPIOB,5,ALTERNATE_PUSH_PULL_OUTPUT); //PPS_OUT
}
	//

uint16_t Ethernet_SMI_Read(uint8_t PHY_Address,uint8_t PHY_Register)
{
	uint16_t data;
	while((ETH->MACMIIAR & ETH_MACMIIAR_MB)){}
	ETH->MACMIIAR = (uint16_t)((0x1F | PHY_Address) << 11);
	ETH->MACMIIAR = (uint16_t)((0x1F | PHY_Register) << 6);
	ETH->MACMIIAR &= (uint16_t)(~(1<<1));
	data = (uint16_t)(ETH->MACMIIDR);
	return data;

}
//

void Ethernet_SMI_Write(uint8_t PHY_Address,uint8_t PHY_Register, uint16_t data)
{
	while(!(ETH->MACMIIAR & ETH_MACMIIAR_MB)){}
	ETH->MACMIIAR = (uint16_t)((0x1F | PHY_Address) << 11);
	ETH->MACMIIAR = (uint16_t)((0x1F | PHY_Register) << 6);
	ETH->MACMIIAR |= (uint16_t)((1<<1));
	ETH->MACMIIDR = (uint16_t)data;
}
//
