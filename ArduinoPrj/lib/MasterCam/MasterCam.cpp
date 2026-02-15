#include <MasterCam.h>

MasterCam::MasterCam(float tSample, int period)
{
    updateTime = tSample;
    camPeriod = period;
    incrsPerSample = 1;

    samplesTot = (int)(camPeriod / updateTime);
    maxVal = incrsPerSample * samplesTot;
}

void MasterCam::Update()
{
    counter = counter + incrsPerSample;

    if (counter > maxVal)
        counter = 0.0;

    actValue = counter;
}

void MasterCam::Reset()
{
    counter = 0.0;
}