<h1> Controller Area Network </h1>

<h3> The CAN.h contains the following functions which can be called in appilcation. </h3>

``` javascript   
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
  
<h3> To set the controller in Normal Mode, it needs to be initialized first. Initialization mode can be entered by calling the following function </h3>

``` javascript
CAN_Initialization_Mode(void);
```

<h3> After initialization, the bitrate, interrupts, identifier and mask should be set </h3>

``` javascript
CAN_Bitrate(int baudrate);
CAN_Interrupt_Setup(int interrupts);
CAN_Identifier_&_Mask(uint16_t id, uint16_t mask);
```

<h3> Once the setup is done, the Normal Mode can be entered. To enter the Normal Mode the following function should be called. </h3>

``` javascript
CAN_Normal_Mode(void);
```

<h3> After the Normal Mode is entered, messages can be sent on CAN bus. To send a message: the mailbox no, standard_id, extended_id, dlc, actual data in the form of an array and message priority should be passed to the function. </h3>

``` javascript
CAN_Transmit_Data_Frame(int mailbox_no, int standard_id, int extended_id, int dlc, int data[], int priority)
```

<h3> To receive messages from CAN bus, the following function should be called. The data in the messages can be accessed by the predfined structs : FIFO_0_Message[] and FIFO_1_Message[]. The fifo number should be passed. </h3>
  
``` javascript
CAN_Receive_Messages(int fifo_number);
```

<h3>As there are two FIFOs and each FIFO can hold 3 messages, so to access message 1 in the FIFO 0, the user should send fifo_number = 0 and access the data from struct FIFO_0_Message[0]. </h3>

 ``` javascript
 CAN_Receive_Messages(0);
 int standard_id = FIFO_0_Message[0].standard_id;
 int extended_id = FIFO_0_Message[0].extended_id;
 int standard_id = FIFO_0_Message[0].standard_id;
 //refer the CAN_Frame struct in CAN.h
 ```
