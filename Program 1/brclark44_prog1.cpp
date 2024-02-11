/*
Title: brclark44_prog1.cpp
Author: Benjamin Clark
Date: 1/30/24
Purpose: This program will take information about one credit card
from the user and calculate how long it will take to pay
the card off.
*/


#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    //variables
    char check;
    string card, stars(60,'*'), lines(57, '-');
    double bal, startingBal, apr, min, startingMin, periodic, interest, principal;
    double totalInterest = 0;
    int month = 0;

    //welcome message
    cout << endl << stars << endl; 
    cout << endl << "This program will take information about your credit card and";
    cout << endl << "calculate how long it will take to pay it off." << endl;
    cout << endl << lines << endl;

    //collecting inputs from user:

    //card name input
    do {
        cout << endl << "Please input the name of your credit card: ";
        getline(cin, card);
        cout << endl << "Your card's name is " << card << ". Is this correct? (y/n) ";
        cin >> check;
        cin.ignore();
    } while (check != 'y' && check != 'Y');

    cout << endl << lines << endl;

    //card balance input
    do {
        cout << endl << "Please input the balance on your card (between $0 and $99999.99 with up to two decimal places): ";
        cin >> bal;
        cout << endl << "Your card's balance is $" << fixed << setprecision(2) << bal << ". Is this correct? (y/n) ";
        cin >> check;
        if (bal < 0 || bal > 99999.99) {
            cout << endl << "Invalid balance. Please try again." << endl;
            check = 'n';
        }
    } while (check != 'y' && check != 'Y');
    
    cout << endl << lines << endl;
    
    //card apr input
    do {
        cout << endl << "Please input the APR of your card (between 0% and 100% with up to two decimal places): ";
        cin >> apr;
        cout << endl << "Your card's APR is " << fixed << setprecision(2) << apr << "%. Is this correct? (y/n) ";
        cin >> check;
        if (apr < 0 || apr > 100) {
            cout << endl << "Invalid APR. Please try again." << endl;
            check = 'n';
        }
    } while (check != 'y' && check != 'Y');
    
    cout << endl << lines << endl;
    
    //card mininum payment input
    do {
        cout << endl << "Please input the minimum payment for your card (between $0 and $99999.99 with up to two decimal places): ";
        cin >> min;
        cout << endl << "Your card's minimum payment is $" << fixed << setprecision(2) << min << ". Is this correct? (y/n) ";
        cin >> check;
        if (min < 0 || min > 99999.99) {
            cout << endl << "Invalid minimum payment. Please try again." << endl;
            check = 'n';
        }
    } while (check != 'y' && check != 'Y');
    
    cout << endl << stars << endl;

    //prints collected information
    cout << endl << "Name of Your Card: " << card;
    cout << endl << "Current Balance: $" << bal;
    cout << endl << "Annual Percentage Rate (APR): " << apr << "%";
    cout << endl << "Monthly Minimum Payment: $" << min << endl;
    cout << endl << lines;
    
    //chart setup
    cout << endl << "            Payment     Interest    Principal   Balance";
    cout << endl << lines;
    cout << endl << "                                                $" << setfill(' ') << setw(8) << bal << endl;

    //math and rest of chart printing
    periodic = apr / 365 * .01;
    double days = 30.42; //average days in a month
    startingBal = bal; //saves the inputed balance for following if statements
    startingMin = min; //saves the inputed minimum payment for the final message

    do {
        interest = bal * periodic * days;
        bal = bal + interest - min;
        totalInterest = totalInterest + interest;
        month++;

        if (bal <= 0) {
            min = bal+min;
            principal = min-interest;
            bal = 0;
        }

        principal = min - interest;

        if (month <= 30) {
            cout << "Month " << setfill(' ') << setw(3) << month << ":  ";
            cout << fixed << setprecision(2);
            cout << "$" << setfill(' ') << setw(8) << min << "   ";
            cout << "$" << setfill(' ') << setw(8) << interest << "   ";
            cout << "$" << setfill(' ') << setw(8) << principal << "   ";
            cout << "$" << setfill(' ') << setw(8) << bal << endl;
        } else if (month == 32) {
            cout << "..." << endl;
        }
    } while(bal > 0.00999 && bal <= startingBal && month <= 120);
    //bal is compared to 0.00999 in order to combat an issue with a balance equivalent to 0.00
    //after setprecision rounding not ending the loop (ie. 0.007 -> 0.00)

    //If during printing, the number of months exceeded 30, then it halts printing. This prints the last month calculated.
    if (month > 30) {
        cout << "Month " << setfill(' ') << setw(3) << month << ":  ";
        cout << fixed << setprecision(2);
        cout << "$" << setfill(' ') << setw(8) << min << "   ";
        cout << "$" << setfill(' ') << setw(8) << interest << "   ";
        cout << "$" << setfill(' ') << setw(8) << principal << "   ";
        cout << "$" << setfill(' ') << setw(8) << bal << endl;
    }

    cout << endl << lines << endl;

    // handles the ending message for five possible outcomes of the chart's while loop
    if (bal == startingBal) {
        cout << endl << "With a monthly payment of $" << startingMin << ", the balance on your card will stay";
        cout << endl << "stagnant and never be paid off. You should consider increasing your monthly payment." << endl; 
    } else if (bal > startingBal) {
        cout << endl << "With a monthly payment of $" << startingMin << ", the balance on your card will continually";
        cout << endl << "grow and never be paid off. You should consider increasing your monthly payment." << endl;
    } else if (month > 120) {
        cout << endl << "With a monthly payment of $" << startingMin << ", the balance on your card will take more";
        cout << endl << "than 10 years to pay off. You should consider increasing your monthly payment." << endl;
    } else if (month == 1) {
        cout << endl << "With a monthly payment of $" << startingMin << ", the balance on your card will be fully";
        cout << endl << "paid off in " << month << " month, with a total accrued interest of $" << totalInterest << "." << endl;
    } else {
        cout << endl << "With a monthly payment of $" << startingMin << ", the balance on your card will be fully";
        cout << endl << "paid off in " << month << " months, with a total accrued interest of $" << totalInterest << "." << endl;
    }

    // prints stars, ends program
    cout << endl << stars << endl;
    return 0;
}