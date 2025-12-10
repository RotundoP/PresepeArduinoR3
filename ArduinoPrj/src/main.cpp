#include <Arduino.h>

int CometStarPwmPin = 3;       
int SkyPwmPin = 5;               
int CometStarFadeVal, SkyFadeVal; 

void setup() {
    Serial.begin(9600);
    pinMode(CometStarPwmPin, OUTPUT);
    pinMode(SkyPwmPin, OUTPUT);

    pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
    analogWrite(CometStarPwmPin,500);
    Serial.print("Hello");
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
}

//void increaseFade();
