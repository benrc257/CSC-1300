/*
    Author: Benjamin Clark
    Name: moonpie.cpp
    Date: 4/2/24
    Purpose: To document the moonpie stealing habits of Jane.
*/
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//prototypes
void enterStolenMoonpies(vector<int>&, int);
int totalStolenMoonpies(vector<int>, int);
double averageStolenMoonpies(vector<int>, int);
int highestStolenMoonpies(vector<int>, int);
int lowestStolenMoonpies(vector<int>, int);

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
    moonpie.resize(days);

    //calls the enter function to request moonpie vector values from the user
    enterStolenMoonpies(moonpie, days);

    //DISPLAY RESULTS
    cout << "\n************************| RESULTS |************************\n";

    //calls the total function to display the total stolen moonpies
    cout << "\nJane has stolen " << totalStolenMoonpies(moonpie, days) << " Moonpies.\n";

    //calls the total function to display the average stolen moonpies
    cout << "\nJane has stolen an average of " << fixed << setprecision(1) << averageStolenMoonpies(moonpie, days) << " Moonpies.\n";

    //calls the total function to display the highest amount of stolen moonpies
    cout << "\nJane stole a record high of " << highestStolenMoonpies(moonpie, days) << " Moonpies in a single day.\n";

    //calls the total function to display the lowest amount of stolen moonpies
    cout << "\nJane stole a record low of " << lowestStolenMoonpies(moonpie, days) << " Moonpies in a single day.\n";

    cout << "\n***********************************************************\n" << endl;

    //ends program
    return 0;
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
    Purpose: Add the stolen moonpies and return the result
*/
int totalStolenMoonpies(vector<int> moonpie, int days) {
    //variables
    int total = 0;

    //for loop runs and adds the elements together
    for (int i = 0; i < days; i++) {
        total += moonpie.at(i);
    }

    //returns the total
    return total;
}

/*
    Name: averageStolenMoonpies()
    Purpose: Average the stolen moonpies and return the result
*/
double averageStolenMoonpies(vector<int> moonpie, int days) {
    //variables
    double total = 0.0;

    //for loop runs and adds the elements together
    for (int i = 0; i < days; i++) {
        total += moonpie.at(i);
    }

    //returns the average
    return (total/days);
}

/*
    Name: highestStolenMoonpies()
    Purpose: Find the highest amount stolen moonpies on a single day and return the result
*/
int highestStolenMoonpies(vector<int> moonpie, int days) {
    //variables
    int highest = 0;

    //for loop runs and finds the average element
    for (int i = 0; i < days; i++) {
        if (highest < moonpie.at(i)) {
            highest = moonpie.at(i);
        }
    }

    //returns the highest value
    return highest;
}

/*
    Name: lowestStolenMoonpies()
    Purpose: Find the lowest amount stolen moonpies on a single day and return the result
*/
int lowestStolenMoonpies(vector<int> moonpie, int days) {
    //variables
    int lowest = INT_MAX;

    //for loop runs and finds the smallest element
    for (int i = 0; i < days; i++) {
        if (lowest > moonpie.at(i)) {
            lowest = moonpie.at(i);
        }
    }

    //returns the lowest value
    return lowest;
}
