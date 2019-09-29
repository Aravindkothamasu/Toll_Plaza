#include"header.h"
#include<reg51.h>

void main()
{
		U8 temp[15];
		inits();					//initilization for interface's
		while(1)
		{
			uart_tx_string("Please Scan your ID\r\n");
			rfid_read(temp);			//it will block the Program untill card reads
			rfid_strcmp(temp);			//compare with database
			uart_tx_string("\r\n\r\n\r\n");		
		}
}
