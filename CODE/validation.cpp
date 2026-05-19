#include "validation.h"
#include <cctype>

// checks if input contains numbers only
bool isNumber(string text) {

    for (int i = 0; i < text.length(); i++) {

        if (!isdigit(text[i])) {
            return false;
        }
    }

    return true;
}

// validates 4-digit pin
bool isValidPin(string pin) {

    if (pin.length() != 4) {
        return false;
    }

    return isNumber(pin);
}

// checks if name is not empty
bool isValidName(string name) {

    // checks if name is empty
    if (name.empty()) {
        return false;
    }

    // checks every character
    for (int i = 0; i < name.length(); i++) {

        // allows letters and spaces only
        if (!isalpha(name[i]) && name[i] != ' ') {

            return false;
        }
    }

    return true;

