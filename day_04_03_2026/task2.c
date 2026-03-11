#include <stdio.h>

int main() {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    int sum = 0;
    for(int i = a; i <= b; i++)
    {
        sum += i;
    }
    printf("%d\n", sum);
}