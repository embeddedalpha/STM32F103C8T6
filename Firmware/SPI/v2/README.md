# SPI Driver v2.0 

### SPI driver for STM32F103C8T6


#### Structures are provided to facilitate seemless and easy hardware configuration. SPI has a master and a slave mode, and structures for each mode are provided. 

```
typedef struct SPI_Master_Config;
typedef struct SPI_SLave_Config;
```

#### Description of members of the SPI_Master_Config structure:
```
SPI_TypeDef *SPI;           //Hardware SPI you wish to use : SPI1 or SPI2
uint8_t mode;               //SPI mode: Bidirectional by passing '1' or Unidirectional by passing '0'. 
                            //In Bidirectional, onlyTX by passing '1' or onlyRX by passing '0' can be selected.
bool onlyTX;
bool onlyRX;
bool frame_format;          //Frame format can be set to 8-bit by passing '0' or to 16-bit by passing '1'
uint8_t clock_speed;        //Clock Speeds are defined in the SPI.h file. Any of those values can be passed.
uint8_t lsb_or_msb;         //Pass '1' for LSB to be transmitted first or '0' for MSB to be transmitted first
bool crc;                   //This enables Hardware SPI CRC. Passing '1' sets Hardware CRC.
bool interrupts;            //Passing '1' enables interrupts
bool tx_int;                //Enable Tx buffer empty interrupt
bool err_int;               //Enable Error interrupt. Helps in error detection when CRC, Mode fault, overrun and 
                            //underrun occurs
bool rx_int;                //Enable RX buffer not empty interrupt
bool clock_phase;           //Pass '1' or '0' according to the application
bool clock_polarity;        //Pass '1' or '0' according to the application
bool txDMA;                 //Enable transmit buffer DMA by passing '1'
bool rxDMA;                 //Enable receiver buffer DMA by passing '1'
```

#### Initiate the structure 
 ```
 struct SPI_Master_Config SPI_Test;
 ```

#### Pass the structure in the SPI_Master_Init function

```
void SPI_Master_Init(SPI_Test);
```

#### Transmit data by using the SPI_Master_TX function

```
SPI_Master_TX(SPI_Test, 0x45);
```
