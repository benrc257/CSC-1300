/*
    Title: lab1.cpp
    Author: Benjamin Clark
    Date: 1/23/2024
    Purpose: Convert Celcius to Farenheit
*/

#include <iostream>
using namespace std;

int main()
{
    double far, cel;
    cout << "\n\nWhat is the temperature in Celcius? ";
    cin >> cel;
    far = cel * (9.0/5.0) + 32;
    cout << "\nRESULT: " << cel << " degrees Ceclius is ";
    cout << far << " degrees Fahrenheit.\n\n";
    return 0;
}