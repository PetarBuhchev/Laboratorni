#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp, *fp1; int i, a, b; i = 1500;
    if ((fp = fopen("binary", "wb")) == NULL) {
        printf("The binary file could not be opened!\n");
        exit(1);
    }

    if ((fp1 = fopen("txt", "w")) == NULL) {
        printf("The text file could not be opened!\n");
        exit(2);
    }

    fprintf(fp1, "%d", i);
    if(fwrite(&i, sizeof(int), 1, fp) != 1) {
        printf("Write error occured!\n");
        exit(3);
    }

    fclose(fp);
    fclose(fp1);
    if ((fp = fopen("binary", "rb")) == NULL) 
    {
        printf("The binary file could not be opened!\n");
        exit(4);
    }

    if ((fp1 = fopen("txt", "r")) == NULL) {
        printf("The text file could not be opened!\n");
        exit(5);
    }

    if (fread(&a, sizeof(int), 1, fp) != 1) {
        printf("Read error occured!\n");
        exit(6);
    }

    fscanf(fp1, "%d", &b);
    printf("a is %d, b is %d\n", a, b);
    fclose(fp);
    fclose(fp1);
    system("pause");
    return 0;
}