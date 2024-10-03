#include <locale.h>
#include <stdio.h>
//#define _CRT_SECURE_NO_DEPRECATE
//#define _NO_CRT_STDIO_INLINE

void main() 
{
	setlocale(LC_ALL, "RUS");

	char c;
	printf("Введите переменную char\n");
	scanf_s("%c", &c);

	int i;
	printf("Введите переменную int\n");
	scanf_s("%d", &i);

	float f;
	printf("Введите переменную float\n");
	scanf("%f", &f);

	double d;
	printf("Введите переменную double\n");
	scanf("%le", &d);

	printf("\n%c\n%i\n%.2f\n%le\n", c, i, f, d);

	double num;
	int intPart;
	double doublePart;

	printf("\nВведите вещественное число\n");
	scanf("%lf", &num);

	intPart = (int)num;

	doublePart = num - intPart;

	printf("Целая часть: %d\n", intPart);
	printf("Дробная часть: %.3lf\n\n", doublePart);

	char c2;
	printf("Введите символ\n");
	scanf(" %c", &c2);

	printf("Десятичный код символа равен %i\n", c2);
	printf("Шестнадцатеричный код символа равен %x\n", c2);

	float result;

	if (i != 0) 
	{
		result = 1.0 / i;
		printf("\n1 / %d = %.2f\n", i, result);
	}
	else 
		printf("\nНа 0 делить нельзя\n");

	int a = 3;
	int b = 11;

	printf("\n%d\n%.2f\n%lf\n", (int)a/b, (float)a/b, (double)a/b);

	int N;
	scanf("Ваше число %d", &N);
	int lastD = N % 10;
	int firstD = N / 100;
	int middleD = (N / 10) % 10;
	printf("\nПоследняя цифра %d \n Первая цифра %d \n Сумма цифр %d", lastD, firstD, lastD + firstD + middleD);
}