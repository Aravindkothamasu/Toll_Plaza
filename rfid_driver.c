#include"header.h"
sbit M1 = P2^5;
sbit M2 = P2^6;
code U8 id[3][4] = { {3,20,35,30} , {53,70,85,40} , {103,120,135,50} };					
			//id.no , name , amount , Toll charge offset addrr.

	
	
	
/******************************************************************/
//                       RFID READ                                //
//                TAKING an array (temp) from main                //
//                  Filtering temp and print                      

	
	
	
#if(abc==1)
void rfid_read(U8 *temp)				//RFID read function.
{
		U8 i,tem,temp1=0;	
		for(i=0;i<12;i++)			//RFID tags gives 14 bytes and 12 will be useful
		{
			tem = uart_rx();
			if( (tem >= 'A' && tem <= 'Z') || ( tem >='0'&& tem <='9'))
			{						//Except A-Z ad 0-9 remaining to be ignored.
				temp[i] = tem;
				temp1  ^= tem;
			}
			else
				i--;
		}
		temp[i] = 0;
		lcd_string(temp);
		uart_tx_string("\r\n Your card no: ");
		uart_tx_string(temp);
		uart_tx_string("\r\n");			//Printing on UART
		
		delay_ms(400);
}
#endif


/***************************************************************/
//                   DATA BASE func                            //
//            ENTERING ALL DETAILS INTO EEPROM                 //
//              I'd , NAME , money                             // 

#if(abc==1)
void data_base(void)
{	
		/**********************Card 1***************************/
		i2c_write_string(0xA0,3,"0600034A0B44");			//Id1 3-18
		i2c_write_string(0xA0,20,"Akhil");				//Id1 name 20 - 30
		i2c_device_write(0xA0,35,250);					//Balance
	
	
		/**********************Card 2***************************/
	
		i2c_write_string(0xA0,53,"120062733437");			//Id2 53-68
		i2c_write_string(0xA0,70,"Saaaaam");				//Id2 name
		i2c_device_write(0xA0,85,200);					//Balance
	
	
	
		/**********************Card 3***************************/
	
		i2c_write_string(0xA0,103,"0200108F8C11");			//Id3 103-118
		i2c_write_string(0xA0,120,"Hanumesh");			 	//Id1 name 
		i2c_device_write(0xA0,135,116);					//Balance
}
#endif


/*****************************************************************/
//                      STRING COMPARE                           //
//                     WITH DATA BASE I'ds                       //
//              IF IT MATCH SEND TO "id_match()"                 // 
//                    IF NOT "Error msg"                         //


#if(abc==1)
void rfid_strcmp(U8 *tag)
{
	U8 da_bse[13],k,i;
	uart_tx_string("\r\nChecking with data base...Plz wait\r\n");
	delay_ms(1500);
	
	
	for(i=3,k=0 ; i<=104 ; i+=50,k++)
	{
		i2c_store(da_bse,0xA0,i);			//storing   Id's no. into array
		if((my_strcmp(da_bse,tag))==1)
		{
			id_match(k);
			return;
		}
	}	
	uart_tx_string("\n\rError 404 Not Found");
	lcd_cmd(0x1);
	lcd_string("Err 404 Not Found");	
	return;
	
}
#endif


/**********************************************************************/
//                  READ THE AVALIABLE BALANCE AND REQ.BAL            //
//                        IF(AVL >= REQ) IS TRUE THEN                 //
//                 DETDECTED THE AMT AND DISPLAY THE INFO.            //
//                        AND RUNS DC MOTOR                           //
//                  IF NOT . USER DOES'T HAVE SUFFICIENT BAL          //
//                        200 AMT HASE BEEN RECHARGE .                //



#if(abc==1)
void id_match(U8 k)
{
	
	U8 avl = i2c_device_read(0xA0,id[k][2]);							//Avaliable Bal
	U8 req = id[k][3];																		//Req for Toll
	delay_ms(2000);

	if(avl >= req)
	{
			i2c_device_write(0xA0,id[k][2],avl - req);
			gallapetti(req);
			display(k);
			dc_motor();
			uart_tx_string("\r\nThank You\r\n");
			uart_tx_string("Next Plz\r\n");
	}
	else
	{
		uart_tx_string("\r\nYou don't have sufficient bal..\r\n");
		delay_ms(3000);
		uart_tx_string("Recharge now it self\t\n");
		recharge(k);
		display(k);
		dc_motor();
	}
}

/************************************************************************/
//                            DISPLAY FUNC                              //
//                      DISPLAY THE I'd ,NAME AND MONEY                 //
//                      AMT DETECTED AND BAL AVALIABLE                  //
//                   ALL THESE SHOULD PRINT ON UART AND LCD             //


#if(abc==1)
void display(U8 k)
{
	U8 j = i2c_device_read(0xA0,id[k][2]);	

	lcd_cmd(0x1);					
	i2c_read_string(0xA0,id[k][0]);						//id printing
	
	lcd_cmd(0xc0);
	
	uart_tx_string("\r\nName :  ");						//name printing
	i2c_read_string(0xA0,id[k][1]);
	uart_tx_string("\r\n\r\n");
	
	lcd_cmd(0xD0);								//RTC printing
	get_time();
	pf_time();
	
	
	lcd_cmd(0x94);

	uart_tx_string("\r\nAmt deduct: ");
	lcd_string("Fee-");
	pf_integer(id[k][3]);							//Bal Left
	lcd_string("  Bal: ");
	uart_tx_string("\r\nBal left: ");
	pf_integer(j);
}
#endif


/**************************************************************************/
//                         GALLAPETTI                                     //
//                 CASH BOX NO.(200 LSB)  (201 MSB)                       //
//                     STORING INTO EEPROM                                //


#if(abc==1)
void gallapetti(U8 amt)
{
	static U16 tot;
	tot += amt;																					//Every time mny is added
	i2c_device_write(0xA0,200,tot);				 //For storing LSB
	i2c_device_write(0xA0,201,(tot<<8)); 			 //For storing MSB
}	
#endif



/***************************************************************************/
//                               RECHARGE FUNCTION                         //
//                            AMT ADDED TO GALLAPETTI                      //





#if(abc==1)
void recharge(U8 k)
{
	U8 j;
	uart_tx_string("\r\n200 is added in ur a/c\r\n");
	delay_ms(2000);
	j = i2c_device_read(0xA0,id[k][2] );
	i2c_device_write(0xA0, id[k][2] ,j + ( 200 - id[k][3] ) );							//adding 200-Toll Charge
	gallapetti(200);																										//adding Amt to Cash box
}
#endif


/*************************************************************************/
//                              DC MOTOR                                 //
//									 //
//									 

#if(abc==1)
void dc_motor()
{
	uart_tx_string("\r\nDC mo");
	M2 = 0;								//For clock wise
	M1 = 1;
	
	delay_ms(500);
	
	M2 = M1 = 1;							//For stop
	
	delay_ms(2000);
	
	M1 = 0;								//For anti clock wise
	M2 = 1;
	
	delay_ms(500);
	
	M1 = M2 = 1;							//for stop
}
#endif
/**************************************************************************/
//                             INTERRUPT TO                               //
//                           CHECK GALLAPETTI                             //
/*void interr_mny(void) interrupt 0
{
 	uart_tx_string("Bal in Tool kit:   ");
	uart_tx(i2c_device_read(0xA0,201));
	uart_tx(i2c_device_read(0xA0,200));

} */
