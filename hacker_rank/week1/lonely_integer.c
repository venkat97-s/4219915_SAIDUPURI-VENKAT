#include <stdio.h>

int lonelyinteger(int arr[], int size) {
    int unique = 0;
    for (int i = 0; i < size; i++) { //using for loop
        unique = unique ^ arr[i];  
    }
    return unique;
}

int main() {
    int n;
    scanf("%d", &n); //using scanf condition 

    int numbers[n];
    for (int i = 0; i < n; i++) { //using for loop
        scanf("%d", &numbers[i]);
    }

    int result = lonelyinteger(numbers, n);
    printf("%d\n", result);

    return 0;
}
