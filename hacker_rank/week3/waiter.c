#include <stdio.h>
#include <math.h>

#define MAX 50000

int isPrime(int num) {  //using int
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0) return 0;
    return 1;
}

void generatePrimes(int primes[], int q) {
    int num = 2, count = 0;
    while (count < q) {
        if (isPrime(num)) {
            primes[count++] = num;
        }
        num++;
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int A[MAX], A_next[MAX], B[MAX];
    int topA = n - 1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]); 
    }

    int primes[q];
    generatePrimes(primes, q);

    for (int i = 0; i < q; i++) {
        int topB = -1;
        int topA_next = -1;

        while (topA >= 0) {
            int plate = A[topA--];
            if (plate % primes[i] == 0) {
                B[++topB] = plate;
            } else {
                A_next[++topA_next] = plate;
            }
        }

        while (topB >= 0) {
            printf("%d\n", B[topB--]);
        }
        topA = topA_next;
        for (int j = 0; j <= topA_next; j++) {
            A[j] = A_next[j];
        }
    }
    while (topA >= 0) {
        printf("%d\n", A[topA--]);
    }

    return 0;
}