#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    
    double* p;

    p = calloc(10, sizeof(double));

    for (i=0; i<10; i++) {
        *(p+i) = i;
    }

    for (i=0; i<10; i++) {
        printf("*(p+%d) = %lf\n", i, *(p+i));
    }

    p = calloc(4, sizeof(double));

    for (i=0; i<4; i++) {
        *(p+i) = i;
    }
    printf("New:\n");
    for (i=0; i<4; i++) {
        printf("*(p+%d) = %lf\n", i, *(p+i));
    }

    free(p);
}