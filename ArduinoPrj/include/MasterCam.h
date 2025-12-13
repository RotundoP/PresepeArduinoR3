#ifndef MasterCam_h
#define MasterCam_h

    class MasterCam
    {
        public:
            MasterCam(int maxV, float tSample, float period); // constructor
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

    MasterCam::MasterCam(int maxV, float tSample, float period)
    {
        maxVal = maxV;
        updateTime = tSample;
        camPeriod = period;

        samplesTot = camPeriod / updateTime;
        incrsPerSample = maxVal / samplesTot;
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
