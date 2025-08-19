#include <stdio.h>

// function to calculate digit sum recursively
int findSuper(long long value) {
    if (value < 10) {
        return (int)value;  // base case
    }
    long long temp = 0;
    while (value > 0) {
        temp += value % 10;
        value /= 10;
    }
    return findSuper(temp);  // recursive call
}

int main() {
    char number[100005];
    long long repeat;
    scanf("%s %lld", number, &repeat);

    // compute sum of digits in the original number string
    long long baseSum = 0;
    for (int i = 0; number[i] != '\0'; i++) {
        baseSum += (number[i] - '0');
    }

    // account for repetition of string
    long long combined = baseSum * repeat;

    // final recursive digit sum
    int answer = findSuper(combined);
    printf("%d\n", answer);

    return 0;
}
