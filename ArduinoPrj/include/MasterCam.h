#ifndef MasterCam_h
#define MasterCam_h

    class MasterCam
    {
        public:
            MasterCam(float tSample, float period); // constructor
            void Update();
            void Reset();
            float actValue;

        private:
            int maxVal;
            float samplesTot;
            float camPeriod; // [s]
            float updateTime; // [s]
            float incrsPerSample;

            float counter;
    };

    MasterCam::MasterCam(float tSample, float period)
    {
        updateTime = tSample;
        camPeriod = period;
        incrsPerSample = 1;

        samplesTot = camPeriod / updateTime;
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
