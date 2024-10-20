#include <locale.h>
#include <stdio.h>
#include <math.h>

void Task2(float num1, char c, float num2)
{
	switch (c)
	{
	case '+':
		printf("= %.2f", num1 + num2);
		break;
	case '-':
		printf("= %.2f", num1 - num2);
		break;
	case '/':
		printf("= %.2f", num1 / num2);
		break;
	case '*':
		printf("= %.2f", num1 * num2);
		break;
	case '^':
		printf("= %.2f", pow(num1, num2));
		break;
	default:
		printf("����������� ��������\n");
	}
}

void Task1(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		printf("��� �����\n");
	else if (ch >= '0' && ch <= '9')
		printf("��� �����\n");
	else
		printf("��� �� �����, �� �����\n");
}

void main()
{
	setlocale(LC_ALL, "RUS");

	char ch;
	printf("������� ������\n");
	scanf_s("%c", &ch);
	Task1(ch);
	

	char c;
	float x, y;
	printf("\n������� ���������\n");
	scanf("%f%c%f", &x, &c, &y);
	Task2(x, c, y);
			
}