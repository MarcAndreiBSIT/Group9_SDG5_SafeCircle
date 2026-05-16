#include "filehandler.h"
#include <fstream>

void saveContacts(Contact contacts[], int count) {

    ofstream file("contacts.txt");

    for (int i = 0; i < count; i++) {

        file << contacts[i].getName() << endl;
        file << contacts[i].getNumber() << endl;
    }

    file.close();
}

void loadContacts(Contact contacts[], int& count) {

    ifstream file("contacts.txt");

    string name;
    string number;

    while (getline(file, name)) {

        getline(file, number);

        contacts[count].setContact(name, number);

        count++;
    }

    file.close();
}
