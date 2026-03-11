//Да се напише програма в която се въвежда цяло число и се увеличава числото с 5. Да се напише функция, която приема цяло число като аргумент и връща резултата от увеличаването на това число с 5. Да се използва тази функция в програмата.
#include <stdio.h>
int increaseByFive(int number) {
    return number + 5;
}
void main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    int result = increaseByFive(number);
    printf("The result of increasing %d by 5 is %d\n", number, result);
}