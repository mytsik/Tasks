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
	scanf_s("%d", &i);

	float f;
	printf("������� ���������� float\n");
	scanf("%f", &f);

	double d;
	printf("������� ���������� double\n");
	scanf("%e", &d);

	printf("\n%c\n%i\n%.2f\n%.0e\n", c, i, f, d);

	double num;
	int intPart;
	double doublePart;

	printf("\n������� ������������ �����\n");
	scanf("%lf", &num);

	intPart = (int)num;

	doublePart = num - intPart;

	printf("����� �����: %d\n", intPart);
	printf("������� �����: %.3lf\n\n", doublePart);

	char c2;
	printf("������� ������\n");
	scanf(" %c", &c2);

	printf("���������� ��� ������� ����� %i\n", c2);
	printf("����������������� ��� ������� ����� %x\n", c2);

	int i2;
	float result;

	printf("\n������� ����� ����� i\n");
	scanf("%d", &i2);

	if (i2 != 0) 
	{
		result = 1.0 / i2;
		printf("1 / %d = %.2f\n", i2, result);
	}
	else 
		printf("�� 0 ������ ������\n");

	int a = 3;
	int b = 11;

	printf("\n%d\n%.2f\n%lf\n", (int)a/b, (float)a/b, (double)a/b);

	int N;
	scanf("���� ����� %d", &N);
	int lastD = N % 10;
	int firstD = N / 100;
	int middleD = (N / 10) % 10;
	printf("\n��������� ����� %d \n ������ ����� %d \n ����� ���� %d", lastD, firstD, lastD + firstD + middleD);
}