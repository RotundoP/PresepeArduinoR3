#include <Arduino.h>
#include <Ticker.h>
#include "header.h"
#include "MasterCam.h"
#include "Cam.h"
#include "Jr6001.h"

//#define DubugMode
#ifdef DubugMode
    #include "avr8-stub.h"
    #include "app_api.h"
#endif

#define CometStarPwmPin 3     
#define SkyPwmPin 5  
#define DayLightPwmPin 6  

// constant definition
const float sampleTime = 0.5;
const int masterCamPeriod = 120;

MasterCam Master(sampleTime, masterCamPeriod);
Ticker tickerMaster(masterUpdate, sampleTime * 1000.0f, 0, MILLIS);

Jr6001 audioModule;
char TX_toAudioModule[10];

// Sky points and cam definition
PointXY sky_p0(0, 0.0f);
PointXY sky_p1(30, 0.0f);
PointXY sky_p2(60, 0.0f);
PointXY sky_p3(90, 0.0f);
PointXY sky_p4(120, 5.0f);
PointXY sky_p5(150, 10.0f);
PointXY sky_p6(180, 10.0f);
PointXY sky_p7(210, 5.0f);
PointXY sky_p8(240, 5.0f);

PointXY *sky_poly[] = {&sky_p0, &sky_p1, &sky_p2, &sky_p3, &sky_p4, &sky_p5, &sky_p6, &sky_p7, &sky_p8}; // Array of pointer to the class type
Cam Sky(sky_poly, 9, (int)(masterCamPeriod/sampleTime));

// CometStar points and cam definition
PointXY comet_p0(0, 0.0f);
PointXY comet_p1(30, 0.0f);
PointXY comet_p2(60, 0.0f);
PointXY comet_p3(90, 0.0f);
PointXY comet_p4(120, 5.0f);
PointXY comet_p5(150, 8.0f);
PointXY comet_p6(180, 8.0f);
PointXY comet_p7(210, 5.0f);
PointXY comet_p8(240, 0.0f);

PointXY *comet_poly[] = {&comet_p0, &comet_p1, &comet_p2, &comet_p3, &comet_p4, &comet_p5, &comet_p6, &comet_p7, &comet_p8}; // Array of pointer to the class type
Cam Comet(comet_poly, 9, (int)(masterCamPeriod/sampleTime));

// DayLight points and cam definition
PointXY dayLight_p0(0, 0.0f);
PointXY dayLight_p1(30, 30.0f);
PointXY dayLight_p2(60, 50.0f);
PointXY dayLight_p3(90, 30.0f);
PointXY dayLight_p4(120, 0.0f);
PointXY dayLight_p5(150, 0.0f);
PointXY dayLight_p6(180, 0.0f);
PointXY dayLight_p7(210, 0.0f);
PointXY dayLight_p8(240, 0.0f);

PointXY *dayLight_poly[] = {&dayLight_p0, &dayLight_p1, &dayLight_p2, &dayLight_p3, &dayLight_p4, &dayLight_p5, &dayLight_p6, &dayLight_p7, &dayLight_p8}; // Array of pointer to the class type
Cam DayLight(dayLight_poly, 9, (int)(masterCamPeriod/sampleTime));

void setup() {
    #ifdef DubugMode
        debug_init();
    #else
        Serial.begin(9600);
    #endif
    
    pinMode(CometStarPwmPin, OUTPUT);
    pinMode(SkyPwmPin, OUTPUT);
    pinMode(DayLightPwmPin, OUTPUT);

    tickerMaster.start();
}

void loop() {
    float pwmValue;
    static int trackNr = 1;
    tickerMaster.update();

    pwmValue = Sky.UpdateCam(Master.actValue);
    analogWrite(SkyPwmPin,round(pwmValue));

    pwmValue = Comet.UpdateCam(Master.actValue);
    analogWrite(CometStarPwmPin,round(pwmValue));

    pwmValue = DayLight.UpdateCam(Master.actValue);
    analogWrite(DayLightPwmPin,round(pwmValue));
    //DayLight.printPoints();
  
    audioModule.play(TX_toAudioModule);
    Serial.print(TX_toAudioModule);
    delay(2000);
    audioModule.setVolume(TX_toAudioModule, 5);
    Serial.print(TX_toAudioModule);
    delay(2000);
    audioModule.playTrack(TX_toAudioModule, trackNr++);
    Serial.print(TX_toAudioModule);
    //Serial.println(trackNr);
    delay(2000);
}

void masterUpdate()
{
    //Serial.println(Master.actValue);
    Master.Update();
}