/*
	Title:    lab11.cpp
	Author:   Benjamin Clark
	Date:     4/16/24
	Purpose:  To catalogue information about esports players for a team
*/
#include <iostream>
#include <cctype>
using namespace std;

//structures
struct Player {
    string name, hometown;
    int age, numGames;
};

int main() {
    //variables
    int size, **playerHoursArray, hours, highestPlayer, lowestPlayer;
    int highestHours = INT_MIN, lowestHours = INT_MAX;
    Player *playerArray;

    //asks the user for the number of esports players
    cout << "\nHow many esports players major in CSC?";
    cout << "\n>> ";
    while (!(cin >> size) || size < 1) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a whole number greater than 0.";
        cout << "\n>> ";
    }

    //dynamically allocate the arrays
    playerArray = new Player[size];
    playerHoursArray = new int*[size];

    //asks the user to input information on the players
    cout << "\nPlease enter the information for each player:\n";
    for (int i=0; i<size; i++) {
        cout << "\nPLAYER " << i+1 << ":";
        cout << "\nName: ";
        cin.ignore();
        getline(cin, playerArray[i].name);
        cout << "Hometown: ";
        getline(cin, playerArray[i].hometown);
        cout << "Age: ";
        while (!(cin >> playerArray[i].age)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a whole number: ";
        }
        cout << "Number of Games: ";
        while (!(cin >> playerArray[i].numGames) || playerArray[i].numGames < 1) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a whole number greater than 0: ";
        }
        cout << "Please enter the number of hours played per game:\n";
        
        //dynamically allocate the hours section of the playerHoursArray
        playerHoursArray[i] = new int[playerArray[i].numGames];
        
        //reset hours variable to zero
        hours = 0;

        //for loop uses the numGames variable to determine how long to run
        for (int j=0; j<playerArray[i].numGames; j++) {
            cout << "\tGame " << j+1 << ": ";
            while (!(cin >> playerHoursArray[i][j]) || playerHoursArray[i][j] < 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\tInvalid input. Please enter a non-negative whole number: ";
            }
            hours+=playerHoursArray[i][j];
        }

        //set aside i for later if the player currently has the highest or lowest hours
        if (hours > highestHours) {
            highestHours = hours;
            highestPlayer = i;
        }

        if (hours < lowestHours) {
            lowestHours = hours;
            lowestPlayer = i;
        }
    }

    //display the highest and lowest hour counts and their players
    cout << "\nThe player with the highest number of total hours (" << highestHours << ") is " << playerArray[highestPlayer].name << ".\n";
    cout << "\nThe player with the lowest number of total hours (" << lowestHours << ") is " << playerArray[lowestPlayer].name << ".\n";

    //delete the dynamically allocated arrays
    for (int i=0; i<size; i++) {
        delete [] playerHoursArray[i];
    }
    delete [] playerHoursArray;
    delete [] playerArray;

    //program ends
    return 0;
}