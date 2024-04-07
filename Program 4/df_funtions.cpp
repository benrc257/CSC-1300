/*
	Title: df_functions.cpp
	Author: Benjamin Clark
	Date: 4/1/24
	Purpose: This program allows the user to add dinosaurs to an arena
    and have them fight. This file contains function definitions.
*/

#include "dinofight.h"

/*
    Name: printArt()
    Purpose: Prints art at the beginning of the function
*/
void printArt()
{
	cout << endl << endl;
	cout << "########  #### ##    ##  #######     ######## ####  ######   ##     ## ######## ####\n"; 
	cout << "##     ##  ##  ###   ## ##     ##    ##        ##  ##    ##  ##     ##    ##    ####\n"; 
	cout << "##     ##  ##  ####  ## ##     ##    ##        ##  ##        ##     ##    ##    ####\n"; 
	cout << "##     ##  ##  ## ## ## ##     ##    ######    ##  ##   #### #########    ##     ##\n";  
	cout << "##     ##  ##  ##  #### ##     ##    ##        ##  ##    ##  ##     ##    ##\n";         
	cout << "##     ##  ##  ##   ### ##     ##    ##        ##  ##    ##  ##     ##    ##    ####\n"; 
	cout << "########  #### ##    ##  #######     ##       ####  ######   ##     ##    ##    ####\n";
	cout << endl;
}

/*
    Name: delay()
    Purpose: Used to provide a short delay for the fight() function's rounds. The delay is in seconds.
*/
void delay(int delay) {
    //variables
    time_t timer;

    //obtain start time and the end time
    timer = time(0)+delay;

    while (time(0) < timer);
}

/*
    Name: getValidateInput() [TWO INTEGERS GIVEN]
    Purpose: Retrieves and validates user's input of an integer. The integer will be returned if it is between
    or includes the highest and lowest values given. Uses the value of string message to display the prompt.
*/
int getValidateInput(int lowest, int highest, string message) {
    //variables
    int input;
    bool done = false;

    //outputs prompt for user
    cout << message << "\n>> ";

    //validates user input until a valid input is received
    do {
        if (!(cin >> input) || (input < lowest || input > highest)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a whole number between " << lowest << " and " << highest << ".";
            cout << "\n>> ";
            done = false;
        } else {
            done = true;
        }
    } while (!done);

    //returns the user's input
    return input;
}

/*
    Name: getValidateInput() [TWO CHARACTERS GIVEN]
    Purpose: Retrieves and validates user's input of a character. 1 will be returned if the input matches char1.
    0 will be returned if the input matches char2. Uses the value of string message to display the prompt.
*/
int getValidateInput(char char1, char char2, string message) {
    //variables
    char input;
    bool done = false;

    //outputs prompt for user
    cout << message << "\n>> ";

    //validates user input until a valid input is received
    do {
        if (!(cin >> input) || (tolower(input) != tolower(char1) && tolower(input) != tolower(char2))) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter " << (toupper(char1)) << " or " << (toupper(char2)) << ".";
            cout << "\n>> ";
            done = false;
        } else {
            done = true;
        }
    } while (!done);

    //returns 1(char1) or 0(char2)
    if (input == char1) {
        return 1;
    } else {
        return 0;
    }
}

/*
    Name: preloadDinos()
    Purpose: Loads in the data from the file (set by global constant FILENAME in dinofight.h)
    into the *Dino array
*/
int preloadDinos(Dinos *Dino, int size) {
    //variables
    ifstream file;
    int total = 0;

    //open FILENAME
    file.open(FILENAME);

    //returns error if the file cannot be opened
    if (!file.is_open()) {
        return -1;
    }

    //runs through the file and writes data to the array, displaying each added dinosaur to the user
    for (int i = 0; i < size; i++) {
        if (file.peek() != EOF) {
            getline(file, Dino[i].type, '#');
            getline(file, Dino[i].name, '#');
            file >> Dino[i].stats.hit;
            file.ignore(1);
            file >> Dino[i].stats.health;
            file.ignore(1);
            total++;
            cout << "\n" << Dino[i].name << " the " << Dino[i].type << " has been added to the arena!";
        } else {
            break;
        }
    }
    cout << endl;

    //closes FILENAME
    file.close();

    //returns the current fill level of the array (number of loaded dinos)
    return total;
}

