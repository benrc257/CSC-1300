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

// Variables
string cardName, stars(60,'*'), protection;
double cardBal, minPay, apr, payment, interest, principal, periodic, totint, ogMinPay;
char getCardInfoOutcome;
int month;
bool monthlimit;

// Functions
int getCardName() // Gets the Card Provider from the User
{
    cout << endl <<  "Please enter the name of your credit card provider, then press enter: ";
    getline(cin,cardName);
    cout << endl << "Is your credit card provider " << cardName << "? (y/n) ";
    cin >> getCardInfoOutcome;
    cin.ignore();
    if (getCardInfoOutcome == 'y' || getCardInfoOutcome == 'Y'){
        return 0;
    } else if (getCardInfoOutcome == 'n' || getCardInfoOutcome == 'N') {
        return 1;
    } else if (isdigit(getCardInfoOutcome)) {
        cout << endl << "Please enter a Y or N, silly. Now you have to try again!" << endl;
        cin >> protection; // protection in case you're extra silly and somehow enter numbers!!
        return 1;
    } else {
         cout << endl << "Please enter a Y or N, silly. Now you have to try again!" << endl;
        return 1;
    }
}

int getCardBal() // Gets the Card Balance from the User
{
    cout << endl <<  "Please enter the balance of your credit card (between 0 and 99999.99 and with only two decimal places), then press enter: ";
    cin >> cardBal;
    if (cardBal >= 0 && cardBal <= 99999.99){
        cout << endl << "Is your card balance $" << fixed << setprecision(2) << cardBal << "? (y/n) ";
        cin >> getCardInfoOutcome;
        if (getCardInfoOutcome == 'y' || getCardInfoOutcome == 'Y'){
            return 0;
        } else if (getCardInfoOutcome == 'n' || getCardInfoOutcome == 'N') {
            return 1;
        } else if (isdigit(getCardInfoOutcome)) {
            cout << endl << "Please enter a Y or N, silly. Now you have to try again!" << endl;
            cin >> protection; // protection in case you're extra silly and somehow enter numbers!!
            return 1;
        } else {
            cout << endl << "Please enter a Y or N, silly. Now you have to try again!" << endl;
            return 1;
        }
    } else {
        cout << endl << "Invalid balance detected. Please try again." << endl;
        return 1;
    }
    
}

int getCardAPR() // Gets the Card APR from the User
{
    cout << endl <<  "Please enter the APR of your credit card (between 0 and 100) WITHOUT a percentage sign and with up to two decimal places, then press enter: ";
    cin >> apr;
    if (apr >= 0 && apr <= 100.00){
        cout << endl << "Is your card APR " << fixed << setprecision(2) << apr << "%? (y/n) ";
        cin >> getCardInfoOutcome;
        if (getCardInfoOutcome == 'y' || getCardInfoOutcome == 'Y'){
            return 0;
        } else if (getCardInfoOutcome == 'n' || getCardInfoOutcome == 'N') {
            return 1;
        } else if (isdigit(getCardInfoOutcome)) {
            cout << endl << "Please enter a Y or N, silly. Now you have to try again!" << endl;
            cin >> protection; // protection in case you're extra silly and somehow enter numbers!!
            return 1;
        } else {
            cout << endl << "Please enter a Y or N, silly. Now you have to try again!" << endl;
            return 1;
        }
    } else {
        cout << endl << "Invalid APR value detected. Please try again." << endl;
        cin >> protection; // protection in case you're extra and somehow enter numbers!!
        return 1;
    }
    
}

int getCardMin() // Gets the Card Minimum Payment from the User
{
    cout << endl <<  "Please enter the Minimum Payment for your credit card (between 0 and 99999.99 and with only two decimal places) WITHOUT the dollar sign, then press enter: ";
    cin >> minPay;
    ogMinPay = minPay;
    if (minPay >= 0 && minPay <= 99999.99){
        cout << endl << "Is your card's minimum payment $" << fixed << setprecision(2) << minPay << "? (y/n) ";
        cin >> getCardInfoOutcome;
        if (getCardInfoOutcome == 'y' || getCardInfoOutcome == 'Y'){
            return 0;
        } else if (getCardInfoOutcome == 'n' || getCardInfoOutcome == 'N') {
            return 1;
        } else if (isdigit(getCardInfoOutcome)) {
            cout << endl << "Please enter a Y or N, silly. Now you have to try again!" << endl;
            cin >> protection; // protection in case you're extra silly and somehow enter numbers!!
            return 1;
        } else {
            cout << endl << "Please enter a Y or N, silly. Now you have to try again!" << endl;
            return 1;
        }
    } else {
        cout << endl << "Invalid Minimum Payment value detected. Please try again." << endl;
        return 1;
    }
    
}

