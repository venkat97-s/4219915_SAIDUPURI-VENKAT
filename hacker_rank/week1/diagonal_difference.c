#include <stdio.h>
#include <stdlib.h>

int diagonalDifference(int matrix[][100], int n) {
    int primarySum = 0, secondarySum = 0;

    for (int i = 0; i < n; i++) {
        primarySum += matrix[i][i];              // Left diagonal
        secondarySum += matrix[i][n - 1 - i];    // Right diagonal
    }
    return abs(primarySum - secondarySum);
}
int main() {
    int n;
    scanf("%d", &n);

    int arr[100][100]; // Max 100x100
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("%d\n", diagonalDifference(arr, n));
    return 0;
}
