#include <Arduino.h>
#include <Servo.h>
#include <Ticker.h>
#include "header.h"
#include "TimerClass.h"

//#define DubugMode
#ifdef DubugMode
    #include "avr8-stub.h"
    #include "app_api.h"
#endif

#define CometStarPwmPin 3     
#define SkyPwmPin 5  
#define DayLightPwmPin 6   

int CometStarFadeVal, SkyFadeVal; 
int servoPos = 0;    // variable to store the servo position
//TimerClass MyTontime = TimerClass(10);
TimerClass pippo(5);
Servo myservo;

void func() {
  Serial.println("func.");
  }
Ticker ticker1(func, 1000, 0, MILLIS);

void setup() {
    #ifdef DubugMode
        debug_init();
    #else
        Serial.begin(9600);
    #endif
    myservo.attach(13);

    pinMode(CometStarPwmPin, OUTPUT);
    pinMode(SkyPwmPin, OUTPUT);
    pinMode(DayLightPwmPin, OUTPUT);
    CometStarFadeVal = 255;
    //pinMode(LED_BUILTIN,OUTPUT);

    ticker1.start();
}

void loop() {
    analogWrite(CometStarPwmPin,CometStarFadeVal);
    analogWrite(SkyPwmPin,CometStarFadeVal);
    analogWrite(DayLightPwmPin,CometStarFadeVal);
    
    delay(200);
    increaseFade(&CometStarFadeVal, -5);

    ticker1.update();
    Serial.println("test");
    //MyTontime.TonTimer(true);
    //digitalWrite(LED_BUILTIN, LOW);
    //delay(500);
    //TON_longDelay(30);

    /*
    for (servoPos = 0; servoPos <= 180; servoPos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(servoPos);              // tell servo to go to position in variable 'servoPos'
        delay(200);                       // waits 15ms for the servo to reach the position

    }

    for (servoPos = 180; servoPos >= 0; servoPos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(servoPos);              // tell servo to go to position in variable 'servoPos
        delay(200);                       // waits 15ms for the servo to reach the position
    }
   */
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
