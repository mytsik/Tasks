#include <locale.h>
#include <stdio.h>
#define _USE_MATH_DEFINES 
#include <math.h>

double F(long double x, double y)
{
	double numerator = sqrt(pow(2 + y, 2) + pow(sin(y + 5), 0.143));
	double denominator = log(x + 1) + pow(y, 3);
	double result = numerator / denominator;
	return result;
}

void main() 
{
	setlocale(LC_ALL, "RUS");

	long double x;
	double xFirstPart;
	double xDegree;
	
	printf("¬ведите значение x\n");
	scanf_s("%lf", &xFirstPart);
	printf("* 10^");	
	scanf_s("%d", &xDegree);

	x = xFirstPart * pow(10, xDegree);
	printf("\n");

	double y;
	printf("¬ведите значение y\n");
	scanf_s("%lf", &y);

	printf("–езультат: %.5lf\n", F(x, y)); 
}