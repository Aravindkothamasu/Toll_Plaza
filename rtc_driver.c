#include"header.h"
U8 ab[7] = {0x45,0x45,0x13,0x4,0x20,0x6,0x19};
code U8 day[7][4]= {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};


void set_time(void)						//For setting a time
{
	S8 i;
	for(i=0;i<7;i++)	
		i2c_device_write(0xD0, i , ab[i] );

}




void get_time(void)						//For getting time
{
	S8 i;
	for(i=0;i<7;i++)	
		ab[i] = i2c_device_read(0xD0 , i );
				
}


void pf_time(void)						//For Printing time
{		
	/****************For hour***************/
	if(ab[2] > 0x12)					//If it greater than 12 hours
		ab[2] -= 0x12;

	time_shrt(ab[2]);					//Printing time (hr's)
	lcd_data(':');
	uart_tx(':');
	
	
	/***************For min****************/
	time_shrt(ab[1]);
	lcd_data(':');
	uart_tx(':');
	
	
	/***************For sec***************/
	time_shrt(ab[0]);

///////////////2nd line in LCD/////////////	

	
//	lcd_cmd(0xc0);
	
	
 	/*****for day*****/
		lcd_string(day [ ab[3]-1 ] );
		lcd_data(' ');
	
	/****for date*****/
		time_shrt(ab[4]);
		lcd_data('/');

	/****for month*****/
		time_shrt(ab[5]);
		lcd_data('/');
	
	/****for year*****/
		lcd_data(50);
		lcd_data(48);
		time_shrt(ab[6]);
 }

 
#if(abc==1)
void time_shrt(U8 t)
{
		lcd_data((t/16)+48);
		lcd_data((t%16)+48);
		
		uart_tx((t/16)+48);
		uart_tx((t%16)+48);

}
#endif
