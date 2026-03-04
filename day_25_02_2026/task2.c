#include <stdio.h>

int main() {
    double diameter;
    scanf("%lf", &diameter);
    double radius = diameter / 2.0;
    double area = 3.14159 * radius * radius;
    printf("%lf\n", area);
    return 0;
}