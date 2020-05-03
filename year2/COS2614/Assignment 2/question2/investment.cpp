#include "investment.h"

Investment::Investment()
{

}

bool Investment::addAmount(double amount){
    int len = amounts.length();
    amounts.append(amount);
    if (amounts.length() != len)
        return(false);
    return(true);
}

void Investment::setProfit(double p){

}
