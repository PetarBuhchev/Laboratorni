#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    int result;

    result = ++a + --b;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("result = %d\n", result);

    return 0;
}