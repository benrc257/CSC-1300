#include "luckyguess.h"

void getUserData(string& name, string& favFood, int& favNum) {
    cout << "\nWhat is your name? ";
    getline(cin, name);
    cout << "\nWhat is your favorite food? ";
    getline(cin, favFood);
    cout << "\nWhat is your favorite number? ";
    cin >> favNum;
}

bool luckyguess(int favNum) {
    int randnum;

    srand(time(0));
    randnum = rand()%(100)+1;
    cout << "\nRandom Number: " << randnum << "\n";

    if (abs(randnum-favNum) <= 25) {
        return true;
    } else {
        return false;
    }
}