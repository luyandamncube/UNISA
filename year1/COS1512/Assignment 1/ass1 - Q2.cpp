#include <iostream>
#include <cassert>
#include <string>
using namespace std;

void inputtime(int& itotal, int& iminutes, int& iseconds, int& ihours)
{
//Enter first time in 24h00 (hh mm ss)
cout << "Please enter the time in the format (hh mm ss), with spaces \n";
cin >>ihours >> iminutes >> iseconds;

//assert macro
assert (iseconds <= 60);
assert(iminutes <= 60);
assert(ihours <= 24) ;

//Convert time to seconds
itotal = (ihours * 3600) + (iminutes * 60) + iseconds;

}

int main()
{
int imax = 0 , idifference = 0, itime2, sdiff, mdiff, hdiff,
itime1,iminutes,iseconds,ihours;
//Input and display first time
inputtime(itime1,iminutes,iseconds,ihours);
cout << "The first time inputted is \n" << ihours <<
":"<< iminutes << ":"<< iseconds;
cout << endl;

//Input and display second time
inputtime(itime2,iminutes,iseconds,ihours);
cout << "The second time inputted is  \n" << ihours <<
":"<< iminutes << ":"<< iseconds;
cout << endl;

//Check which time is smaller
if (itime1 > itime2)
{
	imax = itime1;
	idifference = itime1 - itime2;
	cout << "The first time entered is larger  \n";
    cout << endl;
}

else
{
	imax = itime2;
	idifference = itime2 - itime1;
	cout << "The second time entered is larger \n";
    cout << endl;
}
//Get time difference
mdiff = (idifference / 60)/60;
sdiff = idifference % 60;
hdiff = mdiff / 60;

//Display time difference
cout << "The time difference is " << hdiff <<
":"<< mdiff << ":"<< sdiff;
return 0;
}

