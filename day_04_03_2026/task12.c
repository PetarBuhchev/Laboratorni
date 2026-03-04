//Да се напише програма, която при въвеждането на произволен брой числа извежда сборът им. За край на въвеждането се приема числото 0.
#include <stdio.h>

int main() {
    int sum = 0;
    int num;
    
    printf("Enter numbers (0 to stop): ");
    
    do {
        scanf("%d", &num);
        sum += num; // Add the entered number to the sum
    } while (num != 0); // Continue until 0 is entered
    
    printf("The sum of the entered numbers is: %d\n", sum);
    
    return 0;
}