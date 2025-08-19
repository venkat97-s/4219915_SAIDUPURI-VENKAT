#include <stdio.h>
#include <stdlib.h>

// helper function for qsort
int sorter(const void *x, const void *y) {
    return (*(int*)x - *(int*)y);
}

int main() {
    int size, window;
    scanf("%d", &size);
    scanf("%d", &window);

    int numbers[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    // sort array so nearby elements are closest
    qsort(numbers, size, sizeof(int), sorter);

    int answer = 1000000000; // big initial number
    for (int start = 0; start + window - 1 < size; start++) {
        int end = start + window - 1;
        int diff = numbers[end] - numbers[start];
        if (diff < answer) {
            answer = diff;
        }
    }

    printf("%d\n", answer);
    return 0;
}
