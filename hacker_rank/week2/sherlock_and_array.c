#include <stdio.h>

int main() {
    int testCases;
    scanf("%d", &testCases);

    while (testCases--) {
        int size;
        scanf("%d", &size);

        long long numbers[100005];
        long long totalSum = 0;

        // read and calculate sum simultaneously
        for (int i = 0; i < size; i++) {
            scanf("%lld", &numbers[i]);
            totalSum += numbers[i];
        }

        long long sumLeft = 0;
        int isBalanced = 0;

        for (int i = 0; i < size; i++) {
            long long sumRight = totalSum - sumLeft - numbers[i];
            if (sumLeft == sumRight) {
                isBalanced = 1;
                break;
            }
            sumLeft += numbers[i];
        }

        if (isBalanced)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
