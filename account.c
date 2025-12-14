#include <stdio.h>
#include <string.h>
#include "account.h"
#include "auth.h"
#include "utils.h"

// Create a new account
bool createAccount(Account accounts[], int *count) {
    if (*count >= MAX_ACCOUNTS) {
        printf("Max accounts reached!\n");
        return false;
    }

    Account newAcc;
    newAcc.accNumber = (*count ? accounts[*count - 1].accNumber + 1 : 1001);

    printf("Enter name: ");
    clearInputBuffer();
    fgets(newAcc.name, MAX_NAME, stdin);
    newAcc.name[strcspn(newAcc.name, "\n")] = 0;

    char password[50];
    printf("Enter password: ");
    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = 0;

    hashPassword(password, newAcc.password);

    newAcc.balance = 0;
    newAcc.transactionCount = 0;

    accounts[*count] = newAcc;
    (*count)++;

    printf("Account created successfully! Account number: %d\n", newAcc.accNumber);
    return true;
}

// Login function
bool login(Account accounts[], int count, int *index) {
    int accNumber;
    char password[50];

    printf("Enter account number: ");
    scanf("%d", &accNumber);

    printf("Enter password: ");
    clearInputBuffer();
    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = 0;

    for (int i = 0; i < count; i++) {
        if (accounts[i].accNumber == accNumber &&
            verifyPassword(password, accounts[i].password)) {
            *index = i;
            printf("Login successful!\n");
            return true;
        }
    }
    printf("Invalid credentials!\n");
    return false;
}

// View account info
void viewAccount(Account *acc) {
    printf("Account Number: %d\n", acc->accNumber);
    printf("Name: %s\n", acc->name);
    printf("Balance: %.2lf\n", acc->balance);
    printf("Transactions: %d\n", acc->transactionCount);
}

// Edit account name
void editAccount(Account *acc) {
    printf("Current name: %s\n", acc->name);
    printf("Enter new name: ");
    clearInputBuffer();
    fgets(acc->name, MAX_NAME, stdin);
    acc->name[strcspn(acc->name, "\n")] = 0;
    printf("Name updated successfully!\n");
}
