#include "receiver.h"
#include <QInputDialog>

Receiver::Receiver(){
}


void Receiver::handleButtonProfit(MainWindow w){
    bool ok;
    Receiver r;
    connect(w.btn_2,SIGNAL(clicked()),
              r, SLOT(handleButtonProfit()))
//    w.connect(
//                w.btn_2, SIGNAL (clicked()),
//                this,SLOT(handleButtonProfit()));
//    QString amount = QInputDialog::getText(&w,
//                                         "Input dialog",
//                                         "Add Investor amount (e.g. 1000):",
//                                         QLineEdit::Normal,
//                                         "", &ok);
 }
