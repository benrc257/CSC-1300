/*
	Title: Lab7.h
	Author: Benjamin Clark
	Date: 3/5/24
	Purpose: Teach 3rd to 6th grade students fun facts about animals. This
    file contains the main function.
*/
#include "Lab7.h"

int main() {
    //variables
    int choice, enter, score = 0;
    string stars(60,'*'), lines(40,'-');

    //displays menu and gets choice
    do {

        //displays menu
        cout << endl << stars << endl;
        choice = menu();

        //handles user's choice
        switch (choice) {
            case 1: cout << endl << lines << endl;
                    cout << "Naked Mole Rats: \n";
                    cout << "Naked mole-rats have wrinkly pink or grayish-pink skin, which is somewhat\n";
                    cout << "translucent on their undersides and light purplish-brown on their backs and tails.\n";
                    cout << "This countershading appears to be lost with advanced age. They have short,\n";
                    cout << "broad heads with powerful jaw muscles and very large incisors, which they use to dig tunnels.\n";
                    cout << lines;
                    cout << "\nFun Facts:\n";
                    cout << "1. They live up to 30 years.\n";
                    cout << "2. They are blind, but have keen senses of smell and can sense vibrations.\n";
                    cout << "3. Colonies of naked mole rats can be have up to 300 members.\n";
                    cout << lines;
                    break;
            case 2: cout << endl << lines << endl;
                    cout << "Peacock Mantis Shrimp: \n";
                    cout << "Peacock Mantis Shrimp mostly live in shallow parts of the Indian and Pacific Oceans.\n";
                    cout << "When it finds a delicious-looking snack, the animal goes into full-on boxer mode.\n";
                    cout << "Springing out one of its club-like front claws, the animal delivers a swift punch to its prey.\n";
                    cout << "The punch is 50 times faster than the blink of an eye and strong enough to break glass!\n";
                    cout << lines;
                    cout << "\nFun Facts:\n";
                    cout << "1. They mainly eat crabs and mollusks.\n";
                    cout << "2. They have vibrantly colored exoskeletons.\n";
                    cout << "3. They can grow to be the size of a butter knife.\n";
                    cout << lines;
                    break;
            case 3: cout << endl << lines << endl;
                    cout << "Orangutans: \n";
                    cout << "Known for their distinctive red fur, orangutans are the largest arboreal mammal,\n";
                    cout << "spending most of their time in trees. Long, powerful arms and grasping hands and\n";
                    cout << "feet allow them to move through the branches. These great apes share 96.4 percent of our\n";
                    cout << "genes and are highly intelligent creatures.\n";
                    cout << lines;
                    cout << "\nFun Facts:\n";
                    cout << "1. Adult male oragnutans can weigh up to 200 lbs.\n";
                    cout << "2. They can use their throat sacs to make loud calls.\n";
                    cout << "3. Only some male orangutans have the ability make these calls.\n";
                    cout << lines;
                    break;
        }
        if (choice != 4) {
            cout << "\nPress Enter to continue...";
            cin.get();
            cin.clear();
            cin.ignore(10000,'\n');
            test(score, choice);
        }
    } while (choice != 4);

    //ending message
    cout << "\nEnding program. Your final score was: " << score << "!";

    if (score > 2) {
        cout << " Amazing job!\n";
    } else {
        cout << " You still have more to learn.\n";
    }

    return 0;
}