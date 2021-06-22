# Nokia 5110

### Driver for Nokia 5110         |         [Datasheet](https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf)


#### Functions :
```C
void N5110_Init(SPI_TypeDef *SPI);
void N5110_Reset_High(void);
void N5110_Reset_Low(void);
void N5110_DC_High(void);
void N5110_DC_Low(void);
void N5110_Send_Command(uint8_t Command_Byte);
void N5110_Send_Data(unint8_t Data);
void N5110_Invert_Screen(void);
void N5110_Set_Pointer(uint8_t x, uint8_t y);
void N5110_Draw_Point(uint8_t x, uint8_t y);
void N5110_Printf(uint8_t x,uint8_t y, char *s);
void N5110_Screen_Clear();
```

#### To initialize the display, call the N5110_Init function by passing the the either SPI1 or SPI2.
```C
N5110_Init(SPI1);
```

#### To print text on the screen, call N5110_Printf function by passing x & y co-ordinates and the string to be printed.

```C
N5110_Printf(0,0,"hello world");
```

#### Clear the screen by calling N5110_Screen_Clear function.
```C
N5110_Screen_Clear();
```
