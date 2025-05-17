#include "Transaction.h"

Transaction::Transaction(double amount, TransactionType type, const QDateTime &timestamp)
    : amount(amount), type(type), timestamp(timestamp) {}

QString Transaction::toString() const {
    QString typeStr = (type == TransactionType::Deposit) ? "Deposit" : "Withdrawal";
    return QString("%1: R%2 on %3 at %4")
        .arg(typeStr)
        .arg(amount, 0, 'f', 2)
        .arg(timestamp.date().toString("ddd MMM dd yyyy"))
        .arg(timestamp.time().toString("hh:mm:ss"));
}