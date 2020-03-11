<h1> Analog to Digital Converter </h1>

<h4> STM32F103C8T6 has 2 ADCs which share 12 channel, 10 I/O channels and 2 internal channels. The driver (ADC.h and ADC.c) files extract the peripheral's different function in modular form to be used in applications. </h4>
 <h4> Clock for the ADC must not exceed 14 MHz. After configuring thre prescaller, the clock for ADC comes out to be 12 MHz which satisfies the criteria. The following functions are declared in ADC.h file </h4>

``` javascript
void ADC_Init(ADC_TypeDef *ADC , int conversion_mode, int data_alignment, int DMA_Enable);
int ADC_Calibrate(ADC_TypeDef *ADC);
void ADC_Channel_0_Init(int channel_type, int sequence);
```
