#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//create type definition pointer for dynamic array
typedef int* p;

void encryptordecrypt (char file_Read[16], char file_Write[16], int option)
{

ifstream readtextfile;
int num_characters=0, i=0;
char next;

//open input file stream
readtextfile.open(file_READ);

//loop to count number of characters
while(!readtextfile.eof())
{
cout << ch;
infile.get(ch);
num_characters = num_characters + 1;
}

//Create dynamic array p with numElements
charArrptr p;
charArrptr q;
p = new char [num_characters];
q = new char [num_characters];	//array to hold encryted characters

//loop to input characters from file into char array
in_stream >> p[0];
while (! readtextfile.eof( ))
{
toupper(readtextfile.get(p[i])); //upper & lowercase letters

//encryption algorithm
if (option == 1)
{
	if (p[i] == 'Z')
	q[i] = 'A';
	else
	q[i] = p[i+1];
	// cout ???? how to place into array/file
	i++;
}

//decryption algorithm
else if (option == 2)
{
	if (p[i] == 'A')
	q[i] = 'Z';
	else
	q[i] = p[i-1];
	// cout ???? how to place into array/file
	i++;

}

}
}
int main()
{
int option;
char file_name1[16], file_name2[16];

//declare input & output streams
ifstream readtextfile;
ofstream writetextfile;

//Output user instructions into console
cout<<"Enter Your Option ";
cout<<"1. To Encrypt The File \n";
cout<<"2. To Decrypt The File ";
cout<<"Option : ";
cin>>option;

//Create file for encrypt or decrypt
cout << "Enter the file name to read/ write FROM (maximum of 15 characters):\n";
cin >> file_READ;

cout << "Enter the file name to read/ write TO (maximum of 15 characters):\n";
cin >> file_WRITE;

if(option == 1)
{
cout << "File name for READ is: " << file_READ << endl;


//error check input stream
	if(readtextfile.fail() = 0)
	{
	cout << "Failed to open read/input stream";
	exit(1);
	}
//Call encryptordecrypt function

}
else if (option == 2)
{
cout << "File name for decryption is: " << file_name << endl;
//open output stream
writetextfile.open(file_name);
//error check input stream
	if(writetextfile.fail() = 0)
	{
	cout << "Failed to open write/output stream";
	exit(1);
	}
//Call decrypt option
encryptordecrypt (file_READ[16],fileWRITE[16], option);
}
else
cout << "Please select valid option!";
return 0;
}


