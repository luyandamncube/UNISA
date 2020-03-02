#include <iostream>
#include <math.h>
using namespace std;

void selTabs (int startVal, int rowVal, int incVal)
{
	cout << "NUMBER" << '\t' << "SQUARE" << '\t' << "CUBE" << endl;
	int ansSquare, ansCube;
	int rowNum,startNum, k;
    // Ensures loop repeats according to increment
	rowNum = startVal + (rowVal * incVal);
	for (k =startVal; k < rowNum ; k += incVal)
	{
		ansSquare = pow(k,2);
		ansCube = pow(k,3);
		cout << k << '\t'<< ansSquare << '\t' << ansCube << endl;
	}
}

int main()
{
    int startIn, rowIn, incIn; //Variables for user input
    cout << "Enter the starting value of the table" << endl;
    cin >> startIn;
    cout << "Enter the number of values to be displayed" << endl;
    cin >> rowIn;
    cout << "Enter the increment between the values" << endl;
    cin >> incIn;
	selTabs(startIn,rowIn,incIn);
}
