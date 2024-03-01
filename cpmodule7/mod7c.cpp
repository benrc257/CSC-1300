#include <iostream>
using namespace std;

bool luckyguess(int);

int main() {
    
    string name, favFood;
    int favNum;

    cout << "\nWhat is your name? ";
    getline(cin, name);
    cout << "\nWhat is your favorite food? ";
    getline(cin, favFood);
    cout << "\nWhat is your favorite number? ";
    cin >> favNum;

    if (luckyguess(favNum)) {
        cout << "\n" << name << ", you will get a lifetime supply of " << favFood << "!\n\n";
    } else {
        cout << "\n" << name << ", sorry, you get no " << favFood << "!\n\n";
    }

    return 0;
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