//Да се напише програма, при която се въвеждат две цели числа N и K. След това се въвеждат още N числа и се извеждат броят на числата, коисто са по-големи от K и се делят на 3.
#include <stdio.h>

int main() {
    int N, K, count = 0;
    
    printf("Enter the number of integers (N) and the threshold (K): ");
    scanf("%d %d", &N, &K);
    
    for (int i = 0; i < N; i++) {
        int num;
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &num);
        
        if (num > K && num % 3 == 0) {
            count++;
        }
    }
    
    printf("The count of numbers greater than %d and divisible by 3 is: %d\n", K, count);
    
    return 0;
}