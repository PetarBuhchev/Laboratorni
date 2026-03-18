#include <stdio.h>

int main() {
    double arr[] = {4.5, 6.7, 7.3};
    for (int i = 0; i < 3; i++) {
        printf("%d: %lf\n", i, arr[i]);
    }
    return 0;
}