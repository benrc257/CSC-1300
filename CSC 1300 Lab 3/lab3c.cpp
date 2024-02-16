#include <iostream>
#include <string>
using namespace std;

int main()
{
    //variables
    string stars(50,'*');
    int answer = 0;
    char quit = 'n';

    //prints stars
    cout << endl << stars << endl;
    
    // runs until the user quits or gets the answer
    do {
        cout << endl << "What is 4+18? ";
        cin >> answer;
        cout << endl << "Do you want to quit? (y/n) ";
        cin >> quit;
        
        if (quit == 'y' || quit == 'Y') {
            cout << endl << "Quitters never go anywhere.";
            return 0;
        } else if (answer == 22){
            cout << endl << "22 is correct! Good job." << endl;
        } else {
            cout << endl << "Incorrect! Please try again." << endl;
        }
    } while (answer != 22);

    cout << endl << stars << endl;
    return 0;
}