#ifndef TimerClass_h
#define TimerClass_h

    class TimerClass
    {
        public:
            TimerClass(int); // constructor
            bool TonTimer(bool);
        private:
            int sec_count;
            unsigned long mills;
            unsigned long prev_mills;
            int delta_mills;
    };

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
#endif
