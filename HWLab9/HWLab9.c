#include <stdio.h>
#include <locale.h>
#define M_PI 3.14159265358979323846
#define _USE_MATH_DEFINES

void main()
{
	setlocale(LC_ALL, "RUS");

	char symbol;
	printf("������� ������ �� �������� ����� ��������� ������\n");
	scanf_s("%c", &symbol);
	int radius;
	printf("������� ������\n");
	scanf_s("%d", &radius);

	int sin_p5 = sin(M_PI / 5);
	int width = 2 * radius; //������ ���������
	if (width % 2 == 0)
		width += 1;
	//int side = 2 * radius * sin_p5; //����� ����� �������
	
	int spaces = (width - 1) / 2; //������� ��� ������� �����
	//int spaces2 = spaces; //������� ��� ������ �����

	int side = 0;
	//�������� ������� �����
	for (int i = 1; i <= width; i += 2, spaces -= 1) // ���� ��� ���� ������� ����� ���������
	{				
		for (int j = 1; j <= spaces; j++) // ���� ��� �������� ����� ������
			printf(" ");
		for (int k = 1; k <= i; k++) //���� ��� �������� ����� ������
			printf("%c", symbol);
		printf("\n");
		side += 1;
	}
	//�������� ������ �����
	for (int i = width - 1, s = 1; i >= side; i -= 2, s++)
	{
		for (int j = 1; j <= s; j++) // ���� ��� �������� ����� ������
			printf(" ");
		for (int k = 1; k < i; k++) //���� ��� �������� ����� ������
			printf("%c", symbol);
		printf("\n");
	}
}