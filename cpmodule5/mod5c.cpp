/*
	Title:    mod5c.cpp
	Author:   
	Date:     
	Purpose:  Practice for loops (in-class practice)
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int rnum = 0; 	//rnum holds the random number generated
	int total;  	//total for the particular ability
	int oddRoll;	//holds the number of times an ODD roll occurred
	int rollNum;	//Number of times dice has been rolled for this ability
	//seed the random number generator
	srand (time(0));
	
	cout << "\nDnD Stat Roll\n";
	cout << "1 - Strength\n";
	cout << "2 - Dexterity\n";
	cout << "3 - Constitution\n";
	cout << "4 - Intelligence\n";
	cout << "5 - Wisdom\n";
	cout << "6 - Charisma\n";
	
	cout << "\nFor your character stats, I am rolling a"
			" 6-sided die until an ODD dice roll \noccurs more "
			"than once OR the total of all dice rolled so far is equal\n"
			"to or exceeds 20, whichever comes first.\n\nIf the total "
			"exceeds 20, then the last dice roll is removed.\n\n"
			"I will then print the result for each ability score.\n\n";
	
	for (int diceRolls = 1; diceRolls <=6; diceRolls++) {;
		for (rollNum = 0, total = 0, oddRoll = 0; (total <= 20 && oddRoll < 2); rollNum++) {
			rnum = rand()%(6)+1;
			total+=rnum;
			if (rnum == 1 || rnum == 3 || rnum == 5) {
				oddRoll++;
			}
		}
		if (total > 20) {
			total-=rnum;
		}
		cout << endl << rollNum << " dice were rolled, and your ability score for ability " << diceRolls << " is " << total << endl;
	}
	
	
	
	
	
	
	cout << endl;
	return 0;
}