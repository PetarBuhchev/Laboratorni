//Да се напише програма, която прочита две реални числа и извежда стойностите на функция f(x) = x*x+4 за всички стойности в дадения интервал. Стъпката за обхождане е 0.01.
#include <stdio.h>

int main() {
    double num1, num2;
    
    printf("Enter two real numbers: ");
    scanf("%lf %lf", &num1, &num2);
    
    // Ensure num1 is the smaller number
    if (num1 > num2) {
        double temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    printf("f(x) = x*x + 4 for values between %.2lf and %.2lf:\n", num1, num2);
    
    for (double x = num1; x <= num2; x += 0.01) {
        double fx = x * x + 4; // Calculate f(x)
        printf("f(%.2lf) = %.4lf\n", x, fx);
    }
    
    return 0;
}