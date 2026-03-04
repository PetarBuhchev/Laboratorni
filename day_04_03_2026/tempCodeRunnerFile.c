//Да се прочете едно число от 1 до 7 и да се изведе на екрана кой ден от седмицата съответства на това число. Да се използва switch оператор.
#include <stdio.h>

int main() {
    int day;
    printf("Enter a number (1-7) to find out the corresponding day of the week: ");
    scanf("%d", &day);

    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid input. Please enter a number between 1 and 7.\n");
    }

    return 0;
}