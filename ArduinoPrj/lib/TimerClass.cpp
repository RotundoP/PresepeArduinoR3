#include <Arduino.h>
#include <TimerClass.h>

TimerClass::TimerClass(int secTime)
{
    sec_count = secTime;
}

bool TimerClass::TonTimer(bool enable)
{
    prev_mills = mills;
    mills = millis();
    delta_mills = mills - prev_mills;
    Serial.print(delta_mills);
    delay(1000);
    return true;
}



