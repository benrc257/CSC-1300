#include "dinofight.h"

int main() {
    //variables
    int size, dinoTotal;
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
    dinoTotal = preloadDinos(Dino, size);
    if (dinoTotal == -1) {
        cout << "\n" << FILENAME << " could not be opened.\n";
        dinoTotal = 0;
    }


    return 0;
}