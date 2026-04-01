//Попълнете масив NxN елемента и го попълнете с числа. 
//Изкарайте елементите на главния диагонал
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter the size of the matrix (N): ");
    scanf("%d", &N);

    int matrix[N][N];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int r = rand();
            matrix[i][j] = r;
            printf("%d ", matrix[i][j]);
        }
    }

    printf("Elements on the main diagonal:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");

    return 0;
}