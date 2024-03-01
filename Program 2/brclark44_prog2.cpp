/*
Title: brclark44_prog2.cpp
Author: Benjamin Clark
Date: 2/17/24
Purpose: This program will execute various functions related to sales info based on
the user's choices.
*/
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <cctype>
using namespace std;

//Global Constants
const double TAX = .0975;

//Function prototypes
void printArt();
void enterSales();
void totalSales();

int main() {

    //Variables
    const string lines(90,'-');
    int choice;
    bool exit = false;
    char confirm;
    
    //printing ascii art
    cout << endl;
    printArt();

    //printing dashes for beginning of program
    cout << endl << lines << endl;

    //menus
    do {
        //prints main menu and validates user's choice
        cout << "\nPlease select from the following menu items:";
        cout << "\n\t1. Enter Sales";
        cout << "\n\t2. Total the Daily Sales";
        cout << "\n\t3. Delete Today's Sales";
        cout << "\n\t4. End Program";
        cout << "\n\n\tCHOOSE 1-4: ";
        while (!(cin >> choice) || (choice < 1 || choice > 4)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid choice. Please select a number between 1 and 4: ";
        }

        //handles the outcome of the user's choice
        switch (choice) {
            //allows the user to enter sales data
            case 1: enterSales();
                    break;
            //totals the sales from the file
            case 2: totalSales();
                    break;
            //deletes the sales file
            case 3: cout << "\nAre you sure you want to delete today's sales data? (y/n) ";

                    while (!(cin >> confirm) || (!(tolower(confirm) == 'y')) && !(tolower(confirm) == 'n')) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "\nInvalid choice. Please select y or n: ";
                    }

                    if (tolower(confirm) == 'y' && !(remove("sales.txt"))) {
                        cout << "\nThe sales data was deleted successfully.\n";
                    } else if (tolower(confirm) == 'y' && remove("sales.txt")) {
                        cout << "\n\"sales.txt\" does not exist or was not found.\n";
                    } else {
                        cout << "\nThe sales data was not deleted.\n";
                    }
                    break;
            //ends program
            case 4: cout << "\nExiting program..."; 
                    exit = true; // this ends the do while loop
        }
    } while (exit == false);

    // printing lines and ending program
    cout << endl << lines << endl;
    return 0;
}

/* 
    Name: printArt()
    Purpose: Prints marvel ascii art to the screen
*/
void printArt() {
    cout << "._____.______.......________......________......___......___.._______.......___..........\n";
    cout << "|\\..._.\\.._...\\....|\\...__..\\....|\\...__..\\....|\\..\\..../../||\\..___.\\.....|\\..\\.........\n";
    cout << "\\.\\..\\\\\\__\\.\\..\\...\\.\\..\\|\\..\\...\\.\\..\\|\\..\\...\\.\\..\\../.././\\.\\...__/|....\\.\\..\\........\n";
    cout << ".\\.\\..\\\\|__|.\\..\\...\\.\\...__..\\...\\.\\..._.._\\...\\.\\..\\/.././..\\.\\..\\_|/__...\\.\\..\\.......\n";
    cout << "..\\.\\..\\....\\.\\..\\...\\.\\..\\.\\..\\...\\.\\..\\\\..\\|...\\.\\...././....\\.\\..\\_|\\.\\...\\.\\..\\____..\n";
    cout << "...\\.\\__\\....\\.\\__\\...\\.\\__\\.\\__\\...\\.\\__\\\\._\\....\\.\\__/./......\\.\\_______\\...\\.\\_______\\\n";
    cout << "....\\|__|.....\\|__|....\\|__|\\|__|....\\|__|\\|__|....\\|__|/........\\|_______|....\\|_______|\n";
    return;
}

/* 
    Name: enterSales()
    Purpose: Allows the user to enter sales data
*/
void enterSales() {
    //variables
    ofstream file;
    int choice;
    double items, price, sales;
    bool exit = false;

    //opens sales.txt
    file.open("sales.txt", ios::app);
    if (!file.is_open()) {
        cout << "\n\"sales.txt\" could not be found or opened. Returning to main menu...\n";
        return;
    }

    //sales menu
    do {
        //prints menu and validates user's choice
        cout << "\nPlease select from the following departments:";
        cout << "\n\t1. Guardians of the Galaxy";
        cout << "\n\t2. Spider-Man";
        cout << "\n\t3. Doctor Strange";
        cout << "\n\t4. Return to Main Menu";
        cout << "\n\n\tCHOOSE 1-4: ";
        while (!(cin >> choice) || (choice < 1 || choice > 4)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid choice. Please select a number between 1 and 4: ";
        }

        // breaks the do while loop if the user selects option 4
        if (choice == 4) {
            cout << "\nReturning to main menu...\n";
            exit == true;
            break;
        }

        //prompts the user for the price of the items
        cout << "\nPlease enter the price of the item: $";
        while (!(cin >> price)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input. Please enter the price of the item: $";
        }

        //prompts the user for the number of items
        cout << "\nPlease enter the number of items sold: ";
        while (!(cin >> items)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input. Please enter a whole number: ";
        }

        //calculates the total price of the items and adds tax
        sales = (price * items) + ((price * items ) * TAX);

        //handles the printing of sales data to sales.txt
        switch (choice) {
            case 1: file << "Guardians of the Galaxy\n";
                    break;
            case 2: file << "Spider-Man\n";
                    break;
            case 3: file << "Doctor Strange\n";
        }
        file << fixed << setprecision(2) << sales << "\n";

    } while (exit == false);
    
    //closes file, ends function
    file.close();
    return;
}

/* 
    Name: totalSales()
    Purpose: Totals all sales data and displays it as a chart
*/
void totalSales() {
    //variables
    const string lines(40,'-');
    ifstream file;
    time_t rawtime;
    string department;
    double sales, total, guardians = 0, spider = 0, doctor = 0;

    //opens sales.txt
    file.open("sales.txt");
    if (!file.is_open()) {
        cout << "\n\"sales.txt\" could not be found or opened. Returning to main menu...\n";
        return;
    }

    //reads the department's name, then adds the sales to the correct counter
    while (getline(file, department)) {
        if (department == "Guardians of the Galaxy") {
            file >> sales;
            guardians+=sales;
        } else if (department == "Spider-Man") {
            file >> sales;
            spider+=sales;
        } else {
            file >> sales;
            doctor+=sales;
        }
        file.ignore();
    }

    //totals all of the sales
    total = guardians + spider + doctor;

    //gets the time for printing
    time(&rawtime);

    //prints the time, then the chart with the total prices
    cout << "\nTOTAL SALES ON " << ctime(&rawtime) << "\n";
    cout << lines << "\n";
    cout << fixed << setprecision(2);
    cout << "Guardians of the Galaxy: $" << setw(12) << setfill(' ') << guardians << "\n";
    cout << "             Spider-Man: $" << setw(12) << setfill(' ') << spider << "\n";
    cout << "         Doctor Strange: $" << setw(12) << setfill(' ') << doctor << "\n";
    cout << "                  Total: $" << setw(12) << setfill(' ') << total << "\n";
    cout << lines << "\n";

    //closes file, ends function
    file.close();
    return;
}