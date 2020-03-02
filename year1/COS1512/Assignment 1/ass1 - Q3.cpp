#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
double p[20], r;
int numElements = 0;
int medElement, middlepoint;
ifstream in_stream;
in_stream.open("file1.txt");
if(in_stream.fail())
{
cout << "Failed to open a file" << endl;
system("PAUSE");
exit(0);
}
else
{
cout << "File open SUCCESSFUL. \n";
//Loop to count number of elements in text file
while(!in_stream.eof())
{
in_stream >> p[numElements];
numElements = numElements + 1;
}
}
in_stream.close();

cout <<"Finding median... \n";
//If number of elements are EVEN
if (numElements%2 == 0)
{
    cout << "The number of elements are EVEN \n";
    middlepoint = numElements/2;
    medElement = (p[middlepoint] + p[middlepoint+1])/2;
}
//If number of elements are ODD
else
{
    cout << "The number of elements are ODD \n";
    middlepoint = (numElements/2) + 1;
    medElement = p[middlepoint];
}

cout << "The median of the data set is: " << medElement;
return 0;
}

