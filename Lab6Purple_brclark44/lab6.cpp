/*
	Title: Lab6Purple_brclark44.cpp
	Author: Benjamin Clark
	Date: 2/27/24
	Purpose: This program will keep track of goblin's sick days.
*/
#include <iostream>
using namespace std;

//function prototypes
int DisplayMenuGetChoice();
void GoblinSickDays();
int DisplayCoolMessage(int);

int main()
{
	//variables
	int choice, cooldisplays = 0;

	do {
		//displays menu and gets the user's choice
		choice = DisplayMenuGetChoice();

		//handles the user's choice, if  they select 3, does nothing and loop ends
		switch(choice) {
			case 1: GoblinSickDays();
					break;
			case 2: cooldisplays = DisplayCoolMessage(cooldisplays);
		}
	} 	while (choice != 3);

	cout << "\nYou displayed a cool message " << cooldisplays << " times! Bye!\n\n";
	return 0;
}

/*
	Function: DisplayMenuGetChoice()
	Inputs: none
	Returns: an integer containing the choice selected by the user
	Purpose: Displays a menu of choices for the user to pick
*/
int DisplayMenuGetChoice() {
	int choice;

	//prints main menu and validates user's choice
	do {
        cout << "\nPlease select from the following menu items:";
        cout << "\n\t1. Enter Goblin Sick Days";
        cout << "\n\t2. Display Something Cool";
        cout << "\n\t3. End the Program";
        cout << "\n\n\tCHOOSE 1-3: ";
        while (!(cin >> choice) || (choice < 1 || choice > 3)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid choice. Please select a number between 1 and 3: ";
        }
	} while ((choice < 1 || choice > 3));
	
	return choice;
}

/*
	Function: GoblinSickDays()
	Inputs: none
	Returns: none
	Purpose: Records the goblin's sick days for the past three years
*/
void GoblinSickDays() {
	//variables
	int input, worked = 0, sick = 0;

	//runs 3 times, counting down one year each time, and gets the number of goblins who worked and their sick days
	for (int count = 3; count > 0; count--) {
		cout << "\nHow many goblins worked " << count << " years ago? ";
		while (!(cin >> input)) {
			cin.clear();
            cin.ignore(10000, '\n');
			cout << "\nPlease enter the number of goblins who worked " << count << " years ago: ";
		}
		worked+=input;
		cout << "\nHow many sick days were used " << count << " years ago? ";
		while (!(cin >> input)) {
			cin.clear();
            cin.ignore(10000, '\n');
			cout << "\nPlease enter the number of sick days used " << count << " years ago: ";
		}
		sick+=input;
	}
	cout << "\nOver three years, " << worked << " goblins worked and used " << sick << " sick days.\n";
}

/*
	Function: DisplayCoolMessage()
	Inputs: an integer containing the number of times this function has been called up to this point
	Returns: an integer containing the updated number of times this function has been called
	Purpose: displays ASCII art and then increments the integer sent to this function
*/
int DisplayCoolMessage(int n)
{
	cout << "\n\n";
	cout <<"  /$$$$$$            /$$                                 /$$     /$$\n";
	cout <<" /$$__  $$          |__/                                | $$    | $$\n";
	cout <<"| $$  \\__/  /$$$$$$  /$$ /$$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$ /$$$$$$   /$$$$$\n";
	cout <<"| $$ /$$$$ /$$__  $$| $$| $$__  $$ /$$__  $$ /$$__  $$|_  $$_/|_  $$_/  /$$___/\n";
	cout <<"| $$|_  $$| $$  \\__/| $$| $$  \\ $$| $$  \\ $$| $$  \\ $$  | $$    | $$   | $$$$$$\n"; 
	cout <<"| $$  \\ $$| $$      | $$| $$  | $$| $$  | $$| $$  | $$  | $$ /$$| $$ /$$\\__  $$\n";
	cout <<"|  $$$$$$/| $$      | $$| $$  | $$|  $$$$$$$|  $$$$$$/  |  $$$$/|  $$$$//$$$$$/\n";
	cout <<" \\______/ |__/      |__/|__/  |__/ \\____  $$ \\______/    \\___/   \\___/ |_____/\n"; 
	cout <<"                                   /$$  \\ $$\n";
	cout <<"                                  |  $$$$$$/\n";
	cout <<"                                   \\______/\n\n";
	n++;
	return n;
}