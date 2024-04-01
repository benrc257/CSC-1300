#include "dinofight.h"

/*
    Name: printArt()
    Purpose: Prints art at the beginning of the function
*/
void printArt()
{
	cout << endl << endl;
	cout << "########  #### ##    ##  #######     ######## ####  ######   ##     ## ######## ####\n"; 
	cout << "##     ##  ##  ###   ## ##     ##    ##        ##  ##    ##  ##     ##    ##    ####\n"; 
	cout << "##     ##  ##  ####  ## ##     ##    ##        ##  ##        ##     ##    ##    ####\n"; 
	cout << "##     ##  ##  ## ## ## ##     ##    ######    ##  ##   #### #########    ##     ##\n";  
	cout << "##     ##  ##  ##  #### ##     ##    ##        ##  ##    ##  ##     ##    ##\n";         
	cout << "##     ##  ##  ##   ### ##     ##    ##        ##  ##    ##  ##     ##    ##    ####\n"; 
	cout << "########  #### ##    ##  #######     ##       ####  ######   ##     ##    ##    ####\n";
	cout << endl;
}

/*
    Name: preloadDinos()
    Purpose: Loads in the data from the file (set by global constant FILENAME in dinofight.h)
    into the Dino[] array
*/
int preloadDinos(Dinos Dino[], int size) {
    //variables
    ifstream file;
    int total;

    //open FILENAME
    file.open(FILENAME);

    //returns error if the file cannot be opened
    if (!file.is_open()) {
        return -1;
    }

    //runs through the file and writes data to the array
    for (int i = 0; i < size, file.good(); i++) {
        getline(file, Dino[i].type, '#');
        getline(file, Dino[i].name, '#');
        file >> Dino[i].stats.hit;
        file.ignore();
        file >> Dino[i].stats.health;
        file.ignore();
        total = i;
    }

    //add one to the total, because i starts at 0 and total = i currently
    total++;

    //closes FILENAME
    file.close();

    //returns the current fill level of the array (number of loaded dinos)
    return total;
}

void printDinos(Dinos Dino[], int total) {
    //variables
    string lines(40, '-');

    //prints every dino in the array and their stats to the screen in a list
    cout << endl;
    for (int i=0; i < total; i++) {
        cout << lines << "| DINO FIGHTER " << i << " |" << lines << "\n";
        cout << "Name: " << Dino[i].name << "\n";
    }

}