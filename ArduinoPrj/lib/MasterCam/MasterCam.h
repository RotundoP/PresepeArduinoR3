#ifndef MASTERCAM_H
#define MASTERCAM_H

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

#endif
