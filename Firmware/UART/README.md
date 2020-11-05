# USART: Universal Synchronous Aynchronous Receiver Transmitter 


#### A universal asynchronous receiver-transmitter is a computer hardware device for asynchronous serial communication in which the data format and transmission speeds are configurable.

#### This driver is divided into 2 parts, synchronous & asynchronous. 

### Asynchronous Controller:

#### ⚡ UART_Setup: This function configures the hardware USART controller in asynchronous mode. The parameters passed to the function gives more control to the user to configure the hardware. 
#### Parameters to be passed are mentioned below:
```C
USART        ->       USART1
                      USART2
		      USART3
baudrate     ->       2400
                      9600
                      19200
                      57600
                      115200
                      230400
                      460800
                      921600
                      2250000
                      450000
frame_length  ->      0:  1 Start bit, 8 Data bits, n Stop bit
                      1:  1 Start bit, 9 Data bits, n Stop bit
stop_bits     ->      0:  1 Stop bit
                      1:  0.5 Stop bit
                      2:  2 Stop bits
                      3:  1.5 Stop bit
DMA_TX       ->       0:  DMA mode is enabled for transmission
                      1:  DMA mode is disabled for transmission
DMA_RX        ->      0:  DMA mode is enabled for reception
                      1:  DMA mode is disabled for reception
```


```C
void UART_Setup(USART_TypeDef *USART,uint8_t baudrate, bool frame_length, uint8_t stop_bits, bool DMA_TX, bool DMA_RX);
```


#### ⚡ USART_Interrup_Setup: This function configures the various interrupts associated with USART controller. The user can pass the necessary interrupts as parameters to enable them.

```C
uart                                  ->  USART1
                                          USART2
                                          USART3
parity_interrupt                      ->  0: Disable
                                          1: Enable
transmitter_register_empty_interrupt  ->  0: Disable
                                          1: Enable
transmitter_complete_interrupt        ->  0: Disable
                                          1: Enable
receiver_register_empty_interrupt     ->  0: Disable
                                          1: Enable
idle_interrupt                        ->  0: Disable
                                          1: Enable
CTS_interrupt                         ->  0: Disable
                                          1: Enable
Error_interrupt                       ->  0: Disable
                                          1: Enable
```

```C
void USART_Interrupt_Setup(USART_TypeDef *uart,
						  bool parity_interrupt,
						  bool transmitter_register_empty_interrupt,
						  bool transmitter_complete_interrupt,
						  bool receiver_register_empty_interrupt,
						  bool idle_interrupt,
						  bool CTS_interrupt,
						  bool Error_interrupt
						  );
```


#### ⚡ UART_Flow_Control_Setup: This function enables the flow control signals. The only parameter needed to be passed is the instance of USART to be used.

```C
uart  ->   USART1
           USART2
           USART3
```
```C
void UART_Flow_Control_Setup(USART_TypeDef *uart);
```

#### ⚡ UART_Get_Data: This function returns the received data.

```C
uart  ->   USART1
           USART2
           USART3
```
```C
uint8_t UART_Get_Data(USART_TypeDef *uart);
```

#### ⚡ UART_Send_Data: This function sends out data to external devices (if any).

```C
uart  ->  USART1
          USART2
          USART3
 data  -> 8 bit data
```
```C
void UART_Send_Data(USART_TypeDef *uart,uint8_t data);
```


### Synchronous Controller:

#### ⚡ USART_Setup: This function configures the hardware USART controller in synchronous mode. The parameters passed to the function gives more control to the user to configure the hardware. 
#### Parameters to be passed are mentioned below:
```C
USART        ->       USART1
                      USART2
		      USART3
baudrate     ->       2400
                      9600
                      19200
                      57600
                      115200
                      230400
                      460800
                      921600
                      2250000
                      450000
frame_length  ->      0:  1 Start bit, 8 Data bits, n Stop bit
                      1:  1 Start bit, 9 Data bits, n Stop bit
stop_bits     ->      0:  1 Stop bit
                      1:  0.5 Stop bit
                      2:  2 Stop bits
                      3:  1.5 Stop bit
CPOL                  0:  Steady low value on CK pin outside transmission window
                      1:  Steady high value on CK pin outside transmission window
CPHA                  0:  The first clock transition is the first data capture edge
                      1:  The second clock transition is the first data capture edge
DMA_TX       ->       0:  DMA mode is enabled for transmission
                      1:  DMA mode is disabled for transmission
DMA_RX        ->      0:  DMA mode is enabled for reception
                      1:  DMA mode is disabled for reception
```

```C
void USART_Setup(USART_TypeDef *USART,uint8_t baudrate, bool frame_length, uint8_t stop_bits,bool CPOL,bool CPHA, bool DMA_TX, bool DMA_RX);
```

#### ⚡ USART_Get_Data: This function returns the received data.

```C
uart  ->   USART1
           USART2
           USART3
```
```C
uint8_t USART_Get_Data(USART_TypeDef *uart);
```

#### ⚡ USART_Send_Data: This function sends out data to external devices (if any).

```C
uart  ->  USART1
          USART2
          USART3
 data  -> 8 bit data
```
```C
void USART_Send_Data(USART_TypeDef *uart,uint8_t data);
```
