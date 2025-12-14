#ifndef AUTH_H
#define AUTH_H

#include <stdbool.h>

#define HASH_SIZE 65  // SHA256 hash hex string

// Hash a password into SHA256 hex string
void hashPassword(const char *password, char *outputHash);

// Verify password against stored hash
bool verifyPassword(const char *password, const char *storedHash);

#endif
