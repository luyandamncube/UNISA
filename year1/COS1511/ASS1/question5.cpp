#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;
//Get customer name
string getCustomerName(string& Customername)
{
    cout << "Please enter name of customer:" << endl;
    getline(cin, Customername, '\n');
    return Customername;
}
//Get customer number
string getCustomerNumber(string& Customernumber)
{
    cout << "Please enter customer number:" << endl;
    cin >> Customernumber;
    return Customernumber;
}
//calculateCarpetSize
int calculateCarpetSize(float roomLengthP, float roomWidthP)
{

    cout << "Please enter length of room:" << endl;
	cin >> roomLengthP;
	cout << "Please enter width of room:" << endl;
	cin >> roomWidthP;
	return  ceil(roomLengthP) * ceil(roomWidthP);
}
//calculateCarpetCost
float calculateCarpetCost(int roomSize, float sellingprice)
{
    cout << "Please enter selling price for carpet" << endl;
    cin >> sellingprice;
	return roomSize * sellingprice;
}
//calculateLabourCost
float calculateLabourCost(int roomSize1)
{
	return roomSize1*24;
}
//qualifyForDiscount
bool qualifyForDiscount(string customerNumber)
{
    bool ForDiscount;
	char discountflag;
	discountflag = customerNumber[0];
	ForDiscount = (discountflag == '0'); //Error check this
	return ForDiscount;
}
//computeDiscount
float computeDiscount(float discountpercentageP, float amountP, bool discountflag)
{
    float discountrecieved;
    if (discountflag == 1)
    {
        cout << "Please enter discount to apply (0-100):" << endl;
	    cin >> discountpercentageP;
	    discountrecieved = amountP *(discountpercentageP/100);
	    return discountrecieved;
    }
    else
        return 0;
}
//printCustomerStatement
void printCustomerStatement(string customerName1, string customerNumber1, float CarpetCost1,
                            float LabourCost1, float firstsubtotal1, float discount1,
                            float secondsubtotal1, float taxamount,  float total)
{
    cout << setw(45) << "CROSWELL CARPET STORE" << endl;
    cout << setw(40) << " STATEMENT" << endl;
    cout << setw(40) << "Customer name : " << customerName1 << endl;
    cout << setw(40) << "Customer number : " << customerNumber1 << endl;
    cout << setw(40) << "Carpet price : " << CarpetCost1 << endl;
    cout << setw(40) << "Labour : " << LabourCost1 << endl;
    cout << setw(40) << "Subtotal : " << firstsubtotal1 << endl;
    cout << setw(40) << "Less discount : " << discount1 << endl;
    cout << setw(40) << "Subtotal : " << secondsubtotal1 << endl;
    cout << setw(40) << "Plus tax : " << taxamount << endl;
    cout << setw(40) << "Total : " << total << endl;
}

int main()
{
    float roomLength, roomWidth ;
    //Global variables used in function calls
    float mCarpetsize, mCarpetCost, mLabourCost, mForDiscount,
    mDiscountpercentage, mSellingprice, mDiscountamount, tax, mTotal;
    string mCustomerName, mCustomerNumber;
    const float TAXRATE = 0.14;
    //Variables for subtotals
    float firstsubtotal, secondsubtotal;
    cout.setf(ios::fixed);
    cout.precision(2);
    //Call functions for name and number
    mCustomerName = getCustomerName(mCustomerName);
    mCustomerNumber = getCustomerNumber(mCustomerNumber);
    //Assign called functions to global variables
    mForDiscount = qualifyForDiscount(mCustomerNumber);
    mCarpetsize = calculateCarpetSize(roomLength, roomWidth);
    mCarpetCost = calculateCarpetCost(mCarpetsize, mSellingprice);
    mLabourCost = calculateLabourCost(mCarpetsize);
    firstsubtotal = mCarpetCost + mLabourCost;
    mDiscountamount = computeDiscount(mDiscountpercentage, firstsubtotal, mForDiscount);
    //Additional calculations
    secondsubtotal = firstsubtotal - mDiscountamount;
    tax = mCarpetCost * TAXRATE;
    mTotal = secondsubtotal + tax;
    //Call print function
    printCustomerStatement(mCustomerName, mCustomerNumber, mCarpetCost,mLabourCost ,
                           firstsubtotal, mDiscountamount, secondsubtotal, tax, mTotal);
return 0;
}
