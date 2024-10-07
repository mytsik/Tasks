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

void main() 
{
	setlocale(LC_ALL, "RUS");
	
	int year;
	printf("Введите год\n");
	scanf_s("%d", &year);

	if (Task1(year) == 1)
		printf("Год високосный\n");
	else
		printf("Год не високосный\n");
}