int print() // Prints information about the card on a monthly basis
{
    cout << "Month " << setfill(' ') << setw(2) << month << ":  ";
    cout << fixed << setprecision(2);
    cout << "$" << setfill(' ') << setw(8) << minPay << "   ";
    cout << "$" << setfill(' ') << setw(8) << interest << "   ";
    cout << "$" << setfill(' ') << setw(8) << principal << "   ";
    cout << "$" << setfill(' ') << setw(8) << cardBal << endl;
    return 0;
}

int calculate() // Outputs the Payment, Interest, Principal, and Balance as variables
{
    cout << fixed << setprecision(2);
    interest = cardBal*periodic*30.42;
    cardBal = cardBal+interest-minPay;
    totint = totint+interest;
    if (cardBal <= 0) {
        minPay = cardBal+minPay;
        principal = minPay-interest;
        cardBal = 0.00;
        return 0;
    } else {
        month = month+1;
        principal = minPay-interest;
        if (month < 21){
            print();
        } else {
            monthlimit = true;
        }
        return 1;
    }
}

int main()
{
    // Initializes variables for later
        month = 0;
        monthlimit = false;

    // Write Out Stars
    cout << endl << stars << endl;
    cout << endl << "This program will take your credit card information then compute how long" << endl << "it will take to pay it off, as well as the total interest acrued." << endl;

    // Gets Card Provider Name from User until successful
    while(getCardName() != 0);
    
    // Gets Card Balance from User until successful
    while(getCardBal() != 0);

    // Gets Card APR from User until successful
    while(getCardAPR() != 0);

    // Gets Card Minimum Payment from User until successful
    while(getCardMin() != 0);

    // Outputs the card name and information in a list
    cout << endl << stars << endl;
    cout << endl << "Name of the Credit Card Provider: " << cardName << endl;
    cout << endl << "Current Balance: $" << cardBal << endl;
    cout << endl << "Annual Percentage Rate (APR): " << apr << "%" << endl;
    cout << endl << "Monthly Minimum Payment: $" << minPay << endl;
    cout << endl << stars << endl;
    
    // Math and Chart Printing
    cout << endl << "           Payment     Interest    Principal   Balance" << endl;
    cout << endl << "                                               $" << setfill(' ') << setw(8) << cardBal << endl;
    
    periodic = apr/365*0.01; // Calculates periodic rate for the calculate() function

    while (cardBal > 0 && principal >= 0) {calculate();} // Prints the graph

    if (monthlimit == true) {
        cout << "..." << endl;
    } // If the number of months goes over 20, this will trigger and only show months 1-20 and the last month

    if (principal >= 0 && month > 1) {
        month = month+1;
        print();
        cout << endl << "With a monthly payment of $" << ogMinPay << " you will pay off your current balance in " << month << " months." << endl;
    } else if (principal >= 0) {
        if (month > 1) {
            cout << endl << "With a monthly payment of $" << ogMinPay << " you will pay off your current balance in " << month << " months." << endl;
        } else {
            cout << endl << "With a monthly payment of $" << ogMinPay << " you will pay off your current balance in " << month << " month." << endl;
        }
    } else if (principal < 0) {
        cout << endl << "With a monthly payment of $" << ogMinPay << " you will never pay off your current balance, and it will continually get larger.";
        cout << endl << "You can either increase your monthly payment or create a generational wealth blackhole." << endl;
    } else {
        cout << endl << "Error! Shutting down..." << endl;
        return 1;
    } // Handles the final message and all its quirks

    cout << endl << stars << endl;
    return 0;
}