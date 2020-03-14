#include "gpscoord.h"
#include <QApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextStream qtcout(stdout);
    QTextStream qtcin(stdin);

    GPSCoord gps;
    int d, m, s;
    QString cds;

    qtcout << "Enter the latitude (0 0' 0'' N/S):"<<endl;
    qtcin >> d >> m >> s >> cds;
    gps.setCoordinate(d, m, s, cds.at(0).toUpper());

    qtcout << "Enter the longitude (0 0' 0'' E/W):"<<endl;
    qtcin >> d >> m >> s >> cds;
    gps.setCoordinate(d, m, s, cds.at(0).toUpper());
    qtcout << "String format: " << gps.toString(false) << endl;
    qtcout << "Decimal format: " << gps.toString(true) << endl;

    GPSCoord gps1 = gps;
    gps = gps1;
    gps.~GPSCoord();
    exit(0);
    return a.exec();
}
