#include <stdio.h>
#include <string.h>
#include "transaction.h"
#include "utils.h"

// Deposit money
bool deposit(Account *acc, double amount) {
    if (amount <= 0) return false;

    acc->balance += amount;
    Transaction t;
    strcpy(t.type, "Deposit");
    t.amount = amount;
    t.targetAcc = 0;
    getCurrentDateTime(t.datetime, 20);
    acc->transactions[acc->transactionCount++] = t;

    printf("Deposited %.2lf successfully!\n", amount);
    return true;
}

// Withdraw money
bool withdraw(Account *acc, double amount) {
    if (amount <= 0 || amount > acc->balance) return false;

    acc->balance -= amount;
    Transaction t;
    strcpy(t.type, "Withdraw");
    t.amount = amount;
    t.targetAcc = 0;
    getCurrentDateTime(t.datetime, 20);
    acc->transactions[acc->transactionCount++] = t;

    printf("Withdrawn %.2lf successfully!\n", amount);
    return true;
}

// Transfer money
bool transfer(Account *from, Account *to, double amount) {
    if (amount <= 0 || amount > from->balance) return false;

    from->balance -= amount;
    to->balance += amount;

    Transaction t1;
    strcpy(t1.type, "TransferOut");
    t1.amount = amount;
    t1.targetAcc = to->accNumber;
    getCurrentDateTime(t1.datetime, 20);
    from->transactions[from->transactionCount++] = t1;

    Transaction t2;
    strcpy(t2.type, "TransferIn");
    t2.amount = amount;
    t2.targetAcc = from->accNumber;
    getCurrentDateTime(t2.datetime, 20);
    to->transactions[to->transactionCount++] = t2;

    printf("Transferred %.2lf to account %d successfully!\n", amount, to->accNumber);
    return true;
}

// Print a single transaction
void printTransaction(Transaction *t) {
    printf("[%s] %s %.2lf", t->datetime, t->type, t->amount);
    if (t->targetAcc) printf(" Target Acc: %d", t->targetAcc);
    printf("\n");
}
