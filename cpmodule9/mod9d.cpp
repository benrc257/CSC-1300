#include <iostream>
using namespace std;

//prototypes
void enterDogs(string*, string*, int*, int);
void printDogs(string*, string*, int*, int);

int main() {
    //variables
    int adoptnum, *dogAge;
    string *dogName, *dogBreed;

    cout << "\nHow many dogs did you adopt? ";
    cin >> adoptnum;

    dogName = new string[adoptnum];
    dogBreed = new string[adoptnum];
    dogAge = new int[adoptnum];

    enterDogs(dogName, dogBreed, dogAge, adoptnum);

    printDogs(dogName, dogBreed, dogAge, adoptnum);

    return 0;
}

void enterDogs(string* dogName, string* dogBreed, int* dogAge, int adoptnum) {
    cout << "\nENTER DOGS:\n\n";
    for (int i = 0; i < adoptnum; i++) {
        cout << "*******| DOG " << i+1 << " |*******";
        cout << "\nNAME: ";
        cin.ignore();
        getline(cin, *(dogName+i));
        cout << "BREED: ";
        getline(cin, *(dogBreed+i));
        cout << "AGE: ";
        cin >> *(dogAge+i);
    }
    cout << "**********************";
}

void printDogs(string* dogName, string* dogBreed, int* dogAge, int adoptnum) {
    cout << "\n\nPRINTING DOGS:\n";
    for (int i = 0; i < adoptnum; i++) {
        cout << "\n*******| DOG " << i+1 << " |*******";
        cout << "\nNAME: " << *(dogName+i);
        cout << "\nBREED: " << *(dogBreed+i);
        cout << "\nAGE: " << *(dogAge+i);
    }
    cout << "\n**********************\n\n";
}