#include <locale.h>
#include <stdio.h>
#include <math.h>

float func(float x, int n)
{
	float summ = 0;
	for (int i = 1; i <= n; i++)
	{
		summ += sin(pow(x, i));
	}
	return summ;
}

void main()
{
	setlocale(LC_ALL, "RUS");
	float x;
	int n;
	printf("������� �������������� �����\n");
	scanf_s("%f", &x);
	printf("������� ����������� �����\n");
	scanf_s("%d", &n);
	
	printf("���������: %.2f", func(x, n));
}