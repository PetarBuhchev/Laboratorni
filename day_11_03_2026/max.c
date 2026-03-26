#include <stdio.h>

int max(int,int);
void main() {
    int x = 4;
    int y = 5;
    printf("The maximum of %d and %d is %d\n", x, y, max(x,y));
}
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}