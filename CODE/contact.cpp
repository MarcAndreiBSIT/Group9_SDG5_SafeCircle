#include "contact.h"

// initializes contact object
Contact::Contact() {

    name = "";
    number = "";
}

// saves contact information
void Contact::setContact(string n, string num) {

    name = n;
    number = num;
}

// returns saved contact name
string Contact::getName() {

    return name;
}

// returns saved contact number
string Contact::getNumber() {

    return number;
}
