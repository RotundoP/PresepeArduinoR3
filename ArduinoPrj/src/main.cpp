#include <Arduino.h>
#include <header.h>

int CometStarPwmPin = 3;       
int SkyPwmPin = 5;               
int CometStarFadeVal, SkyFadeVal; 

void setup() {
    Serial.begin(9600);
    pinMode(CometStarPwmPin, OUTPUT);
    pinMode(SkyPwmPin, OUTPUT);
    CometStarFadeVal = 245;
    //pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
    //analogWrite(CometStarPwmPin,500);
    
    delay(500);
    increaseFade(&CometStarFadeVal, -10);
    Serial.println("CometStar value: ");
    Serial.print(CometStarFadeVal);
    Serial.println();
    //digitalWrite(LED_BUILTIN, LOW);
    //delay(500);
   
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
