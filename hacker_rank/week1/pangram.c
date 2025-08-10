#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TOTAL_LETTERS 26

// FUNCTION CHECK
const char* pangrams(const char *text) {
    int seen[TOTAL_LETTERS] = {0};
    int foundCount = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            int index = tolower(text[i]) - 'a';
            if (!seen[index]) {
                seen[index] = 1;
                foundCount++;
                if (foundCount == TOTAL_LETTERS) {
                    return "pangram";
                }
            }
        }
    }

    return "not pangram";
}
