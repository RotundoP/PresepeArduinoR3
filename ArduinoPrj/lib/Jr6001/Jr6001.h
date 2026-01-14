#ifndef Jr6001_H
#define Jr6001_H
    #include <Arduino.h>

    class Jr6001
    {
        public:
            Jr6001();

            void play(char* retCode);
            void pause(char* retCode);
            void stop(char* retCode);
            void next(char* retCode);
            void last(char* retCode);
            void playTrack(char* retCode, int trackNr);
            void setVolume(char* retCode, int volLevel);
            void volumeUp(char* retCode);
            void volumeDown(char* retCode);
            int getVolume();

        private:
            char currentTrack[6];
            int currentVolume;

    };

#endif