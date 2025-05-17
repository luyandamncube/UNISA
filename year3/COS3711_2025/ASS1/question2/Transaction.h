#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>
#include <QDateTime>

enum class TransactionType {
    Deposit,
    Withdrawal
};

class Transaction {
public:
    Transaction(double amount, TransactionType type, const QDateTime &timestamp = QDateTime::currentDateTime());
    QString toString() const;

private:
    double amount;
    TransactionType type;
    QDateTime timestamp;
};

#endif // TRANSACTION_H