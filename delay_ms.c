#include"header.h"
#if(abc==1)
void delay_ms(unsigned int ms)
{
	unsigned char i;
	for( ;ms>0;ms--)			//Produces 2 micro sec delay
	{
		for(i=250;i>0;i--);		//Produces 501 micro sec delay
		for(i=247;i>0;i--);		//Produces 497 micro sec delay
	}
}
#endif
