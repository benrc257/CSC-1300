#include "dinofight.h"

int main() {
    //variables
    int size = 0, dinoTotal;
    Dinos Dino[size];
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

    //calls preloadDinos to load existing dinos from the file assigned to FILENAME
    //and find the existing number of dinos. Displays an error if FILENAME could not
    //be opened
    dinoTotal = preloadDinos(Dino, size);
    if (dinoTotal = -1) {
        cout << "\n" << FILENAME << " could not be opened.\n";
    }

    //temp
    printDinos(Dino, dinoTotal);

    return 0;
}