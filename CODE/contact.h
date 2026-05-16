#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
using namespace std;

// contact class for storing contact details
class Contact {

private:
    string name;
    string number;

public:

    // constructor for contact class
    Contact();

    // stores contact information
    void setContact(string n, string num);

    // returns contact name
    string getName();

    // returns contact number
    string getNumber();
};

#endif
