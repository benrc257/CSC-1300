/*
	Title:    Lab4GOLD_brclark44.cpp
	Author:   Benjamin Clark
	Date:     2/13/24
	Purpose:  Make a game using loops
*/
#include <iostream>
#include <ctime>
using namespace std;

int main() {

    //Variables
    string name, stars(60,'*'), lines(50,'-');
    int choiceNum, random;
    char confirm, choiceChar;
    int coins = 0;

    //seeding random number generator and collecting it's output
    srand(time(0));
    random = rand()%(3)+1;

    cout << endl << stars << endl;

    // starting message and name collection
    do {
        cout << endl << "Hello adventurer! Please enter your name: ";
        getline(cin, name);
        cout << endl << "YOUR NAME IS: " << name << ". IS THIS CORRECT? (Y/N) ";
        cin >> confirm;
        if (confirm != 'Y' && confirm != 'y') {
            cout << endl << "You chose to change your name." << endl;
        } else {
            cout << endl;
        }
    } while (confirm != 'Y' && confirm != 'y');

    //ascii art
    cout << endl << lines;
    cout << endl << "88888888ba  88888888888 I8,        8        ,8I   db        88888888ba  88888888888"
        << endl << "88       8b 88          `8b       d8b       d8'  d88b       88       8b 88"
        << endl << "88      ,8P 88            8,     ,8 8,     ,8   d8'`8b      88      ,8P 88"
        << endl << "88aaaaaa8P' 88aaaaa       Y8     8P Y8     8P  d8'  `8b     88aaaaaa8P' 88aaaaa"
        << endl << "88      8b, 88            `8b   d8' `8b   d8' d8YaaaaY8b    88    88'   88"
        << endl << "88      `8b 88             `8a a8'   `8a a8' d8        8b   88    `8b   88"
        << endl << "88      a8P 88              `8a8'     `8a8' d8'        `8b  88     `8b  88"
        << endl << "88888888P   88888888888      `8'       `8' d8'          `8b 88      `8b 88888888888";
    cout << endl << lines;

    // asks the user if they enter the cave
    cout << endl << name << ", you are about to embark into a dangerous cave.";
    cout << endl << "Are you ready? (Y/N) ";
    cin >> confirm;
    if (confirm != 'Y' && confirm != 'y') {
            cout << endl << "You pass by the cave. Sad." << endl << endl << stars;
            return 0;
    }
        
    cout << endl << endl << "You step foot into the dark, dingy cave.";

    // random bonus coin
    if (random == 1) {
        cout << endl << "You spot a coin on the ground and add it to your pouch. Lucky!";
        coins = coins + 1;
    }
    
    // two paths the user can pick
    do {
        cout << endl << "You see two paths, one to the left [1] and one to the right [2]. Which will you take? ";
        cin >> choiceNum;
        if (choiceNum != 1 && choiceNum !=2) {
            cout << endl << endl << "Please select path 1 or 2."<< endl;
        }
    } while (choiceNum != 1 && choiceNum !=2);
    
    // death message for path 2
    if (choiceNum == 2) {
        cout << endl << endl << "You follow the right path..." 
        << endl << " and fall down a large hole! " << name << " is no more.";
        return 0;
    }

    // left path message
    cout << endl << endl << "You follow the left path..."
        << endl << "and find a stash of gold! You collect 100 coins.";
    coins = coins + 100;

    // if they win, they see this message and see their total coins
    cout << endl << endl << "You exit the cave, with you pockets full of " << coins << " coins! Great job!";

    cout << endl << endl << "The game is over." << endl;
    cout << endl << stars << endl;

    return 0;
}