#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 5
char *M[SIZE]={"1-Vavejdane","2-Izvevdane","3-Suma","4-Max","5-Izhod"};
int* input(int *br, int *mas)
{
    int k=0;
    printf("Vavedat razmer:");
    scanf("%d", &k);
    mas = (int*) malloc(k*sizeof(int));
    if (mas == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i=0; i<k; i++) {
        printf("[%d]=", i);
        scanf("%d", (mas+i));
    }
    *br = k;
    return mas;
}

void out(int br, int *mas)
{
    for (int i=0; i<br; i++) {
        printf("[%d]=%d ", i, *(mas+i));
    }
    printf("\n");
}

int sum(int br, int *mas)
{
    int sum=0;
    for (int i=0; i<br; i++) {
        sum+=*(mas+i);
    }
    return sum;
}

int max(int br, int *mas)
{
    int max=*(mas);
    for (int i=1; i<br; i++) {
        if (*(mas+i)>max) {
            max=*(mas+i);
        }
    }
    return max;
}

int main()
{
    int cod,n=0,*p=NULL,flag=0;

    do
    {
        for(int i=0; i<SIZE; i++) {
            puts(M[i]);
        }
        printf("Vavedete kod:");
        scanf("%d", &cod);
        switch (cod) {
            case 1:
                p = input(&n, p); flag=1;
                break;
            case 2:
                if (flag==1) {
                    out(n, p);
                } else {
                    printf("Izberete parvo 1\n");
                }
                _getch();
                break;
            case 3:
                if (flag == 1) {
                    out(n, p);
                    printf("Sum=%d\n", sum(n, p));
                } else {
                    printf("Izberete parvo 1\n");
                }
                _getch();
                break;
            case 4:
                if (flag == 1) {
                    printf("Max=%d\n", max(n, p));
                } else {
                    printf("Izberete parvo 1\n");
                }
                _getch();
                break;
            case 5:
                if (p != NULL) {
                    free(p);
                    printf("Osvobojdavane na pametta!\n");
                    p = NULL;
                }
                exit(1);
                break;
            default:
                printf("Nevaliden kod\n");
        }
    } while (1);
    
}