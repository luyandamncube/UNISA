#include "coordinate.h"
//Constructor: initialize objects of class Coordinate
Coordinate::Coordinate(int _degrees, int _minutes, int _seconds, QChar _direction)
    : degrees(_degrees), minutes(_minutes), seconds(_seconds), direction(_direction){
    //number of degrees should be an integer from 0 to 179,
    //number of minutes and seconds should both be integers from 0 to 59
    //cardinal direction should be N or S for latitude, or E or W for longitude.

}

QString Coordinate::toString(){
    //USAGE: QString(%1 %2 %3).arg(name,20).arg(" = ").arg(value);
    return(QString("%1%2 %3 %4 %5").arg(degrees).arg(QChar(0260))
           .arg(minutes).arg(seconds).arg(direction));
}

double Coordinate::toDecimal(){
    int dec;
    int cardinalDirection;
    //ternary operator: assign positive if direction is 'N' or 'E'
    cardinalDirection = (direction == 'N' || direction == 'E') ? 1 : -1;
    //geographic coordinate to decimal

    dec = (degrees + minutes/60 + seconds/3600)*cardinalDirection;
    return(dec);
}
