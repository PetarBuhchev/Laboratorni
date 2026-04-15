//Съставете структува за точка в пространството. Направете масив от точки и ги попълненете с данни. Направете тригълници със зададените точки и намерете страните на тригълниците.
//Да се използва формулата d = sqrt((x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2) за намиране на разстоянието между две точки в пространството.
#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
} Point;

float distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
}

int main() {
    Point points[3];

    // Input points
    for (int i = 0; i < 3; i++) {
        printf("Enter coordinates for point %d (x y z): ", i + 1);
        scanf("%f %f %f", &points[i].x, &points[i].y, &points[i].z);
    }

    // Calculate sides of the triangle formed by the three points
    float side1 = distance(points[0], points[1]);
    float side2 = distance(points[1], points[2]);
    float side3 = distance(points[2], points[0]);

    // Output the sides of the triangle
    printf("Sides of the triangle:\n");
    printf("Side 1: %.2f\n", side1);
    printf("Side 2: %.2f\n", side2);
    printf("Side 3: %.2f\n", side3);

    return 0;
}