#ifndef GPSCOORD_H
#define GPSCOORD_H
#include "coordinate.h"
#include <QChar>

class GPSCoord{
    private:
        //define as pointers
        Coordinate *latitude;
        Coordinate *longitude;
    public:
        //no-arg constructor
        GPSCoord();
        //destructor
        ~GPSCoord();
        //copy constructor (overloaded constructor)
        GPSCoord(const GPSCoord& g);
        //copy assignment operator
        GPSCoord & operator=(const GPSCoord& g);
        void setCoordinate(int degrees, int minutes, int seconds, QChar d);
        QString toString(bool decimal);
};

#endif // GPSCOORD_H
