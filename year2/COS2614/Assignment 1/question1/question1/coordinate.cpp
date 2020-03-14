#include "coordinate.h"
#include <QDebug>
//Constructor: initialize objects of class Coordinate
Coordinate::Coordinate(int _degrees, int _minutes, int _seconds, QChar _direction)
    : degrees(_degrees), minutes(_minutes), seconds(_seconds), direction(_direction){
}

QString Coordinate::toString(){
     return(QString::number(degrees) + QChar(0260) + " "+
            QString::number(minutes) + "' " +
            QString::number(seconds) + "\" "+
            direction
    );
}

double Coordinate::toDecimal(){
    double dec;
    double cardinalDirection;
    //ternary operator: assign positive if direction is 'N' or 'E'
    cardinalDirection = (direction == 'N' || direction == 'E') ? 1.0 : -1.0;
    //geographic coordinate to decimal
    dec = (degrees + minutes/60.0 + seconds/3600.0)*cardinalDirection;
    return(dec);
}
