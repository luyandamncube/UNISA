#ifndef TRANSACTIONLIST_H
#define TRANSACTIONLIST_H

#include "Transaction.h"
#include <QList>
#include <QTextStream>

class TransactionList {
public:
    static TransactionList& instance();
    void addTransaction(Transaction *tx);
    void writeToConsole() const;
    void writeToFile(const QString &filePath) const;

private:
    TransactionList() = default;
    QList<Transaction*> transactions;
};

#endif // TRANSACTIONLIST_H