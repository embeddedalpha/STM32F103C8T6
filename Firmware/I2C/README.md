<h1> Inter Integrated Circuit (I2C) </h1>


<h4> Functions available :</h4>

```C
I2C_Master_Init(I2C_Config I2C);
I2C_Master_Start(I2C_Config I2C);
I2C_Master_Send_Address(I2C_Config I2C, char address,char RW);
I2C_Master_Send_Data(I2C_Config I2C, char data);
I2C_Master_Receive_Data(I2C_Config I2C);
I2C_Master_Stop(I2C_Config I2C);
I2C_Master_Send_NACK(I2C_Config I2C);

```
<h4> Declare a struct with type I2C_Config</h4>

```C
struct I2C_Config MPU6050;
```
