#include <iostream>
#include <fstream>
#include <unistd.h>
#include <chrono>
#include <thread>
using namespace std;

int main() {

    string input, name;
    srand(time(0));

    cout << "\nWho? ";
    getline(cin, name);

    cout << "\nAether welcomes " << name << ".";

    cout << "\n\nLocating tower";
    sleep(2);
    cout << ".";
    sleep(2);
    cout << ".";
    sleep(2);
    cout << ".";
    sleep(2);
    cout << "\nSearching...";
    sleep(2);
    for(int timer = 1; timer <=100; timer++) {
        this_thread::sleep_for(chrono::milliseconds(rand()%(300-100)+1));
        cout << "\r\t\t" << timer << "%";
    }
    cout << "\r\t\t" << "    ";
    cout << "\n\nTower found.\n";
    this_thread::sleep_for(chrono::milliseconds(500));

    cout << "\nNortheast. ";
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "WDEH Radio.\n";;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "\nHeavily armored.";
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "\nAnti-air defense.";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "\nArm self.";
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "\nProceed cautiously.\n";
    this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "\nTime before ignition runs out.\n";
    this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "Do not allow ignition.\n";
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "\n(o)\n";
    cout << "/|\\" << endl;
}