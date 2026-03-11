//Напишете функция factorial и програма, кяот използва тази функция.
#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Факториалът на 0 и 1 е 1
    } else {
        return n * factorial(n - 1); // Рекурсивно извикване
    }
}

int main() {
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        int result = factorial(num);
        printf("The factorial of %d is %d\n", num, result);
    }

    return 0;
}