#include <stdio.h>
#define SIZE 1000

int main(void) {
    int n,sum=0,i;
    int ar[SIZE];
    do
    {
        printf("n=");
        scanf("%d",&n);
        if(n>SIZE||n<0)
        {
            printf("Enter new n");
        }
    } while (n>SIZE||n<=0);
    for(i=0;i<n;i++)
    {
        printf("ar[%d]=",i);
        scanf("%d",&ar[i]);
        sum+=ar[i];
    }
    printf("Sum=%d",sum);
    return 0;
}