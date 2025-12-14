#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdbool.h>

#define MAX_NAME 50
#define MAX_ACCOUNTS 1000
#define MAX_TRANSACTIONS 1000
#define PASSWORD_HASH_SIZE 65

typedef struct {
    char type[10];  // Deposit, Withdraw, Transfer
    double amount;
    char datetime[20];
    int targetAcc;  // For transfer, 0 otherwise
} Transaction;

typedef struct {
    int accNumber;
    char name[MAX_NAME];
    char password[PASSWORD_HASH_SIZE];
    double balance;
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;
} Account;

// Account management functions
bool createAccount(Account accounts[], int *count);
bool login(Account accounts[], int count, int *index);
void viewAccount(Account *acc);
void editAccount(Account *acc);

#endif
