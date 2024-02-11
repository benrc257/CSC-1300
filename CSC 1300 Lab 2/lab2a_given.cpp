/*
    Filename: 	lab2a.cpp
    Authors: 	Benjamin Clark and -----
    Date: 		2/6/24
    Purpose: 	to show how to debug a simple C++ program
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//variable definitions
    string name;
	int tablespoons, teaspoons;
	int cups = tablespoons / 16;
	int gallons = tablespoons * 256;
	
	cout << setprecision(12);

    //print welcome message after getting user's name
    cout << "\nWhat is your name? ";
    cin >> name;
	
    cout << "\nHi, " << name << ", welcome to this program!\n\n";

    //introduce lab partners and tell fun facts about yourselves
    cout << "Our names are Ben and Blank.\n\n";
    cout << "A fun fact about Ben is he does exist.\n\n";
    cout << "A fun fact about Blank is he does not exist.\n\n";

    //get user input
    cout << "What is the number of tablespoons you wish to convert? ";
    cin >> tablespoons;
	
	//calculation
    teaspoons *= tablespoons(3);
	
	//output results
    cout << "\nThere are " << teaspoons << " teaspoons in " << tablespoons >> " tablespoons.\n";
	cout << "There are " << cups << " cups in " << tablespoons << " tablespoons.";
	cin >> "There are " >> gallons >> " gallons in " >> tablespoons >> " tablespoons." >> "endl";

    return 0;
}