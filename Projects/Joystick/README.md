<h1> Interfacing Dual Axis Joystick with STM32F103C8T6 </h1>


<b> Libraries used are: <br>
1.  [ADC.h](https://github.com/embeddedalpha/Embedded-Systems/blob/master/Firmware/ADC/ADC.h) 
2.  [DMA.h](https://github.com/embeddedalpha/Embedded-Systems/blob/master/Firmware/DMA/DMA.h)
3.  [Debug.h](https://github.com/embeddedalpha/Embedded-Systems/blob/master/Firmware/Debug/Debug.h)

<h4> The 4 pins of the joystick are connected to the 4 channels of ADC. The toggling of the stick changes the analog voltage that is sampled by the ADC. The ADC is configured in multi-channel mode and the data accquired from these channels is transferred from the data register to the integer array via DMA. The data is the then displayed onto the serial monitor using UART.  </h4> 
