/*
	Title: brclark44_functions.cpp
	Author: Benjamin Clark
	Date: 3/9/24
	Purpose: Gathers information from a file on students, then displays
    statistics from the data. This file has the functions.
*/
#include "brclark44_prog3.h"

/*
	Function: 	getData                      
	Purpose:	To retrieve data from the given file and
                place it into three arrays.
*/
int getData(string first[], string last[], double hours[], string filename, int size) {
    //variables
    ifstream infile;
    int count;

    //open file, detect and return -1 if failed
    infile.open(filename);
    if (!infile.is_open()) {
        return -1;
    }

    //places the data from the file into the arrays for as long as i is less than the
    //max size of the arrays and the file has no errors and has not ended
    for (int i = 0; i < size, infile.good(); i++) {
        getline(infile, first[i], ',');
        getline(infile, last[i], ',');
        infile >> hours[i];
        infile.ignore();
        count = i;
    }

    //fills the next slot in the hours array with -1 and returns the number of students found in the file
    hours[count] = -1;
    return count;
}

/*
	Function: 	selectionSort                        
	Purpose:	This function performs the selection sort     
				algorithm on hoursSM array, sorting the 
				hours in ascending order and making sure 
				to also sort the name arrays at the same 
				time.
*/
void selectionSort(string lastName[], string firstName[], double hoursSM[], int size)
{
	int start, minIndex;
	double minValue;
	string nameTemp;

	for (start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = hoursSM[start];
		for(int index = start + 1; index < size; index++)
		{
			if (hoursSM[index] < minValue)
			{
				minValue = hoursSM[index];
				minIndex = index;
			}
		}
		//swap hoursSM array values
		hoursSM[minIndex] = hoursSM[start];
		hoursSM[start] = minValue;
		//swap firstName array values
		nameTemp = firstName[minIndex];
		firstName[minIndex] = firstName[start];
		firstName[start] = nameTemp;
		//swap lastName array values
		nameTemp = lastName[minIndex];
		lastName[minIndex] = lastName[start];
		lastName[start] = nameTemp;
	}
}

/*
	Function: 	printArray                       
	Purpose:	Prints the data from the arrays
                into a chart.
*/
void printArray(string first[], string last[], double hours[], int size) {

    cout << "\n| Avg. Hours Per Day | First Name | Last Name |";
    cout << "\n***********************************************";

    //prints through the array until it reaches a -1
    cout << fixed << setprecision(2);
    for (int i = 0; i < size, hours[i] != -1; i++) {
        cout << "\n" << setw(21) << setfill(' ') << hours[i] << setw(13) << setfill(' ') << first[i] << last[i];
    }
    cout << "\n";
}

/*
	Function: 	getAverage                       
	Purpose:	Returns the average hours from
                the array.
*/
double getAverage(double hours[], int size) {
    return 1;
}

/*
	Function: 	getMedian                      
	Purpose:	Returns the median hours from
                the array.
*/
double getMedian(double hours[], int size) {
    return 1;
}

/*
	Function: 	getMode                      
	Purpose:	Returns the mode hours from
                the array.
*/
double getMode(double hours[], int size) {
    return 1;
}