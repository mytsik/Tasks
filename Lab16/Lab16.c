#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 1000

double* full_elements(double* ptr_array, int size)
{
	double x = 0.1;
	for (int i = 0; i < size; i++)
	{
		double res = pow(x, 2) - pow(cos(x + 1), 2);
		double* point_res = &res;
		ptr_array[i] = *point_res;
		x += 0.1;
	}
}

double* calc_elements(double* ptr_array, int size)
{
	double* ptr_array2;
	ptr_array2 = (double*)malloc(size * sizeof(double));
	
	for (int i = 0; i < size; i++)
		ptr_array2[i] = ptr_array[i] / 10;

	return ptr_array2;
}

int put_elements(double* ptr_array, int size)
{	
	for (int i = 0; i < size; i++)
		printf("%.4lf ", ptr_array[i]);
	printf("\n");
}

void main()
{
	setlocale(LC_ALL, "RUS");

	double* ptr_array;
	int size;
	printf("¬ведите размер массива\n");
	scanf_s("%d", &size);
	ptr_array = (double*)malloc(size * sizeof(double));

	if (ptr_array == NULL) 
	{
		puts("error");
		return -1;
	}

	full_elements(ptr_array, size);
	calc_elements(ptr_array, size);

	printf("\nЁлементы исходного массива:\n");
	put_elements(ptr_array, size);
	
	double* ptr_array2;
	ptr_array2 = (double*)malloc(size * sizeof(double));
	ptr_array2 = calc_elements(ptr_array, size);

	printf("\nЁлементы обработанного массива:\n");
	put_elements(ptr_array2, size);

	free(ptr_array);
	free(ptr_array2);
}