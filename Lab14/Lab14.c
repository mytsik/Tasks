#include <stdio.h>
#include <locale.h>
#include <math.h>

double full_elements(double *ptr_array, int n) //заполнение массива значени€ми из функции зад.2 лаб.8
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

int put_elements(double *ptr_array, int n) //печать элементов массива
{
	printf("\nЁлементы массива:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%.3lf ", ptr_array[i]);
	}
}
//
//double *calc_elements(double* ptr_array, int n) //обработка элементов массива (см.  инд. вариант  зад. 1.3 в работе 11)
//{
//
//}

void main()
{
	setlocale(LC_ALL, "RUS");

	double array[1000];
	double* ptr_array = &array;

	int size;
	printf("¬ведите размер массива:\n");
	scanf_s("%d", &size);

	full_elements(ptr_array, size);
	put_elements(ptr_array, size);
	
}