#include <stdio.h>
#include <locale.h>

void task1_1() 
{
	printf("\n");
	int row, col;
	for (row = 1; row <= 9; ++row)
	{
		for (col = 1; col <= 9; col++)
			printf("%5d", col * row);
		printf("\n");
	}
	system("pause");
}
void task1_2()
{
	printf("\n");
	int row, col;
	for (row = 1; row <= 9; ++row)
	{
		for (col = 1; col <= row; col++)
			printf("%5d", col * row);
		printf("\n");
	}
	system("pause");
}

void task1_3()
{
	printf("\n");
	int row, col;
	for (row = 1; row <= 9; ++row)
	{
		for (col = 1; col <= 9; col++)
			printf("%d * %d = %-5d", col, row, col * row);
		printf("\n");
	}
	system("pause");
}

int task2(char number)
{
	
}

void main()
{
	setlocale(LC_ALL, "RUS");

	task1_1();
	task1_2();
	task1_3();

	char number[100];
	printf("������� �����\n");
	scanf("%s", number);

	int sum = 0;
	for (int i = 0; number[i] != '\0'; i++)
	{
		// �������������� ������� � ����� � �������������� �������
		int digit = number[i] - '0'; // �������������� ������� � ����� �����

		// ��������, �������� �� ����� ��������
		if (digit % 2 != 0) {
			sum += digit; // ���������� �������� ����� � �����
		}
	}

	printf("����� �������� ���� ����� %d\n", sum);
}