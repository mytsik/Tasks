#include <stdio.h>
#include <locale.h>

typedef struct
{
	int number;
	char direction[20];
	int arrival_time;
	int departure_time;
	int distance;

} train;

int writefile(char* fname, train* t, int size)
{
	FILE* out;
	if ((out = fopen(fname, "wt")) == NULL)
	{
		printf("Ошибка открытия файла для записи");
		return 0;
	}

	for (int i = 0; i < size; i++)
		fprintf(out, " No поезда:%3d ; Направление:%20s ; Время прибытия:%2d:%2d; Время отбытия:%2d:%2d; Расстояние:%d\n",
			t[i].number, t[i].direction, t[i].arrival_time, t[i].departure_time, t[i].distance);

	fclose(out);
	return 1;
}

void main()
{
	setlocale(LC_ALL, "RUS");
	char fname[20] = "number.txt";
	FILE* out = fopen(fname, "a");

	puts("Создание файла");
	if (out = fopen(fname, "wt") == NULL)
	{
		printf("Ошибка открытия файла для записи");
		return 0;
	}

	fprintf(out, "%.2lf\n", 12.56);
	fclose(out);

	system("pause");
		
	char* fname2 = "file2.txt";

	double step;
	printf("Введите значение шага\n");
	scanf("%lf", &step);
	getchar();

	int u_ch;
	printf("Введите 1 - запись в новый файл, введите 2 - дозапись в существующий\n");
	scanf("%d", &u_ch);
	getchar();

	FILE* file;

	if (u_ch == 1)
		file = fopen(fname2, "w");
	else if (u_ch == 2)
		file = fopen(fname2, "a");
	else
		return 1;

	if (file == NULL)
		return 1;

	if (step <= 2.2 && step >= 0.1)
	{
		fprintf(file, "_____________________\n");
		fprintf(file, "|   x    |    f(x)  |\n");
		fprintf(file, "---------------------\n");
		for (double x = 0.1; x <= 2.2; x += step)
		{
			double res = pow(x, 2) - pow(cos(x + 1), 2);
			fprintf(file, "|  %.1f   |   %4.1f   |\n", x, res);
			fprintf(file, "---------------------\n");
		}
	}
	else
		printf("Значение шага находится вне интервала");

	fclose(file);
}