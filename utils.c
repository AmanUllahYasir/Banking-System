#include <stdio.h>
#include <time.h>
#include "utils.h"

// Clear stdin buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}

// Get current timestamp string
void getCurrentDateTime(char *buffer, int size) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(buffer, size, "%04d-%02d-%02d %02d:%02d:%02d",
             tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,
             tm.tm_hour, tm.tm_min, tm.tm_sec);
}
