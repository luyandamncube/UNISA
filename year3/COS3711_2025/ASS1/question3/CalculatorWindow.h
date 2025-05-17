#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QLCDNumber>
#include "FocusableSpinBox.h"

class CalculatorWindow : public QMainWindow {
    Q_OBJECT

public:
    CalculatorWindow(QWidget *parent = nullptr);

private slots:
    void handleOperation();
    void handleDigitInput(const QString &digit);
    void onInput1Focus();
    void onInput2Focus();

private:
    FocusableSpinBox *input1;
    FocusableSpinBox *input2;
    QLCDNumber *resultDisplay;
    QPushButton *addButton;
    QPushButton *subButton;
    QPushButton *mulButton;
    QPushButton *divButton;

    QString buffer1;
    QString buffer2;


    FocusableSpinBox *lastFocusedInput = nullptr;
    FocusableSpinBox *activeInput = nullptr;

    void setupUi();
    void applyStyle(QPushButton *button);


};

#endif // CALCULATORWINDOW_H
