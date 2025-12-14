#include <stdio.h>
#include "account.h"
#include "transaction.h"
#include "file.h"
#include "utils.h"

int main() {
    Account accounts[MAX_ACCOUNTS];
    int count = loadAccounts(accounts);

    int choice;
    int loggedIndex = -1;

    do {
        printf("\n--- Secure Banking System ---\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &count);
                saveAccounts(accounts, count);
                break;
            case 2:
                if (login(accounts, count, &loggedIndex)) {
                    int userChoice;
                    do {
                        printf("\n1. View Account\n2. Edit Name\n3. Deposit\n4. Withdraw\n5. Transfer\n6. View Transactions\n7. Logout\nChoice: ");
                        scanf("%d", &userChoice);
                        Account *acc = &accounts[loggedIndex];

                        switch(userChoice) {
                            case 1: viewAccount(acc); break;
                            case 2: editAccount(acc); saveAccounts(accounts, count); break;
                            case 3: {
                                double amt; printf("Amount: "); scanf("%lf", &amt);
                                if (deposit(acc, amt)) saveAccounts(accounts, count); break;
                            }
                            case 4: {
                                double amt; printf("Amount: "); scanf("%lf", &amt);
                                if (withdraw(acc, amt)) saveAccounts(accounts, count); break;
                            }
                            case 5: {
                                double amt; int target;
                                printf("Target Account Number: "); scanf("%d", &target);
                                printf("Amount: "); scanf("%lf", &amt);
                                int targetIndex = -1;
                                for (int i=0;i<count;i++) if(accounts[i].accNumber==target) targetIndex=i;
                                if(targetIndex!=-1 && transfer(acc, &accounts[targetIndex], amt)) saveAccounts(accounts, count);
                                else printf("Invalid target account!\n");
                                break;
                            }
                            case 6: 
                                for(int i=0;i<acc->transactionCount;i++) printTransaction(&acc->transactions[i]); 
                                break;
                            case 7: printf("Logged out.\n"); break;
                        }
                    } while(userChoice != 7);
                }
                break;
            case 3:
                saveAccounts(accounts, count);
                printf("Exiting system. Goodbye!\n");
                break;
        }
    } while(choice != 3);

    return 0;
}
