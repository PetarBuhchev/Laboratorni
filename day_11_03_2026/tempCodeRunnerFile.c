//Напишете функция за решаване на квадратно уравнение.
#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

void solveQuadratic(float a, float b, float c) {
    float discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        float root1 = (-b + sqrt(discriminant)) / (2 * a);
        float root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("The roots are real and different: %.2f and %.2f\n", root1, root2);
    } else if (discriminant == 0) {
        float root = -b / (2 * a);
        printf("The roots are real and the same: %.2f\n", root);
    } else {
        printf("The roots are complex and different.\n");
    }
}

int main() {
    float a, b, c;
    printf("Enter coefficients a, b, and c for the quadratic equation ax^2 + bx + c = 0: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0) {
        printf("Coefficient a cannot be zero for a quadratic equation.\n");
    } else {
        solveQuadratic(a, b, c);
    }

    return 0;
}