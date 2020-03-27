<h1> Inter Integrated Circuit (I2C) </h1>


<h4> The functions available to the user are:</h4>

```
void I2C_Master_Init(void);
void I2C_Master_Start(void);
void I2C_Master_Address_Read(uint8_t data);
void I2C_Master_Address_Write(uint8_t data);
void I2C_Master_Send_Data( uint8_t data);
int I2C_Master_Rx_Data(void);
void I2C_Master_Stop(void);
````

<h4> The user must define the I2C peripheral to be used: </h4>

``` 
I2C = I2C1 
or
I2C = I2C2
```

<h4> To initialize I2C in master mode, call the following function </h4>

```
I2C_Master_Init();
```

<h4> To write to a slave device: </h4>

```
I2C_Master_Address_Write(Slave_Address);
```

<h4> To read from a slave device: </h4>

```
I2C_Master_Address_Read(Slave_Address);
```

<h4> To write data to a slave device: </h4>

```
I2C_Master_Send_Data(0x52); //or any data
```

<h4> To read data from a slave device: </h4>

```
I2C_Master_Rx_Data(0x52); //or any data
```
