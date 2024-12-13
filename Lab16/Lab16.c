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
	return 1;
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

	return 1;
}

int delete_k(double* ptr_arr, int size, int k) 
{
	int n = size - 1;
	for (int i = k; i < size; i++)
		ptr_arr[i] = ptr_arr[i + 1];
	return n;
}

int* insert(int* ptr_arr, int *size, int index, int num)
{
	int size_n = (*size) + 1;
	if (ptr_arr == NULL) return NULL;
	int* ptr_arr_n = (int*)realloc(ptr_arr, size_n * sizeof(int));
	if (ptr_arr_n == NULL) return ptr_arr;
	ptr_arr = ptr_arr_n;
	for (int i = size_n - 1; i > index; i--)
		ptr_arr[i] = ptr_arr[i - 1];
	ptr_arr[index] = num;
	*size = size_n;
	return ptr_arr;
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

	double* ptr_array3;
	ptr_array3 = (double*)malloc(size * sizeof(double));

	srand(time(NULL));
	for (int i = 0; i < size; i++)
		ptr_array3[i] = -1 + rand() % (1 - (-1) + 1);
	printf("\n");
	for (int i = 0; i < size; i++)
		printf("%.0lf ", ptr_array3[i]);
	printf("\n");

	int k;
	printf("\n¬ведите номер элемента дл€ удалени€\n");
	scanf_s("%d", &k);

	delete_k(ptr_array3, size, k);
	printf("\nћассив с удаленным элементом\n");
	put_elements(ptr_array3, size);

	/*free(ptr_array3);

	int* ptr_array4;
	ptr_array4 = (int*)malloc(size * sizeof(int));*/

	/*srand(time(NULL));
	for (int i = 0; i < size; i++)
		ptr_array4[i] = -1 + rand() % (1 - (-1) + 1);*/

	//free(ptr_array);

	//очистка буфера
	/*scanf("%*[^\n]");
	scanf("%*c");*/
	




	srand(time(NULL));
	int index = 0 + rand() % ((size - 1) - 0 + (size - 1));
	int insert_num = -999;
	
	insert(ptr_array3, &size, index, insert_num);
	printf("\n\n");
	put_elements(ptr_array3, size);
}