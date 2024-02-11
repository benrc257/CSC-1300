/*
    Filename: 	lab3a.cpp
    Authors: 	Benjamin Clark
    Date: 		2/6/24
    Purpose: 	to give advice on time management
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//variables
double screenTime, studyTime;
string stars(50,'*');

int main()
{
    cout << endl << stars << endl;
    cout << fixed << setprecision(1);

    cout << endl << "This program will help you manage your time! Please answer the following questions." << endl;

    //asks the user and gets the values for study time and screen time
    cout << endl << "On average, how many hours do you spend looking at a screen each day?" << endl << "Enter a number with up to one decimal place: ";
    cin >> screenTime;
    screenTime = fabs(screenTime);

    cout << endl << "On average, how many hours do you spend studying each day?" << endl << "Enter a number with up to one decimal place: ";
    cin >> studyTime;
    studyTime = fabs(studyTime);

    // gives the user advice based on their inputs
    if (screenTime <= 2 && studyTime >= 6){
        cout << endl << "You need to socialize with people more often.";
    } else if (screenTime <= 2 && (studyTime >= 2 && studyTime < 6)) {
        cout << endl << "You manage your time well.";
    } else if (screenTime >= 2 && studyTime >= 6) {
        cout << endl << "You need to socialize with people more often and get off that phone.";
    } else if (screenTime >= 2 && studyTime <= 6) {
        cout << endl << "What are you going to do if you lose that phone?"; 
        cout << endl << "It is interfering with your ability to have a real life.";
    } else {
        cout << endl << "I am unable to help you.";
    }
    cout << endl << endl << stars;
    return 0;
}