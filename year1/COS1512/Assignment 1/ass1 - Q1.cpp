#include <iostream>
using namespace std;

void getprize(int ticketnum, char gender)
{
float prizemoney;
		if (gender == 'm' && ticketnum > 30000)
			prizemoney = ticketnum/90;
		else
		if (gender == 'f' && ticketnum > 20000)
			prizemoney = ticketnum/80;
	//output prize money
	cout << "Congratulations, you won a prize of: R" << prizemoney;
}

void getprize(int ticketnum, char gender, int age)
{
float prizemoney;

//if age <= 21, prize money  = age * 40
if (age <= 21 )
	prizemoney = age * 40;
else
//if age > 21, prize money  = age * 30
if ( age > 21)
	prizemoney =  age * 30;
//output prize money
cout << "Congratulations, you won a prize of: R" << prizemoney;
	}

int main()
{
    int ticketnum, age;
    char gender;
//Input ticket number
cout << "Please enter your ticket number: \n";
cin >> ticketnum;

//Input gender
cout << "Please enter your gender ('m' or 'f'):  \n";
cin >> gender;

//check divisible by 6  AND 7
	if (ticketnum % 6 == 0 && ticketnum % 7 == 0)
	{
		cout << "Please enter your age: \n" ;
		cin >> ticketnum;
		getprize(ticketnum,gender,age);
	}
	else
	//Check divisible by 100
    if (ticketnum % 100 == 0)
	 getprize(ticketnum,gender);

else
//If all conditions not met, ouput "not winning ticket"
cout << "Sorry, you don't have a winning ticket" ;

return 0;

}
