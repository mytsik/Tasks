#include <locale.h>
#include <stdio.h>

void getPunctName(char pun)
{
    switch (pun) 
    {
        case '.':
            printf("�����\n");
            break;
        case ',':
            printf("�������\n");
            break;
        case '?':
            printf("�������������� ����\n");
            break;
        case '!':
            printf("��������������� ����\n");
            break;
        case ':':
            printf("���������\n");
            break;
        case ';':
            printf("����� � �������\n");
            break;
        case '-':
            printf("����\n");
            break;
        default:
            printf("����������� ���� ����������\n");
    }
}

void main()
{
	setlocale(LC_ALL, "RUS");

    char pun;
	printf("������� ���� ����������\n");
    scanf_s(" %c", &pun);
    getPunctName(pun);
}