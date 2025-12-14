#ifndef Fade_H
#define Fade_H

    class PointXY
    {
        public:
            float X;
            float Y;
    };

    class Fade
    {
        public:
            Fade(PointXY p[5]);
            float UpdateCam(float masterVal);

        private:
            float c0, c1, c2, c3;
            float y0, max_y, min_y;
    };

    Fade::Fade(PointXY p[5])
    {
        p[0].X;
        p[0].Y;
    }

    float Fade::UpdateCam(float masterVal)
    {
        return 1.0;
    }

#endif