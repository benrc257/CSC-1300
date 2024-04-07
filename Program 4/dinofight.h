/*
	Title: dinofight.h
	Author: Benjamin Clark
	Date: 4/1/24
	Purpose: This program allows the user to add dinosaurs to an arena
    and have them fight. This is the header file.
*/

#ifndef DINOFIGHT_H
#define DINOFIGHT_H

//libraries
#include <iostream>
#include <fstream>
#include <cctype>
#include <ctime>
using namespace std;

//structures
struct Stats {
    int hit;
    int health;
};

struct Dinos {
    string type;
    string name;
    Stats stats;
};

//function prototypes
void printArt();
void delay(int);
int getValidateInput(int, int, string);
int getValidateInput(char, char, string);
int preloadDinos(Dinos *, int);
int enterDinos(Dinos *, int, int);
void printDinos(Dinos *, int);
int deleteDino(Dinos *, Dinos *, int);
int fight(Dinos *, int);
void saveToFile(Dinos *, int);

//global constants
//FILENAME is made a global constant so the program's storage file can be changed between runs
const string FILENAME = "dinosaurs.txt";

#endif