#include <stdio.h>
#define N 20
typedef struct {
    char ime[30];
    long fnum;
    int grup;
    float ocenka;
} STD;

void my_line_flush();
STD inputStd(void);
void outputStd(STD);
void uspeh(STD s[N], int br);

void my_line_flush()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

STD inputStd(void)
{
    STD a;
    printf("Vavedete ime: ");
    my_line_flush();
    gets(a.ime);
    printf("Vavedete fakulteten nomer: ");
    scanf("%ld", &a.fnum);
    printf("Vavedete grupa: ");
    scanf("%d", &a.grup);
    printf("Vavedete ocenka: ");
    scanf("%f", &a.ocenka);
    return a;
}

void outputStd(STD a)
{
    printf("Ime: %s\n", a.ime);
    printf("Fakulteten nomer: %ld\n", a.fnum);
    printf("Grupa: %d\n", a.grup);
    printf("Ocenka: %.2f\n", a.ocenka);
}

void uspeh(STD s[N], int br)
{
    float sum = 0.0; int gr = 0,key;
    printf("Vavedete grupa: ");
    scanf("%d", &key);
    for (int i = 0; i < br; i++) {
        if (s[i].grup == key) {
            sum += s[i].ocenka;
            gr++;
        }
    }
}

int main()
{
    int i, num = 0, sum = 0;
    STD s[N];
    printf("Vavedete broi studenti: ");
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        s[i] = inputStd();
    }
    for (i = 0; i < num; i++) {
        outputStd(s[i]);
    }
    uspeh(s, num); 
    return 0;
}