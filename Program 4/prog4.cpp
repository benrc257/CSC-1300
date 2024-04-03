#include "dinofight.h"

int main() {
    //variables
    int size, total, choice;
    string stars(80, '*');

    //prints art to screen
    printArt();
    cout << stars << endl;

    //ask the user for the capacity of the Dino[] array
    do {
        cout << "\nPlease enter the maximum capacity of the dino arena (this must be a whole number): ";

        if (!(cin >> size) || size < 1) {
            cout << "Invalid capacity. Please enter a whole number greater than 0.\n";
            size = -1;
        }
    } while (size < 1);

    //declares the Dino[] array to be of the size given by the user
    Dinos Dino[size];

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
        cout << "\nSelect 1-4: ";
        cout << "\n1. Enter Dinosaurs";
        cout << "\n2. Print Dinosaurs";
        cout << "\n3. FIGHT!";
        cout << "\n4. End Program";
        cout << "\n>> ";
            while (!(cin >> choice) || (choice < 1 || choice > 4)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\nInvalid choice. Please enter a number between 1 and 4: ";
            }
        switch (choice){
            case 1:
                enterDinos(Dino, size, total);
                break;
            case 2:
                printDinos(Dino, total);
                break;
            case 3:
                //fight();
                break;
            case 4:
                break;
        }
    } while (choice != 4);

    //saveToFile();

    return 0;
}