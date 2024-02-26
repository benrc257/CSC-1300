#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream file;
    string name, score;
    int year;
    int count = 0;

    file.open("movieData1_windows.txt");

    while (getline(file, name)) {
        count++;
        file >> year;
        file.ignore();
        getline(file, score);
        cout << endl << count << ") Title: " << name << ", Year: " << year << ", Rotten Tomatoes Score: " << score;
    }

    file.close();
    return 0;
}