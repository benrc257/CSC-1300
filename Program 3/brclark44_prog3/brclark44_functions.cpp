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
int getData(string first[], string last[], double hours[], string& filename, int size) {
    //variables
    ifstream infile;
    int count;

	cout << "\nWhat is the file name containing the data? (filename.txt) ";
    getline(cin, filename);

    //open file, detect and return -1 if failed
    infile.open(filename);
    if (!infile.is_open()) {
        return -1;
    }

    //places the data from the file into the arrays for as long as i is less than the
    //max size of the arrays and the file has no errors and has not ended
    for (int i = 0; i < size && infile.good(); i++) {
        getline(infile, first[i], ',');
        getline(infile, last[i], ',');
        infile >> hours[i];
        infile.ignore();
        count = i;
    }

    //returns the number of students found in the file
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

    //prints through the array until it reaches the end
    cout << fixed << setprecision(2);
    for (int i = 0; i < size; i++) {
		if (hours[i] != 0) {
        	cout << "\n" << setw(21) << setfill(' ') << left << hours[i] << setw(13) << setfill(' ') << left << first[i] << last[i];
		}
	}
    cout << "\n";
}

/*
	Function: 	getAverage                       
	Purpose:	Returns the average hours from
                the array.
*/
double getAverage(double hours[], int size) {
    //variables
	double totalHours = 0;
	int count = 0;

	//counts the number of values in the set and adds them together
	for (int i = 0; i < size; i++) {
		if (hours[i] != 0) {
        	count++;
		}
		totalHours += hours[i];
	}

	//returns the average
	return totalHours/count;
}

/*
	Function: 	getMedian                      
	Purpose:	Returns the median hours from
                the array.
*/
double getMedian(double hours[], int size) {
	//variables
	int count = 0;
	double median;
	
	//counts the number of values in the hours array
	for (int i = 0; i < size; i++) {
		if (hours[i] != 0) {
        	count++;
		}
	}

	//finds if the count is even or odd
	//if even, the two middle values are averaged
	if ((count % 2) == 0) {
		median = (hours[size - (count/2)] + hours[(size - (count/2)) - 1]) / 2;
	} else {
		median = hours[size - (count/2)];
	}


	//returns the median
    return median;
}

/*
	Function: 	getMode                      
	Purpose:	Returns the mode hours from
                the array.
*/
double getMode(double hours[], int size) {
	//variables
	int count = 0, highestCount = 0;
	double mode;

	//for loop goes through each slot of the array
	for (int i = 0; i < size; i++) {
		//skips over values of 0 and ensures that hours[i-1] doesn't access hours[-1] and crash.
		//if the current value of hours[] isn't 0 and it isn't the first value in the array,
		//then the current value in the array is checked against the last. if they are different,
		//the count is set to 1. if they are the same, the count increases by 1.
		if (!(hours[i] <= 0) && ((i - 1) > -1)) {
			if (hours[i] != hours[i - 1]) {
				count = 1;
			} else {
				count++;
			}
		} else if (!(hours[i] <= 0)) {
			count = 1;
		}

		//if the current count is higher than the highest count reached in previous loops,
		//the current value in the array is marked as the mode. it stays as the mode until
		//the highest count is surpassed again.
		if (count > highestCount) {
			highestCount = count;
			mode = hours[i];
		}
	}

	//only returns the mode if the count surpassed 1
	if (highestCount > 1) {
		return mode;
	}
	
	return -1;
}