#include "IceCream.h"
#include <iostream>
#include <string>

int main() {
    IceCream **icecream;
    string cone, flavor, topping;
    double price;
    int size;

    cout << "\nHow much ice cream would you like to create?";
    cout << "\n>> ";
    cin >> size;

    icecream = new IceCream*[size];

    for (int i=0; i<size; i++) {
        cout << "\nEnter Ice Cream " << i+1 << ":";
        cout << "\nCONE: ";
        cin.ignore();
        getline(cin, cone);
        cout << "FLAVOR: ";
        getline(cin, flavor);
        cout << "TOPPING: ";
        getline(cin, topping);
        cout << "PRICE: ";
        cin >> price;

        icecream[i] = new IceCream;
    }
    
    for (int i=0; i<size; i++) {
        cout << "\nIce Cream " << i+1 << ":";
        icecream[i]->printIceCream();
    }

    for (int i=0; i<size; i++) {
        delete &(*(icecream[i]));
    }

    delete [] icecream;
    return 0;
}