#ifndef MasterCam_h
#define MasterCam_h

    class MasterCam
    {
        public:
            MasterCam(float tSample, int period); // constructor
            void Update();
            void Reset();
            int actValue;

        private:
            int maxVal;
            int samplesTot;
            int camPeriod; // [s]
            float updateTime; // [s]
            int incrsPerSample;

            int counter;
    };

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

#endif
