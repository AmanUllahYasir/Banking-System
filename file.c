#include <stdio.h>
#include "file.h"

#define FILE_NAME "bank.dat"

void saveAccounts(Account accounts[], int count) {
    FILE *f = fopen(FILE_NAME, "wb");
    if (!f) {
        printf("Error saving file!\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, f);
    fwrite(accounts, sizeof(Account), count, f);
    fclose(f);
}

int loadAccounts(Account accounts[]) {
    FILE *f = fopen(FILE_NAME, "rb");
    int count = 0;
    if (f) {
        fread(&count, sizeof(int), 1, f);
        fread(accounts, sizeof(Account), count, f);
        fclose(f);
    }
    return count;
}
