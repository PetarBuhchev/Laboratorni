//Да се напише програма, в която се въвеждат 2 цели числа и извежда сумата на числата между тях. Въведените числа не е задължително да с в ред по-малко, по-голямо
#include <stdio.h>

int main() {
    int num1, num2, sum = 0;
    
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    
    // Ensure num1 is the smaller number
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    for (int i = num1; i <= num2; i++) {
        sum += i;
    }
    
    printf("The sum of numbers between %d and %d is: %d\n", num1, num2, sum);
    
    return 0;
}