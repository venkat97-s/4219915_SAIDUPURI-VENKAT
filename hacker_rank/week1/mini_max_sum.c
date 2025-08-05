#include <stdio.h>

int main() {
    long numbers[5];
    long total = 0;
    long min, max;
    for (int i = 0; i < 5; i++) {
        scanf("%ld", &numbers[i]);
        total += numbers[i];
    }
    min = total - numbers[0];
    max = total - numbers[0];
    for (int i = 1; i < 5; i++) {
        long current = total - numbers[i];
        if (current < min) min = current;
        if (current > max) max = current;
    }
    printf("%ld %ld\n", min, max);
    return 0;
}