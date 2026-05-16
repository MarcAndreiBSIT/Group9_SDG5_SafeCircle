#include "safety.h"
#include "validation.h"
#include <thread>
#include <chrono>

using namespace std;

// activates panic alert message
void panicAlert() {

    cout << "\n!!! PANIC ALERT ACTIVATED !!!\n";
    cout << "Emergency contacts notified.\n";
}

// starts safety countdown timer
void safetyTimer(string userPin) {

    int timer = 10;
    string pin;

    cout << "\nSafety Timer Started...\n";

    while (timer > 0) {

        cout << "Time left: " << timer << " seconds\n";

        this_thread::sleep_for(chrono::seconds(1));

        timer--;
    }

    cout << "\nTimer Ended!\n";

    cout << "Enter 4-digit PIN to deactivate: ";
    cin >> pin;

    if (pin == userPin) {

        cout << "\nTimer Deactivated Successfully.\n";
    }

    else {

        cout << "\nUSER AT RISK!\n";
    }
}

// displays nearest safe location
void nearestSafeLocation() {

    int zone;

    cout << "\nSelect Zone\n";
    cout << "1. North\n";
    cout << "2. South\n";
    cout << "3. East\n";
    cout << "4. West\n";
    cout << "Enter choice: ";
    cin >> zone;

    switch (zone) {

    case 1:
        cout << "Nearest Safe Location: 7-Eleven North\n";
        break;

    case 2:
        cout << "Nearest Safe Location: Police Station South\n";
        break;

    case 3:
        cout << "Nearest Safe Location: Barangay Hall East\n";
        break;

    case 4:
        cout << "Nearest Safe Location: Hospital West\n";
        break;

    default:
        cout << "Invalid zone.\n";
    }
}

// displays safety reminders
void showSafetyTips() {

    cout << "\nSafety Tips\n";
    cout << "1. Stay in well-lit areas\n";
    cout << "2. Avoid walking alone at night\n";
    cout << "3. Keep emergency contacts ready\n";
    cout << "4. Stay alert in public places\n";
}

// =========================
// filehandler.h
// =========================

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "contact.h"

// saves contacts into text file
void saveContacts(Contact contacts[], int count);

// loads saved contacts from text file
void loadContacts(Contact contacts[], int& count);

#endif
