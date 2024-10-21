#include <locale.h>
#include <stdio.h>
#include <math.h>

void Task2(float step)
{
	if (step <= 2.2 && step >= 0.1)
	{
		printf("_____________________\n");
		printf("|   x    |    f(x)  |\n");
		printf("---------------------\n");
		for (float x = 0.1; x <= 2.2; x += step)
		{
			float res = pow(x, 2) - pow(cos(x + 1), 2);
			printf("|  %.1f   |   %4.1f   |\n", x, res);
			printf("---------------------\n");
		}
	}
	else
		printf("Значение шага находится вне интервала");
}

void Task1A(int num) 
{
	float res = 0;
	for (int pw = 1; res <= num; pw++)
	{
		res = pow(2, pw);
		float resK = res / 1024;
		if (res > num)
			break;
		
		printf("2^%d=%15.5fK\n", pw, resK);
	}
}

void Task0(char ch1, char ch2, int n)
{
	int half_n = n / 2;
	for (int start = 1; start <= half_n; start++)
		printf("+%c!", ch1);
	for (int start = 1; start <= half_n; start++)
		printf("%c!", ch2);
	if (n % 2 != 0)
		printf("%c", ch2);
}

void main()
{
	setlocale(LC_ALL, "RUS");
	char ch1, ch2;
	int n;
	printf("Введите два символа и число\n");
	scanf_s(" %c", &ch1);
	scanf_s(" %c", &ch2);
	scanf_s("%d", &n);
	Task0(ch1, ch2, n);

	int s = 0;
	int n2, m;
	printf("\n\nВведите два числа\n");
	scanf_s("%d%d", &n2, &m);
	for (int k = 1, i = m; i >= n2; i--)
	{
		s += i;
		printf("Выполнено %d раз(-а)\n", k++);
	}
	printf("\nРезультат %d\n", s);

	int num;
	printf("\nВведите число, до которого нужно выводить степени\n");
	scanf_s("%d", &num);
	Task1A(num);

	float step;
	printf("\nВведите значение шага для табулирования функции y=x^2-cos^2(x+1) в пределах интервала от 0.1 до 2.2 включительно\n");
	scanf_s("%f", &step);

	Task2(step);

}
