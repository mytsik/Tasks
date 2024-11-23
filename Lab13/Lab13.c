#include <string.h>
#include <stdio.h>

void main()
{
	char Snew[41] = "Hello, ";
	char Name[10];

	printf("What is your name?\n");
	scanf("%s", Name);

	for (int i = 0; i < 10; i++)
		Name[i] = toupper(Name[i]);

	strcat(Snew, Name);	
	char vos[1] = "!";
	char* pt_vos = &vos;
	
	int amount = 40 - strlen(&Snew);
	for (int j = 0; j < amount; j++)
		strcat(Snew, "!");

	Snew[40] = '\0';
	printf("%s!\n", Snew);
}