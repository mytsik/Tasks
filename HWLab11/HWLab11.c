#include <stdio.h>
#include <locale.h>

void main() 
{
    setlocale(LC_ALL, "RUS");

    int n, A;
    printf("������� ���������� ��������� ������� n\n");
    scanf_s("%d", &n);
    printf("������� ����� A\n");
    scanf_s("%d", &A);

    
    int array[1000]; 
    printf("������� %d ��������� �������\n", n);
    for (int i = 0; i < n; i++) 
        scanf_s("%d", &array[i]);

    int count = 0;    
    for (int j = 0; j < n; j++) 
    {
        if (array[j] > A) 
            count++;
    }

    printf("���������� ��������� �������, ������� ������ %d ����� %d\n", A, count);
}
