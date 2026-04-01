#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=7,n;
    int * stations;

    stations = (int*) malloc (i*4);

    if (stations == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (n=0; n<i; n++) {
        stations[n] = n;
    }

    for(n=0; n<i; n++) {
        printf("%d ", stations[n]);
        printf("\n");
    }

    int *ptrToStations = stations;

    stations = (int*) malloc (++i*4);

    for (n=0; n<i; n++) {
        stations[n] = ptrToStations[n];
        stations[i-1] = i;;
    }
    for (n=0; n<i; n++) {
        printf("%d ", stations[n]);
        printf("\n");
    }

    ptrToStations = stations;
    int x = 3;
    for (n=x;n<i;n++) {
        ptrToStations[n-1] = ptrToStations[n];
    }
    stations = (int*) malloc (--i*4);
    for (n=0; n<i; n++) {
        stations[n] = ptrToStations[n];
    }
    for (n=0; n<i; n++) {
        printf("%d ", stations[n]);
        printf("\n");
    }
}