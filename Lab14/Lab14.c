#include <stdio.h>
#include <locale.h>

double full_elements(double *ptr_array, int n) //���������� ������� ���������� (��������, �� ������� ���.2 ���.8)
{	
	double *arr = ptr_array;

	printf("������� %d ��������� �������\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%f", &arr[i]); //��������� ���� ������� ������ ����� ������ ��� ��� i-�� ��������
	}
		
}

//int put_elements(double *ptr_array, int n) //������ ��������� �������
//{
//
//	for (int i = 0; i < n; i++)
//		printf("%f", ptr_array[i]);
//	return 1;
//}
//
//double *calc_elements(double* ptr_array, int n) //��������� ��������� ������� (��.  ���. �������  ���. 1.3 � ������ 11)
//{
//
//}

void main()
{
	setlocale(LC_ALL, "RUS");

	double array[1000];
	double* ptr_array = &array;

	int size;
	printf("������� ������ ������� > ");
	scanf_s("%d", &size);

	full_elements(ptr_array, size);
	
}