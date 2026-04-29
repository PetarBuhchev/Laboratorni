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

int main()
{
    FILE *fp;
    Medicine medicines[5];

    // Initialize test data
    strcpy(medicines[0].name, "Aspirin 500mg");
    strcpy(medicines[0].expiry_date, "12.2026");
    medicines[0].product_code = 1234567890123LL;
    medicines[0].price = 2.50;
    medicines[0].quantity = 100;

    strcpy(medicines[1].name, "Ibuprofen 200mg");
    strcpy(medicines[1].expiry_date, "06.2027");
    medicines[1].product_code = 1234567890124LL;
    medicines[1].price = 3.75;
    medicines[1].quantity = 50;

    strcpy(medicines[2].name, "Paracetamol 500mg");
    strcpy(medicines[2].expiry_date, "03.2028");
    medicines[2].product_code = 1234567890125LL;
    medicines[2].price = 1.99;
    medicines[2].quantity = 200;

    strcpy(medicines[3].name, "Vitamins Complex");
    strcpy(medicines[3].expiry_date, "09.2027");
    medicines[3].product_code = 1234567890126LL;
    medicines[3].price = 5.99;
    medicines[3].quantity = 75;

    strcpy(medicines[4].name, "Antibiotic XYZ");
    strcpy(medicines[4].expiry_date, "01.2027");
    medicines[4].product_code = 1234567890127LL;
    medicines[4].price = 8.50;
    medicines[4].quantity = 30;

    // Write to binary file
    if ((fp = fopen("medicines.bin", "wb")) == NULL) {
        printf("Cannot create file!\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        if (fwrite(&medicines[i], sizeof(Medicine), 1, fp) != 1) {
            printf("Error writing to file!\n");
            fclose(fp);
            return 2;
        }
    }

    fclose(fp);
    printf("File medicines.bin created successfully with 5 test medicines!\n");
    return 0;
}
