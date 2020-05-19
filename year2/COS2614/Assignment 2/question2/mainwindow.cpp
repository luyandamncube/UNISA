#include "mainwindow.h"

#include <QLayout>
#include <QFormLayout>

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QInputDialog>
#include <QLineEdit>
#include "investmentmodel.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent): QDialog(parent){
    QWidget * wdg = new QWidget(this);

    QFormLayout *vLayout = new QFormLayout(wdg);
    vLayout->setSpacing(10);

    btn_1 = new QPushButton("Add Investor");
    btn_2 = new QPushButton("Calculate Profit");
    sb_1 = new QSpinBox();
    te_1 = new QTextEdit();

    sb_1->setRange(-99999999, 99999999);
    QLabel * lbl_1 = new QLabel("Specify Total Profit Amount");
    QLabel * lbl_2 = new QLabel("Add investor amount");
    vLayout->addRow(lbl_1,sb_1);
    vLayout->addRow(lbl_2, btn_1);
    vLayout->addRow(te_1);
    vLayout->addRow(btn_2);

    //Adjust size of widget to fit it's contents
    wdg->adjustSize();
//    setCentralWidget(wdg);
}
void MainWindow::setInvestment(InvestmentModel i){
    m_investment = i;
}

void MainWindow::handleButtonAmount(){
    bool ok;
    double amount = 0.00;
    QString text = QInputDialog::getText(this,
                                             "Input dialog",
                                             "Add Investor amount (e.g. 1000):",
                                             QLineEdit::Normal,
                                             "", &ok);
        if(!ok){
               //cancel was pressed, exit function
               return;
        }
        amount = text.trimmed().toDouble();
        m_investment.addAmount(amount);

 }

void MainWindow::handleButtonSetProfit(){
    //DEBUG
//    qDebug()<< "Profit: " << sb_1->value();
    m_investment.setProfit(sb_1->value());

}

void MainWindow::handleButtonProfitCalc(){
    m_investment.setInvestorID();
    m_investment.setTotalInvestment();
    te_1->clear();
    //DEBUG
    for (int i = 0; i < m_investment.getAllAmmounts().size(); i++){
          te_1->append(QString::number(i+1) + "\t" +
                       QString::number(m_investment.getInvestorAmount(i),'f',2) + "\t" +
                       QString::number(m_investment.percentage(i))+ "%\t" +
                       QString::number(m_investment.share(i), 'f',2)
                      );
    }
 }
