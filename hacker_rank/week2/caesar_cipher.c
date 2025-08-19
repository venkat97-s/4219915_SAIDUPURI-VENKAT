#include <stdio.h>

int main() {
    int length, shift;
    scanf("%d", &length);

    char text[length + 1];
    scanf("%s", text);

    scanf("%d", &shift);
    shift = shift % 26;   // keep within alphabet range

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        // process only alphabet letters
        if (c >= 'a' && c <= 'z') {
            int offset = c - 'a';
            c = 'a' + (offset + shift) % 26;
        } 
        else if (c >= 'A' && c <= 'Z') {
            int offset = c - 'A';
            c = 'A' + (offset + shift) % 26;
        }
        // non-letters remain unchanged

        putchar(c);
    }

    putchar('\n');
    return 0;
}