/*
	Title: Lab7.h
	Author: Benjamin Clark
	Date: 3/5/24
	Purpose: Teach 3rd to 6th grade students fun facts about animals. This
    file contains the functions.
*/
#include "Lab7.h"

/*
	Name: menu()
    Returns: The choice of the user
	Purpose: Get the choice of animal to learn about from the user.
*/
int menu() {
    //variables
    int choice;

    //prints main menu and validates user's choice
    do {
        cout << "\nPlease select an animal to learn about:";
        cout << "\n\t1. Naked Mole Rats";
        cout << "\n\t2. Peacock Mantis Shrimp";
        cout << "\n\t3. Orangutans";
        cout << "\n\t4. End Program";
        cout << "\n\n\tCHOOSE 1-4: ";
        while (!(cin >> choice) || (choice < 1 || choice > 4)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid choice. Please select a number between 1 and 4: ";
        }
    } while ((choice < 1 || choice > 4));

    return choice;
}

/*
	Name: menu()
    Input: The current score and the choice from the menu.
	Purpose: Tests the user's knowledge of each animal.
*/
void test (int& score, int type) {

    //variables
    string lines (40, '-');
    int choice;

    //starting message
    cout << lines << "\nQuiz Time!";

    //Gives a different question based on the previous animal facts given
    switch (type) {
        case 1: do {
                    cout << "\nWhich fun fact about Naked Mole Rats is true?";
                    cout << "\n\t1. They have large talons.";
                    cout << "\n\t2. They can breathe underwater.";
                    cout << "\n\t3. They can live in colonies with up to 300 members.";
                    cout << "\n\t4. They have rainbow colored eyes.";
                    cout << "\n\n\tCHOOSE 1-4: ";
                    while (!(cin >> choice) || (choice < 1 || choice > 4)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "\nInvalid choice. Please select a number between 1 and 4: ";
                    }
                } while ((choice < 1 || choice > 4));

                if (choice == 3) {
                    cout << "\nCorrect! You gained one point.\n";
                    score++;
                } else {
                    cout << "\nIncorrect. Better luck next time!\n";
                }
                
                break;
        case 2: do {
                    cout << "\nWhich fun fact about Peacock Mantis Shrimp is true?";
                    cout << "\n\t1. They have shells.";
                    cout << "\n\t2. They have vibrantly colored exoskeletons.";
                    cout << "\n\t3. They can live 1000 years.";
                    cout << "\n\t4. They can smell color.";
                    cout << "\n\n\tCHOOSE 1-4: ";
                    while (!(cin >> choice) || (choice < 1 || choice > 4)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "\nInvalid choice. Please select a number between 1 and 4: ";
                    }
                } while ((choice < 1 || choice > 4));

                if (choice == 2) {
                    cout << "\nCorrect! You gained one point.\n";
                    score++;
                } else {
                    cout << "\nIncorrect. Better luck next time!\n";
                }
                
                break;
        case 3: do {
                    cout << "\nWhich fun fact about Oragnutans is true?";
                    cout << "\n\t1. They can see infrared light.";
                    cout << "\n\t2. They build small houses from sticks.";
                    cout << "\n\t3. They have no fur.";
                    cout << "\n\t4. They can make loud calls with their throat sacs.";
                    cout << "\n\n\tCHOOSE 1-4: ";
                    while (!(cin >> choice) || (choice < 1 || choice > 4)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "\nInvalid choice. Please select a number between 1 and 4: ";
                    }
                } while ((choice < 1 || choice > 4));

                if (choice == 4) {
                    cout << "\nCorrect! You gained one point.\n";
                    score++;
                } else {
                    cout << "\nIncorrect. Better luck next time!\n";
                }
                
                break;
    }
}