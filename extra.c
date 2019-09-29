#include"header.h"
#include<reg51.h>

#if(abc==1)
void inits() 
{
	lcd_init();					//lcd initilization
	uart_init(9600);				//uart initilization for 9600 baudrate
	data_base();					//data base initilization i.e (i'd,name,balance) 
	config_int();					//Configuration of interrupt
	set_time();					//For Setting time
	
}
#endif

#if(abc==1)
void pf_integer(U8 j)					//For printing Integer
{
		uart_tx(j/100+48);			//For 3-digit printing
		uart_tx(((j/10)%10)+48);		//On UART
		uart_tx((j%10)+48);
		
		lcd_data(j/100+48);			//for 3-digit printing
		lcd_data(((j/10)%10)+48);		//On LCD
		lcd_data((j%10)+48);
}
#endif

#if(abc==1)
void config_int()					//for cofiguring interrrupt
{
	EX0 = 1;
	EA  = 1;
	IT0 = 1;
}
#endif
