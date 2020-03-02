#include <QApplication>
#include <QInputDialog>
#include "coordinate.h"
#include <QMessageBox>
#include <QDebug>
#include <iostream>
using namespace std;

bool hasErrors(QStringList &coordinateList){
//    coordinateList = coordinateList.split(" ");
//    bool flag = true;
    qDebug() << "Entered errors";
    bool isChar = coordinateList[3].length() == 1;
    bool isDirection =  coordinateList[3].toUpper() == 'N' ||
                        coordinateList[3].toUpper() == 'S' ||
                        coordinateList[3].toUpper() == 'E' ||
                        coordinateList[3].toUpper() == 'W';
    bool isInt;
    qDebug() << "isChar: "+ QString::number(isChar);
    qDebug() << "isDirection: "+QString::number(isChar);
    qDebug() << "isInt: "+QString::number(isChar);
    qDebug() << coordinateList.length();
    if (coordinateList.length() != 4){
        qDebug() << "No. of parameters should be 4";
        exit(0);
    }
    if (isChar && isDirection == false){
        qDebug() << "Direction not N | S | E | W";
        exit(0);
    }
    coordinateList[3] = coordinateList[3].toUpper();
    if ((coordinateList[0].toInt(&isInt) >= 0) &&
            (coordinateList[0].toInt(&isInt) < 180) == false){
        qDebug() << "Degrees not between 0 and 179";
        exit(0);
    }
    if ((coordinateList[1].toInt(&isInt) >= 0) &&
            (coordinateList[1].toInt(&isInt) < 60) == false){
        qDebug() << "Minutes not between 0 and 59";
        exit(0);
    }
    if ((coordinateList[2].toInt(&isInt) >= 0) &&
            (coordinateList[2].toInt(&isInt) < 60) == false){
        qDebug() << "Seconds not between 0 and 59";
        exit(0);
    }
//    if (isInt == false){
//        qDebug() << "No. of parameters should be 4";
//        exit(0);
//    }
    return true;
}

int main(int argc, char *argv[])
{
    //Use QApplication instead of QApplicationGui
    QApplication a(argc, argv);
    bool ok;
    QString inputCoordinates;
    QStringList coordinateList;
    inputCoordinates =QInputDialog::getText(0,"Input","Please enter a coordinate (e.g. 52 13 10)",
                                         QLineEdit::Normal, QString(""), &ok);
    coordinateList = inputCoordinates.split(" ");
//    for (int i = 0; i < coordinateList.length();i++){
//        qDebug() << QString::number(i) <<  ": " << coordinateList.at(i) << endl;
//    }
    if(!ok){
        exit(0);
    }
    else if(hasErrors(coordinateList) == false) {
//        qDebug() << "ERROR";
        exit(0);
    }
    else{
    Coordinate list(coordinateList[0].toInt(),coordinateList[1].toInt(),
            coordinateList[2].toInt(), coordinateList[3].at(0).toUpper());
QMessageBox::information(0, "Output", result);
    }
    return a.exec();
}
