#include <locale.h>
#include <stdio.h>

void main() 
{
	setlocale(LC_ALL, "RUS");

    float Vc; 
    float S;  
    float Vp; 
    float T;  

    printf("������� �������� �������� (�/�): \n");
    scanf_s("%f", &Vc);
    printf("������� ���������� �� �������� �������� ��������� (�): \n");
    scanf_s("%f", &S);
    printf("������� �������� ������ (�/�): \n");
    scanf_s("%f", &Vp);

    if (Vp <= Vc) {
        printf("������ �� ������ �������� ����, ��� ��� � �������� ������ ��� ����� �������� ��������.\n");
    }
    else {
        T = S / (Vp - Vc);
        printf("����� �� ��������� ����: %.2f ������\n", T);
    }
}