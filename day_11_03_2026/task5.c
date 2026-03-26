//Напишете функция, която превръща от десетично в двоично число. Да не се използват указатели и масиви.
#include <stdio.h>

void toBinary(int n) {
    if (n > 1) {
        toBinary(n / 2); // Рекурсивно извикване
    }
    printf("%d", n % 2); // Печата остатъка при връщане от рекурсията
}

int main() {
    int num;
    scanf("%d", &num);

    if (num < 0) {
        printf("Enter new num");
    } else {
        printf("Binary: ");
        if (num == 0) printf("0");
        else toBinary(num);
        printf("\n");
    }

    return 0;
}

