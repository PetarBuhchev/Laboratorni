#include <string.h>
#include <stdio.h>

typedef struct Person {
    char name[50];
    int citNo;
    float salary;
} person;

int main() {
    person p1;
    strcpy(p1.name, "George Orwell");
    p1.citNo = 1984;
    p1.salary = 50000.0;
    printf("Name: %s\n", p1.name);
    printf("Citizenship Number: %d\n", p1.citNo);
    printf("Salary: %.2f\n", p1.salary);
    return 0;
}