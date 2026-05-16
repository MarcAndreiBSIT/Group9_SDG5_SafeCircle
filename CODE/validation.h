#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
#include <string>
using namespace std;

// checks if input is number only
bool isNumber(string text);

// validates 4-digit pin
bool isValidPin(string pin);

// checks if name is not empty
bool isValidName(string name);

#endif
