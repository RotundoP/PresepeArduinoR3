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

    Cam::Cam(PointXY **p, int nrPolyPoints, int maxCamVal)
    {
        pointsDefOk = true;
        points = p;
        nrPoints = nrPolyPoints;

        // Check points.X ascending order
        for (int i = 0; i < nrPoints - 1 ; i++)
        {
            if ((points[i])->getX() < (points[i+1])->getX())
            {
                //std::cout << "Seg. " << i << "ok" << std::endl;
                Serial.println("Class Cam verifica OK");
            }
            else
            {
                Serial.println("Class Cam Error");
                //std::cout << "Error X Points definition in Seg." << i << std::endl;
                pointsDefOk = false;
                break;
            }
        }

        // Other checks
        if (points[0]->getX() != 0 || points[nrPoints-1]->getX() != maxCamVal)
        {
            Serial.println("Class Cam Error");
            //std::cout << "Error on edge points definition" << std::endl;
            pointsDefOk = false;
        }      
    }

    float Cam::UpdateCam(int masterVal)
    {
        float camValue = 0;
        float y_Pn, y_Pnn;
        int x_Pn, x_Pnn;

        if (pointsDefOk)
        {
            for (int i = 0; i < nrPoints - 1 ; i++)
            {
                x_Pn = points[i]->getX();
                y_Pn = points[i]->getY();
                x_Pnn = points[i+1]->getX();
                y_Pnn = points[i+1]->getY();

                if (masterVal >= x_Pn && masterVal <= x_Pnn)
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

    bool Cam::isPointDefOk()
    {
        return pointsDefOk;
    }

    void Cam::printPoints()
    {
        for (int i = 0; i < nrPoints ; i++)
        {
            //Serial.println(sizeof(points));
            
            Serial.print("P"); Serial.print(i); Serial.print(" ");
            Serial.print(points[i]->getX()); Serial.print(" ");
            delay(200);
            Serial.print(points[i]->getY());
            Serial.println();
            delay(200);
        }
    }

#endif