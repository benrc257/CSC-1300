#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ofstream file;

    file.open("mod6a.txt");
    file << "Ben\n" << "2027\n" << "My favorite song is Bambi by Hippo Campus\n";
    file.close();

    cout << "\nFile successfully written.\n";

    return 0;
}