#include "dinofight.h"

int main() {
    //variables
    int size, total, choice;
    string stars(80, '*');
    Dinos *Dino = NULL;

    //prints art to screen
    printArt();
    cout << stars << endl;

    //ask the user for the capacity of the Dino[] array
    do {
        cout << "\nPlease enter the maximum capacity of the dino arena (this must be a whole number): ";

        if (!(cin >> size) || size < 1) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid capacity. Please enter a whole number greater than 0.\n";
            size = -1;
        }
    } while (size < 1);

    //initializes the Dino pointer to be a dynamically allocated array of the size given by the user
    Dino = new Dinos[size];

    //calls preloadDinos to load existing dinos from the file assigned to FILENAME
    //and find the existing number of dinos. Displays an error if FILENAME could not
    //be opened
    total = preloadDinos(Dino, size);
    if (total == -1) {
        cout << "\n" << FILENAME << " could not be opened.\n";
        total = 0;
    }

    //prints main menu and validates user's choice, then executes the corresponding function
    do {
        //menu
        cout << "\nSelect 1-4: ";
        cout << "\n1. Enter Dinosaurs";
        cout << "\n2. Print Dinosaurs";
        cout << "\n3. FIGHT!";
        cout << "\n4. End Program";
        cout << "\n>> ";

        //choice validation
        while (!(cin >> choice) || (choice < 1 || choice > 4)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid choice. Please enter a number between 1 and 4: ";
        }
        
        //choice execution
        switch (choice){
            case 1:
                enterDinos(Dino, size, total);
                break;
            case 2:
                printDinos(Dino, total);
                break;
            case 3:
                fight(Dino, total);
                break;
            case 4:
                break; //this option ends the while loop
        }
    } while (choice != 4);

    //saveToFile();

    //deletes the allocated memory for Dino
    delete [] Dino;

    //program ends
    return 0;
}