#include <stdio.h>

// helper: check if value is power of 2
int isPow2(unsigned long long x) {
    return (x > 0) && ((x & (x - 1)) == 0);
}

// helper: find nearest smaller/equal power of 2
unsigned long long nearestPow2(unsigned long long x) {
    unsigned long long val = 1;
    while (val * 2ULL <= x) {
        val *= 2ULL;
    }
    return val;
}

int main() {
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        unsigned long long n;
        scanf("%llu", &n);

        int moves = 0;  // track number of turns

        while (n > 1) {
            if (isPow2(n)) {
                n /= 2;
            } else {
                n -= nearestPow2(n);
            }
            moves++;
        }

        if (moves % 2 == 1) {
            printf("Louise\n");
        } else {
            printf("Richard\n");
        }
    }

    return 0;
}
