#include <iostream>
#include <string>
using namespace std;

//Function 1
float specialdiscount(char popcorn1, float ticketprice)
{
    float total;
    if (popcorn1 == 'Y')
        total = ticketprice*0.80;
    else
        total = ticketprice*0.90;
    return total;
}
//Function 2
float normaldiscount(char popcorn2, float ticketprice1)
{
    float total1;
    if (popcorn2 == 'Y')
        total1 = ticketprice1*0.90;
    else
        total1 = ticketprice1;
    return total1;
}
int main ()
{
    const float TICKETPRICE = 80.00;
    char entry, popcorn;
    float totalprice;
    //While loop to ensure correct entry of characters
    while (popcorn != 'Y' || popcorn != 'N'|| entry != 'S' || entry != 'P' || entry != 'O')
    {
        cout << "Please enter p for pensioner, s for student or o for other:" << endl;
        cin >> entry;
        entry = toupper(entry);
        cout << "Did you buy any popcorn?  Y/N: " << endl;
        cin >> popcorn;
        popcorn = toupper(popcorn);
        if (entry == 'P' || entry == 'S')
        {
            totalprice = specialdiscount(popcorn,TICKETPRICE);
            cout << "This person will pay " << totalprice << " for their ticket" << endl;
            break;
        }

        else if (entry == 'O')
        {
           totalprice = normaldiscount(popcorn,TICKETPRICE);
           cout << "This person will pay " << totalprice << " for their ticket" << endl;
           break;
        }
        else
        cout << "Invalid entry, please try again." << endl;
    }

return 0;
}
