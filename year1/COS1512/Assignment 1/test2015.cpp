#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void checkFile(ifstream& infile, int& p, int& num_Characters)
{
char ch;
infile.get(ch);

typedef int* p;
typedef int* q;
charArrptr p;
charArrptr q;

while(!infile.eof())
{
cout << ch;
infile.get(ch);
num_characters = num_characters + 1;
}
p = new char [num_characters];
q = new char [num_characters];
}
int main()
{
ifstream infile;
ofstream outfile;
ifstream encrptedfile; //to display the encrypted file
ifstream decryptedfile;//to display the decrypted file
string file_READ, outName;
int option, num_characters;
cout<<"Enter Your Option ";
cout<<"1. To Encrypt The File \n";
cout<<"2. To Decrypt The File \n";
cout<<"Option : ";
cin>>option;

cout << endl << "Enter the input file name. " << endl;
cin >> file_READ;
cout << endl << "Enter the output file name. " << endl;
cin >> outName;
infile.open(file_READ.c_str());
if (infile.fail())
{
cout << "Failed to open a file" << endl;
system("PAUSE");
exit(0);
}
outfile.open(outName.c_str());
if (outfile.fail())
{
cout << "Failed to open a file" << endl;
system("PAUSE");
exit(0);
}
while(!infile.eof())
{
array1[g] = ' ';
i = 0;
infile.get(ch);
}

else if (ch == ' ')
{
cout << ' ';
infile.get(ch);
}

infile.close();
outfile.close();

encrptedfile.open(file_READ.c_str());
if (encrptedfile.fail())
{
cout << "Cannot open file "
<< file_READ << " Aborting!" << endl;
exit(1);
}
cout << endl << "The contents of the input file is : "<< endl << endl;
checkFile(encrptedfile);
encrptedfile.close();


decryptedfile.open(outName.c_str());
if (decryptedfile.fail())
{
cout << "Failed to open a file" << endl;
system("PAUSE");
exit(0);
}
cout << endl << endl<< "The contents of the output file is : "
<< endl << endl;
checkFile(decryptedfile);
decryptedfile.close();
return 0;
}
