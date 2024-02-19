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
using namespace std;

//Global Constants
const double TAX = .0975;

//prints marvel ascii art
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

//allows the user to enter sale data
void enterSales() {
    //variables
    ofstream activeFile;
    int choice, sold;
    char confirm;
    double sales, salesTax;
    bool exit = false;
    string department;
    
    //opens the file
    activeFile.open("sales.txt", ios::app);
    if (activeFile.is_open() == false) {
        cout << "\nCould not open or find sales.txt, or it does not exist. Returning to main menu.\n";
        return;
    }

    do {
        //resets choice to 0 to avoid conflict with menus
        choice = 0;

        //menu
        do {
            cout << "\nPlease select a department:"
                 << "\n  1. Guardians of the Galaxy"
                 << "\n  2. Spider-Man"
                 << "\n  3. Doctor Strange"
                 << "\n  4. Return to main menu"
                 << "\n\n CHOOSE 1-4: ";
            cin >> choice;
            if (choice < 1 || choice > 4) {
                cout << "\nInvalid input. Please enter a number between 1 and 4.\n";
            }
        } while (choice < 1 || choice > 4);

        //handles user input from menu
        switch (choice) {
            case 1: department = "Guardians of the Galaxy";
                    break;
            case 2: department = "Spider-Man";
                    break;
            case 3: department = "Doctor Strange";
                    break;
            case 4: exit = true; //this breaks the loop
                    cout << "\nReturning to main menu.\n";
        }
        
        //detects that exit is true and stops the current loop, allowing the loop to properly end
        if (exit == true) {
            break;
        }

        //inputs the sales and department to the output file
        activeFile << department << endl;
        do {
        cout << "\nPlease enter the number of items sold: ";
        cin >> sold;
        cout << "\nThe number of items sold is " << sold << ". Is this correct? (y/n) ";
        cin >> confirm;
        if (confirm != 'y' && confirm != 'Y') {
            cout << "\nYou entered no. Please correct the number of items sold.\n";
        }
        } while (confirm != 'y' && confirm != 'Y');

        do {
        cout << "\nPlease enter the price of the item, as a number with two decimal places: $";
        cin >> sales;
        cout << "\nThe price of the item is $" << fixed << setprecision(2) << sales << ". Is this correct? (y/n) ";
        cin >> confirm;
        if (confirm != 'y' && confirm != 'Y') {
            cout << "\nYou entered no. Please correct the sales number.\n";
        }
        } while (confirm != 'y' && confirm != 'Y');
        
        cout << "\nThe number of items sold was " << sold << " and the price was $" << fixed << setprecision(2) << sales << " per item.";
        salesTax = (sold*sales)*TAX;
        sales = (sales*sold)+salesTax;
        cout << "\nThe total price after tax is $"  << fixed << setprecision(2) << sales << ".";

        //outputs sale data to file
        activeFile << fixed << setprecision(2) << sales << endl;
        cout << "\nSales data has been recorded to \"sales.txt\".\n";

    } while (exit != true);

    //closes file, ends function
    activeFile.close();
    return;
}

//allows the user to total all sales
void totalSales() {
    //variables
    ifstream activeFile;
    time_t rawtime;
    string department, lines(38,'-');
    double guardian = 0; 
    double spider = 0;
    double strange = 0;
    double sales = 0;

    //opens file
    activeFile.open("sales.txt");
    if (activeFile.is_open() == false) {
        cout << "\nCould not open or find sales.txt, or it does not exist. Returning to main menu.\n";
        return;
    }

    //gets the totals
    do {
        getline(activeFile, department);
        activeFile >> sales;
        activeFile.ignore();
        if (department == "Guardians of the Galaxy") {
            guardian+=sales;
        } else if (department == "Spider-Man") {
            spider+=sales;
        } else if (department == "Doctor Strange") {
            strange+=sales;
        }
    } while (!activeFile.eof());

    //gets the time and prints it
    time(&rawtime);
    cout << "\nTOTAL SALES ON " << ctime(&rawtime);

    //prints totals
    cout << lines;
    cout << fixed << setprecision(2);
    cout << "\nGuardians of the Galaxy: $" << setw(12) << setfill(' ') << guardian;
    cout << "\n             Spider-Man: $" << setw(12) << setfill(' ') << spider;
    cout << "\n         Doctor Strange: $" << setw(12) << setfill(' ') << strange;
    cout << "\n                  Total: $" << setw(12) << setfill(' ') << guardian + spider + strange;
    cout << endl << lines << endl;

    //closes file and ends function
    activeFile.close();
    return;
}

//allows the user to delete today's sale data
void deleteSales() {
    char confirm;

    //confirms the user wants to delete the file
    cout << "\nYOU ARE ATTEMPTING TO DELETE ALL SALES DATA FROM \"sales.txt\". Proceed? (y/n) ";
    cin >> confirm;

    //deletes the file if the user enters yes
    if (confirm == 'y' || confirm == 'Y') {
        if(remove("sales.txt")) {
            cout << "\nCould not delete or find sales.txt, or it does not exist.\n";
        } else {
            cout << "\nThe file was deleted successfully.\n";
        }
    } else {
        cout << "\nThe file was not deleted.\n";
    }

    //function ends
    return;
}

int main() {

    //Variables
    string lines(90,'-');
    bool exit = false;
    int choice;
    
    //printing ascii art
    cout << endl;
    printArt();

    //printing dashes for beginning of program
    cout << endl << lines << endl;

    //menu stuff
    do {
        //resets choice to 0 to avoid conflict with menus
        choice = 0;

        //main menu
        do {
            cout << "\nPlease select one of the following:"
                 << "\n  1. Enter sales"
                 << "\n  2. Total the daily sales"
                 << "\n  3. Delete today's sales"
                 << "\n  4. End Program"
                 << "\n\n CHOOSE 1-4: ";
            cin >> choice;
            if (choice < 1 || choice > 4) {
                cout << "\nInvalid input. Please enter a number between 1 and 4.\n";
            }
        } while (choice < 1 || choice > 4);

        //handles user input from main menu
        switch (choice) {
            case 1: enterSales();
                    break;
            case 2: totalSales();
                    break;
            case 3: deleteSales();
                    break;
            case 4: exit = true;
        }
    } while (exit != true);

    // printing lines and ending program
    cout << endl << lines << endl;
    return 0;
}