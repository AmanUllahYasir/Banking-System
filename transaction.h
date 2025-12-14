#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "account.h"

bool deposit(Account *acc, double amount);
bool withdraw(Account *acc, double amount);
bool transfer(Account *from, Account *to, double amount);

void printTransaction(Transaction *t);

#endif
