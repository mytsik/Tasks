#include <locale.h>

#include <stdio.h>

void main()

{

	setlocale(LC_ALL, "RUS"); // ��� ������������ ������� ���������

	puts("Hello Word!"); // ����� ������

	getchar(); // �������� ������

	return 0;

}