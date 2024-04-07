/*
	Title: prog4.cpp
	Author: Benjamin Clark
	Date: 4/1/24
	Purpose: This program allows the user to add dinosaurs to an arena
    and have them fight. This file contains main().
*/

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
    size = getValidateInput(1, INT_MAX, "\nPlease enter the maximum capacity of the dino arena.");
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

        //choice retrieval and validation
        choice = getValidateInput(1, 4, "");
        
        //choice execution
        switch (choice){
            case 1:
                total = enterDinos(Dino, size, total); //allows the user to enter dinos, total is updated upon returning
                break;
            case 2:
                printDinos(Dino, total); //prints current dinos in a list
                break;
            case 3:
                total = fight(Dino, total); //fights dinos, total is updated upon returning
                break;
            case 4:
                saveToFile(Dino, total); //writes the current Dino array to FILENAME
                break; //this option ends the while loop
        }
    } while (choice != 4);

    

    //deletes the allocated memory for Dino
    delete [] Dino;

    //program ends, displays exit message
    cout << "\nGood Fight!\n";
    return 0;
}