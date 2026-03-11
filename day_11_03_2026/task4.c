//Напишете функция, която проверява дали дадено число е четно или нечетно.
#include <stdio.h>
int isEven(int number) {
    if (number % 2 == 0) {
        return 1; // Числото е четно
    } else {
        return 0; // Числото е нечетно
    }
}
int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);

    if (isEven(number)) {
        printf("The number %d is even.\n", number);
    } else {
        printf("The number %d is odd.\n", number);
    }

    return 0;
}