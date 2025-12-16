#include <Arduino.h>
#include <Servo.h>
#include <Ticker.h>
#include "header.h"
#include "MasterCam.h"
#include "Cam.h"

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

PointXY sky_p0(0, 0.0f);
PointXY sky_p1(150, 100.0f);
PointXY sky_p2(300, 0.0f);
PointXY sky_p3(450, 100.0f);
PointXY sky_p4(500, 0.0f);
PointXY sky_p5(750, 100.0f);
PointXY sky_p6(900, 0.0f);
PointXY sky_p7(1100, 100.0f);
PointXY sky_p8(1200, 0.0f);

PointXY *sky_poly[9] = {&sky_p0, &sky_p1, &sky_p2, &sky_p3, &sky_p4, &sky_p5, &sky_p6, &sky_p7, &sky_p8}; // Array of pointer to the class type
Cam Sky(*sky_poly,8);

void setup() {
    #ifdef DubugMode
        debug_init();
    #else
        Serial.begin(9600);
        Sky.setSerial(&Serial);
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
    /*
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
    */
    float pwmValue;
    tickerMaster.update();
    Serial.println(Sky.);
    pwmValue = Sky.UpdateCam(Master.actValue);
    //Serial.println(pwmValue);
    analogWrite(SkyPwmPin,pwmValue);
    
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

void masterUpdate()
{
    //Serial.println(Master.actValue);
    Master.Update();
}