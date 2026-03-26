#include <stdio.h>

float Sum(float a, float b) {
    return a + b;
}

int main() {
    float a,b;
    scanf("%f %f", &a, &b);
    float result = Sum(a, b);
    printf("The sum of %.2f and %.2f is %.2f\n", a, b, result);
    return 0;
}