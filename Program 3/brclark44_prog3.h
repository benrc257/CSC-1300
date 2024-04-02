/*
	Title: brclark44_prog3.h
	Author: Benjamin Clark
	Date: 3/9/24
	Purpose: Gathers information from a file on students, then displays
    statistics from the data. This is the header file.
*/
#ifndef BRCLARK44_PROG3_H
#define BRCLARK44_PROG3_H

#include <iostream>
#include <cctype>
#include <fstream>
#include <iomanip>
using namespace std;

//function prototypes
int getData(string [], string [], double [], string&);
void selectionSort(string [], string [], double []);
void printArray(string [], string [], double []);
double getAverage(double []);
double getMedian(double []);
double getMode(double []);

//global variables
const int SIZE = 200;

#endif