//Направете структува за превозно средство с подходящи полета. Направете втора структура за различен тип превозни средства и попълнете данните за променливи от вид кола, мотор, лодка и самолет. Сравнявайте различните средства по характеристика по избор.
#include <stdio.h>

typedef struct {
    char type[20];
    char brand[20];
    int year;
    float speed;
} Vehicle;

int main() {
    Vehicle car = {"Car", "Toyota", 2020, 180.0};
    Vehicle motorcycle = {"Motorcycle", "Yamaha", 2019, 220.0};
    Vehicle boat = {"Boat", "Bayliner", 2018, 60.0};
    Vehicle airplane = {"Airplane", "Boeing", 2015, 900.0};

    printf("Comparing vehicles based on speed:\n");
    printf("%s: %.2f km/h\n", car.type, car.speed);
    printf("%s: %.2f km/h\n", motorcycle.type, motorcycle.speed);
    printf("%s: %.2f km/h\n", boat.type, boat.speed);
    printf("%s: %.2f km/h\n", airplane.type, airplane.speed);

    return 0;
}