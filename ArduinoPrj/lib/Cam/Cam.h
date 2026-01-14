#ifndef Cam_H
#define Cam_H
    #include <Arduino.h>

    class PointXY
    {
        public:
            PointXY(int Px, float Py);
            int getX();
            float getY();

        private:
            int x;
            float y;
    };

    class Points : PointXY
    {
        public:
            Points();
            void SetPoints(PointXY p0,PointXY p1,PointXY p2,PointXY p3,PointXY p4 ,PointXY p5, PointXY p6, PointXY p7, PointXY p8);

        private:
            PointXY points[9];
    };

    class Cam
    {
        public:
            Cam(PointXY **p, int nrPolyPoints, int maxCamVal);
            float UpdateCam(int masterVal);
            bool isPointDefOk();
            void printPoints();

        private:
            bool pointsDefOk;
            int nrPoints;
            PointXY **points;
    };

#endif