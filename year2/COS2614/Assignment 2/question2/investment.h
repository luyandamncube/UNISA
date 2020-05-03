#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <QList>

class Investment
{
    private:
        double profit;
        QList<double> amounts;

    public:
        Investment();
        bool addAmount(double amount);
        void setProfit(double p);
        double totalInvestment();
        int percentage(int investorNumber);
        int share(int investorNumber);
};

#endif // INVESTMENT_H
