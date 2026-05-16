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

    if (name.empty()) {
        return false;
    }

    return true;
}
