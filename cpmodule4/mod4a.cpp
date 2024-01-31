#include <iostream>
using namespace std;

//Variables
int partySize;

int main() 
{
    cout << endl << "How many people are in your party? ";
    cin >> partySize;

    if (partySize < 3 &&  partySize >= 1) {
        cout << endl << "You may be seated at a small table." << endl << endl;
    } else if (partySize >= 3) {
        cout << endl << "You may be seated at a large table." << endl << endl;
    } else {
        cout << endl << "That table size is invalid." << endl << endl;
    }
    
    return 0;
}