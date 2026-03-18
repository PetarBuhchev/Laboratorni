#include <stdio.h>

int main() {
    int arr[] = {10,20,30,40,50,60};
    int* ptr = arr;

    printf("Size of arr[] %ld\n", sizeof(arr));
    printf("Size of ptr %ld\n", sizeof(ptr));
    printf("Size of ptr %ld\n", *ptr++);
    return 0;
}