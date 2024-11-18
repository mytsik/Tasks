#include <stdio.h>
#include <locale.h>

double full_elements(double *ptr_array, int n) //заполнение массива значени€ми (например, из функции зад.2 лаб.8)
{	
	double *arr = ptr_array;

	printf("¬ведите %d элементов массива\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%f", &arr[i]); //нарушение прав доступа скорее всего потому что нет i-го элемента
	}
		
}

//int put_elements(double *ptr_array, int n) //печать элементов массива
//{
//
//	for (int i = 0; i < n; i++)
//		printf("%f", ptr_array[i]);
//	return 1;
//}
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
	printf("¬ведите размер массива > ");
	scanf_s("%d", &size);

	full_elements(ptr_array, size);
	
}