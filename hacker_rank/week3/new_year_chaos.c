#include <stdio.h>
#include <stdlib.h>

void countBribes(int size, int *arr) {
    long long bribes = 0;

    // Check if any person has moved more than 2 places forward
    for (int i = 0; i < size; i++) {
        if (arr[i] - (i + 1) > 2) {
            printf("Too chaotic\n");
            return;
        }
    }

    // Count total bribes
    for (int i = size - 1; i >= 0; i--) {
        int start = arr[i] - 2;
        if (start < 0) start = 0;

        for (int j = start; j < i; j++) {
            if (arr[j] > arr[i]) {
                bribes++;
            }
        }
    }

    printf("%lld\n", bribes);
}

int main() {
    int test_cases;
    scanf("%d", &test_cases);

    while (test_cases--) {
        int n;
        scanf("%d", &n);

        int *line = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &line[i]);
        }

        countBribes(n, line);

        free(line);
    }

    return 0;
}
