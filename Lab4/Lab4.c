#include <locale.h>
#include <stdio.h>
//#define _CRT_SECURE_NO_DEPRECATE
//#define _NO_CRT_STDIO_INLINE

void main() 
{
	setlocale(LC_ALL, "RUS");

	char c;
	printf("������� ���������� char\n");
	scanf_s("%c", &c);	

	int i;
	printf("������� ���������� int\n");
	scanf_s("%i", &i);

	float f;
	printf("������� ���������� float\n");
	scanf("%f", &f);

	double d;
	printf("������� ���������� double\n");
	scanf("%e", &d);

	printf("\n%c\n%i\n%.2f\n%.0e\n", c, i, f, d);
}