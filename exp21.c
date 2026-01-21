#include <stdio.h>

int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    switch ((year % 4 == 0) * 2 + (year % 100 == 0) * 1) {
        case 0: case 2:         // Divisible by 4, not by 100 → leap
            printf("%d is a leap year.\n", year);
            break;
        case 3:                 // Divisible by 100, check 400
            if (year % 400 == 0)
                printf("%d is a leap year.\n", year);
            else
                printf("%d is not a leap year.\n", year);
            break;
        case 1:                 // Not divisible by 4 → not leap
            printf("%d is not a leap year.\n", year);
            break;
    }

    return 0;
}

