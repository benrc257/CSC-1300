/*
	Title:    lab5.cpp
	Author:   Benjamin Clark
	Date:     2/20/24
	Purpose:  Make a resturant ordering system
*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    //variables
    ofstream outfile;
    string stars(50,'*');
    int choice; 
    double items;
    const double pPrice = 20.00;
    const double fPrice = 2.00;
    const double bPrice = 15.00;
    const double cPrice = 10.00;
    int pudding = 0;
    int fruit = 0;
    int beef = 0;
    int cabbage = 0;
    double total = 0;
    

    //welcome message
    cout << endl << stars << endl;
    cout << endl << "Welcome to the Shindig Irish Restaurant & Pub!";

    //opening output file
    outfile.open("restaurant.txt", ios::app);

    //ordering system
    do {
        choice = 5;
        //asks the user what they want to order
        while(choice > 4 || choice < 0) {
            cout << endl << "Please select one of the following items to order:";
            cout << endl << "1 - Bread Pudding";
            cout << endl << "2 - Corned Beef";
            cout << endl << "3 - Fried Cabbage";
            cout << endl << "4 - Done Ordering";
            cout << endl << "Enter 1-4: ";
            cin >> choice;
            if (choice > 5 || choice < 0) {
                cout << endl << endl << "Please enter a number between 1 and 4." << endl; 
            }
        }
    
        //handles the input for number of items to order
        switch (choice) {
            case 1: cout << endl << "You selected bread pudding. How many would you like to order? ";
                    do {
                        cin >> items;
                        if (items < 1) {
                            cout << endl << "Please select a number greater than 0.";
                        }
                    } while(items < 1);
                    total = total+((items*pPrice));
                    if (pudding == 0) {
                        total-=4;
                    }
                    pudding+=items;
                    cout << endl << items << " bread pudding(s) were added. Please select the number of fruit toppings (+$2.00/topping) for each: " << endl;
                    outfile << endl << items << " bread pudding(s) were added. The total is now $" << fixed << setprecision(2) << total;
                    for (int count = 1, ogItems = items; count <= ogItems; count++) {
                        cout << "How many fruit toppings on bread pudding " << count << "? ";
                        do {
                            cin >> items;
                            if (items < 0) {
                                cout << endl << "Please select a positive number or 0.";
                            }
                        } while(items < 0);
                        fruit+=items;
                        total = total+((items*fPrice));
                        cout << endl << items << " fruit topping(s) were added. Your total is now $" << fixed << setprecision(2) << total;
                        outfile << endl << items << " fruit topping(s) were added. The total is now $" << fixed << setprecision(2) << total;
                    }
                   
                    break;
            case 2: cout << endl << "You selected corned beef. How many would you like to order? ";
                    do {
                        cin >> items;
                        if (items < 1) {
                            cout << endl << "Please select a number greater than 0.";
                        }
                    } while(items < 1);
                    total = total+((items*bPrice));
                    if (beef == 0) {
                        total-=2.25;
                    }
                    beef+=items;
                    cout << endl << items << " corned beef(s) were added. Your total is now $" << fixed << setprecision(2) << total;
                    outfile << endl << items << " corned beef(s) were added. The total is now $" << fixed << setprecision(2) << total;
                    break;
            case 3: cout << endl << "You selected fried cabbage. How many would you like to order? ";
                    do {
                        cin >> items;
                        if (items < 1) {
                            cout << endl << "Please select a number greater than 0.";
                        }
                    } while(items < 1);
                    total = total+((items*cPrice));
                    if (cabbage == 0) {
                        total-=1;
                    }
                    cabbage+=items;
                    cout << endl << items << " fried cabbage(s) were added. Your total is now $" << fixed << setprecision(2) << total;
                    outfile << endl << items << " fried cabbage(s) were added. The total is now $" << fixed << setprecision(2) << total;
                    break;
            case 4: cout << endl << "Ordering complete. Your total is: $" << fixed << setprecision(2) << total;
                    outfile << endl << "Ordering complete. The total is: $" << fixed << setprecision(2) << total;
                    break;
        }
    } while(choice !=4);

    outfile.close();
    //ends program, prints stars
    cout << endl << stars;
    return 0;
}