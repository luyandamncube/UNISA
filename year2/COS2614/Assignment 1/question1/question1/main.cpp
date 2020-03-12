#include <QApplication>
#include <QInputDialog>
#include "coordinate.h"
#include <QMessageBox>
#include <QDebug>

bool hasErrors(QStringList &coordinateList){
    if (coordinateList.length() != 4){
        qDebug() << "No. of parameters should be 4";
        return(false);
    }
    bool isChar = coordinateList[3].length() == 1;
    bool isDirection =  coordinateList[3].toUpper() == 'N' ||
                        coordinateList[3].toUpper() == 'S' ||
                        coordinateList[3].toUpper() == 'E' ||
                        coordinateList[3].toUpper() == 'W';
    bool isInt;
    if (isChar && isDirection == false){
        QMessageBox::critical(0, "Error", "Direction should be 'N' or 'S' or 'E' or 'W'");
        return(false);
    }
    coordinateList[3] = coordinateList[3].toUpper();
    if ((coordinateList[0].toInt(&isInt) >= 0) &&
            (coordinateList[0].toInt(&isInt) < 180) == false){
        QMessageBox::critical(0, "Error", "Degrees not between 0 and 179");
        return(false);
    }
    if ((coordinateList[1].toInt(&isInt) >= 0) &&
            (coordinateList[1].toInt(&isInt) < 60) == false){
        QMessageBox::critical(0, "Error", "Minutes not between 0 and 59");
        return(false);
    }
    if ((coordinateList[2].toInt(&isInt) >= 0) &&
            (coordinateList[2].toInt(&isInt) < 60) == false){
        QMessageBox::critical(0, "Error", "Seconds not between 0 and 59");
        return(false);
    }
    return true;
}

int main(int argc, char *argv[])
{
    //Use QApplication instead of QApplicationGui
    QApplication a(argc, argv);
    bool ok;
    QString inputCoordinates;
    QStringList coordinateList;
    QMessageBox::StandardButton reply;
    do{
        inputCoordinates =QInputDialog::getText(0,"Input","Please enter a coordinate (e.g. 52 13 10)",
                                             QLineEdit::Normal, QString(""), &ok);
        coordinateList = inputCoordinates.split(" ");
        if(!ok){
            exit(0);
        }
        else if(hasErrors(coordinateList) == false) {
            exit(0);
        }
        else{

            Coordinate Outputlist(coordinateList[0].toInt(),coordinateList[1].toInt(),
                coordinateList[2].toInt(), coordinateList[3].at(0).toUpper());
            QMessageBox::information(0, "Output", "String format: " + Outputlist.toString() +
                                     "\nDecimal format: "  + QString::number(Outputlist.toDecimal()) + "\n");
            reply = QMessageBox::question(0, "Coordinate", "Enter another coordinate?",
                                            QMessageBox::Yes|QMessageBox::No);
        }

    }while(reply == QMessageBox::Yes);
    exit(0);
    return a.exec();
}
