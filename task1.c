#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[31];
    char date[8];
    long long product_code;
    double price;
    int quantity;
} Medicine;

void delete_medicine (Medicine *medicines, int *amount, char *name, char *date)
{
    int index = -1;
    for (int i = 0; i < *amount; i++){
        if (strcmp(medicines[i].name, name) == 0 && strcmp(medicines[i].date, date) == 0)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Medicine wasnt found and deleted")
        return;
    }

    for (int i = index; i < *count_ptr - 1; i++) {
        medicines[i] = medicines[i + 1];
    }
    (*count_ptr)--;
}