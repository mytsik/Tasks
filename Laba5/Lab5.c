#include <locale.h>
#include <stdio.h>
#define _USE_MATH_DEFINES 
#include <math.h>
#define M_PI 3.14159265358979323846

int task3(int A, int B, int C) {
	if (((A % 2 == 0) || (B % 2 == 0)) && ((A % 3 == 0) && (B % 3 == 0) && (C % 3 == 0)))
		return 1;
	else
		return 0;
}

void main() 
{
	setlocale(LC_ALL, "RUS");

	float gr;
	printf("¬ведите значение угла в градусах\n");
	scanf_s("%f", &gr);
	printf("—инус угла равен %.6f\n", sin(gr * M_PI / 180));

	int t = -6;
	double x;

	printf("\n¬ведите значение x\n");
	scanf_s("%lf", &x);

	double a = log(x);
	double b = sqrt(pow(x, 2) + pow(t, 2));
	double y = pow(fabs(a - b * x), 0.2);
	printf("\nx=%.1f\ny=%.4f\n", x, y);

	int A = (int)a;
	int B = (int)b;
	int C = (int)y;

	printf("\nусловие выполнено(1 - да, 0 - нет)");
	printf("\n–езультат:%d\n", task3(A, B, C));
}

