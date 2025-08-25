#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[100005];
    int letters[26] = {0};      // frequency of each character
    int freqCount[100005] = {0}; // how many characters have a given frequency
    int len, i;

    // Input string
    scanf("%s", str);
    len = strlen(str);

    // Count frequency of each character
    for (i = 0; i < len; i++) {
        letters[str[i] - 'a']++;
    }

    // Count how many times each frequency occurs
    for (i = 0; i < 26; i++) {
        if (letters[i] > 0) {
            freqCount[letters[i]]++;
        }
    }

    int f1 = 0, f2 = 0; // two distinct frequencies
    int c1 = 0, c2 = 0; // how many characters have them

    for (i = 1; i <= len; i++) {
        if (freqCount[i] > 0) {
            if (f1 == 0) {
                f1 = i; 
                c1 = freqCount[i];
            } else if (f2 == 0) {
                f2 = i; 
                c2 = freqCount[i];
            } else {
                printf("NO\n");
                return 0;
            }
        }
    }

    // Cases for a valid string
    if (f2 == 0) {
        printf("YES\n");
    } 
    else if (c2 == 1 && (f2 - f1 == 1 || f2 == 1)) {
        printf("YES\n");
    } 
    else if (c1 == 1 && (f1 - f2 == 1 || f1 == 1)) {
        printf("YES\n");
    } 
    else {
        printf("NO\n");
    }

    return 0;
}
