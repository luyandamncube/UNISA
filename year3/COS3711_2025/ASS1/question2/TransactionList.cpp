#include "TransactionList.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

// --- Singleton instance accessor ---
TransactionList& TransactionList::instance() {
    static TransactionList instance;
    return instance;
}

// --- Add a transaction to the internal list ---
// Returns false if withdrawal exceeds balance
bool TransactionList::addTransaction(Transaction *transaction) {
    double amount = transaction->getAmount();
    TransactionType type = transaction->getType();

    // --- Check for insufficient funds on withdrawal ---
    if (type == TransactionType::Withdrawal && amount > balance) {
        qWarning() << "[ERROR] Insufficient funds for withdrawal. Current balance: R"
                   << QString::number(balance, 'f', 2);
        return false;
    }

    // --- Apply transaction ---
    if (type == TransactionType::Deposit)
        balance += amount;
    else if (type == TransactionType::Withdrawal)
        balance -= amount;

    transactions.append(transaction);

    // qDebug() << "[DEBUG] New balance: R" << QString::number(balance, 'f', 2);
    return true;
}

// --- Output all stored transactions to the console ---
void TransactionList::writeToConsole() const {
    qDebug() << "[DEBUG] Writing all transactions to console...";
    for (const auto& transaction : transactions) {
        qDebug() << transaction->toString();
    }
}

// --- Output the most recently added transaction only ---
void TransactionList::writeLatestToConsole() const {
    if (!transactions.isEmpty()) {
        qDebug() << "[DEBUG] Latest transaction:" << transactions.last()->toString();
    } else {
        qDebug() << "[DEBUG] No transactions available to print.";
    }
}

// --- Write all transactions to a specified text file ---
void TransactionList::writeToFile(const QString &filePath) const {
    qDebug() << "[DEBUG] Attempting to write transactions to file:" << filePath;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "[ERROR] Unable to open file for writing:" << filePath;
        return;
    }

    QTextStream out(&file);
    for (const auto& transaction : transactions) {
        out << transaction->toString() << "\n";
    }

    file.close();
    qDebug() << "[DEBUG] Successfully wrote" << transactions.size() << "transaction(s) to file.";
}

// --- Get the current balance ---
double TransactionList::getBalance() const {
    return balance;
}