/*
    Name: enterDinos()
    Purpose: Adds Dinos to the array and increments the total number of dinos
*/
int enterDinos(Dinos *Dino, int size, int total) {

    //the loop runs continously until the array is full or the user is finished
    do {
        //checks if the arena is full, returns if true
        if (total >= size) {
            cout << "\nSorry, your arena is full! You cannot add more dinosaurs.";
            cout << "\nReturning to main menu..." << endl;
            return total;
        }

        //collects and validates the dino's species from the user
        cout << "\nPlease enter the dino's species.";
        cout << "\n>> ";
        cin.ignore();
        while (!getline(cin, Dino[total].type)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid species! Please enter a different species.";
            cout << "\n>> ";
        }

        //collects and validates the dino's name from the user
        cout << "\nPlease enter the dino's name.";
        cout << "\n>> ";
        while (!getline(cin, Dino[total].name)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid name! Please enter a different name.";
            cout << "\n>> ";
        }

        //collects and validates the hit stat from the user
        Dino[total].stats.hit = getValidateInput(1, INT_MAX, "\nPlease enter the dino's attack power.");

        //collects and validates the health stat from the user
        Dino[total].stats.health = getValidateInput(1, INT_MAX, "\nPlease enter the dino's maximum health.");

        //increments the total and displays it to the user
        total++;
        cout << "\nThere are now " << total << "/" << size << " dinosaurs in the arena!\n";

        //checks if the arena is now full again
        if (total >= size) {
            cout << "\nYour arena is now full! You cannot add more dinosaurs.";
            cout << "\nReturning to main menu..." << endl;
            return total;
        }

    //determines if the user would like to continue addings dinos
    } while (getValidateInput('y', 'n', "\nAdd more dinos? (y/n)"));

    //returns the new total amount of dinos
    cout << "\nReturning to main menu..." << endl;
    return total;
}

/*
    Name: printDinos()
    Purpose: Displays all dinos currently in the array
*/
void printDinos(Dinos *Dino, int total) {
    //variables
    string lines(40, '-');

    //if no dinos are in the array, returns and displays a message
    if (total == 0) {
        cout << "\nThere are currently no dinos in the arena.\n";
        return;
    }

    //prints every dino in the array and their stats to the screen in a list
    cout << endl;
    for (int i=0; i < total; i++) {
        cout << lines << "| DINO FIGHTER " << i+1 << " |" << lines << "\n";
        cout << "Name: " << Dino[i].name << "\n";
        cout << "Type: " << Dino[i].type << "\n";
        cout << "Damage: " << Dino[i].stats.hit << "\n";
        cout << "Health: " << Dino[i].stats.health << "\n";
    }
    cout << lines << "******************" << lines << endl;
}

/*
    Name: deleteDino()
    Purpose: Removes a single dino from the array
*/
int deleteDino(Dinos *Dino, Dinos *slain, int total) {
    //variables
    int pos = 0;

    //finds the position of *slain's memory address in the Dino array
    for (int i = 0; i < total && (&Dino[i] != &(*slain)); i++, pos++);

    //shifts all following elements over by one
    for (int i=pos; i < (total-1); i++) {
        Dino[i].name = Dino[i+1].name;
        Dino[i].type = Dino[i+1].type;
        Dino[i].stats.health = Dino[i+1].stats.health;
        Dino[i].stats.hit = Dino[i+1].stats.hit;
    }

    //decrements the total by 1 and returns it
    return (total-1);
}

