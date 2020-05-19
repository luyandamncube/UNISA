#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include "mainwindow.h"

class Receiver
{
    Q_OBJECT
public:
    Receiver();
public slots:
    void handleButtonProfit(MainWindow w);
};

#endif // RECEIVER_H
