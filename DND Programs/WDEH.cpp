#include <iostream>
#include <fstream>
#include <unistd.h>
#include <chrono>
#include <thread>
using namespace std;

bool active = true;

int intake() {
    
    int num;

    do {
        cout << "\nSelect 1-4: \n";
        cout << "1: Set radio broadcast strength\n";
        cout << "2: Select broadcast input\n";
        cout << "3: View logs\n";
        cout << "4: Disable/Enable transmitter\n";
        cout << "> ";
        cin >> num;
        if (num < 1 || num > 4) {
            cout << "\nEnter a number between 1 and 4.\n";
        }
    } while (num < 1 || num > 4);
    return num;
}

int first() {
    int input;
    cout << "\nInput a value between 1 and 100.";
    cout << "\nCAUTION - SETTING STRENGTH ABOVE 100 MAY DAMAGE TRANSMITTER";
    cout << "\nSelect broadcast strength: ";
    cin >> input;
    cout << "Broadcast strength at " << input << "%\n";
    if (input >= 200) {
        cout << "\nTRANSMITTER OPERATING BEYOND CAPACITY. DAMAGE MAY FOLLOW.";
        sleep(5);
        cout << "\n\nTRANSMITTER FAILURE - MODULE DAMAGED\n";
    } else if (input > 100) {
        cout << "\nTRANSMITTER OPERATING BEYOND CAPACITY. DAMAGE MAY FOLLOW.\n";
    }

    return input;
}

string second() {
    
    int num;
    string input;

    do {
        cout << "\nSelect Input 1-3: \n";
        cout << "1: Studio Output\n";
        cout << "2: Microphone\n";
        cout << "3: Tape Input\n";
        cout << "> ";
        cin >> num;
        if (num < 1 || num > 3) {
            cout << "\nEnter a number between 1 and 3.\n";
        }
    } while (num < 1 || num > 3);
    
    switch (num) {
            case 1: {
                cout << "Studio Output now broadcasting.\n";
                input = "Studio";
                break;
            }
            case 2: {
                cout << "Microphone now broadcasting.\n";
                input = "Microphone";
                break;
            }
            case 3: {
                cout << "Tape Input now broadcasting.\n";
                input = "Tape";
                break;
            }
        }
    return input;
}

void third() {
    int num;

    cout << "\nOne log detected. Outputting contents: \n";
    cout << "\nDate: 1/7/1981 \nOrders: \n1. Continue broadcast. Maintain control of shades. \n2. Continue conversions when safe. \n3. Immediately report any known shimmer reservoirs. The Ark runs low.";
    cout << "\n\n-LOG END-\n";
}

bool fourth() {
    char input;

    if (active == false) {
        cout << "\nTransmitter offline. Activate Transmitter? (y/n) ";
        cin >> input;
        if (input == 'y' || input == 'Y') {
            cout << "\nTransmitter online.\n";
        }
        return true;
    } else {
        cout << "\nTransmitter online. Deactivate Transmitter? (y/n) ";
        cin >> input;
        if (input == 'y' || input == 'Y') {
            cout << "\nTransmitter offline.\n";
        }
        return false;
    }
}

int main() {

    string input;
    int num;
    int power = 80;
    int quit = 0;

    do {
        num = intake();
        switch (num) {
            case 1: {
                power = first();
                if (power >= 200) {
                    sleep(5);
                    return 0;
                }
                break;
            }
            case 2: {
                input = second();
                break;
            }
            case 3: {
                third();
                break;
            }
            case 4: {
                active = fourth();
                break;
            }
        }
    } while(quit != 1);
    


    return 0;
}
