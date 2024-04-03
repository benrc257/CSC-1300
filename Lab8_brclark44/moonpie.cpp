/*
    Author: Benjamin Clark
    Name: moonpie.cpp
    Date: 4/2/24
    Purpose: To document the moonpie stealing habits of Jane.
*/
#include <iostream>
#include <vector>
using namespace std;

//prototypes
void enterStolenMoonpies(vector<int>&, int);
void totalStolenMoonpies(vector<int>, int);
void averageStolenMoonpies(vector<int>, int);
void highestStolenMoonpies(vector<int>, int);
void lowestStolenMoonpies(vector<int>, int);

int main() {
    //variables
    int days = 1;
    vector<int> moonpie(days);

    //asks the user for the number of days Jane has stolen
    cout << "\nHow many days has Jane stolen Moonpies?";
    cout << "\n>> ";
    while (!(cin >> days) || days < 1) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid number of days. Please enter a whole number greater than 0.";
        cout << "\n>> ";
    }
    
    //resize the vector
    moonpie.

    //calls the enter function to request moonpie vector values from the user
    enterStolenMoonpies(moonpie, days);

    //calls the total function to display the total stolen moonpies
    totalStolenMoonpies(moonpie, days);

    //calls the total function to display the average stolen moonpies
    averageStolenMoonpies(moonpie, days);

    //calls the total function to display the highest amount of stolen moonpies
    highestStolenMoonpies(moonpie, days);

    //calls the total function to display the lowest amount of stolen moonpies
    lowestStolenMoonpies(moonpie, days);
}

/*
    Name: enterStolenMoonpies()
    Purpose: Prompt the user for the number of stolen moonpies on each day
*/
void enterStolenMoonpies(vector<int>& moonpie, int days) {

    //for loop runs for the number of days set by the days variable
    cout << "\nPlease enter the number of stolen Moonpies on each day:\n";
    for (int i = 0; i < days; i++) {
        cout << "Day " << i+1 << " >> ";

        //verifies user input
        while (!(cin >> moonpie.at(i)) || moonpie.at(i) < 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid number of Moonpies. Please enter a whole number greater than or equal to 0.";
            cout << "Day " << i << " >> ";
        }
    }
}

/*
    Name: totalStolenMoonpies()
    Purpose: Add the stolen moonpies and display the result
*/
void totalStolenMoonpies(vector<int> moonpie, int days) {
    //variables
    int total = 0;

    //for loop runs and adds the elements together
    for (int i = 0; i < days; i++) {
        total += moonpie.at(i);
    }

    //displays the total
    cout << "\nJane has stolen " << total << " Moonpies.\n";
}

/*
    Name: averageStolenMoonpies()
    Purpose: Average the stolen moonpies and display the result
*/
void averageStolenMoonpies(vector<int> moonpie, int days) {
    //variables
    int total = 0;

    //for loop runs and adds the elements together
    for (int i = 0; i < days; i++) {
        total += moonpie.at(i);
    }

    //displays the average
    cout << "\nJane has stolen an average of " << (total /= days) << " Moonpies.\n";
}

/*
    Name: highestStolenMoonpies()
    Purpose: Find the highest amount stolen moonpies on a single day and display the result
*/
void highestStolenMoonpies(vector<int> moonpie, int days) {
    //variables
    int highest = 0;

    //for loop runs and finds the average element
    for (int i = 0; i < days; i++) {
        if (highest < moonpie.at(i)) {
            highest = moonpie.at(i);
        }
    }

    //displays the highest value
    cout << "\nJane stole a record high of" << highest << " Moonpies in a single day.\n";
}

/*
    Name: lowestStolenMoonpies()
    Purpose: Find the lowest amount stolen moonpies on a single day and display the result
*/
void lowestStolenMoonpies(vector<int> moonpie, int days) {
    //variables
    int lowest = 0;

    //for loop runs and finds the smallest element
    for (int i = 0; i < days; i++) {
        if (lowest > moonpie.at(i)) {
            lowest = moonpie.at(i);
        }
    }

    //displays the lowest value
    cout << "\nJane stole a record high of" << lowest << " Moonpies in a single day.\n";
}
