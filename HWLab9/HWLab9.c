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
		printf("������� ������ �� �������� ����� ��������� ������\n");
		scanf_s(" %c", &symbol);
		int Radius; //������ ��������� ����������
		printf("������� ������\n");
		scanf_s("%d", &Radius);
				
		int cos_p5 = cos(M_PI / 5);
		int side = (1.18 * Radius);
		side = (int)side;//�������
		int width = 2 * Radius; //������ 

		if (width % 2 == 0)
			width += 1;
		if (side % 2 == 0)
			side += 1;

		int spaces = (width - 1) / 2; //������� ��� ������� �����

		//�������� ������� �����
		for (int i = 1; i < width; i += 6, spaces -= 3) // ���� ��� ���� ������� ����� ���������
		{
			for (int j = 0; j <= spaces; j++) // ���� ��� �������� ����� ������
				printf(" ");
			for (int k = 1; k <= i; k++) //���� ��� �������� ����� ������
				printf("%c", symbol);
			printf("\n");
		}
		//�������� ������ �����
		for (int i = width, s = 1; i >= side; i -= 2, s++)
		{
			for (int j = 1; j <= s; j++) // ���� ��� �������� ����� ������
				printf(" ");
			for (int k = 1; k <= i; k++) //���� ��� �������� ����� ������
				printf("%c", symbol);
			printf("\n");
		}

		
		//
		printf("\n����������? (�� - 1, ��� - 0)\n");				
		scanf_s("%d", &a);
		if (a == 0)
			break;
				
		//printf("\n����������? (�� - �, ��� - �)\n");
		////system("pause");
		//if ((a = getchar()) == "�") break;
	}	
}