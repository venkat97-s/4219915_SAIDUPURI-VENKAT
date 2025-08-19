#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// simple bubble sort for a string (instead of qsort)
void sortRow(char *row) {
    int len = strlen(row);
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (row[j] > row[j + 1]) {
                char tmp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int tests;
    scanf("%d", &tests);

    while (tests--) {
        int n;
        scanf("%d", &n);

        char matrix[n][101];
        for (int i = 0; i < n; i++) {
            scanf("%s", matrix[i]);
            sortRow(matrix[i]);   // sort each row immediately
        }

        int ok = 1;
        int width = strlen(matrix[0]);

        // check columns
        for (int col = 0; col < width && ok; col++) {
            for (int row = 1; row < n; row++) {
                if (matrix[row][col] < matrix[row - 1][col]) {
                    ok = 0;
                    break;
                }
            }
        }

        if (ok) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
