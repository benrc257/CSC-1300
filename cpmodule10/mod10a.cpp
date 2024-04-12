#include <iostream>
using namespace std;

struct Song {
    string name, artist;
    double length;
};

int main(){
    Song Song1;

    cout << "\nEnter the song's name: ";
    getline(cin, Song1.name);
    cout << "Enter the song's artist: ";
    getline(cin, Song1.artist);
    cout << "Enter the song's length: ";
    cin >> Song1.length;

    cout << "\nThe song you entered is: ";
    cout << "\nName - " << Song1.name;
    cout << "\nArtist - " << Song1.artist;
    cout << "\nLength - " << Song1.length << endl << endl;

    return 0;
}