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
int getValidateInput(int, string);
int getValidateInput(char, char, string);
int preloadDinos(Dinos *, int);
void enterDinos(Dinos *, int, int&);
void printDinos(Dinos *, int);
void deleteDino(Dinos *, Dinos *, int&);
void fight(Dinos *, int&);
//---- saveToFile();

//global constants
//FILENAME is made a global constant so the program's preload file can be changed between runs
const string FILENAME = "dinosaurs-sample.txt";

#endif