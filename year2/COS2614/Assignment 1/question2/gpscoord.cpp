#include "gpscoord.h"
#include <QDebug>

GPSCoord::GPSCoord():
    latitude(new Coordinate(0, 0, 0, 'N')),
      longitude(new Coordinate(0, 0, 0, 'E')) {
}

GPSCoord::~GPSCoord(){
    qDebug() << "Destructor";
    delete latitude;
    delete longitude;
}

GPSCoord::GPSCoord(const GPSCoord & g)
 : latitude(new Coordinate(*g.latitude)),
   longitude(new Coordinate(*g.longitude)) {
    qDebug() << "Copy Constructor";
}

GPSCoord & GPSCoord::operator=(const GPSCoord & g) {
     qDebug() << "Copy Assignment Operator";
     *latitude = *g.latitude;
     *longitude = *g.longitude;
     return *this;
}
void GPSCoord::setCoordinate(int degrees, int minutes, int seconds, QChar d){
    if (d == 'N' || d == 'S'){
        delete latitude;
        latitude = new Coordinate(degrees, minutes, seconds, d);
    }
    else {
        delete longitude;
        longitude = new Coordinate(degrees, minutes, seconds, d);
    }
}

QString GPSCoord::toString(bool decimal){
    QString output;
    bool result;

    result = decimal == false;
    output = result
            ? latitude->toString() + " " + longitude->toString()
            : QString::number(latitude->toDecimal()) + " " + QString::number(longitude->toDecimal());
    return output;
}
