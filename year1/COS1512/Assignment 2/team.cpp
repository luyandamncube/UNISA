#include "Team.h"
#include <iostream>
#include <string>
using namespace std;

//Default constructor
Team::Team()
{
country = "Country 0";
round = 0;
points = 0;
goalsFor = 0;
goalsAgainst = 0;
}

//Overloaded constructor
Team::Team(string c1, int r1, int p1, int gF, int gA)
{
country = c1;
round = r1;
points = p1;
goalsFor = gF;
goalsAgainst = gA;
}
//Destructor
Team::~Team()
{
cout<<"Game Over" << endl;
}
string Team::get_country() const
{
return country;
}
int Team::get_round() const
{
return round;
}
int Team::get_points()const
{
return points;
}
int Team::get_goals_for()const
{
return goalsFor;
}
int Team::get_goals_against()const
{
return goalsAgainst;
}
void Team::set_country(string c1)
{
country = c1;
}
void Team::set_round(int r1)
{
round = r1;
}
void Team::set_points(int p1)
{
points = p;
}
void Team::set_goals_for(int gF)
{
goalsFor = gF;
}
void Team::set_goals_against(int gAg)
{
goalsAgainst = gA;
}
//resets to values specified by parameters.
void Team::reset(string c1, int r1, int p1, int gF, int gA)
{
country = c1;
round = r1;
points = p1;
goalsFor = gF;
goalsAgainst = gA;
}
int Team:: calcGoalDifference ()const
{
return (goalsFor - goalsAgainst);
}
void Team::update(int p1, int gF, int gA)
{
points = points + p1;
goalsFor = goalsFor + gF;
goalsAgainst = goalsAgainst + gA;
}
Team operator++(Team &T)
{
++T.round;
return T;
}
bool operator>(const Team &Team1, const Team &Team2)
{
if ((Team1.points > Team2.points)||((Team1.points == Team2.points) &&
(Team1. calcGoalDifference() > Team2. calcGoalDifference ())))
return true;
return false;
}
bool operator==(const Team &Team1, const Team &Team2)
{
if ((Team1.points == Team2.points)&&(Team1. calcGoalDifference () == Team2. calcGoalDifference ()))
return true;
return false;
}
//Stream for insertion
istream & operator>>(istream& ins, Team& T)
{
ins >> T.country;
ins >> T.round;
ins >> T.points;
ins >> T.goalsFor;
ins >> T.goalsAgainst;
return ins;
}
//Stream for display
ostream & operator<<(ostream& outs, const Team& T)
{
cout << "Country : " << T.country << endl;
cout << "Round : " << T.round << endl;
cout << "Points : " << T.points << endl;
cout << "Goals for: " << T.goalsFor << endl;
cout << "Goals against: " << T.goalsAgainst << endl;
return out;
}
