//Да се напише функция, която намира дължината на низ, без да използва вградените функции за работа с низове.
#include <stdio.h>

int main()
{
    char str[] = "Hello, World!";
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    printf("The length of the string is: %d\n", length);
    return 0;
}