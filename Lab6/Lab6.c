#include <locale.h>
#include <stdio.h>
#define _USE_MATH_DEFINES 
#include <math.h>

int Task1(int year) 
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return 1;
	else
		return 0;
}

double Task2(double x)
{
	double result = x <= 3 ? pow(x, 2) - 3 * x + 9 : 1 / (pow(x, 3) + 6);
	return result;
}

void main() 
{
	setlocale(LC_ALL, "RUS");
	
	int year;
	printf("������� ���\n");
	scanf_s("%d", &year);

	if (Task1(year) == 1)
		printf("��� %d ����������\n", year);
	else
		printf("��� %d �� ����������\n", year);

	double x;
	printf("\n������� ���������� x\n");
	scanf_s("%lf", &x);

	printf("F(x) = %.3lf\n", Task2(x));
}