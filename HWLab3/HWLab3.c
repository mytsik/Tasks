#include <stdio.h>
#include <locale.h>
#include <math.h>
#define M_PI 3.14159265358979323846

float SurfaceArea(float radius) {
    return 4.0 * M_PI * pow(radius, 2);
}

float Volume(float radius) {
    return (4.0 / 3.0) * M_PI * pow(radius, 3);
}

void main() {
    float diameter, radius, surfaceArea, volume;

    setlocale(LC_ALL, "RUS");

    printf("Введите диаметр шара\n");
    scanf_s("%f", &diameter);

    radius = diameter / 2.0;

    surfaceArea = SurfaceArea(radius);
    volume = Volume(radius);

    printf("Площадь поверхности шара равна %.2f\n", surfaceArea);
    printf("Объем шара равен %.2f\n", volume);
}