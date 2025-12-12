#include <Arduino.h>
#include "header.h"
#include "TimerClass.h"
#include "avr8-stub.h"


int CometStarPwmPin = 3;       
int SkyPwmPin = 5;               
int CometStarFadeVal, SkyFadeVal; 
TimerClass MyTontime(10);

void setup() {
    
    Serial.begin(9600);
    pinMode(CometStarPwmPin, OUTPUT);
    pinMode(SkyPwmPin, OUTPUT);
    CometStarFadeVal = 245;
    //pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
    //analogWrite(CometStarPwmPin,500);
    
    delay(200);
    increaseFade(&CometStarFadeVal, -5);
    Serial.println("CometStar value: ");
    Serial.print(CometStarFadeVal);
    Serial.println();

    //MyTontime.TonTimer(true);
    //digitalWrite(LED_BUILTIN, LOW);
    //delay(500);
    //TON_longDelay(30);
   
}

void increaseFade(int* value, int increaseUnit)
{
    int val;
    val = *value;
    val += increaseUnit;

    if (val > 255)
        val = 255;
    else if (val < 0)
        val = 0;
    
    *value = val;   
}
/*
/// @brief long acyclic TON delay [s]
/// @param value 
/// @return return expired delay status
bool TON_longDelay(bool enable, int value)
{
    if (enable)
    {

    }
    else
        return false;
}
        */
