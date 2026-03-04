//Да се напише програма която намира стойностите на функцията y(x) за всички стойности на x е даден интервал от стойности [beg;end] с крачка delta. Стойностите на beg, end, delta, m, a и b да реални числа.
//Забележка: При въвеждане на стойностите за beg и end е нужно да се направи проверка дали beg<end и ако това не е така да се поиска въвеждане на нова стойност само за end. Трябва ад бъде проверено и дали стойността на M лежи в интервала [beg;end]. Не трябва да се допуска деление на нула при извършване на ичисления по втория израз. При възникване на такава ситуация изчислението може да се избегне с помощта на оператор continue.
//Ако x <= m, то y(x) = b+x; Ако x > m, то y(x) = (a*x)/4-x
#include <stdio.h>

int main() {
    double beg, end, delta, m, a, b;
    
    // Input and validation for beg and end
    printf("Enter the beginning of the interval (beg): ");
    scanf("%lf", &beg);
    printf("Enter the end of the interval (end): ");
    scanf("%lf", &end);
    do {
        scanf("%lf", &end);       
    } while (beg >= end);
    
    // Input for delta, m, a, and b
    printf("Enter the step size (delta): ");
    scanf("%lf", &delta);
    
    printf("Enter the value of m: ");
    scanf("%lf", &m);
    
    // Validate that m is within the interval [beg; end]
    while (m < beg || m > end) {
        printf("Invalid input. 'm' must be between %.2lf and %.2lf. Please try again.\n", beg, end);
        printf("Enter the value of m: ");
        scanf("%lf", &m);
    }
    
    printf("Enter the value of a: ");
    scanf("%lf", &a);
    
    printf("Enter the value of b: ");
    scanf("%lf", &b);
    
    // Calculate and print y(x) for values in the interval [beg; end]
    printf("x\t\ty(x)\n");
    for (double x = beg; x <= end; x += delta) {
        double y;
        
        if (x <= m) {
            y = b + x;
        } else {
            if ((a * x) / 4 - x == 0) { // Check for division by zero
                continue; // Skip this iteration if it would cause division by zero
            }
            y = (a * x) / 4 - x;
        }
        
        printf("%.2lf\t\t%.4lf\n", x, y);
    }
    
    return 0;
}