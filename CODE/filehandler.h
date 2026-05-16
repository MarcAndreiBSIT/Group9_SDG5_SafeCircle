#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "contact.h"

// saves contacts into text file
void saveContacts(Contact contacts[], int count);

// loads saved contacts from text file
void loadContacts(Contact contacts[], int& count);

#endif
