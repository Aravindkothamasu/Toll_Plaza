#include<reg51.h>
#include"header.h"
sbit RS = P3^4;						//RS pin decleration
sbit RW = P3^5;						//RW pin decleration
sbit EN = P3^6;						//EN-enable pin decleration

#if(abc==1)
void lcd_string(char *s)				//lcd_string func
{
	while(*s)
	{	  		
		lcd_data(*s);
		s++;
	}
}
#endif

#if(abc==1)
void lcd_cmd(unsigned char c)				//lcd command func
{
	P0 = c;
	RS = 0;
	RW = 0;
	EN = 1;
	delay_ms(2);
	EN = 0;
}
#endif

#if(abc==1)
void lcd_data(unsigned char d)				//lcd data func
{
	P0 = d;
	RS = 1;
	RW = 0;
	EN = 1;
	delay_ms(2);
	EN = 0;
}
#endif

#if(abc==1)
void lcd_init(void)					//lcd initilization func
{
	lcd_cmd(0x2);
	lcd_cmd(0x38);
	lcd_cmd(0xe);
	lcd_cmd(0x6);
	lcd_cmd(0x1);
}
#endif
