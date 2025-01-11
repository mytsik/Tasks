#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#define SIZE_TH 1000
#define SIZE_TTH 10000
#define SIZE_H 100

int sort_bubble(int* ptrarr, int n);
int sort_kokteil(int* ptrarr, int n);
int sort_select(int* ptrarr, int n);
int sort_insert(int* ptrarr, int n);

int* full_array(int*, int);
int put_array(int* ptrarr, int n);

void main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "RUS");

	int arr[SIZE_TH];
	int* ptrarr = &arr;

	int size;
	printf("Введите размер массива\n");
	scanf("%d", &size);

	full_array(ptrarr, size);
	clock_t t = clock();
	sort_insert(ptrarr, size);
	double time = (double)(clock() - t) / CLOCKS_PER_SEC;

	int arr_h[SIZE_H];
	int arr_th[SIZE_TH];
	int arr_tth[SIZE_TTH];
	int* ptrarr_h = &arr_h;
	int* ptrarr_th = &arr_th;
	int* ptrarr_tth = &arr_th;

	full_array(ptrarr_h, SIZE_H);
	full_array(ptrarr_th, SIZE_TH);
	full_array(ptrarr_tth, SIZE_TTH);

	sort_bubble(ptrarr_h, SIZE_H);
	sort_bubble(ptrarr_th, SIZE_TH);
	sort_bubble(ptrarr_tth, SIZE_TTH);

	printf("Пузырьковая сортировка:\n");
	printf("100 значений\n");
	put_array(ptrarr_h, SIZE_H);
	printf("1000 значений %f\n");
	put_array(ptrarr_th, SIZE_TH);
	printf("10000 значений %f\n");
	put_array(ptrarr_th, SIZE_TTH);
	printf("\n\n");
	scanf("%*[^\n]");
	scanf("%*c");

	sort_kokteil(ptrarr_h, SIZE_H);
	sort_kokteil(ptrarr_th, SIZE_TH);
	sort_kokteil(ptrarr_tth, SIZE_TTH);

	printf("Шейкерная сортировка:\n");
	printf("100 значений\n");
	put_array(ptrarr_h, SIZE_H);
	printf("1000 значений %f\n");
	put_array(ptrarr_th, SIZE_TH);
	printf("10000 значений %f\n");
	put_array(ptrarr_th, SIZE_TTH);
	printf("\n\n");
	scanf("%*[^\n]");
	scanf("%*c");

	sort_insert(ptrarr_h, SIZE_H);
	sort_insert(ptrarr_th, SIZE_TH);
	sort_insert(ptrarr_tth, SIZE_TTH);

	printf("Сортировка вставками:\n");
	printf("100 значений\n");
	put_array(ptrarr_h, SIZE_H);
	printf("1000 значений %f\n");
	put_array(ptrarr_th, SIZE_TH);
	printf("10000 значений %f\n");
	put_array(ptrarr_th, SIZE_TTH);
	printf("\n\n");
	scanf("%*[^\n]");
	scanf("%*c");

	sort_select(ptrarr_h, SIZE_H);
	sort_select(ptrarr_th, SIZE_TH);
	sort_select(ptrarr_tth, SIZE_TTH);

	printf("Сортировка простым выбором:\n");
	printf("100 значений\n");
	put_array(ptrarr_h, SIZE_H);
	printf("1000 значений %f\n");
	put_array(ptrarr_th, SIZE_TH);
	printf("10000 значений %f\n");
	put_array(ptrarr_th, SIZE_TTH);
	printf("\n\n");
	scanf("%*[^\n]");
	scanf("%*c");
}

int sort_bubble(int* ptrarr, int n)
{
	int length = n;
	while (length != 0)
	{
		int maxlength = 0;
		for (int i = 1; i < length; i++)
		{
			if (ptrarr[i - 1] > ptrarr[i])
			{
				int temp = ptrarr[i - 1];
				ptrarr[i - 1] = ptrarr[i];
				ptrarr[i] = temp;
				maxlength = i;
			}
		}
		length = maxlength;
	}
	return 1;
}

int sort_kokteil(int* ptrarr, int n)
{
	int left = 0;
	int right = n - 1;
	int flag = 1;

	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)
		{
			if (ptrarr[i] > ptrarr[i + 1])
			{
				double t = ptrarr[i];
				ptrarr[i] = ptrarr[i + 1];
				ptrarr[i + 1] = t;
				flag = 1;
			}
		}
		right -= 1;
		for (int i = right; i > left; i--)
		{
			if (ptrarr[i - 1] > ptrarr[i])
			{
				int temp = ptrarr[i];
				ptrarr[i] = ptrarr[i - 1];
				ptrarr[i - 1] = temp;
				flag = 1;
			}
		}
		left += 1;
		if (flag == 0) 
			break;
	}
	return 1;
}

int sort_select(int* ptrarr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (ptrarr[j] < ptrarr[min_index])
				min_index = j;
		}

		if (min_index != i)
		{
			int temp = ptrarr[i];
			ptrarr[i] = ptrarr[min_index];
			ptrarr[min_index] = temp;
		}
	}
	return 1;
}

int sort_insert(int* ptrarr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int sorted = i - 1;
		while (sorted > -1 && ptrarr[sorted] > ptrarr[sorted + 1])
		{
			int temp = ptrarr[sorted];
			ptrarr[sorted] = ptrarr[sorted + 1];
			ptrarr[sorted + 1] = temp;
			sorted -= 1;
		}
	}
	return 1;
}

int* full_array(int* ptrarr, int size)
{
	for (int i = 0; i < size; i++)
		ptrarr[i] = rand() % 30;

	return ptrarr;
}

int put_array(int* ptrarr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", ptrarr[i]);
	return 1;
}


