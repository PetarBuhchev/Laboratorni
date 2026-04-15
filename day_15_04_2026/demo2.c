#include <stdio.h>

struct complex {
    float real;
    float imag;
};

struct number {
    struct complex comp;
    int integer;
} num1;

int main() {
    num1.comp.real = 3.5;
    num1.comp.imag = 2.5;
    num1.integer = 10;

    printf("Complex number: %.2f + %.2fi\n", num1.comp.real, num1.comp.imag);
    printf("Integer: %d\n", num1.integer);

    return 0;
}