#ifndef FILE_H
#define FILE_H

#include "account.h"

void saveAccounts(Account accounts[], int count);
int loadAccounts(Account accounts[]);

#endif
