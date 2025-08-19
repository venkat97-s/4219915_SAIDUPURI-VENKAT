#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long check = n;
    int zeros = 0;

    // count how many bits are 0 in binary form of n
    while (check > 0) {
        if ((check % 2) == 0) {   // remainder check instead of bitwise
            zeros++;
        }
        check /= 2;
    }

    // answer is 2^zeros
    long long ways = 1;
    for (int i = 0; i < zeros; i++) {
        ways *= 2;
    }

    printf("%lld\n", ways);
    return 0;
}