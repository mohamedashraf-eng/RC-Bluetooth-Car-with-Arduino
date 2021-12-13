/*
  Author: Wx & Derwy.
  Date: 12/8/2021.
  Subject: Main file to excute the code.
*/
//======= ======= ======= ======= ======= ======= ======= ======= =======

// Headers Included:
#include "Movement.h"
#include "BLUHC05.h"

// Global Variables:

// Timer interrupt variables.
unsigned long TIME[] = {0, 0, 0};

char bluetooth_input;

const uint8_t BUZZ = 9;

void setup() 
{
  // For debugging.
  //Serial.begin(115200);
  pinMode(BUZZ, OUTPUT);
  digitalWrite(BUZZ, LOW);
  
// code routine.
  // INIT FUNCTION FOR THE L293d.
  L293d_INIT();

  // INIT FUNCTION FOR THE HC05.
  HC05_INIT();

  
  // Setting init time for the code: (time in milliseconds)
  for(uint8_t i = 0; i < 3; i++) {TIME[i] = millis();}
}

void loop() 
{
  
  // Detect the bluetooth data input:
  if(Serial.available() > 0)
  {
    bluetooth_input = HC05_DATA.read();

    CAR_MOVEMENT(bluetooth_input, 85);
  }


}
