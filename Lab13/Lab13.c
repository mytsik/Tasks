#include <string.h>
#include <stdio.h>

void main()
{
	char Snew[20] = "Hello, ";
	char Name[10];

	printf("What is your name?\n");
	scanf("%s", Name);
	strcat(Snew, Name);
	printf("%s!", Snew);

}