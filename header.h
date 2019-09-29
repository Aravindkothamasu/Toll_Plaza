#ifndef _HEADER_H_
#define _HEADER_H_
#include<reg51.h>
typedef unsigned char U8;
typedef unsigned int U16;
typedef signed char S8;



/***************************delay functions*********************/
extern void delay_ms(unsigned int); 






/************read and write functions on lcd and switches**********/
extern void io_write(int PORT ,int PIN,int VAL);	
extern void io_byte_write(int,int);	
extern int io_read(int ,int );






/************************lcd functions*****************************/
extern void lcd_int( int );
extern void lcd_float(float);
extern void lcd_data(unsigned char d);
extern void lcd_init(void);
extern void lcd_cmd(unsigned char c);
extern void lcd_string(char *s);
extern void lcd_string_cir(char *s,char j);
extern void lcd_custom(void);
extern void lcd_scrol(char *);





/***************************keypad function**************************/
extern unsigned char keyscan(void);





/************************string based funtions**********************/
extern int my_strcmp(char *,char *);
extern void str_rev(U8 *);
extern void my_strcpy(char *,char *);






/***************************timer based funtions********************/
extern void tdelay_1ms(void);
extern void tdelay_500us(void);






/*******************************uart function*************************/
extern void uart_init(unsigned int );
extern void uart_tx(unsigned char );
extern unsigned char uart_rx(void);
extern void uart_tx_string(unsigned char*);
extern void uart_rx_string(U8 *,U8);
extern int uart_exp(unsigned char *);






/**************************additional based functions***************/
extern int pwd_check(unsigned char *);
extern void addition(unsigned char *);
extern void palindrome(U8 *,U8 *);





/************************for configurring the interrupt****************/
extern void config_interrupt(void);





/**********************i2c driver functions**************************/
extern void i2c_start(void);
extern void i2c_stop(void);
extern void i2c_write(U8);
extern U8 i2c_read(void);
extern void i2c_ack(void);
extern void i2c_noack(void);
extern void i2c_device_write(U8 ,U8,U8);
extern U8 i2c_device_read(U8 ,U8 );
extern void i2c_read_string(U8 ,U8 );
extern void i2c_write_string(U8 ,U8,U8 *);
extern void i2c_store(U8 *,U8 ,U8 );





/****************************RTC functions****************************/
extern void set_time(void);
extern void get_time(void);
extern void pf_time(void);
extern void time_shrt(U8 );





/***************************RFID fuctions*****************************/
extern void dc_motor(void);
extern void rfid_read(U8 *);
extern void data_base(void);
extern void display(U8);
extern void id_match(U8 );
extern void rfid_strcmp(U8 *);
extern void gallapetti(U8 );
extern void recharge(U8);





/**************************Extra Functions*************************/
extern void inits(void);
extern void print_hexa(U8 );
extern void pf_integer(U8);
extern void stppr_motor(void);
extern void config_int(void);



#define LED1 0
#define LED2 1
#define LED3 2
#define LED4 3

#define abc 1 

#define PORT0 0
#define PORT1 1
#define PORT2 2
#define PORT3 3

#define PO0 0
#define PO1 1
#define PO2 2
#define PO3 3


#define HIGH  1
#define LOW   0

#endif
