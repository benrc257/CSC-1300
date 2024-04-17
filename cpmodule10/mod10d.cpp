#include <iostream>
using namespace std;

//structures
struct Course {
    int courses, *hours;
};

struct Student {
    Course course;
    string name, house;
};

//function prototypes
void enterData(Student []);
int calculateHours(Student);

//global constants
const int SIZE = 5; 

int main() {
    Student Students[SIZE];
    int totalHours;

    cout << "\nWhich of the five students can work in addition to going to school?";
    enterData(Students);
    for(int i=0; i<SIZE; i++) {
        totalHours = calculateHours(Students[i]);
        if (totalHours > 30) {
            cout << "\n" << Students[i].name << " is already taking " << totalHours << " credit hours, ";
            cout << "\nso they should not take a part time job.\n";
        } else {
            cout << "\n" << Students[i].name << " is only taking " << totalHours << " credit hours, ";
            cout << "\nso they should take a part time job.\n";
        }
    }

    for(int i=0; i<SIZE; i++) {
        delete [] Students[i].course.hours;
    }

    return 0;
}

void enterData(Student Students[]) {

    cout << "\n\nPlease enter each student's information.\n";
    for(int i=0; i < SIZE; i++) {
        cout << "\nStudent " << i+1 << ":";
        cout << "\nName: ";
        cin.ignore();
        while (!(getline(cin, Students[i].name))) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter the student's name: ";
        }
        cout << "House: ";
        while (!(getline(cin, Students[i].house))) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter the student's house: ";
        }
        cout << "Number of Courses: ";
        while (!(cin >> Students[i].course.courses) || Students[i].course.courses < 1) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter the student's number of courses as a whole number greater than 0: ";
        }
        Students[i].course.hours = new int[Students[i].course.courses];
        for (int j=0; j < Students[i].course.courses; j++) {
            cout << "Number of Credit Hours in Course " << j+1 << ": ";
            while (!(cin >> Students[i].course.hours[j]) || Students[i].course.hours[j] < 1) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter the student's number of courses as a whole number greater than 0: ";
            }
        }
    }
}

int calculateHours(Student Students) {
    int totalHours = 0;

    for (int j=0; j < Students.course.courses; j++) {
        totalHours+=((Students.course.hours[j]*3) + Students.course.hours[j]);
    }

    return totalHours;
}
