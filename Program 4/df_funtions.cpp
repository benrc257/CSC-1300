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

    //runs through the file and writes data to the array
    for (int i = 0; i < size; i++) {
        if (file.peek() != EOF) {
            getline(file, Dino[i].type, '#');
            getline(file, Dino[i].name, '#');
            file >> Dino[i].stats.hit;
            file.ignore(1);
            file >> Dino[i].stats.health;
            file.ignore(1);
            total++;
        } else {
            break;
        }
    }

    //closes FILENAME
    file.close();

    //returns the current fill level of the array (number of loaded dinos)
    return total;
}

/*
    Name: enterDinos()
    Purpose: Adds Dinos to the array and increments the total number of dinos
*/
void enterDinos(Dinos *Dino, int size, int& total) {
    //variables
    char choice;

    //the loop runs continously until the array is full or the user is finished
    do {
        //checks if the arena is full, returns if true
        if (total >= size) {
            cout << "\nSorry, your arena is full! You cannot add more dinosaurs.";
            cout << "\nReturning to main menu..." << endl;
            return;
        }

        //asks for and validates the inputs for each of the dino's attributes
        cout << "\nPlease enter the dino's name.";
        cout << "\n>> ";
        cin.ignore();
        while (!getline(cin, Dino[total].name)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid name! Please enter a different name.";
            cout << "\n>> ";
        }

        cout << "\nPlease enter " << Dino[total].name << "'s species.";
        cout << "\n>> ";
        while (!getline(cin, Dino[total].type)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid species! Please enter a different species.";
            cout << "\n>> ";
        }

        cout << "\nPlease enter " << Dino[total].name << "'s attack power.";
        cout << "\n>> ";
        while (!(cin >> Dino[total].stats.hit) || Dino[total].stats.hit < 1) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid value! Please enter a whole number greater than 0.";
            cout << "\n>> ";
        }

        cout << "\nPlease enter " << Dino[total].name << "'s maximum health.";
        cout << "\n>> ";
        while (!(cin >> Dino[total].stats.health) || Dino[total].stats.health < 1) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid value! Please enter a whole number greater than 0.";
            cout << "\n>> ";
        }

        //increments the total and displays it to the user
        total++;
        cout << "\nThere are now " << total << "/" << size << " dinosaurs in the arena!\n";

        //checks if the arena is now full again
        if (total >= size) {
            cout << "\nYour arena is now full! You cannot add more dinosaurs.";
            cout << "\nReturning to main menu..." << endl;
            return;
        }

        //determines if the user would like to continue addings dinos
        cout << "\nAdd more dinos? (y/n) ";
        while (!(cin >> choice) || (tolower(choice) != 'y' && tolower(choice) != 'n')) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid choice. Please select y or n: ";
        }
    } while (tolower(choice) != 'n');

    cout << "\nReturning to main menu..." << endl;
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
    Name: fight()
    Purpose: Allows the user to select two dinos and have them fight, then updates the remaining total of dinos
*/
void fight(Dinos *Dino, int total) {
    //variables
    int choice;
    Dinos *dino1 = NULL, *dino2 = NULL, **hitter, **reciver;
    bool running = true, alive = true;
    int order, attack;

    //seed random number generator for later
    srand(time(0));

    do {
        //displaying fight welcome text
        cout << "\nDINO FIGHT BEGINNING!";

        //checking to see if there are at least 2 dinos
        if (total < 2) {
            cout << "\n\nThere must be at least two dinosaurs in the arena to fight.";
            cout << "\nSelect option 1 to add more dinos! Returning to main menu...\n";
            return;
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
        cout << "\n\nSelect the first dinosaur.";
        cout << "\n>> ";
        do {
            if (!(cin >> choice) || (choice < 1 || choice > total)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid choice. Please select a whole number between 1 and " << total << ".\n";
                choice = -1;
            }
        } while (choice < 1 || choice > total);

        //assigns dino1 to the memory address of the second dino
        dino1 = &Dino[(choice-1)];
        cout << "\nFighter " << choice << ", " << (*dino1).name << " the " << (*dino1).type << ", selected!";

        //receiving and validating the user's second choice
        cout << "\n\nSelect the second dinosaur.";
        cout << "\n>> ";
        do {
            if (!(cin >> choice) || (choice < 1 || choice > total)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid choice. Please select a whole number between 1 and " << total << ".\n";
                choice = -1;
            }
        } while (choice < 1 || choice > total);

        //assigns dino2 to the memory address of the second dino
        dino2 = &Dino[(choice-1)];
        cout << "\nFighter " << choice << ", " << (*dino2).name << " the " << (*dino2).type << ", selected!";

        //FIGHTING BEGINS HERE
        cout << "READY, SET, FIGHT!";
        
        //for loop runs three times or until a dino dies
        for (int i=0; (i < 2 && alive); i++) {
            //generates the random order of attack
            order = rand()%(2)+1;
            cout << endl << order << endl;

            if (order == 2) {

            } else {

            }



        }

    } while (running);
}