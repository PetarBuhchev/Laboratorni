#include <stdio.h>

double d[10] = {10.23, 19.87, 1002.23, 12.9, 0.897, 11.45, 75.34, 0.0, 1.01, 875.875};

int main()
{
    long loc;
    double value;
    FILE *fp;

    if((fp = fopen("myflle", "wb"))==NULL)
    {
        printf("Cannot open file!\n");
        exit(1);
    }

    if(fwrite(d, sizeof d,1,fp)!= 1)
    {
        printf("Write error!\n");
        exit(1);
    }
}