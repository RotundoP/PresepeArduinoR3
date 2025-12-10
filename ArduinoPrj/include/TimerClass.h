#ifndef TimerClass_h
#define TimerClass_h
    #include <Arduino.h>

    class TimerClass
    {
        public:
            TimerClass(int secTime); // constructor
            bool TonTimer(bool enable);
        private:
            int sec_count;
            unsigned long mills;
            unsigned long prev_mills;
            int delta_mills;
    };
#endif