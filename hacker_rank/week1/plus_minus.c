#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int numbers[n];
    int positives = 0, negatives = 0, zeros = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < n; i++) {
        if (numbers[i] > 0) {
            positives++;
        } else if (numbers[i] < 0) {
            negatives++;
        } else {
            zeros++;
        }
    }

    double positive_ratio = (double)positives / n;
    double negative_ratio = (double)negatives / n;
    double zero_ratio = (double)zeros / n;

    printf("%.6lf\n", positive_ratio);
    printf("%.6lf\n", negative_ratio);
    printf("%.6lf\n", zero_ratio);

    return 0;
}