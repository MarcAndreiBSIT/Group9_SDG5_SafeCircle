#ifndef SAFETY_H
#define SAFETY_H

#include <iostream>
#include <string>
using namespace std;

// activates panic alert
void panicAlert();

// starts safety countdown timer
void safetyTimer(string userPin);

// displays nearest safe location
void nearestSafeLocation();

// displays safety reminders
void showSafetyTips();

#endif
