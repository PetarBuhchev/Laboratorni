//Напишете програма, която изкарва колко пъти се среща даден символ в низ. Потребителят въвежда само низа и се извежат бройките на всеки символ.
#include <stdio.h>

int main() {
    char str[100];
    int count[256] = {0}; // Масив за броене на срещанията на всеки символ

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Броим срещанията на всеки символ
    for (int i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }

    // Извеждаме броя на срещанията за всеки символ
    printf("Character counts:\n");
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            printf("'%c': %d\n", i, count[i]);
        }
    }

    return 0;
}