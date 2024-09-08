#include <locale.h>

#include <stdio.h>

void main()

{

	setlocale(LC_ALL, "RUS"); // для переключения русской кодировки

	puts("Моя программа"); // вывод строки

	getchar(); // задержка экрана

}