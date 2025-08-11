#include <stdio.h>
#include <string.h>

#define MAX_UNIQUE 1000   //  unique words allowed
#define WORD_SIZE  50     //  length for a single word

typedef struct {
    char text[WORD_SIZE];
    int frequency;
} WordData;

int main() {
    int totalWords, totalQueries;
    WordData wordList[MAX_UNIQUE];
    int distinctCount = 0;

    scanf("%d", &totalWords);

    // Read each word and update its frequency
    for (int i = 0; i < totalWords; i++) {
        char currentWord[WORD_SIZE];
        scanf("%s", currentWord);

        int exists = 0;
        for (int j = 0; j < distinctCount; j++) {
            if (strcmp(wordList[j].text, currentWord) == 0) {
                wordList[j].frequency++;
                exists = 1;
                break;
            }
        }

        if (!exists && distinctCount < MAX_UNIQUE) {
            strcpy(wordList[distinctCount].text, currentWord);
            wordList[distinctCount].frequency = 1;
            distinctCount++;
        }
    }

    scanf("%d", &totalQueries);

    
    for (int i = 0; i < totalQueries; i++) {
        char queryWord[WORD_SIZE];
        scanf("%s", queryWord);

        int matchFound = 0;
        for (int j = 0; j < distinctCount; j++) {
            if (strcmp(wordList[j].text, queryWord) == 0) {
                printf("%d\n", wordList[j].frequency);
                matchFound = 1;
                break;
            }
        }
        if (!matchFound) {
            printf("0\n");
        }
    }

    return 0;
}