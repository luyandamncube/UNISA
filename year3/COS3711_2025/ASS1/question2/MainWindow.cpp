#include "MainWindow.h"
#include "TransactionList.h"
#include "Transaction.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    auto layout = new QVBoxLayout(central);

    layout->addWidget(new QLabel("Date:"));
    dateDisplay = new QDateEdit(QDate::currentDate(), this);
    dateDisplay->setReadOnly(true);
    layout->addWidget(dateDisplay);

    layout->addWidget(new QLabel("Amount:"));
    amountInput = new QLineEdit(this);
    amountInput->setPlaceholderText("0.00");
    layout->addWidget(amountInput);

    depositButton = new QPushButton(QIcon(":/icons/deposit.png"), "Deposit", this);
    withdrawButton = new QPushButton(QIcon(":/icons/withdraw.png"), "Withdrawal", this);
    toFileButton = new QPushButton(QIcon(":/icons/save.png"), "To file", this);

    auto buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(depositButton);
    buttonLayout->addWidget(toFileButton);
    buttonLayout->addWidget(withdrawButton);
    layout->addLayout(buttonLayout);

    connect(depositButton, &QPushButton::clicked, this, &MainWindow::handleDeposit);
    connect(withdrawButton, &QPushButton::clicked, this, &MainWindow::handleWithdrawal);
    connect(toFileButton, &QPushButton::clicked, this, &MainWindow::saveToFile);

    amountInput->setFocus();
}

void MainWindow::handleDeposit() {
    double amount = getAmountInput();
    if (amount <= 0) return;

    Transaction *tx = new Transaction(amount, TransactionType::Deposit);
    TransactionList::instance().addTransaction(tx);
    TransactionList::instance().writeToConsole();
    clearInputs();
}

void MainWindow::handleWithdrawal() {
    double amount = getAmountInput();
    if (amount <= 0) return;

    Transaction *tx = new Transaction(amount, TransactionType::Withdrawal);
    TransactionList::instance().addTransaction(tx);
    TransactionList::instance().writeToConsole();
    clearInputs();
}

void MainWindow::saveToFile() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save Transactions", "", "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        TransactionList::instance().writeToFile(fileName);
        QMessageBox::information(this, "Saved", "Transactions saved to file.");
    }
}

double MainWindow::getAmountInput() const {
    return amountInput->text().toDouble();
}

void MainWindow::clearInputs() {
    amountInput->clear();
    amountInput->setFocus();
}