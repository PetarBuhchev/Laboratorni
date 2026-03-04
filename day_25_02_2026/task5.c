#include <stdio.h>
int main() {
    double a,b;
    scanf("%lf", &a);
    scanf("%lf", &b);
    printf("%.3f\n", a + b);
    printf("%.3f\n", a - b);
    printf("%.3f\n", a * b);
    return 0;
}