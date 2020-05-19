#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>
#include "investmentmodel.h"
#include <QtWidgets>

class MainWindow : public QDialog
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        void setInvestment(InvestmentModel i);
        QPushButton *btn_1;
        QPushButton *btn_2;
        QSpinBox * sb_1;
        QTextEdit *te_1;

    public slots:
        void handleButtonAmount();
        void handleButtonSetProfit();
        void handleButtonProfitCalc();

    private:
         InvestmentModel m_investment;
};
#endif // MAINWINDOW_H
