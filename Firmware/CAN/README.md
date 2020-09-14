<h1> Controller Area Network </h1>

<h4> CAN is a two-wired half duplex high speed serial network technology used basically in automotive application as inter vehicle   communication protocol. Driver files (CAN.c and CAN.h) provide the software designer with all the functions with which they can communicate with the CAN PHY.</h4>

<h4> CAN frame bit timing: </h4>

![bit_timing](https://user-images.githubusercontent.com/38166489/76237857-efe8ae80-6254-11ea-9bbe-113bb305bdb4.png)

<h4> 
 The values chosen for 
      >> SYNC_SEG : 1 
      >> Prop_Seg + Phase_Seg1: 15 [14 + 1]
      >> Phase_Seg2 : 2 [1 + 1]
</h4>

<h4> The acceptable baudrates are: </h4>

```C
 CAN_BitRate_1000_kbps   1000
 CAN_BitRate_500_kbps    500
 CAN_BitRate_250_kbps    250
 CAN_BitRate_125_kbps    125
 CAN_BitRate_100_kbps    100
 CAN_BitRate_50_kbps     50
 CAN_BitRate_20_kbps     20
 CAN_BitRate_10_kbps     10
````

<h4> The CAN.h contains the following functions which can be called in application. </h4>

```C   
int CAN_Initialization_Mode(void);
int CAN_Normal_Mode(void);
int CAN_Sleep_Mode(void);
void CAN_Bitrate(int baudrate);
void CAN_Test_Mode_Setup(int mode);
int CAN_Transmit_Data_Frame(int mailbox_no, int standard_id, int extended_id, int dlc, int data[], int priority);
int CAN_Buffer_0_Transmission_Errors(void);
int CAN_Buffer_1_Transmission_Errors(void);
int CAN_Buffer_2_Transmission_Errors(void);
void CAN_Receive_FIFO_Data(int fifo_number,struct CAN_Frame rx_frame);
int CAN_Receive_Messages(int fifo_number);
```
  
<h4> To set the controller in Normal Mode, it needs to be initialized first. Initialization mode can be entered by calling the following function </h4>

``` javascript
CAN_Initialization_Mode(void);
```

<h4> After initialization, the bitrate, interrupts, identifier and mask should be set </h4>

```C
CAN_Bitrate(int baudrate);
CAN_Interrupt_Setup(int interrupts);
CAN_Identifier_&_Mask(uint16_t id, uint16_t mask);
```

<h4> Once the setup is done, the Normal Mode can be entered. To enter the Normal Mode the following function should be called. </h4>

```C
CAN_Normal_Mode(void);
```

<h4> After the Normal Mode is entered, messages can be sent on CAN bus. To send a message: the mailbox no, standard_id, extended_id, dlc, actual data in the form of an array and message priority should be passed to the function. </h4>

```C
CAN_Transmit_Data_Frame(int mailbox_no, int standard_id, int extended_id, int dlc, int data[], int priority)
```

<h4> To receive messages from CAN bus, the following function should be called. The data in the messages can be accessed by the predfined structs : FIFO_0_Message[] and FIFO_1_Message[]. The fifo number should be passed. </h4>
  
``` C
CAN_Receive_Messages(int fifo_number);
```

<h4>As there are two FIFOs and each FIFO can hold 3 messages, so to access message 1 in the FIFO 0, the user should send fifo_number = 0 and access the data from struct FIFO_0_Message[0]. </h4>

 ```C
 CAN_Receive_Messages(0);
 int standard_id = FIFO_0_Message[0].standard_id;
 int extended_id = FIFO_0_Message[0].extended_id;
 int standard_id = FIFO_0_Message[0].standard_id;
 //refer the CAN_Frame struct in CAN.h
 ```

<h4> Simple Example of CAN Transmission and Reception </h4>

 ``` C
 #include  "stm32f10x.h"
#include "CAN.h"


int main()
{

CAN_Initialization_Mode();
CAN_Bitrate(CAN_BitRate_1000_kbps);
CAN_Normal_Mode();

struct CAN_Frame Tx_frame1;
struct CAN_Frame Rx_frame1;

// Transmit Data
Tx_frame1.standard_id = 0x12;
Tx_frame1.extended_id = 0x112;
Tx_frame1.priority    = 0;
Tx_frame1.dlc        = 4;
Tx_frame1.data[0] =  0;
Tx_frame1.data[1] =  0;
Tx_frame1.data[2] =  0;
Tx_frame1.data[3] =  0;


CAN_Transmit_Data_Frame(0,Tx_frame1.standard_id, Tx_frame1.extended_id, Tx_frame1.dlc, Tx_frame1.data );

// Receive Data

CAN_Receive_Messages(0);
Rx_frame1.standard_id = FIFO_0_Message[0].standard_id;
Rx_frame1.extended_id = FIFO_0_Message[0].extended_id;
Rx_frame1.dlc         = FIFO_0_Message[0].dlc;
Rx_frame1.time_stamp  = FIFO_0_Message[0].time_stamp;

//This data can be used in application

}

 ```
