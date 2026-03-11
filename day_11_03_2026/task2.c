//Да се напише програма, вкоят се въвежда цяло число, което представлява код на геометрична фигура - 1 - квадрат, 2 - правоъгълник, 3 - правоъгълен триъгълник, 4 - кръг. След това се въвеждат размерите на избраната фигура, както и нейното лице. За пресмятането на лицето да се напишат подходящи функции, които да се извикват от главната функция main. Да се използва switch оператор.
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
float calculateSquareArea(float side) {
    return side * side;
}
float calculateRectangleArea(float length, float width) {
    return length * width;
}
float calculateRightTriangleArea(float base, float height) {
    return 0.5 * base * height;
}
float calculateCircleArea(float radius) {
    return M_PI * radius * radius;
}
int main() {
    int shapeCode;
    printf("Enter the code for the geometric shape (1 - square, 2 - rectangle, 3 - right triangle, 4 - circle): ");
    scanf("%d", &shapeCode);

    switch (shapeCode) {
        case 1: {
            float side;
            printf("Enter the side length of the square: ");
            scanf("%f", &side);
            float area = calculateSquareArea(side);
            printf("The area of the square is: %.2f\n", area);
            break;
        }
        case 2: {
            float length, width;
            printf("Enter the length and width of the rectangle: ");
            scanf("%f %f", &length, &width);
            float area = calculateRectangleArea(length, width);
            printf("The area of the rectangle is: %.2f\n", area);
            break;
        }
        case 3: {
            float base, height;
            printf("Enter the base and height of the right triangle: ");
            scanf("%f %f", &base, &height);
            float area = calculateRightTriangleArea(base, height);
            printf("The area of the right triangle is: %.2f\n", area);
            break;
        }
        case 4: {
            float radius;
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);
            float area = calculateCircleArea(radius);
            printf("The area of the circle is: %.2f\n", area);
            break;
        }
        default:
            printf("Invalid shape code. Please enter a number between 1 and 4.\n");
    }

    return 0;
}