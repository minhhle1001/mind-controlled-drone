//************************************************************************
//  HCD flying example
//  (C) DZL December2013
//
// Inputs:
//
//************************************************************************
#include <Brain.h>
#include <HCD.h>

// Set up the brain reader, pass it the hardware serial object you want to listen on.
Brain brain(Serial);

// Setup the drone reader
HCD drone0;

//Drone ID's (pick 4 random numbers)
unsigned char ID0[]={
  0x16,0x01,0x55,0x11};

void setup()
{
  Serial.begin(9600);
  //Serial.println("Press 0 to bind to HCD");
}

unsigned long timer=0;

void loop()
{
  if (brain.update()) {
        Serial.println(brain.readErrors());
        Serial.println(brain.readCSV());
        //Serial.println(brain.readAttention());
    }
  if(Serial.available())
  {
    //unsigned char c=Serial.read();
    unsigned char c = '0';
    switch(c)
    {
    case '0':              //-Press zero to
      if(drone0.inactive())
        drone0.bind(ID0);
      break;
    }
  }
  //drone0.update(255,0,0x40,0,0,0x40,0x40,0);
 if(brain.readSignalQuality() == 0){
   if(brain.readAttention() >= 50){
    drone0.update(brain.readAttention(),0,0x40,0,0,0x40,0x40,0);
   }
   else{
    drone0.update(0,0,0x40,0,0,0x40,0x40,0);
   }
 }else{
  drone0.update(0,0,0x40,0,0,0x40,0x40,0);
 }
 
 
}
































