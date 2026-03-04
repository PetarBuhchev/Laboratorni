//12,5
#include <stdio.h>

int main() {
    int x = 12
    , y = 5;
    printf("%d\n", x / y);
    printf("%d\n", x++);
    printf("%d\n", y--);
    printf("x=%d y=%d\n", x,y);
    printf("%d\n", x && y);
    printf("%d\n", x || y);
    return 0;
}