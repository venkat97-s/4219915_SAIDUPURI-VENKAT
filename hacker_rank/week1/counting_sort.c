#include <stdio.h>

#define SIZE 100  //  possible value range (0 to 99)

int main() {
    int totalNumbers;
    int countArray[SIZE] = {0};  //  all counts to zero

    scanf("%d", &totalNumbers);

    // Read numbers and update their frequency
    for (int i = 0; i < totalNumbers; i++) {
        int value;
        scanf("%d", &value);
        if (value >= 0 && value < SIZE) {
            countArray[value]++;
        }
    }

    //  frequency array
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", countArray[i]);
    }

    return 0;
}
