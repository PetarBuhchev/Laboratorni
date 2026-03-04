//Да се напише програма, в която се въвеждат 2 цели числа и извежда сумата от четните числа и произведението на нечетните числа между тях. Въведените числа не е задължително да с в ред по-малко, по-голямо.
#include <stdio.h>

int main() {
    int num1, num2;
    int even_sum = 0;
    int odd_product = 1;
    
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    
    // Ensure num1 is the smaller number
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    for (int i = num1; i <= num2; i++) {
        if (i % 2 == 0) {
            even_sum += i; // Add even numbers to the sum
        } else {
            odd_product *= i; // Multiply odd numbers to the product
        }
    }
    
    printf("The sum of even numbers between %d and %d is: %d\n", num1, num2, even_sum);
    printf("The product of odd numbers between %d and %d is: %d\n", num1, num2, odd_product);
    
    return 0;
}