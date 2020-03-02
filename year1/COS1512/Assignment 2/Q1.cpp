#include <iostream>
#include <string>
using namespace std;
class Employee
{
public:
Employee();
Employee(string firstName, string lastName, float salary);
~Employee();

string getfirstName() const;
string getlastName() const;
float getSalary() const;

void setfirstName(string f1);
void setlastName(string n1);
void setSalary(float s1);

private:
string firstName;
string lastName;
float salary;
};
//constructor default
Employee::Employee()
{
firstName = "";
lastName = "";
salary = 00.00;
}
//constructor overloaded
Employee::Employee(string f1, string n1, float s1)
//
{
firstName = f1;
lastName = n1;
salary = s1;
}

//destructor
Employee::~Employee()
{ }

//Mutators
void Employee:: setfirstName(string f1)
{
firstName = f1;
}
void Employee:: setlastName(string n1)
{
lastName = n1;
}
void Employee:: setSalary(float s1)
{
salary = s1;
}
//Accessors
string Employee::getfirstName () const
{
return firstName;
}
string Employee::getlastName () const
{
return lastName;
}


float Employee::getSalary () const
{
return salary;
}

int main()
{
//New object, data from keyboard
string sfirstName, slastName;
float fSalary1, fSalary2;
Employee newEmployee(sfirstName, slastName, fSalary2);

//Object for employee Joe Soap
Employee oldEmployee("Joe", "Soap", 1456.00);

cout << "Please enter employee name: ";
getline(cin, sfirstName, '\n');
newEmployee.setfirstName(sfirstName);

cout << "Please enter employee last name: ";
getline(cin, slastName, '\n');
newEmployee.setlastName(slastName);

cout << "Please enter employee salary: ";
cin >> fSalary2;
newEmployee. setSalary(fSalary2);

cout << endl << "Employee 1 is: " << endl;
cout << oldEmployee.getfirstName() << endl;
cout << oldEmployee.getlastName() << endl;
cout << oldEmployee.getSalary () << endl;

//Show increase in Salary
cout << "After the increase, Employee 1 salary is: ";
fSalary1 = oldEmployee.getSalary();
fSalary1 *= 1.1;
oldEmployee.setSalary(fSalary1);
cout << oldEmployee.getSalary() << endl;

cout << endl << "Employee 2 is: " << endl;
cout << newEmployee.getfirstName() << endl;
cout << newEmployee.getlastName() << endl;
cout << newEmployee.getSalary() << endl;

//Show increase in Salary
cout << "After the increase, Employee 2 salary is: ";
fSalary2 *= 1.1;
newEmployee.setSalary(fSalary2);
cout << newEmployee.getSalary() << endl;

return 0;
}




