# Toll_Plaza
By Using AT89S52(8051) , Implementation of Toll Plaza .
By Using keil 4 version implementation of Toll Plaza,


INTERFACINGS:
      LCD,RFID Reader (RDM6300),
   I2C protocol interfacings :  EEPROM,RTC.


How to Compile:
      Create a Project with AT89S52,and add all those files in this repository and set a Crystal Freq of 12 Mhz and do the whole compile.


Description:
      rfid_driver:
                It is heart of the project,the main this happens in this file it self,from RFID card reads to checking with database and checking the avaliable balance and detect the amount.
                              
      main.c:
                it driver to the rfid_driver.c file .
            
there are other files which describe the their functionalities of that their particular function.            
