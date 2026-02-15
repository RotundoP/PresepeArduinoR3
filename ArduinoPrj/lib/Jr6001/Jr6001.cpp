#include <Jr6001.h>

Jr6001::Jr6001()
{
    for(int i = 0; i < 6; i++) 
    {
        currentTrack[i] = '_';
    }

    currentVolume = 20; // default value
}

void Jr6001::play(char* retCode)
{
    // Directive: 'A2'
    retCode[0] = 'A';
    retCode[1] = '2';
    retCode[2] = '\0';
}

void Jr6001::pause(char* retCode)
{
    // Directive: 'A3'
    retCode[0] = 'A';
    retCode[1] = '3';
    retCode[2] = '\0';
}

void Jr6001::stop(char* retCode)
{
    // Directive: 'A4'
    retCode[0] = 'A';
    retCode[1] = '4';
    retCode[2] = '\0';
}

void Jr6001::next(char* retCode)
{
    // Directive: 'A5'
    retCode[0] = 'A';
    retCode[1] = '5';
    retCode[2] = '\0';
}

void Jr6001::last(char* retCode)
{
    // Directive: 'A6'
    retCode[0] = 'A';
    retCode[1] = '6';
    retCode[2] = '\0';
}

void Jr6001::setVolume(char* retCode, int volLevel)
{
    // Directive: 'AF:XX' where XX is 0 to 30
    if(volLevel > 30)
        volLevel = 30;
    else if (volLevel < 0)
        volLevel = 0;

    int tens, units;
    tens = volLevel / 10;
    units = volLevel - (tens * 10);

    currentVolume = volLevel;

    retCode[0] = 'A';
    retCode[1] = 'F';
    retCode[2] = ':';
    retCode[3] = tens + '0';
    retCode[4] = units + '0';
    retCode[5] = '\0';
}

void Jr6001::volumeUp(char* retCode)
{
    if(currentVolume < 30)
    {
        currentVolume++;
    
        // Directive: 'B0'
        retCode[0] = 'B';
        retCode[1] = '0';
        retCode[2] = '\0';
    }
}


void Jr6001::volumeDown(char* retCode)
{
    if(currentVolume > 0)
    {
        currentVolume--;

        // Directive: 'B1'
        retCode[0] = 'B';
        retCode[1] = '1';
        retCode[2] = '\0';
    }
}

int Jr6001::getVolume()
{
    return currentVolume;
}

void Jr6001::playTrack(char* retCode, int trackNr)
{
    int hundreds, tens, units;
    hundreds = trackNr / 100;
    tens = (trackNr - (hundreds * 100)) / 10;
    units = trackNr - (tens * 10);

    retCode[0] = 'A';
    retCode[1] = '7';
    retCode[2] = ':';
    retCode[3] = '0';
    retCode[4] = '0';
    retCode[5] = hundreds + '0';
    retCode[6] = tens + '0';
    retCode[7] = units + '0';
    retCode[8] = '\0';
}