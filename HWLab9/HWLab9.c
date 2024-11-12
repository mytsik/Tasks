#include <stdio.h>
#include <locale.h>
#define M_PI 3.14159265358979323846
#define _USE_MATH_DEFINES

void main()
{
	setlocale(LC_ALL, "RUS");

	char symbol;
	printf("¬ведите символ из которого будет строитьс€ фигура\n");
	scanf_s("%c", &symbol);
	int radius;
	printf("¬ведите радиус\n");
	scanf_s("%d", &radius);

	int sin_p5 = sin(M_PI / 5);
	int width = 2 * radius; //ширина пентагона
	if (width % 2 == 0)
		width += 1;
	//int side = 2 * radius * sin_p5; //длина одной стороны
	
	int spaces = (width - 1) / 2; //пробелы дл€ верхней части
	//int spaces2 = spaces; //пробелы дл€ нижней части

	int side = 0;
	//печатаем верхнюю часть
	for (int i = 1; i <= width; i += 2, spaces -= 1) // цикл дл€ всей верхней части пентагона
	{				
		for (int j = 1; j <= spaces; j++) // цикл дл€ пробелов одной строки
			printf(" ");
		for (int k = 1; k <= i; k++) //цикл дл€ символов одной строки
			printf("%c", symbol);
		printf("\n");
		side += 1;
	}
	//печатаем нижнюю часть
	for (int i = width - 1, s = 1; i >= side; i -= 2, s++)
	{
		for (int j = 1; j <= s; j++) // цикл дл€ пробелов одной строки
			printf(" ");
		for (int k = 1; k < i; k++) //цикл дл€ символов одной строки
			printf("%c", symbol);
		printf("\n");
	}
}