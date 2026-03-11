//Напишете програма, която по три въведени от потребителя цели числа определя чрез потребителски функции: сумата от числата, най-малкото от трите числа, най-голямото от трите числа и средното аритметично на трите числа.
#include <stdio.h>

int sum(int a, int b, int c) {
    return a + b + c;
}

int min(int a, int b, int c) {
    int result = a;
    if (b < result) result = b;
    if (c < result) result = c;
    return result;
}

int max(int a, int b, int c) {
    int result = a;
    if (b > result) result = b;
    if (c > result) result = c;
    return result;
}

float average(int a, int b, int c) {
    return (float)(a + b + c) / 3;
}

int main() {
    int x, y, z;
    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);

    printf("Sum: %d\n", sum(x, y, z));
    printf("Minimum: %d\n", min(x, y, z));
    printf("Maximum: %d\n", max(x, y, z));
    printf("Average: %.2f\n", average(x, y, z));

    return 0;
}