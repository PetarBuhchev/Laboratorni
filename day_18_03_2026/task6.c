//Да се състави програма, чрез която се въвеждат 7 цели числа от интервала [50;500] в едномерен масив. Програмата да изведе най-голямото и най-малкото от въведените числа.
#include <stdio.h>

int main() {
    int arr[7];
    int max, min;

    for (int i = 0; i < 7; i++) {
        do {
            printf("Enter an integer between 50 and 500: ");
            scanf("%d", &arr[i]);
            if (arr[i] < 50 || arr[i] > 500) {
                printf("Invalid input. Please enter a number between 50 and 500.\n");
            }
        } while (arr[i] < 50 || arr[i] > 500);
    }

    max = min = arr[0]; // Initialize max and min to the first element

    for (int i = 1; i < 7; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("The largest number entered is: %d\n", max);
    printf("The smallest number entered is: %d\n", min);
    
    return 0;
}