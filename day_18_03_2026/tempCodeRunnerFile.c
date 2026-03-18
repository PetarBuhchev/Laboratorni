//Да се създаде масив с 10 елемента. Да се впишат числата от 1 до 10 в масива и да се отпечатат на екрана.
#include <stdio.h>

int main() {
    int arr[10];
    
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }
    
    printf("The numbers from 1 to 10 are:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d \n", arr[i]);
    }
    
    return 0;
}