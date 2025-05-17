#ifndef TRANSACTIONLIST_H
#define TRANSACTIONLIST_H

#include "Transaction.h"
#include <QList>
#include <QString>

// --- Singleton class to manage a list of transactions and running balance ---
class TransactionList {
public:
    // Singleton accessor
    static TransactionList& instance();

    // Adds a transaction (returns false if invalid, e.g. insufficient balance)
    bool addTransaction(Transaction *transaction);

    // Writes all transactions to console
    void writeToConsole() const;

    // Writes only the most recent transaction to console
    void writeLatestToConsole() const;

    // Writes all transactions to a text file
    void writeToFile(const QString &filePath) const;

    // Returns the current balance
    double getBalance() const;

private:
    // Private constructor for singleton
    TransactionList() = default;

    // List of all transactions
    QList<Transaction*> transactions;

    // Running balance
    double balance = 0.0;
};

#endif // TRANSACTIONLIST_H
