// This program will input an undetermined number of student names
// and a number of grades for each student. The number of grades is
// given by the user. The grades are stored in an array.
// Two functions are called for each student.
// One function will give the numeric average of their grades.
// The other function will give a letter grade to that average.
// Grades are assigned on a 10 point spread.
// 90-100 A   80- 89 B  70-79 C   60-69 D   Below 60 F

// AUTHOR(S): Benjamin Clark
// DATE: 3/19/24

#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

const  int MAXGRADE = 25;              // maximum number of grades per student
const  int MAXCHAR = 30;               // maximum characters used in a name

double findGradeAvg(double[], int);  
char findLetterGrade(double);          

int main()
{
	char firstname[MAXCHAR];
	char lastname[MAXCHAR];
	double grades[MAXGRADE];
	int numOfGrades;                
	double average;                      // holds the average of a student's grade
	char moreInput;                      // determines if there is more input

	cout << setprecision(2) << fixed << showpoint;

	// Input the number of grades for each student
	cout << "\n\nPlease input the number of grades each student will receive." << endl
		<< "This must be a number between 1 and " << MAXGRADE << " inclusive" << endl;
	cout << "NUMBER OF GRADES: ";
	cin >> numOfGrades;

	while (numOfGrades > MAXGRADE || numOfGrades < 1)
	{
		cout << "\nPlease input the number of grades for each student." << endl
			<< "This must be a number between 1 and " << MAXGRADE << " inclusive\n";
		cout << "NUMBER OF GRADES: ";
		cin >> numOfGrades;
	}

	// Input names and grades for each student
	cout << "\nDo you wish to input student data? (y/n)  ";
	cin >> moreInput;
	while(tolower(moreInput) != 'y' && tolower(moreInput) != 'n')
	{
		cout << "\nInvalid entry.  Please enter y or n:  ";
		cin >> moreInput;
	}

	while (tolower(moreInput) == 'y')
	{
		cout << "\nFirst Name: ";
		cin.ignore();
		cin.getline(firstname, 30);
		cout << "Last Name: ";
		cin.getline(lastname, 30);

		for (int count = 0; count < numOfGrades; count++)
		{
			cout << "Grade " << count+1 << ": ";
			cin >> grades[count];
		}

		cout << firstname << ' ' << lastname << " has an average of ";

		// Fill in code to get and print average of student to screen
		// Fill in call to get and print letter grade of student to screen
		// call to the function to find average
   		average = findGradeAvg(grades, numOfGrades);

  		cout << average << endl;

   		// call to the function to find letter grade
   		cout << "Their letter grade is " << findLetterGrade(average) << endl;


		cout << endl << endl;
		cout << "Do you wish to input more student data? (y/n)  ";
		cin >> moreInput;
		while(tolower(moreInput) != 'y' && tolower(moreInput) != 'n')
		{
			cout << "\nInvalid entry.  Please enter y or n:  ";
			cin >> moreInput;
		}
	}

	return 0;
}

//***********************************************************************
//
//                              findGradeAvg
//  task:           This function finds the average of the
//                  numbers stored in an array.
//
//  datain:         an array of integer numbers
//  data returned:  the average of all numbers in the array
//
//***********************************************************************
double findGradeAvg(double array[], int numGrades)
{
	double grades = 0;

    //goes through the entire array and adds the grades to "grades"
	for (int i = 0; i < numGrades; i++) {
    	grades+=array[i];
    }

    //returns the total of all grades divided by the number of grades
    return grades/numGrades;
}

//***********************************************************************
//
//                              findLetterGrade
//  task:           This function finds the letter grade for the number
//                  passed to it by the calling function
//
//  data in:         a double
//  data returned:  the grade (based on a 10 point spread) of the number
//                  passed to the function
//
//***********************************************************************
char  findLetterGrade(double numGrade)
{
	char letter;

	if (numGrade >= 90) {
		letter = 'A';
	} else if (numGrade >= 80) {
		letter = 'B';
	} else if (numGrade >= 70) {
		letter = 'C';
	} else if (numGrade >= 60) {
		letter = 'D';
	} else {
		letter = 'F';
	}

	return letter;
}