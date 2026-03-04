//Да се прочетат 3 числа и да се изведе най-малкото от тях.
#include <stdio.h>

int main() {
    int num1, num2, num3;
    printf("Enter three integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int min = num1;

    if (num2 < min) {
        min = num2;
    }
    if (num3 < min) {
        min = num3;
    }

    printf("The smallest number is: %d\n", min);
    return 0;
}