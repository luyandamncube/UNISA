#include <iostream>
using namespace std;

int main ()
{
int next = 2, sum = 0; //sum should be initialised to 0
while (next <= 5)
{
sum = sum + next;
next++; //Loop control variable next should only be incremented AFTER the sum is calculated
}
cout << "The sum of 2 through 5 is " << sum << endl;
    return 0;
}
