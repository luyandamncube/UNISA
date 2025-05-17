#include "CalculatorWindow.h"
#include "OperationFactory.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

CalculatorWindow::CalculatorWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
}

void CalculatorWindow::setupUi() {
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    auto *mainLayout = new QVBoxLayout(central);
    input1 = new QDoubleSpinBox(this);
    input2 = new QDoubleSpinBox(this);
    resultDisplay = new QLCDNumber(this);
    resultDisplay->setDigitCount(10);

    mainLayout->addWidget(input1);
    mainLayout->addWidget(input2);
    mainLayout->addWidget(resultDisplay);

    addButton = new QPushButton("+", this);
    subButton = new QPushButton("-", this);
    mulButton = new QPushButton("*", this);
    divButton = new QPushButton("/", this);
    clearButton = new QPushButton("Clear", this);

    auto *btnLayout = new QHBoxLayout();
    btnLayout->addWidget(addButton);
    btnLayout->addWidget(subButton);
    btnLayout->addWidget(mulButton);
    btnLayout->addWidget(divButton);
    btnLayout->addWidget(clearButton);
    mainLayout->addLayout(btnLayout);

    connect(addButton, &QPushButton::clicked, this, &CalculatorWindow::handleOperation);
    connect(subButton, &QPushButton::clicked, this, &CalculatorWindow::handleOperation);
    connect(mulButton, &QPushButton::clicked, this, &CalculatorWindow::handleOperation);
    connect(divButton, &QPushButton::clicked, this, &CalculatorWindow::handleOperation);
    connect(clearButton, &QPushButton::clicked, this, &CalculatorWindow::clearAll);
}

void CalculatorWindow::handleOperation() {
    QPushButton *senderButton = qobject_cast<QPushButton*>(sender());
    if (!senderButton) return;

    QString symbol = senderButton->text();
    performCalculation(symbol);
}

void CalculatorWindow::performCalculation(const QString& opSymbol) {
    double a = input1->value();
    double b = input2->value();

    Operation *op = OperationFactory::instance().create(opSymbol);
    if (!op) return;

    try {
        double result = op->compute(a, b);
        resultDisplay->display(result);
    } catch (std::runtime_error &e) {
        QMessageBox::warning(this, "Error", e.what());
        resultDisplay->display(0);
    }

    delete op;
}

void CalculatorWindow::clearAll() {
    input1->setValue(0);
    input2->setValue(0);
    resultDisplay->display(0);
}