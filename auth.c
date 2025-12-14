#include <stdio.h>
#include <string.h>
#include <openssl/sha.h> // Requires OpenSSL for SHA256
#include "auth.h"

// Hash password using SHA256
void hashPassword(const char *password, char *outputHash) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)password, strlen(password), hash);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(outputHash + (i * 2), "%02x", hash[i]);
    outputHash[HASH_SIZE - 1] = '\0';
}

// Verify password
bool verifyPassword(const char *password, const char *storedHash) {
    char hash[HASH_SIZE];
    hashPassword(password, hash);
    return strcmp(hash, storedHash) == 0;
}
