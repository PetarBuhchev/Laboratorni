//В двоичен файл имате цели числа (не е указано колко на брой).
//Да се напише програма, която създава файла.
//Да се напише програма, която изкарва на екрана броя на четните и броя на нечетнице цифри от така дадените N числа.
//Да се напише програма, която прочита така подадения масив от N елемента и изкарва в текстови файл сортирания по възходящ ред масив.
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp; int i, n, even = 0, odd = 0;
    if ((fp = fopen("binary", "wb")) == NULL) {
        printf("The binary file could not be opened!\n");
        exit(1);
    }

    printf("How many numbers? ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    if (fwrite(arr, sizeof(int), n, fp) != n) {
        printf("Write error occured!\n");
        exit(2);
    }
    fclose(fp);

    printf("Even numbers: %d\n", even);
    printf("Odd numbers: %d\n", odd);

    // След затваряне на файла:
    // 1. Отваряне за четене
    fp = fopen("binary", "rb");
    fread(arr, sizeof(int), n, fp);
    fclose(fp);

    // 2. Сортиране (bubble sort)
    for (i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++)
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

    // 3. Запис в текстов файл
    fp = fopen("sorted.txt", "w");
    for (i = 0; i < n; i++)
        fprintf(fp, "%d\n", arr[i]);
    fclose(fp);

    return 0;
}