#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream file;
    string name, score, year;
    int count = 0;

    file.open("movieData2.txt");

    if (!file.is_open()) {
        cout << endl << "Could not open file." << endl;
        return 1;
    }

    while (getline(file, name, '#')) {
        count++;
        getline(file, year, '#');
        getline(file, score, '#');
        cout << endl << count << ") Title: " << name << ", Year: " << year << ", Rotten Tomatoes Score: " << score;
    }
    cout << endl << endl;
    file.close();
    return 0;
}