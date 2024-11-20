#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

double *full_elements(double *ptr_array, int n) //���������� ������� ���������� �� ������� ���.2 ���.8
{
	double x = 0.1;
	for (int i = 0; i < n; i++)
	{
		double res = pow(x, 2) - pow(cos(x + 1), 2);
		double* point_res = &res;
		ptr_array[i] = *point_res;
		x += 0.1;		
	}	
}

int put_elements(double *ptr_array, int n) //������ ��������� �������
{
	printf("\n�������� �������:\n");
	for (int i = 0; i < n; i++)
		printf("%.3lf ", ptr_array[i]);
}

double *calc_elements(double* ptr_array, int n) //��������� ��������� ������� (��.  ���. �������  ���. 1.3 � ������ 11) � ������ 
{
	double array2[1000];
	printf("\n������������ �������� �������:\n");
	for (int i = 0; i < n; i++)
	{		
		array2[i] = ptr_array[i] / 10;
		printf("%.4lf ", array2[i]);
	}	
}

double sum_elements(double* ptr_array, int begin, int end)
{
	double sum = 0;
	for (int i = begin; i <= end; i++)
		sum += ptr_array[i];
	return sum;
}

int find_element(double* ptr_array, int n, double element)
{
	for (int i = 0; i < n; i++) 
	{
		if (ptr_array[i] == element)
			return i;
	}
	return -1;
}

void main()
{
	setlocale(LC_ALL, "RUS");

	double array[1000];
	double* ptr_array = &array;

	int size;
	printf("������� ������ �������:\n");
	scanf_s("%d", &size);

	full_elements(ptr_array, size);
	put_elements(ptr_array, size);
	printf("\n");
	calc_elements(ptr_array, size);
	printf("\n");

	int begin, end;
	printf("\n������� ��������� ������:\n");
	scanf_s("%d", &begin);
	printf("������� �������� ������:\n");
	scanf_s("%d", &end);
	if ((end < 0) || (begin < 0) || (begin > end) || (end >= size))
		printf("������� ������������ �������� �������� ���������\n");
	else
		printf("����� ��������� ������� �� ������� %d �� ������� %d ����� %.3lf\n", begin, end, sum_elements(ptr_array, begin, end));	

	double num;
	printf("\n������� ����� ��� ������:\n");
	scanf_s("%lf", &num);
	printf("������ ���������� �������� ����� %d\n", find_element(ptr_array, size, num));
}