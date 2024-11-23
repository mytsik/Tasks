#include <locale.h>
#include <stdio.h>

double function(int* ptr_array, int n)
{
	int max = ptr_array[0];
	int max_index = 0;

	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] > max)
		{
			max = ptr_array[i];
			max_index = i;
		}
	}

	int min = ptr_array[0];
	int min_index = 0;

	for (int j = 0; j < n; j++)
	{
		if (ptr_array[j] < min)
		{
			min = ptr_array[j];
			min_index = j;
		}
	}

	int summ = 0;
	double count = 0.0;
	for (int k = min_index; k <= max_index; k++)
	{
		summ += ptr_array[k];
		count += 1.0;
	}
	double average = summ / count;

	return average;
}

void main()
{
	setlocale(LC_ALL, "RUS");

	int array[10];
	int* ptr_array = &array;

	printf("������� 10 ��������� �������\n");
	for (int i = 0; i < 10; i++)
		scanf_s("%d", &array[i]);

	printf("C������ �������� ���������, ������������� ����� ����������� � ������������ ��������� ������� ����� %.2lf\n", function(ptr_array, 10));
}