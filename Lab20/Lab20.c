#include <stdio.h>
#include <locale.h>
#define SIZE_TH 1000

void main()
{
	setlocale(LC_ALL, "RUS");

	char* fname = "file2.txt";
	FILE* in = fopen(fname, "r");

	if (in == NULL)
		printf("Ошибка открытия файла для чтения");

	double sum = 0;
	double a;
	int n = 0;
	while (!feof(in))
	{
		fscanf(in, "%i", &a);
		sum += a;
		n++;
	}

	printf("%lf", sum / n);
	fclose(in);

	char* fname = "input.dat";
	char* fname2 = "inputparity1.dat";

	FILE* file = fopen(fname, "r");
	FILE* file2 = fopen(fname2, "w");

	if (file == NULL)
		return 1;
	if (file2 == NULL)
		return 1;

	while (!feof(file))
	{
		double res;
		fscanf(file, "%lf", &res);

		res -= 100;
		fprintf(file2, "%lf\n", res);
	}

	fclose(file);
	fclose(file2);
}
