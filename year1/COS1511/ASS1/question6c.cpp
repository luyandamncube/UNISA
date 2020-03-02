#include <iostream>
#include <string>
using namespace std;

string getname(string name, string surname)
{
    string joinednames;
    cout << "Please enter customer name:" << endl;
    getline(cin, name, '\n');
    cout << "Please enter surname:" << endl;
    getline(cin, surname, '\n');
    joinednames = name + " " + surname;
    return joinednames;
}

float gethours(string& fullname, float payrate)
{
    float total = 0, hoursworked, bonus, salary;

    cout << "Please enter payrate per hour for employee: " << endl;
    cin >> payrate;

    for (int k = 1; k <= 5; k++)
    {
        cout << "Please enter hours worked for day:  " << k << endl;
        cin >> hoursworked;
        total += hoursworked;
    }
    cout << "Employee worked " << total << " hours."<< endl ;
    if (total > 40)
    {
        bonus = 1.10;
        cout << "Employee recieved 10% bonus." << endl ;
    }

    else
    {
        bonus = 0.90;
        cout << "Employee recieved 10% reduction." << endl ;
    }

    salary = total * payrate*bonus;
    return salary;

}
int main()
{
    string employeename, employeesurname, fullname1;
    float payrate1, salary1;
    fullname1 = getname(employeename,employeesurname);
    salary1 = gethours(fullname1, payrate1);
    cout << "The employee " << fullname1 << " salary was: R" << salary1 << endl;

}
