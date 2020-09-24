# USART: Universal Synchronous Aynchronous Receiver Transmitter 


#### A universal asynchronous receiver-transmitter is a computer hardware device for asynchronous serial communication in which the data format and transmission speeds are configurable.

#### This driver is divided into 2 parts, synchronous & asynchronous. 

### Asynchronous Controller:

#### UART_Setup: This function configures the hardware USART controller in asynchronous mode. The parameters passed to the function gives more control to the user to configure the hardware. 
#### Parameters to be passed are mentioned below:
```C
uart         ->       USART1
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
void UART_Setup(USART_TypeDef *uart, uint8_t baudrate, bool frame_length, uint8_t stop_bits, bool DMA_TX, bool DMA_RX);
```
