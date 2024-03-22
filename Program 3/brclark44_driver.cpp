/*
	Title: brclark44_driver.cpp
	Author: Benjamin Clark
	Date: 3/9/24
	Purpose: Gathers information from a file on students, then displays
    statistics from the data. This is the main function file.
*/
#include "brclark44_prog3.h"

int main() {

    //variables
    string first[SIZE];
    string last[SIZE];
    double hours[SIZE];
    string filename;
    int getDataResults;
    bool running = true;
    char choice;
    double getModeResults;

    //do while loop runs until the user selects 'n' for the run again prompt
    do {

        //resets all values of the hours array to 0
        for (int i = 0; i < SIZE; i++) {
            hours[i] = 0;
        }

        cout << "\n*****SOCIAL MEDIA STATISTICAL DATA PROGRAM*****\n";

        getDataResults = getData(first, last, hours, filename, SIZE);
            
        //detects if getDataResults ran successfully and runs the program
        if (getDataResults == -1) {
            cout << "\nUnable to open " << filename << "!\n";
        } else {

            //displays number of students in data set
            cout << "\nSuccessfully entered data on " << getDataResults << " students.\n";

            cout << "\nData entered from the file in ascending\norder of hours spent on social media:\n";
                
            //sorts data in arrays
            selectionSort(first, last, hours, SIZE);

            //prints chart with data
            printArray(first, last, hours, SIZE);

            getModeResults = getMode(hours, SIZE);


            //prints statistics from the data
            cout << "\n*****STATISTICS FOR TIME SPENT ON SOCIAL MEDIA*****\n";
            cout << fixed << setprecision(4);
            cout << "\nAverage: " << getAverage(hours, SIZE) << " hours";
            cout << "\nMedian: " << getMedian(hours, SIZE) << " hours";
            if (getModeResults != -1) {
                cout << "\nMode: " << getModeResults << " hours";
            } else {
                cout << "\nMode: " << "The set has no mode.";
            }
            cout << "\n";
        }
        
        //prompts the user if they would like to rerun the program
        cout << "\nRun again? (y/n) ";
        while (!(cin >> choice) || (tolower(choice) != 'y' && tolower(choice) != 'n')) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid choice. Please select y or n: ";
        }
        cin.ignore();

        if (tolower(choice) == 'n') {
            running = false; //this ends the while loop
        }

    } while (running);

    //goodbye message, ends program
    cout << "\nGoodbye!\n";
    return 0;
}