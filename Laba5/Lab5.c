#include <locale.h>
#include <stdio.h>
#define _USE_MATH_DEFINES 
#include <math.h>
#define M_PI 3.14159265358979323846

void main() 
{
	setlocale(LC_ALL, "RUS");

	float gr;
	printf("������� �������� ���� � ��������\n");
	scanf_s("%f", &gr);
	printf("����� ���� ����� %.6f\n", sin(gr * M_PI / 180));
}

