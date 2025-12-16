#ifndef Cam_H
#define Cam_H

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

    PointXY::PointXY(int Px, float Py)
    {
        x = Px;
        y = Py;
    }

    int PointXY::getX()
    {
        return x;
    }

    float PointXY::getY()
    {
        return y;
    }

    Fade::Fade(PointXY *p, int nrPolyPoints)
    {
        pointsDefOk = true;
        points = p;

        // Check points.X ascending order
        for (int i = 0; i < nrPoints - 1 ; i++)
        {
            if ((points+i)->getX() < (points+i+1)->getX())
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
        if (points->getX() != 0 || (points+nrPoints-1)->getX() != 5000)
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
                x_Pn = (points+i)->getX();
                y_Pn = (points+i)->getY();
                x_Pnn = (points+i+1)->getX();
                y_Pnn = (points+i+1)->getY();

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