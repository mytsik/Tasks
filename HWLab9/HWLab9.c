#include <stdio.h>
#include <locale.h>
#define M_PI 3.14
#define _USE_MATH_DEFINES

void main()
{
	setlocale(LC_ALL, "RUS");
	
	while (1)
	{		
		int a;
		
		char symbol;
		printf("Введите символ из которого будет строиться фигура\n");
		scanf_s(" %c", &symbol);
		int Radius; //радиус описанной окружности
		printf("Введите радиус\n");
		scanf_s("%d", &Radius);
				
		int cos_p5 = cos(M_PI / 5);
		int side = (1.18 * Radius);
		side = (int)side;//сторона
		int width = 2 * Radius; //ширина 

		if (width % 2 == 0)
			width += 1;
		if (side % 2 == 0)
			side += 1;

		int spaces = (width - 1) / 2; //пробелы для верхней части

		//печатаем верхнюю часть
		for (int i = 1; i < width; i += 6, spaces -= 3) // цикл для всей верхней части пентагона
		{
			for (int j = 0; j <= spaces; j++) // цикл для пробелов одной строки
				printf(" ");
			for (int k = 1; k <= i; k++) //цикл для символов одной строки
				printf("%c", symbol);
			printf("\n");
		}
		//печатаем нижнюю часть
		for (int i = width, s = 1; i >= side; i -= 2, s++)
		{
			for (int j = 1; j <= s; j++) // цикл для пробелов одной строки
				printf(" ");
			for (int k = 1; k <= i; k++) //цикл для символов одной строки
				printf("%c", symbol);
			printf("\n");
		}

		
		//
		printf("\nПродолжить? (Да - 1, нет - 0)\n");				
		scanf_s("%d", &a);
		if (a == 0)
			break;
				
		//printf("\nПродолжить? (Да - д, нет - н)\n");
		////system("pause");
		//if ((a = getchar()) == "н") break;
	}	
}