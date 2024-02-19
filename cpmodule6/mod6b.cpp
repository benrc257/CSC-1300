#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file;
    string name;
    int num;

    file.open("mod6b.txt");
    getline(file, name);
    cout << endl << name;


    for (int count = 0; count < 5; count++) {
    file >> num;
    cout << endl << num;
    }

    cout << endl << endl;
    
    file.close();
    return 0;
}