#include <iostream>
using namespace std;

const int SIZE = 10;

int main() {
    string foods[SIZE];
    string *pointer;
    
    pointer = foods;

    cout << "\nEnter your 10 favorite foods:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i+1 << ": ";
        cin >> *(pointer+i);
    }

    cout << "\nYour 10 favorite foods are:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i+1 << ": " << foods[i] << "\n";
    }

    return 0;
}