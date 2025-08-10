#include <stdio.h>
#include <stdlib.h>

// ascending
int compareAsc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// descending
int compareDesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// Condition
const char* twoArrays(int A[], int B[], int n, int k) {
    // Sort A ascending, B descending
    qsort(A, n, sizeof(int), compareAsc);
    qsort(B, n, sizeof(int), compareDesc);

    // Check condition for every index
    for (int i = 0; i < n; i++) {
        if (A[i] + B[i] < k) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int q;
    scanf("%d", &q); //  queries

    while (q--) {
        int n, k;
        scanf("%d %d", &n, &k);

        int A[n], B[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &B[i]);
        }

        printf("%s\n", twoArrays(A, B, n, k));
    }
    return 0;
}