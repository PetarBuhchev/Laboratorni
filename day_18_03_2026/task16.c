//Напишете програма, която заменя малките бувки в даден низ с големи.
#include <stdio.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A'); // Превръщаме малката буква в голяма
        }
    }

    printf("String with uppercase letters: %s\n", str);
    return 0;
}