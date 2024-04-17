/*
	Title: lab10.cpp
	Author: Benjamin Clark
	Date: 4/9/24
	Purpose: This program stores data for various libraries
    about the number of books they contain and their genres.
*/
#include <iostream>
#include <iomanip>
using namespace std;

//global constants
const int SIZE = 4; //equal to the number of libraries

int main() {
    //variables
    int *numBooksArray[SIZE], numGenres, largest = 0, largestGenre = 0, largestLib = 0;

    //asks the user for the number of genres and validates input
    cout << "\nHow many genres do the libraries have?";
    cout << "\n>> ";
    while (!(cin >> numGenres) || numGenres < 1) {
        cout << "\nInvalid number of genres. Please enter a whole number greater than 0.";
        cout << "\n>> ";
    }

    //allocate arrays for each library using numGenres as the size
    for (int i=0; i < SIZE; i++) {
        numBooksArray[i] = new int[numGenres];
    }

    //receives and places input of books per genre from user into the arrays
    cout << "\nPlease enter the number of books in each genre:\n";
    for (int i=0; i < SIZE; i++) {

        cout << endl; //skips a line at the start of a new library

        for (int j=0; j < numGenres; j++) {

            cout << "LIBRARY " << i+1 << ", GENRE " << j+1 << ": ";

            while (!(cin >> numBooksArray[i][j]) || numBooksArray[i][j] < 0) {
                cout << "Invalid number of books. Please enter a positive whole number: ";
            }

            //saves info on the largest number of books and it's position for later
            if (largest < numBooksArray[i][j]) {
                largest = numBooksArray[i][j];
                largestGenre = j;
                largestLib = i;
            }
        }
    } 

    //displays the largest collection of books in any genre
    cout << "\nLIBRARY " << largestLib+1 << " has the largest number of books in GENRE " << largestGenre+1 << " which contains " << largest << " books!!\n\n";

    //deletes all dynamically allocated arrays
    for (int i=0; i < SIZE; i++) {
        delete [] numBooksArray[i];
    }

    //program ends
    return 0;
}