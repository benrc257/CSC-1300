// This program will read in a group of test scores( positive integers from 1 to 100)
// from the keyboard and then calculates and outputs  the average score
// as well as the highest and lowest score. There will be a maximum of 100 scores.

// AUTHOR(S): Benjamin Clark
// DATE: 3/19/24

#include <iostream>
using namespace std;



double findAverage (int[], int);  // finds average of all grades
int   findHighest (int[], int);  // finds highest of all grades
int   findLowest  (int[], int);  // finds lowest of all grades

int main()
{
   const int SIZE = 100;
   int grades[SIZE];              // the array holding the grades.
   int  numberOfGrades;            // the number of grades read.
   int pos;                        // index to the array.

   double avgOfGrades;              // contains the average of the grades.
   int highestGrade;               // contains the highest grade.
   int lowestGrade;                // contains the lowest grade.

   // Read in the values into the array
   pos = 0;
   cout << "Please input a grade from 1 to 100, (or -1 to stop)" << endl;
   cin  >> grades[pos];

   while (grades[pos] != -1)
   {
      pos++;
      cin >> grades[pos];
   }

   numberOfGrades = pos;

   // call to the function to find average
   avgOfGrades = findAverage(grades, numberOfGrades);

   cout << endl << "The average of all the grades is " << avgOfGrades << endl;

   // call to the function to find highest
   highestGrade = findHighest(grades, numberOfGrades);
   
   cout << endl << "The highest grade is " << highestGrade << endl;

   // call to the function to find lowest
   lowestGrade = findLowest(grades, numberOfGrades);
   
   cout << endl << "The lowest grade is " << lowestGrade << endl;

   return 0;
}

//****************************************************************************
//                                 findAverage
//
// task:          This function receives an array of integers and its size.
//                It finds and returns the average of the numbers in the array
// data in:       array of floating point numbers
// data returned: avarage of the numbers in the array
//
//****************************************************************************
double findAverage (int array[], int size)
{
   double grades = 0;

   //goes through the entire array and adds the grades to "grades"
   for (int i = 0; i < size; i++) {
      grades+=array[i];
   }

   //returns the total of all grades divided by the number of grades
   return grades/size;
}

//****************************************************************************
//                                 findHighest
//
// task:          This function receives an array of integers and its size.
//                It finds and returns the highest value of the numbers in
//                the array
// data in:       array of floating point numbers
// data returned: highest value of the numbers in the array
//
//****************************************************************************
int   findHighest (int array[], int size)
{
  int highest = 0;

   //runs through the whole array, comparing all values to the current highest value
   for (int i = 0; i < size; i++) {
      if (array[i] > highest) {
         highest = array[i];
      }
   }

   //returns the highest value found
   return highest;
}

//****************************************************************************
//                                 findLowest
//
// task:          This function receives an array of integers and its size.
//                It finds and returns the lowest value of the numbers in
//                the array
// data in:       array of floating point numbers
// data returned: lowest value of the numbers in the array
//
//****************************************************************************
int   findLowest  (int array[], int size)
{
   int lowest = 100;

   //runs through the whole array, comparing all values to the current lowest value
   for (int i = 0; i < size; i++) {
      if (array[i] < lowest) {
         lowest = array[i];
      }
   }

   //returns the lowest value found
   return lowest;
}