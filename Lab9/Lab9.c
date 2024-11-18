#include <stdio.h>
#include <locale.h>

void task1_1() 
{
	printf("\n");
	int row, col;
	for (row = 1; row <= 9; row++)
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
	for (row = 1; row <= 9; row++)
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

void main()
{
	setlocale(LC_ALL, "RUS");

	task1_1();
	task1_2();
	task1_3();

	char number[100];
	printf("¬ведите число\n");
	scanf("%s", number);

	int sum = 0;
	for (int i = 0; number[i] != 0; i++)
	{ 
		if (number[i] % 2 != 0) 
		{
			int int_num = number[i] - '0';
			sum += int_num;
		}			
	}

	printf("—умма нечетных цифр в числе равна %d\n", sum);
}