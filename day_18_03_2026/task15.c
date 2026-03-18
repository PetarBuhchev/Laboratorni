//Напишете програма, коят връща броя на гласните в даден низ.
#include <stdio.h>

int main() {
    char str[100];
    int vowelCount = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowelCount++;
        }
    }

    printf("The number of vowels in the string is: %d\n", vowelCount);
    return 0;
}