#include <stdio.h>
#include <locale.h>
#define SIZE_TH 1000

void main()
{
	setlocale(LC_ALL, "RUS");

	char* fname3 = "winter.txt";
	FILE* file3 = fopen(fname3, "r");

	char* ufname[SIZE_TH];
	printf("ֲגוהטעו טלÿ פאיכא\n");
	scanf("%s", &ufname);
	getchar();

	FILE* file4 = fopen(ufname, "w");

	while (!feof(file3))
	{
		char string[255];
		fgets(string, 255, file3);

		int i = 0;
		while (string[i] != '\0')
		{
			if (isupper(string[i]))
				string[i] = ' ';
			i += 1;
		}
		fprintf(file4, string);
	}

	fclose(file3);
	fclose(file4);
}