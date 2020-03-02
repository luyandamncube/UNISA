// This program finds the average time spent programming by a student
// each day over a three day period.
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
int numStudents;
float numHours, total, average, Biologyaverage, Programmingaverage;
int student,day = 0,numdays,subjectflag; // these are the counters for the loops
string subject;
cout << "This program will find the average number of hours a day"
<< " that a student spent programming over a long weekend\n\n";
cout << "How many students are there?" << endl;
cin >> numStudents;
cout << "Enter the number of days in the long weekend" << endl;
cin >> numdays;
cout << "============================================================================" << endl;
	for( student = 1; student <= numStudents; student++)
	{
		for( subjectflag = 1; subjectflag <= 2; subjectflag++)
		{
			switch (subjectflag)
			{
				case 1 :
				subject = "Biology";
				break;
				case 2 :
				subject = "Programming";
				break;
			}
            total = 0;
			for(day = 1; day <= numdays; day++)
			{
				cout << "Please enter the number of hours worked by student "
				<< student <<" on day " << day << " for " << subject << endl;
				cin >> numHours;
				total = total + numHours;
			}
			average = total / numdays;
			cout << "The average number of hours per day spent on " << subject
			<< " by student " << student << " is " << average
			<< endl << endl << endl;

			if (subjectflag == 1 ) //Seperate each subject average
				Biologyaverage = average;
			else
				Programmingaverage = average;
		}

		if (Biologyaverage >  Programmingaverage)
            cout << "Student " << student << " spent the most time on Biology" << endl;

		else
            cout << "Student " << student << " spent the most time on Programming" << endl;;
        cout << "============================================================================" << endl;
	}

return 0;
}
