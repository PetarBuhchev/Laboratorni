//Да се напише програма която отпечатва числата от 1 до 10 с while цикъл и с for цикъл.
#include <stdio.h>

int main() {
    int i = 1;
    printf("Using while loop:\n");
    while (i <= 10) {
        printf("%d ", i);
        i++;
    }
    printf("\n");

    printf("Using for loop:\n");
    for (i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}