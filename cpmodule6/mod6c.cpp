#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream file;
    string name, score;
    int year;
    
    file.open("movieData1_windows.txt");

    while (getline(file, name)) {
        file >> year;
        file.ignore();
        getline(file, score);
        cout << endl << name << endl << year << endl << score;
    }

    file.close();
    return 0;
}