/*
    Name: fight()
    Purpose: Allows the user to select two dinos and have them fight, then updates the remaining total of dinos
    Note: This function does not permanently effect a dinosaur's hitpoints
*/
int fight(Dinos *Dino, int total) {
    //variables
    string stars(40, '*');
    Dinos *hitter, *receiver;
    bool alive = true;
    int choice1, choice2, attack, attack1, attack2, *attackTrack;
    int d = 1; //sets the delay of the delay() function

    //seed random number generator for later
    srand(time(0));

    do {
        //displaying fight welcome text
        cout << "\nDINO FIGHT BEGINNING!";

        //checking to see if there are at least 2 dinos
        if (total < 2) {
            cout << "\n\nThere must be at least two dinosaurs in the arena to fight.";
            cout << "\nSelect option 1 to add more dinos! Returning to main menu...\n";
            return total;
        }

        //continuinging fight welcome text
        cout << " CHOOSE YOUR FIGHTERS.\n";

        //displaying menu text
        cout << "\nPlease select the two dinosaurs you would like to fight:";

        //displaying names
        for (int i = 0; i < total; i++) {
            cout << "\n" << i+1 << ": " << Dino[i].name << " the " << Dino[i].type;
        }

        //receiving and validating the user's first choice
        choice1 = getValidateInput(1, total, "\n\nSelect the first dinosaur.");
        cout << "\nFighter " << choice1 << ", " << Dino[(choice1-1)].name << " the " << Dino[(choice1-1)].type << ", selected!";

        //receiving and validating the user's second choice
        choice2 = getValidateInput(1, total, "\n\nSelect the second dinosaur.");

        //runs until the output of choice2 = getValidateInput is different from choice1
        while (choice2 == choice1) {
            cout << "Fighter " << choice1 << " has already been selected.";
            choice2 = getValidateInput(1, total, "\n\nSelect the second dinosaur.");
        }
        cout << "\nFighter " << choice2 << ", " << Dino[(choice2-1)].name << " the " << Dino[(choice2-1)].type << ", selected!";

        //FIGHTING BEGINS HERE
        cout << "\n\nREADY, SET, FIGHT!\n";

        //for loop runs three times or until a dino dies
        for (int i=0; (i < 3 && alive); i++) {
            //generates the random order of attack
            attack = rand()%(2)+1;

            //assigns hitter and receiver pointers based off order
            //this was done to avoid writing multiple sets of fighting code
            if (attack == 1) {
                hitter = &Dino[(choice1-1)];
                receiver = &Dino[(choice2-1)];
                attackTrack = &attack1;
            } else {
                hitter = &Dino[(choice2-1)];
                receiver = &Dino[(choice1-1)];
                attackTrack = &attack2;
            }

            //generates the attack's power
            attack = rand()%(10)+1;

            //reassigns attack to the hitter's attack power divided by the randomly generated value,
            //then adds it to the hitters's total damage dealt using the attackTrack pointer
            attack = (*hitter).stats.hit / attack;
            *attackTrack += attack;

            //subtracts attack's value from the receivers current health, correcting negative values to 0
            (*receiver).stats.health -= attack;
            if ((*receiver).stats.health < 0) {
                (*receiver).stats.health = 0;
            }

            //displays round results
            delay(d);
            cout << endl << stars << "| ROUND " << i+1 << " |" << stars << "\n";
            delay(d);
            cout << (*hitter).name << " the " << (*hitter).type << " attacked, dealing " << attack << " damage!\n";
            delay(d);
            cout << (*receiver).name << " the " << (*receiver).type << " now has " << (*receiver).stats.health << " health remaining!\n";

            //displays a death message if a dino hits 0 hitpoints and deletes the corresponding dino
            if (!((*receiver).stats.health)) {
                delay(d);
                cout << (*receiver).name << " the " << (*receiver).type << " has fallen in battle!\n";
                delay(d);
                cout << (*receiver).name << " the " << (*receiver).type << " has been cremated.\n";
                total = deleteDino(Dino, receiver, total); //returns the decremented total
                alive = false;
            }
            
        }

        //displays fight results
        delay(d);
        cout << "\n" << stars << "| RESULTS |" << stars << endl;
        delay(d);

        if (!alive) {
            cout << (*hitter).name << " the " << (*hitter).type << " is the winner!\n";
            alive = true; //resets the state of the alive boolean
        } else if (attack1 > attack2) {
            cout << Dino[(choice1-1)].name << " the " << Dino[(choice1-1)].type << " is the winner!\n";
        } else if (attack2 > attack1) {
            cout << Dino[(choice2-1)].name << " the " << Dino[(choice2-1)].type << " is the winner!\n";
        } else {
            cout << "Both Dinosaurs fought valiantly. It was a draw!\n";
        }

        delay(d);
        cout << "\n" << stars << "***********" << stars << endl;
        delay(d);

    //asks the user if they would like to fight again
    } while (getValidateInput('y', 'n', "\nThe fight has concluded. Fight again? (y/n)"));

    //returns the updated total of dinosaurs
    return total;
}

/*
    Name: saveToFile()
    Purpose: Writes the current Dino array to FILENAME. This overwrites the existing data in FILENAME.
*/
void saveToFile(Dinos *Dino, int total) {
    //variables
    ofstream file;

    //opens the file
    file.open(FILENAME, ios::trunc);

    //detects if file opened correctly, returns and displays error message if not
    if (!file.is_open()) {
        cout << "\n" << FILENAME << " could not be opened. The Dinosaurs were not saved.";
        return;
    }
    
    //writes data from array to file
    if (total > 0) {
        file << (*(Dino)).type << "#" << (*(Dino)).name << "#" << (*(Dino)).stats.hit << "#" << (*(Dino)).stats.health;
        for (int i=1; i < total; i++) {
            file << "#" <<(*(Dino+i)).type << "#" << (*(Dino+i)).name << "#" << (*(Dino+i)).stats.hit << "#" << (*(Dino+i)).stats.health;
        }
    }

    //closes file
    file.close();
    cout << "\nThe Dinosaurs were succesfully saved to " << FILENAME << "." << endl;
}