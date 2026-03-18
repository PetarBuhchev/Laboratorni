//Да се състави програма, чрез коят се въвеждат 7 цели числа от интервала [50;500] в едномерен масив. Програмата да изведе числото, което е най-близко до средната стойност на въведените числа и къде се намира.
#include <stdio.h>
#include <stdlib.h>

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

    double average = sum / 7.0;
    int closest = arr[0];
    int closestIndex = 0;
    double minDiff = fabs(arr[0] - average);

    for (int i = 1; i < 7; i++) {
        double diff = fabs(arr[i] - average);
        if (diff < minDiff) {
            minDiff = diff;
            closest = arr[i];
            closestIndex = i;
        }
    }

    printf("The average of the entered numbers is: %.2lf\n", average);
    printf("The closest number to the average is: %d at index %d\n", closest, closestIndex);
    
    return 0;
}