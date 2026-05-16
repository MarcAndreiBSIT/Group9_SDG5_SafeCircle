#include <iostream>
#include <string>
#include <limits>
#include "contact.h"
#include "validation.h"
#include "safety.h"
#include "filehandler.h"

using namespace std;

// maximum number of contacts
const int MAX = 20;

// global profile variables
string userName;
int userAge;
string userPin;

// array of contact objects
Contact contacts[MAX];

// counts total contacts
int contactCount = 0;

// displays menu options
void showMenu();

// creates user profile
void createProfile();

// displays saved profile
void viewProfile();

// adds new emergency contact
void addContact(int& count);

// displays all saved contacts
void viewContacts(int count);

// searches contact using name
void searchContact(int count);

// updates selected contact
void updateContact(int count);

// deletes selected contact
void deleteContact(int& count);

// pauses the screen
void pauseScreen();

// main function of the program
int main() {

    int choice;

    // loads saved contacts from file
    loadContacts(contacts, contactCount);

    do {

        // displays menu
        showMenu();

        cin >> choice;

        // validates menu input
        if (cin.fail()) {

            cin.clear();
            cin.ignore(1000, '\n');

            cout << "\nInvalid input.\n";
            continue;
        }

        // menu navigation
        switch (choice) {

        case 1:
            createProfile();
            break;

        case 2:
            viewProfile();
            break;

        case 3:
            addContact(contactCount);
            break;

        case 4:
            viewContacts(contactCount);
            break;

        case 5:
            searchContact(contactCount);
            break;

        case 6:
            updateContact(contactCount);
            break;

        case 7:
            deleteContact(contactCount);
            break;

        case 8:
            panicAlert();
            break;

        case 9:
            safetyTimer(userPin);
            break;

        case 10:
            nearestSafeLocation();
            break;

        case 11:
            showSafetyTips();
            break;

        case 12:
            saveContacts(contacts, contactCount);
            cout << "\nProgram Closed.\n";
            break;

        default:
            cout << "\nInvalid choice.\n";
        }

        pauseScreen();

    } while (choice != 12);

    return 0;
}

// pauses screen until enter is pressed
void pauseScreen() {

    cout << "\nPress ENTER to continue...";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// displays menu options
void showMenu() {

    cout << "\n===== SAFECIRCLE SYSTEM =====\n";
    cout << "1. Create Profile\n";
    cout << "2. View Profile\n";
    cout << "3. Add Contact\n";
    cout << "4. View Contacts\n";
    cout << "5. Search Contact\n";
    cout << "6. Update Contact\n";
    cout << "7. Delete Contact\n";
    cout << "8. Panic Alert\n";
    cout << "9. Safety Timer\n";
    cout << "10. Nearest Safe Location\n";
    cout << "11. Safety Tips\n";
    cout << "12. Exit\n";
    cout << "Enter Choice: ";
}

// creates and saves user profile
void createProfile() {

    cin.ignore();

    cout << "\nEnter Name: ";
    getline(cin, userName);

    while (!isValidName(userName)) {

        cout << "Invalid name. Enter again: ";
        getline(cin, userName);
    }

    cout << "Enter Age: ";
    cin >> userAge;

    cin.ignore();

    cout << "Enter 4-digit PIN: ";
    getline(cin, userPin);

    while (!isValidPin(userPin)) {

        cout << "Invalid PIN. Enter 4 digits only: ";
        getline(cin, userPin);
    }

    cout << "\nProfile Created Successfully!\n";
}

// displays saved user profile
void viewProfile() {

    cout << "\n--- USER PROFILE ---\n";

    if (userName.empty()) {

        cout << "No profile found.\n";
    }

    else {

        cout << "Name: " << userName << endl;
        cout << "Age: " << userAge << endl;
    }
}

// adds new emergency contact
void addContact(int& count) {

    string name;
    string number;

    if (count >= MAX) {

        cout << "\nContact List Full.\n";
        return;
    }

    cin.ignore();

    cout << "\nEnter Contact Name: ";
    getline(cin, name);

    while (!isValidName(name)) {

        cout << "Invalid Name. Enter Again: ";
        getline(cin, name);
    }

    cout << "Enter Contact Number: ";
    getline(cin, number);

    while (!isNumber(number)) {

        cout << "Invalid Number. Enter Digits Only: ";
        getline(cin, number);
    }

    contacts[count].setContact(name, number);

    count++;

    cout << "\nContact Added Successfully!\n";
}

// displays all saved contacts
void viewContacts(int count) {

    cout << "\n--- CONTACT LIST ---\n";

    if (count == 0) {

        cout << "No contacts found.\n";
    }

    else {

        for (int i = 0; i < count; i++) {

            cout << i + 1 << ". "
                << contacts[i].getName()
                << " - "
                << contacts[i].getNumber()
                << endl;
        }
    }
}

// searches contact using name
void searchContact(int count) {

    string searchName;
    bool found = false;

    cin.ignore();

    cout << "\nEnter Contact Name to Search: ";
    getline(cin, searchName);

    for (int i = 0; i < count; i++) {

        if (contacts[i].getName() == searchName) {

            cout << "\nContact Found!\n";

            cout << contacts[i].getName()
                << " - "
                << contacts[i].getNumber()
                << endl;

            found = true;
        }
    }

    if (found == false) {

        cout << "\nContact Not Found.\n";
    }
}

// updates contact information
void updateContact(int count) {

    int number;
    string newName;
    string newContact;

    viewContacts(count);

    if (count == 0) {
        return;
    }

    cout << "\nEnter Contact Number to Update: ";
    cin >> number;

    if (number >= 1 && number <= count) {

        cin.ignore();

        cout << "Enter New Name: ";
        getline(cin, newName);

        cout << "Enter New Number: ";
        getline(cin, newContact);

        contacts[number - 1].setContact(newName, newContact);

        cout << "\nContact Updated Successfully!\n";
    }

    else {

        cout << "\nInvalid Contact Number.\n";
    }
}

// deletes selected contact
void deleteContact(int& count) {

    int number;
    char confirm;

    viewContacts(count);

    if (count == 0) {
        return;
    }

    cout << "\nEnter Contact Number to Delete: ";
    cin >> number;

    if (number >= 1 && number <= count) {

        cout << "Are you sure? (Y/N): ";
        cin >> confirm;

        if (confirm == 'Y' || confirm == 'y') {

            for (int i = number - 1; i < count - 1; i++) {

                contacts[i] = contacts[i + 1];
            }

            count--;

            cout << "\nContact Deleted Successfully!\n";
        }

        else {

            cout << "\nDelete Cancelled.\n";
        }
    }

    else {

        cout << "\nInvalid Contact Number.\n";
    }
}
