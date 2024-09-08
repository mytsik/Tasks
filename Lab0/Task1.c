#include <locale.h>

#include <stdio.h>

void main()

{

	setlocale(LC_ALL, "RUS"); // для переключения русской кодировки

	puts("Hello Word!"); // вывод строки

	getchar(); // задержка экрана

	return 0;

}