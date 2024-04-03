#include <iostream>
#include <cstring>
using namespace std;

int main() {
    
    char name1[30] = "Benjamin";
    string name2 = "Archie";

    cout << "\nname1: " << name1 << "\nname2: " << name2;

    cout << "\n\nWhat is your name? ";
    cin.getline(name1, 30);

    cout << "\nWhat is your friend's name? ";
    getline(cin, name2);

    cout << "\nname1: " << name1 << "\nname2: " << name2 << "\n\n";

    strcpy(name1, "SCOUT");
    name2 = "JACK";

    for (int i=0; i < 5; i++) {
        cout << name1[i] << "*";
    }
    cout << "\n";

    for (int i=0; i < 4; i++) {
        cout << name2[i] << "*";
    }
}