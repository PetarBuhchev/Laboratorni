//Да се въведе цяло число и да се изведе съобщение ако то е по голямо от 6
#include <stdio.h>

int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);

    if (number > 6) {
        printf("The number is greater than 6.\n");
    } else {
        printf("The number is not greater than 6.\n");
    }

    return 0;
}