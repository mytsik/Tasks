#include <locale.h>
#include <stdio.h>
#include <math.h>

void main()
{
	setlocale(LC_ALL, "RUS");

	char ch;
	printf("Введите символ\n");
	scanf_s("%c", &ch);

	if (ch >= 'a' && ch <= 'z') 
		printf("Это буква\n");		
	else if (ch >= '0' && ch <= '9') 
		printf("Это цифра\n"); 
	else
		printf("Это ни буква, ни цифра\n");

	char c;
	float x, y;
	printf("\nВведите выражение\n");
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
			printf("Неизвестный оператор\n");
	}		
}