#ifndef INVESTMENTMODEL_H
#define INVESTMENTMODEL_H

#include <QList>

class InvestmentModel
{
    private:
        //data members
        double m_profit;
        double m_investment;
        int m_investorNumber = -1;
        QList<double> m_amounts;
        QList<double> m_percentages;
    public:
        float percentage(int id);
        double share(int id);
        //getters
        double totalInvestment();
        double totalProfit();
        QList<double> getAllAmmounts();
        int getInvestorNumber();
        double getInvestorAmount(int id);
        //setters
        void addAmount(double amount);
        void setProfit(double amount);
        void setInvestment(const double investment);
        void setInvestorID();
        void setTotalInvestment();


};

#endif // INVESTMENTMODEL_H
