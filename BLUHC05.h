/*
  Author: Wx & Derwy.
  Date: 12/8/2021.
  Subject: Bluetooth control header. 
*/
//======= ======= ======= ======= ======= ======= ======= ======= =======

//Header Guards:
#ifndef __BLUHC05_H__
#define __BLUHC05_H__

#include <SoftwareSerial.h>

/****************************************
 *          Declared Functions          *
****************************************/

void HC05_INIT(void);

/****************************************
 *          Global Variables            *
****************************************/           

const uint8_t BLUHC05_PINS[2] = {
                                 10, // Rx Ardu - Tx HC05
                                 11 //  Tx Ardu - Rx HC05
                                 }; 

                                 
#define ArduMini_Rx BLUHC05_PINS[0]
#define ArduMini_Tx BLUHC05_PINS[1]         

SoftwareSerial HC05_DATA(ArduMini_Rx, ArduMini_Tx);

/****************************************
 *          Main Functions              *
****************************************/

void HC05_INIT(void)
{
  // wait for bluetooth to connect.
  while(!Serial) {;}

  HC05_DATA.begin(9600);
}


//======= ======= ======= ======= ======= ======= ======= ======= =======
#endif
