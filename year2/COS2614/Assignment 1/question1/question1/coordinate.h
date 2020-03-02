#ifndef COORDINATE_H
#define COORDINATE_H
#include <QString>

class Coordinate {
    private:
        int degrees;
        int minutes;
        int seconds;
        QChar direction;
    public:
        //Constructor
        //QChar
        Coordinate(int degrees, int minutes, int seconds, QChar direction);
        QString toString();
        double toDecimal();
};

#endif // COORDINATE_H
