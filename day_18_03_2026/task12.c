//Напишете програма, която намира броя на думите в низ. Низът е на един ред и думите са разделени с интервал. Броят на думите се извежда на конзолата.
#include <stdio.h>

int main() {
    char str[100];
    int wordCount = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            wordCount++;
        }
    }

    // Ако последният символ не е интервал или нов ред, добавяме 1 към броя на думите
    if (str[0] != ' ') {
        wordCount++;
    }

    printf("The number of words in the string is: %d\n", wordCount);
    return 0;
}