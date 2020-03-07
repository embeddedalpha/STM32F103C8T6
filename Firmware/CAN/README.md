# Controller Area Network

The CAN.h contains the following functions

``` javascript   
int CAN_Initialization_Mode();
int CAN_Normal_Mode();
int CAN_Sleep_Mode();
void CAN_Bitrate(int baudrate);
void CAN_Test_Mode_Setup(int mode);
int CAN_Transmit_Data_Frame(int mailbox_no, int standard_id, int extended_id, int dlc, int data[], int priority);
int CAN_Buffer_0_Transmission_Errors(void);
int CAN_Buffer_1_Transmission_Errors(void);
int CAN_Buffer_2_Transmission_Errors(void);
void CAN_Receive_FIFO_Data(int fifo_number,struct CAN_Frame rx_frame);
int CAN_Receive_Messages(int fifo_number);
```
  
