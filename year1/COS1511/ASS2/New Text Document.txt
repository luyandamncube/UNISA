#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    for (int k = 1; k <= 5; k++)
    {
        string theEmployee1;
        float theHoursWorked;
        float thePayRate;
        cout << "Please enter employee name: "  << endl;
        getline(cin, theEmployee1);
        cout << endl;
        cout << "Please enter how many hours the employee worked: " << endl;
        cin >> theHoursWorked;
        cout << endl;
         cout << "Please enter employee hourly pay rate: " << endl;
        cin >> thePayRate;
        cout << endl;
        //Output           
        cout << theEmployee1 << endl;
        cout << theHoursWorked << endl;
        cout << thePayRate << endl;
    }
return 0;
}
