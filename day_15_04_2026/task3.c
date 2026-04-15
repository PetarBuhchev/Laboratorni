//Направете масив с тип структура за ученици. Направете структува за випуск с няколко класа. Въведете данни за ученици от един клас и изчислете средния бал на групата.
//Изчислете средния бал на випуска
#include <stdio.h>

typedef struct {
    char name[50];
    float grade;
} Student;

int main() {
    Student students[25];
    float total_grade = 0.0;

    // Input student data
    for (int i = 0; i < 25; i++) {
        printf("Enter name and grade for student %d: ", i + 1);
        scanf("%s %f", students[i].name, &students[i].grade);
        total_grade += students[i].grade;
    }

    // Calculate and output the average grade for the class
    float average_grade = total_grade / 25;
    printf("Average grade for the class: %.2f\n", average_grade);

    return 0;
}

