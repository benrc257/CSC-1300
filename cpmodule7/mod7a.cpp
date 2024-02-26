#include <iostream>
#include <cctype>
using namespace std;

void countCharacters(string, int);

int main() {
    string str;

    cout << "\nEnter in a string: ";
    getline(cin, str);
    countCharacters(str, 1);
    countCharacters(str, 2);
}

void countCharacters(string str, int type) {
    int num = 0;
    if (type == 1) {
        for (int count = 0; count < size(str); count++) {
            if (isdigit(str[count])) {
                num++;
            }
        }
        cout << "\nThere are " << num << " digits in the string."; 
    } else {
        for (int count = 0; count < size(str); count++) {
            if (ispunct(str[count])) {
                num++;
            }
        }
        cout << "\nThere are " << num << " symbols in the string.";
    }
    return;
}