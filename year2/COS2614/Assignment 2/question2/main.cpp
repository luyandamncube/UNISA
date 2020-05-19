#include "mainwindow.h"
#include "investmentmodel.h"

#include <QApplication>
#include <QInputDialog>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Create instance of MainWindow
    MainWindow w;
    //Create instance of InvestmentModel
    InvestmentModel i ;
    w.setInvestment(i);

    QObject::connect(
                w.btn_1, SIGNAL (clicked()),
                &w,SLOT(handleButtonAmount()));

    QObject::connect(
                w.sb_1, SIGNAL (valueChanged(int)),
                &w,SLOT(handleButtonSetProfit()));

   QObject::connect(
                w.btn_2, SIGNAL (clicked()),
                &w,SLOT(handleButtonProfitCalc()));
    w.show();
    return a.exec();
}
