#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
class book
{
public:
    book();
    void setbook(); //mutator for book info
    void getbook(); //accessor for book info
    void applydiscount(); //accessor for discount info

private:
    char title[20];
    char author[20];
    float price;
    int stock;

};
//constructor default
  book::book()
  {
    char * title=new char[50];
    char *author=new char[50];
    price=0;
    stock=0;
   }

//mutator
void book::setbook()
{
    cin.ignore();
    cout<<"\n Enter the Title of the Book:";
    cin.getline(title,50,'\n');

    cout<<"\n Enter The Name Of the Author:";
    cin.getline(author,50,'\n');

    cout<<"\n Enter the Price of the book in Rands:";
    cin>>price;

    cout<<"\n Enter number of books in stock:";
    cin>>stock;


}

//accessor
void book::getbook()
{
    cout <<"\n "<<title<<"\t\t  "<<author<<"\t "<< price<<"\t "<<stock;
}

void book::applydiscount()
{
if (stock >= 20)
    cout  <<"\n "<<title<<"\t\t  "<<author<<"\t "<< price*0.85<<"\t "<<stock;
}

int main()
{
int userchoice,k,i;
book bookarray[100];

do
{
cout<<"\n************BOOK SHOP*******************";
cout<<"\n 1.Enter new book \n 2.Display all books in stock \n 3.Exit";
cout<<"\n Enter Your Choice:";
cin>>userchoice;
switch(userchoice)
{
case 1:
    cout<<"\n How many books do you want to enter?: ";
    cin>>k;
    for(i=0;i<k;i++)
    {
        bookarray[i].setbook();
    }
break;
case 2:
    cout << "\n CURRENT INVENTORY";
    cout<<"\n"<<"TITLE"<<"\t\t\t  "<<"AUTHOR"<<"\t\t "<<"PRICE"<<"\t "<<"STOCK";
    //Display all books in inventory
    for(i=0;i<k;i++)
    {
        bookarray[i].getbook();
    };
    cout << "\n DISCOUNTED INVENTORY";
    cout<<"\n"<<"TITLE"<<"\t\t\t  "<<"AUTHOR"<<"\t\t  "<<"PRICE"<<"\t "<<"STOCK";
    //Display all discounted books in inventory
    for(i=0;i<k;i++)
    {
        bookarray[i].applydiscount();
    }
break;
case 3: exit(EXIT_SUCCESS);
break;
default :
    cout<<"\n Choice does not exist! enter again:";
break;
 }
   }while(userchoice!=5);
 return 0;
}
