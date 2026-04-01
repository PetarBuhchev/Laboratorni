//Да се разработи меню програма, коят прочита числата от клавиатурата и ги записва в едномерен динамичен масив. При недостиг на елементите, масивът динамично да се попълва с нови клетки до прочитане на всички числа. Да се използва 0 за край на въвеждането. Програмата да има следната функционланост:
//1. Прочитане на поредицата от клавиатурата
//2. Извеждане на числата от масива
//3. Сумиране на числата от масива

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    int size = 0, capacity = 0, num;

    printf("Enter numbers (0 to end):\n");
    while (1) {
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        if (size == capacity) {
            capacity = capacity == 0 ? 1 : capacity * 2;
            arr = realloc(arr, capacity * sizeof(int));
            if (arr == NULL) {
                printf("Memory allocation failed\n");
                exit(1);
            }
        }
        arr[size++] = num;
    }

    printf("Numbers entered:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("Sum of numbers: %d\n", sum);

    free(arr);
    return 0;
}