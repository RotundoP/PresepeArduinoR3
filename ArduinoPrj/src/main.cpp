#include <Arduino.h>
#include <Servo.h>
#include <Ticker.h>
#include "header.h"
#include "MasterCam.h"

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
Servo myservo;
MasterCam Master(0.25, 60);
Ticker tickerMaster(masterUpdate, 250, 0, MILLIS);

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

    tickerMaster.start();
}

void loop() {
    if (Master.actValue < 1000)
    {
        analogWrite(CometStarPwmPin,0);
        analogWrite(SkyPwmPin,0);
        analogWrite(DayLightPwmPin,230);
    }
    else if (Master.actValue >= 1000 && Master.actValue < 4000)
    {
        analogWrite(CometStarPwmPin,0);
        analogWrite(SkyPwmPin,50);
        analogWrite(DayLightPwmPin,0);
    }
    else
    {
        analogWrite(CometStarPwmPin,50);
        analogWrite(SkyPwmPin,50);
        analogWrite(DayLightPwmPin,0);
    }
    
    tickerMaster.update();
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

void masterUpdate()
{
    Serial.println(Master.actValue);
    Master.Update();
}