#include "investmentmodel.h"
#include <QDebug>

float InvestmentModel::percentage(int id){
    return(getInvestorAmount(id) / m_investment)*100;
}

double InvestmentModel::share(int id){
    return (percentage(id)/100)*m_profit;
}


//getters
double InvestmentModel::totalInvestment(){
    return m_investment;
}
QList<double> InvestmentModel::getAllAmmounts(){
    return m_amounts;
}
int InvestmentModel::getInvestorNumber(){
    return m_investorNumber;
}
double InvestmentModel::getInvestorAmount(int id){
    return m_amounts.at(id);
}
//setters
void InvestmentModel::addAmount(double amount){
    m_amounts.append(amount);
}
void InvestmentModel::setProfit(const double profit) {
    m_profit = profit;
}
void InvestmentModel::setInvestment(const double investment) {
    m_investment = investment;
}
void InvestmentModel::setInvestorID(){
    m_investorNumber +=1;
    qDebug() << "Invesor ID: " << QString::number(m_investorNumber);
}
void InvestmentModel::setTotalInvestment(){
    double total;
    total = 00.00;
    for (int i = 0; i < m_amounts.size(); i++){
        total += m_amounts.at(i);
    }
    qDebug() << "Total investment: " << QString::number(total,'f',2);
    m_investment = total;

}

