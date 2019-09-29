#include"header.h"
#include<reg51.h>

sbit SDA = P2^0;
sbit SCL = P2^1;

#if(abc==1)
void i2c_start()						//i2c_start func
{
 SCL = 1;
 SDA = 1;
 SDA = 0;
}
#endif

#if(abc==1)
void i2c_stop()							//i2c_stop func
{
	SCL = 0;
	SDA = 0;
	SCL = 1;
	SDA = 1;
}
#endif

#if(abc==1)
void i2c_write(U8 d)						//i2c_write func
{
	signed char i;
	for(i=7;i>=0;i--)
	{
	  SCL = 0;
   	  SDA = (d&(1<<i))?1:0;
	  SCL = 1;
	}
}
#endif

#if(abc==1)
U8 i2c_read()							//i2c_read func
{	
	U8 temp=0;
	signed char i=0;
	for(i=7;i>=0;i--)
	{
	  SCL = 1;
	  if(SDA == 1)
	       temp |= 1<<i;
	  SCL = 0;
	}
	return temp;
}
#endif

#if(abc==1)
void i2c_ack()							//i2c_acknowlwdgement func
{
	SCL = 0;
	SDA = 1;
	SCL = 1;
	while(SDA == 1);
	SCL = 0;
}
#endif


#if(abc==1)
void i2c_noack()						//i2c_no-ack func
{
	SCL = 0;
	SDA = 1;
	SCL = 1;
}
#endif

#if(abc==1)	
void i2c_device_write(U8 sa,U8 mr,U8 d)				//i2c_device_write func
{
	i2c_start();
	i2c_write(sa);
	i2c_ack();
	i2c_write(mr);
	i2c_ack();
	i2c_write(d);
	i2c_ack();
	i2c_stop();
	delay_ms(10);
}
#endif

#if(abc==1)
void i2c_write_string(U8 sa,U8 mr,U8 *buf)			//for writing a string into a i2c_device_string
{
	U8 i;
	for(i=0;buf[i];i++)
	{
		i2c_device_write(sa,mr+i,buf[i]);
	}
	i2c_device_write(sa,mr+i,'\0');
}
#endif

#if(abc==1)
void i2c_read_string(U8 sa,U8 mr)				//i2c_read string
{

	U8 temp=32,i=0;	
	do{

		uart_tx(temp);
		lcd_data(temp);
		temp= i2c_device_read(sa,mr+ (i++) );
		
		}while(temp);

}
#endif



#if(abc==1)
U8 i2c_device_read(U8 sa,U8 mr)					//i2c_device_read func
{
	U8 temp;
	i2c_start();
	i2c_write(sa);
	i2c_ack();
	i2c_write(mr);
	i2c_ack();
	i2c_start();
	i2c_write(sa|1);
	i2c_ack();
	temp = i2c_read();
	i2c_noack();
	i2c_stop();
	return temp;
}
#endif


#if(abc==1)
void i2c_store(U8 *bu,U8 sa,U8 mr)
{
	U8 temp,i=0;
	do
	{
		temp = i2c_device_read(sa,mr+i);
		bu[i++]= temp;
	}while(temp);
}
#endif
