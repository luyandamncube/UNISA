#include "Transaction.h"

// --- Constructor ---
Transaction::Transaction(double amount, TransactionType type, const QDateTime &timestamp)
    : amount(amount), type(type), timestamp(timestamp) {
    // Optional debug log
    // qDebug() << "[DEBUG] Created transaction:" << toString();
}

// --- Convert transaction to human-readable string ---
QString Transaction::toString() const {
    // Convert enum to readable string
    QString typeStr = (type == TransactionType::Deposit) ? "Deposit" : "Withdrawal";

    // Format amount to 2 decimal places
    QString formattedAmount = QString::number(amount, 'f', 2);

    // Format date and time
    QString dateStr = timestamp.date().toString("ddd MMM dd yyyy");
    QString timeStr = timestamp.time().toString("hh:mm:ss");

    // Return formatted string
    return QString("%1: R%2 on %3 at %4")
        .arg(typeStr)
        .arg(formattedAmount)
        .arg(dateStr)
        .arg(timeStr);
}
