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

    qDebug() << "[DEBUG] Current working directory:" << QDir::currentPath();
    QDir iconDir("icons");
    qDebug() << "[DEBUG] Icons in folder:" << iconDir.entryList(QDir::Files);


    QStringList iconNames = {"deposit.png", "withdraw.png", "save.png"};

    for (const QString &name : iconNames) {
        QString path = QDir("icons").absoluteFilePath(name);
        QFileInfo file(path);

        // qDebug() << "[DEBUG] Icon file path:" << path;
        // qDebug() << "         Exists?" << file.exists();
    }

    QIcon depositIcon(QDir("icons").absoluteFilePath("deposit.png"));
    QIcon withdrawIcon(QDir("icons").absoluteFilePath("withdraw.png"));
    QIcon saveIcon(QDir("icons").absoluteFilePath("save.png"));

    // Debugging: Check if icons are loaded properly
    if (depositIcon.isNull()) qWarning() << "[ERROR] Failed to load deposit.png";
    if (withdrawIcon.isNull()) qWarning() << "[ERROR] Failed to load withdraw.png";
    if (saveIcon.isNull()) qWarning() << "[ERROR] Failed to load save.png";

    depositButton = new QPushButton(depositIcon, "Deposit", this);
    withdrawButton = new QPushButton(withdrawIcon, "Withdrawal", this);
    toFileButton = new QPushButton(saveIcon, "To file", this);


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
    qDebug() << tx->toString();
    clearInputs();
}

void MainWindow::handleWithdrawal() {
    double amount = getAmountInput();
    if (amount <= 0) return;

    Transaction *tx = new Transaction(amount, TransactionType::Withdrawal);

    if (!TransactionList::instance().addTransaction(tx)) {
        QMessageBox::warning(this, "Withdrawal Failed", "Insufficient funds.");
        delete tx;
        return;
    }

    qDebug() << tx->toString();
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
