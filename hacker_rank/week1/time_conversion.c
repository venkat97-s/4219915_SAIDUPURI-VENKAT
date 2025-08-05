#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void timeConversion(char* time12) {
    char hourStr[3];
    int hour;
    strncpy(hourStr, time12, 2);
    hourStr[2] = '\0';
    hour = atoi(hourStr);
    if (strstr(time12, "AM")) {
        if (hour == 12) {
            hour = 0;
        }
    } else if (strstr(time12, "PM")) {
        if (hour != 12) {
            hour += 12;
        }
    }
    printf("%02d:%c%c:%c%c\n", hour, time12[3], time12[4], time12[6], time12[7]);
}

int main() {
    char time12[11];
    scanf("%s", time12);

    timeConversion(time12);

    return 0;
}
