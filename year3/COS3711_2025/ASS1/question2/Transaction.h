#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>
#include <QDateTime>

// --- Enum for transaction types ---
enum class TransactionType {
    Deposit,
    Withdrawal
};

// --- Represents a single banking transaction ---
class Transaction {
public:
    // Constructor
    Transaction(double amount, TransactionType type, const QDateTime &timestamp = QDateTime::currentDateTime());

    // Convert to string for display/logging
    QString toString() const;

    // Getters
    double getAmount() const { return amount; }
    TransactionType getType() const { return type; }

private:
    double amount;
    TransactionType type;
    QDateTime timestamp;
    QList<Transaction*> transactions;
    double balance = 0.0;
};

#endif // TRANSACTION_H
