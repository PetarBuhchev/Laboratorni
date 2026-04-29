//Създайте структура Medicine, която да съхранява информация за лекарарства. Съхраняваната информация за всяко лекарство е:
//Наименование на лекарството (до 30 символа), дата на годност (низ с фиксирана дължина и формат ММ.ГГГГ), код на продукта - уникален (тринадесетцифрено число), единична цена (реално число), налично количество (цяло число)
//Данните се съхраняват в бинарен файл medicines.bin, във формат - променливи от тип структурата Medicine. Прочетете данните от файла и ги заредете в динамичен масив medicines. Обработвайте грешки, възникнали при работа с бинарния файл
//*Приемете, че файлът вече е създаден и попълнен с данни, като е необходимо само да го достъпите.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[31];
    char expiry_date[8];
    long long product_code;
    double price;
    int quantity;
} Medicine;

//Дефинирайте функция, която приема като параметри масив селементи от тип структурата Medicine, брой елементи на масива, име на лекарство, дата на годност (низ с фиксиран размер и формат ММ.ГГГГ). Функцията изтрива лекарството със съответното име и дата на годност от динамичния масив. Ако няма открито съвпадение функцията принтира съответно съобщение.

void delete_medicine(Medicine *medicines, int *count_ptr, char *name, char *expiry_date) {

    int index = -1;
    for (int i = 0; i < *count_ptr; i++) {
        if (strcmp(medicines[i].name, name) == 0 && strcmp(medicines[i].expiry_date, expiry_date) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine with name '%s' and expiry date '%s' not found.\n", name, expiry_date);
        return;
    }

    for (int i = index; i < *count_ptr - 1; i++) {
        medicines[i] = medicines[i + 1];
    }
    (*count_ptr)--;
}


int save_offers(Medicine *medicines, int count, double min_price, double max_price) {
    FILE *fp;
    int offer_count = 0;

    if ((fp = fopen("offer.txt", "w")) == NULL) {
        printf("Cannot open file for writing!\n");
        return 0;
    }

    for (int i = 0; i < count; i++) {
        if (medicines[i].price >= min_price && medicines[i].price <= max_price) {
            fprintf(fp, "%s\n", medicines[i].name);
            fprintf(fp, "%s\n", medicines[i].expiry_date);
            fprintf(fp, "%lld\n", medicines[i].product_code);
            fprintf(fp, "%.2f евро\n", medicines[i].price);
            offer_count++;
            fprintf(fp, "\n");
        }
    }

    fclose(fp);
    return offer_count;
}

Medicine *find_expired_medicines(Medicine *medicines, int count, char target_date[8], int *expired_count_ptr) {
    Medicine *expired_medicines = NULL;
    int expired_count = 0;

    // Parse target date (MM.YYYY)
    int target_month = (target_date[0] - '0') * 10 + (target_date[1] - '0');
    int target_year = (target_date[3] - '0') * 1000 + (target_date[4] - '0') * 100 + 
                      (target_date[5] - '0') * 10 + (target_date[6] - '0');

    // First: COUNT how many expired medicines (expiry_date < target_date)
    for (int i = 0; i < count; i++) {
        int exp_month = (medicines[i].expiry_date[0] - '0') * 10 + (medicines[i].expiry_date[1] - '0');
        int exp_year = (medicines[i].expiry_date[3] - '0') * 1000 + (medicines[i].expiry_date[4] - '0') * 100 + 
                       (medicines[i].expiry_date[5] - '0') * 10 + (medicines[i].expiry_date[6] - '0');
        
        if (exp_year < target_year || (exp_year == target_year && exp_month < target_month)) {
            expired_count++;
        }
    }

    *expired_count_ptr = expired_count;

    if (expired_count == 0) {
        return NULL;
    }

    expired_medicines = (Medicine *)malloc(expired_count * sizeof(Medicine));
    if (expired_medicines == NULL) {
        return NULL;
    }

    int idx = 0;
    for (int i = 0; i < count; i++) {
        int exp_month = (medicines[i].expiry_date[0] - '0') * 10 + (medicines[i].expiry_date[1] - '0');
        int exp_year = (medicines[i].expiry_date[3] - '0') * 1000 + (medicines[i].expiry_date[4] - '0') * 100 + 
                       (medicines[i].expiry_date[5] - '0') * 10 + (medicines[i].expiry_date[6] - '0');
        
        if (exp_year < target_year || (exp_year == target_year && exp_month < target_month)) {
            expired_medicines[idx++] = medicines[i];
        }
    }

    return expired_medicines;
}

int main()
{
    FILE *fp;
    Medicine *medicines;

    if ((fp = fopen("medicines.bin", "rb")) == NULL) {
        printf("Cannot open file!\n");
        exit(1);
    }

    // Count the number of records in the file using fseek and ftell
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    int count = file_size / sizeof(Medicine);
    rewind(fp); // Reset file pointer to the beginning

    // Allocate memory for the medicines array
    medicines = (Medicine *)malloc(count * sizeof(Medicine));
    if (medicines == NULL) {
        printf("Memory allocation failed!\n");
        fclose(fp);
        exit(2);
    }

    // Read the medicines from the file into the array
    for (int i = 0; i < count; i++) {
        if (fread(&medicines[i], sizeof(Medicine), 1, fp) != 1) {
            printf("Error reading from file!\n");
            free(medicines);
            fclose(fp);
            exit(3);
        }
    }

    fclose(fp);

    // Print the medicines
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", medicines[i].name);
        printf("Expiry Date: %s\n", medicines[i].expiry_date);
        printf("Product Code: %lld\n", medicines[i].product_code);
        printf("Price: %.2f\n", medicines[i].price);
        printf("Quantity: %d\n", medicines[i].quantity);
        printf("\n");
    }

    // Find expired medicines before 01.2027
    int expired_count = 0;
    Medicine *expired_medicines = find_expired_medicines(medicines, count, "01.2027", &expired_count);
    
    if (expired_medicines != NULL) {
        printf("\nExpired medicines (before 01.2027):\n");
        for (int i = 0; i < expired_count; i++) {
            printf("Expired Medicine: %s (Expiry: %s)\n", expired_medicines[i].name, expired_medicines[i].expiry_date);
        }
        free(expired_medicines);
    } else {
        printf("\nNo expired medicines found.\n");
    }

    int offers_saved = save_offers(medicines, count, 2.00, 5.00);
    printf("Брой лекарства СЛЕД изтриването: %d\n", count);
    delete_medicine(medicines, &count, "Ibuprofen 200mg", "06.2027");
    printf("Брой лекарства СЛЕД изтриването: %d\n", count);
    free(medicines);
    return 0;
}