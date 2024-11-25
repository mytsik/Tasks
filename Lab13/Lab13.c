#include <string.h>
#include <stdio.h>
#include <locale.h>

void main()
{
	char Snew[41] = "Hello, ";
	char Name[10];

	printf("What is your name?\n");
	scanf("%s", Name);
	char NameTask2[10];
	strcpy(NameTask2, Name);

	for (int i = 0; i < 10; i++)
		Name[i] = toupper(Name[i]);

	strcat(Snew, Name);	
	
	int amount = 40 - strlen(&Snew);
	for (int j = 0; j < amount; j++)
		strcat(Snew, "!");

	Snew[40] = '\0';
	printf("%s!\n", Snew);

	setlocale(LC_ALL, "RUS");

	char SnewTask2[41] = "Привет, ";
	int nameLen = strlen(&NameTask2);
	char NameBack[10];
	int k = 0;

	for (int i = nameLen - 1; i >= 0; i--)
	{
		NameBack[k] = NameTask2[i];
		if (i == nameLen - 1)
			NameBack[k] = tolower(NameBack[k]);
		else if (i == 0)
			NameBack[k] = toupper(NameBack[k]);
		k += 1;
	}

	strcat(SnewTask2, NameBack);
	printf("\n%s!\n", SnewTask2);
}