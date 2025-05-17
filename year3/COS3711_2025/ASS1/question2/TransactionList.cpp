#include "TransactionList.h"
#include <QDebug>
#include <QFile>

TransactionList& TransactionList::instance() {
    static TransactionList instance;
    return instance;
}

void TransactionList::addTransaction(Transaction *tx) {
    transactions.append(tx);
}

void TransactionList::writeToConsole() const {
    for (const Transaction *tx : transactions) {
        qDebug() << tx->toString();
    }
}

void TransactionList::writeToFile(const QString &filePath) const {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Unable to open file:" << filePath;
        return;
    }

    QTextStream out(&file);
    for (const Transaction *tx : transactions) {
        out << tx->toString() << "\n";
    }

    file.close();
}