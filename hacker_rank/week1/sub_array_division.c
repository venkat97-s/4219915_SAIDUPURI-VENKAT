#include <stdio.h>

int countWays(int arr[], int n, int d, int m) {
    int count = 0;
    for (int start = 0; start <= n - m; start++) { //for loop using
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += arr[start + j];
        }
        if (sum == d) {
            count++;
        }
    }
    return count; // returning the count value
}
int main() {
    int n;
    scanf("%d", &n);

    int squares[n];
    for (int i = 0; i < n; i++) { //using for loop
        scanf("%d", &squares[i]);
    }

    int d, m;
    scanf("%d %d", &d, &m);

    printf("%d\n", countWays(squares, n, d, m));
    return 0;
}