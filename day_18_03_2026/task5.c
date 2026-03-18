//Да се състави програма, чрез която се въвеждат 7 цели числа от интервала [50;500] в едномерен масив. Програмата да изведе общата сума на въведените числа.
#include <stdio.h>

int main() {
    int arr[7];
    int sum = 0;

    for (int i = 0; i < 7; i++) {
        do {
            printf("Enter an integer between 50 and 500: ");
            scanf("%d", &arr[i]);
            if (arr[i] < 50 || arr[i] > 500) {
                printf("Invalid input. Please enter a number between 50 and 500.\n");
            }
        } while (arr[i] < 50 || arr[i] > 500);
        sum += arr[i];
    }

    printf("The total sum of the entered numbers is: %d\n", sum);
    return 0;
}