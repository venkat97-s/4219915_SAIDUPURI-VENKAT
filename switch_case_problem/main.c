#include <stdio.h>

int main() {
    int day;
    printf("Enter any day between 1 to 7: ");
    scanf("%d", &day);

    while(day < 1 || day > 7) {
        printf("Enter Correct choice\n");
        printf("Enter any day between 1 to 7: ");
        scanf("%d", &day);
    }

    switch(day) {
        case 1: printf("Monday\n"); break;
        case 2: printf("Tuesday\n"); break;
        case 3: printf("Wednesday\n"); break;
        case 4: printf("Thursday\n"); break;
        case 5: printf("Friday\n"); break;
        case 6: printf("Saturday\n"); break;
        case 7: printf("Sunday\n"); break;
    }

    return 0;
}