#include "IceCream.h"
#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>

//accessors
string IceCream::getCone() const {
    return cone;
}

string IceCream::getFlavor() const {
    return flavor;
}

string IceCream::getTopping() const {
    return topping;
}

double IceCream::getPrice() const {
    return price;
}

//mutators
void IceCream::setCone(string c) {
    cone = c;
}

void IceCream::setFlavor(string f) {
    flavor = f;
}

void IceCream::setTopping(string t) {
    topping = t;
}

void IceCream::setPrice(double p) {
    price = p;
}

//constructors
IceCream::IceCream() {
    cone = "";
    flavor = "";
    topping = "";
    price = 0.0;
}

IceCream::IceCream(string c, string f, string t, double p) {
    cone = c;
    flavor = f;
    topping = t;
    price = p;
}

//other member functions
void IceCream::printIceCream() {
    cout << "\nCone: " << cone;
    cout << "\nFlavor: " << flavor;
    cout << "\nTopping: " << topping;
    cout << "\nPrice: " << fixed << setprecision(2) << price;
}

//destructor
IceCream::~IceCream() {
    cout << "\nThe " << flavor << " Ice Cream in a " <<  cone << " cone with " << topping << " topping has been destroyed (eaten).";
}