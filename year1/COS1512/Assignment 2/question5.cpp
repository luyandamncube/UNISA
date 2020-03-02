#include <iostream>
#include <string>
#include "Team.h"
using namespace std;
int main()
{
//Instantiate new objects opponent and newOpponent
Team opponent, newOpponent;
Team home("South-Africa", 1, 4, 6, 4);
opponent.reset("Germany", 1, 4, 6, 4);

cout << "The home team is: " << endl << home << endl;
cout << "The opponent team is " << endl << opponent << endl;
if (home == opponent)
cout << "This is a tie!" << endl;
else if (home > opponent)
++home;
else ++opponent;
cout << home.get_country() << " has " << home.get_points()
<< " points and " << opponent.get_country() << " has "
<< opponent.get_points() << " points" << endl;
cout << home.get_country() << " is in round " << home.get_round()
<< " and " << opponent.get_country() << " is in round "
<< opponent.get_round() << endl << endl;
cout << "Enter data for new opponent (country, round, points, goals "
<< "for and goals against): ";
cin >> newOpponent;
cout << endl;
int SApoints, Spoints, goalsForSA, goalsForS,goalsAgainstSA;
int goalsAgainstS;
cout << "Enter points earned for this match by South-Africa: ";
cin >> SApoints;
cout << "Enter goals for SA: ";
cin >> goalsForSA;
cout << "Enter goals against SA: ";
cin >> goalsAgainstSA;
cout << "Enter points earned for this match by Spain: ";
cin >> Spoints;
cout << "Enter goals for Spain: ";
cin >> goalsForS;
cout << "Enter goals against Spain: ";
cin >> goalsAgainstS;
home.update(SApoints,goalsForSA,goalsAgainstSA);
opponent.update(Spoints,goalsForS,goalsAgainstS);
if (home == newOpponent)
cout << "This is a tie!" << endl;
else if (home > newOpponent)
++home;
else ++newOpponent;
cout << home.get_country() << " has " << home.get_points()
<< " points and " << newOpponent.get_country() << " has "
<< newOpponent.get_points() << " points" << endl;
cout << home.get_country() << " is in round " << home.get_round()
<< " and " << newOpponent.get_country() << " is in round "
<< newOpponent.get_round() << endl << endl;
return 0;
}







