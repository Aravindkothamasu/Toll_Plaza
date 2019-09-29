#include<reg51.h>
#include"header.h"
#if(abc==1)
void uart_init(unsigned int band)					//UART initilization
{
	SCON |= 0X50;
	TMOD |= 0x20;
	switch(band)
	{
		case 7200:  TH1 = 252; break;
		case 9600:  TH1 = 253; break;
		case 14440: TH1 = 254; break;
		case 28800: TH1 = 255; break;
		case 57600: TH1 = 255; PCON |=0x80; break;
	}
	TR1 = 1;
}
#endif

#if(abc==1)
void uart_tx_string(unsigned char *s)					//transmit string 
{
	while(*s)
		uart_tx(*s++);
}
#endif

#if(abc==1)
void uart_tx(unsigned char ch)						//trasmit a character
{	
	SBUF = ch;
	while(TI == 0);
	TI = 0;
}
#endif

#if(abc==1)
unsigned char uart_rx()							//uart recieve a character
{
 	while(RI == 0);
	RI = 0;
	return SBUF;
}
#endif
