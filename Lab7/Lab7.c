#include <locale.h>
#include <stdio.h>
#include <math.h>

void main()
{
	setlocale(LC_ALL, "RUS");

	char ch;
	printf("������� ������\n");
	scanf_s("%c", &ch);

	if (ch >= 'a' && ch <= 'z') 
		printf("��� �����\n");		
	else if (ch >= '0' && ch <= '9') 
		printf("��� �����\n"); 
	else
		printf("��� �� �����, �� �����\n");

	char c;
	float x, y;
	printf("\n������� ���������\n");
	scanf("%f%c%f", &x, &c, &y);

	switch (c)
	{
		case '+':
			printf("= %.2f", x + y);
			break;
		case '-':
			printf("= %.2f", x - y);
			break;
		case '/':
			printf("= %.2f", x / y);
			break;
		case '*':
			printf("= %.2f", x * y);
			break;
		case '^':
			printf("= %.2f", pow(x, y));
			break;
		default:
			printf("����������� ��������\n");
	}		
}