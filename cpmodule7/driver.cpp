#include "luckyguess.h"

int main() {
    
    string name, favFood;
    int favNum;

    getUserData(name, favFood, favNum);

    if (luckyguess(favNum)) {
        cout << "\n" << name << ", you will get a lifetime supply of " << favFood << "!\n\n";
    } else {
        cout << "\n" << name << ", sorry, you get no " << favFood << "!\n\n";
    }

    return 0;
}
