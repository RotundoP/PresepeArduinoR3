#ifndef Cam_H
#define Cam_H

    class PointXY
    {
        public:
            float X;
            float Y;
    };

    class Fade
    {
        public:
            Fade(PointXY *p, int nrPolyPoints);
            float UpdateCam(int masterVal);

        private:
            bool pointsDefOk;
            int nrPoints;
            PointXY *points;
    };

    Fade::Fade(PointXY *p, int nrPolyPoints)
    {
        pointsDefOk = true;
        points = p;

        // Check points.X ascending order
        for (int i = 0; i < nrPoints - 1 ; i++)
        {
            if ((points+i)->X < (points+i+1)->X)
            {
                //std::cout << "Seg. " << i << "ok" << std::endl;
            }
            else
            {
                //std::cout << "Error X Points definition in Seg." << i << std::endl;
                pointsDefOk = false;
                break;
            }
        }

        // Other checks
        if (points->X != 0 || (points+nrPoints-1)->X != 5000)
        {
            //std::cout << "Error on edge points definition" << std::endl;
            pointsDefOk = false;
        }
        
    }

    float Fade::UpdateCam(int masterVal)
    {
        float camValue = 0;
        float y_Pn, y_Pnn;
        int x_Pn, x_Pnn;

        if (pointsDefOk)
        {
            for (int i = 0; i < nrPoints - 1 ; i++)
            {
                x_Pn = (points+i)->X;
                y_Pn = (points+i)->Y;
                x_Pnn = (points+i+1)->X;
                y_Pnn = (points+i+1)->Y;

                if (masterVal >= x_Pn && masterVal < x_Pnn)
                {
                    //std::cout << "Working on segment " << i << std::endl;
                    
                    camValue = y_Pn + (y_Pnn - y_Pn) / (x_Pnn - x_Pn) * (masterVal - x_Pn);
                }
                    
            }
        }
        else
            camValue = 0.0f;
            
        return camValue;
    }

#endif