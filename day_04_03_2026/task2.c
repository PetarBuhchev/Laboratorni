//Да се въведе число и да се изведе съобщение, ако остатъка при деление с 8 е 4
#include <stdio.h>

int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);

    if (number % 8 == 4) {
        printf("The remainder when the number is divided by 8 is 4.\n");
    } else {
        printf("The remainder when the number is divided by 8 is not 4.\n");
    }

    return 0;
}