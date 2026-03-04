#include <stdio.h>
#include <stdlib.h>

int main() {
    float a,b,c,x,y=0;
    printf("a=");scanf("%f",&a);
    printf("b=");scanf("%f",&b);
    printf("c=");scanf("%f",&c);
    printf("x=");scanf("%f",&x);
    y = a*x + 2 * (15*b-c);
    printf("y=%.2f",y);
    system("pause");
    return 0;
}