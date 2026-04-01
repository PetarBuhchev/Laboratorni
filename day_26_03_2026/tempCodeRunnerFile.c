#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int row = 5, col = 7, i, j, count;
 
    int (*arr)[col] = calloc(row, sizeof *arr);
     
    count = 0;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            arr[i][j] = ++count;
 
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
    printf("\n");
    }
    for (int i = 0; i < row; i++) {
        printf("%d ", arr[i][i]);
    }
 
    free(arr);
     
    return 0;
}