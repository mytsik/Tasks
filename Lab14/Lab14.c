#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

double *full_elements(double *ptr_array, int n) //заполнение массива значениями из функции зад.2 лаб.8
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
	printf("\nЭлементы массива:\n");
	for (int i = 0; i < n; i++)
		printf("%.3lf ", ptr_array[i]);
}

double *calc_elements(double* ptr_array, int n) //обработка элементов массива (см.  инд. вариант  зад. 1.3 в работе 11) и печать 
{
	double array2[1000];
	printf("\nОбработанные элементы массива:\n");
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

int function(double* ptr_array, int n, int type) 
{
	switch (type)
	{
		case 1:
			for (int i = 0; i < n; i++) 
			{
				if (ptr_array[i] > 0) 
				{
					return i;
					break;
				}					
			}						
		case -1:
			for (int i = 0; i < n; i++)
			{
				if (ptr_array[i] < 0) 
				{
					return i;
					break;
				}					
			}			
		case 0:
			for (int i = 0; i < n; i++)
			{
				if (ptr_array[i] == 0) 
				{
					if (i == n)
					{
						return -1;
						break;
					}	
					return i;
					break;
				}				
			}			
		default:
			return -1;
	}
}

void main()
{
	setlocale(LC_ALL, "RUS");

	double array[1000];
	double* ptr_array = &array;

	int size;
	printf("Введите размер массива:\n");
	scanf_s("%d", &size);

	full_elements(ptr_array, size);
	put_elements(ptr_array, size);
	printf("\n");
	calc_elements(ptr_array, size);
	printf("\n");

	int begin, end;
	printf("\nВведите начальный индекс:\n");
	scanf_s("%d", &begin);
	printf("Введите конечный индекс:\n");
	scanf_s("%d", &end);
	if ((end < 0) || (begin < 0) || (begin > end) || (end >= size))
		printf("Введены недопустимые значения индексов элементов\n");
	else
		printf("Сумма элементов массива от индекса %d до индекса %d равна %.3lf\n", begin, end, sum_elements(ptr_array, begin, end));	

	double num;
	printf("\nВведите число для поиска:\n");
	scanf_s("%lf", &num);
	printf("Индекс найденного элемента равен %d\n", find_element(ptr_array, size, num));
	printf("\n");
	printf("Порядковый номер первого положительного элемента массива равен %d\n", function(ptr_array, size, 1));
	printf("Порядковый номер первого отрицательного элемента массива равен %d\n", function(ptr_array, size, -1));
	printf("Порядковый номер первого нулевого элемента массива равен %d\n", function(ptr_array, size, 0));
}