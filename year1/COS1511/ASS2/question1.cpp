#include <iostream>
using namespace std;
int main()
{
int selection; // Fill in the code to define an integer variable called selection
float cost, number;
cout.setf(ios::fixed);
cout.precision(2);
cout << "Please enter the choice of hotdog "
<< "(a number from 1 to 4 or 0 to quit) " << endl;
cout << "Hot Dog Menu " << endl << endl;
cout << "1: Plain hotdog" << '\t' << '\t' << '\t'<< "R15.00" << endl;
cout << "2: Chilli hotdog" << '\t' <<  '\t' << "R12.50" << endl;
cout << "3: Cheese hotdog" << '\t' <<  '\t' << "R17.00" << endl;
cout << "4: Russian hotdog" << '\t' <<  '\t' << "R22.50" << endl;
cout << "0: QUIT " << endl <<endl << endl;
cin >> selection ;
while (selection < 0 || selection > 4 ) //complete the condition
{
cout << "Invalid choice - Please re-enter ";
cin >> selection;
cout << endl;
}
cout << "You have selected option number " << selection;
cout << ", How many hotdogs would you like?" << endl;
cin >> number;     // Fill in the code to read in number

// Fill in the code to begin a switch statement
switch (selection)// that is controlled by selection
{
case 1: cost = number * 15.0;
cout << "The total cost is R " << cost << endl;
break;
// Fill in the code for the case chilli hotdog ( R12.50 each)
case 2: cost = number * 12.50;
cout << "The total cost is R " << cost << endl;
break;
// Fill in the code for the case chesse hotdog (R17.00 each)
case 3: cost = number * 17.0;
cout << "The total cost is R " << cost << endl;
break;
// Fill in the code for the case Russian hotdog (R22.50 each)
case 4: cost = number * 22.50;
cout << "The total cost is R " << cost << endl;
break;
case 0: cout << " Please come again" << endl;
break;
default:
cout << "Invalid selection";
cout << " Try again please" << endl;
}
return 0;
}

