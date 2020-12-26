#ifndef       _LCD_16_2_
#define       _LCD_16_2_




void LCD_Init(void);
void delay();
void lcd_cmd(unsigned char c);
 void lcd_data(unsigned char c);
void LCD_SEND_DATA(char *c);
void LCD_new_line();



#endif
