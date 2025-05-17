#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QLCDNumber>

class CalculatorWindow : public QMainWindow {
    Q_OBJECT

public:
    CalculatorWindow(QWidget *parent = nullptr);

private slots:
    void handleOperation();
    void clearAll();

private:
    QDoubleSpinBox *input1;
    QDoubleSpinBox *input2;
    QLCDNumber *resultDisplay;
    QPushButton *addButton;
    QPushButton *subButton;
    QPushButton *mulButton;
    QPushButton *divButton;
    QPushButton *clearButton;

    void setupUi();
    void performCalculation(const QString& opSymbol);
};

#endif // CALCULATORWINDOW_H