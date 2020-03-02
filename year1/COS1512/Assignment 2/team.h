//Avoid repeated expansionss
#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <string>
using namespace std;
class Team
{
public:
Team();

Team(string c1, int r1, int p1, int gF, int gA);
~Team();
//Overloaded operators
friend bool operator>(const Team &Team1, const Team &Team2);
friend bool operator==(const Team &Team1, const Team &Team2);
//Overloaded stream operators
friend istream& operator>>(istream& ins, Team & T);
friend ostream& operator<<(ostream& outs, const Team & T);

//Accessors
string get_country() const;
int get_round() const;
int get_points()const;
int get_goalsFor()const;
int get_goalsAgainst()const;

//Mutators
void set_country(string c1);
void set_round(int r1);
void set_points(int p1);
void set_goalsFor(int gF);
void set_goalsAgainst(int gA);

//Reset to specific parameters
void reset(string c1, int r1, int p1, int gF, int gA);

int calcGoalDifference()const;
void update(int p, int gF, int gA);
friend Team operator++(Team &T);
private:
string country;
int round;
int points;
int goalsFor;
int goalsAgainst;
};

#endif
