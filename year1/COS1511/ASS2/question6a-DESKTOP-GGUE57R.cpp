#include <iostream>
#include <string>
using namespace std;

//Function 1: Input
void employeeinput (string& theEmployee1, float& theHoursWorked, float& thePayRate)
{
    cout << "Please enter employee name: \n";
    cin >> theEmployee1;
    cin.get();
    cout << "Please enter how many hours the employee worked: " << endl;
    cin >> theHoursWorked;
    cout << "Please enter employee hourly pay rate: " << endl;
    cin >> thePayRate;
    cout << endl;
}
//Function 2: Employee's Pay calculation
float calculatepay (float hoursworked, float payrate)
{
    if (hoursworked > 40)
        return hoursworked * payrate * 1.5;
    else
        return hoursworked * payrate;
}
//Function 3: Output
void employeeoutput (string employeename, float hoursworked1, float payrate1, float finalpay)
{
    float overtime;
    if (hoursworked1 > 40)
    overtime = hoursworked1 - 40;
    else
    overtime = 0;
    cout << "Pay slip for " << employeename << endl;
    cout << "Hours worked: " << hoursworked1 << " hours" << endl;
    cout << "Overtime hours: " << overtime << endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Hourly pay rate: " << payrate1 << endl;
    cout << "Pay: R" << finalpay << endl;
    cout << "==================================" << endl;
}
int main()
{
    string mEmployee;
    float mHours, mPayrate, mPay;
 for (int k =1; k <= 5; k++)
 {
     employeeinput(mEmployee,mHours,mPayrate);
     mPay = calculatepay(mHours, mPayrate);
     employeeoutput(mEmployee, mHours,mPayrate, mPay);
 }
return 0;
}
